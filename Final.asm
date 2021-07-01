include macros.asm
include number.asm

.MODEL  LARGE 		;tipo de modelo de memoria usado
.386
.STACK 200h 			; bytes en el stack

.DATA 				; comienzo de la zona de datos
_a                            	dd				?
_b                            	dd				?
_c                            	dd				?
_d                            	dd				?
_e                            	db				35 dup (?),'$'
_f                            	db				35 dup (?),'$'
CTE_4                         	dd				4
CTE_1                         	dd				1
CTE_5                         	dd				5
CTE_6                         	dd				6
CTE_2                         	dd				2
CTE_47                        	dd				47
CTE_33                        	dd				33
str0                          	db				"Prueba",'$'
str1                          	db				"Prueba WRT",'$'
CTE_7                         	dd				7
str2                          	db				"condicion inlist",'$'
@aux28                        	dd				?
@aux29                        	dd				?
@aux32                        	dd				?
@aux33                        	dd				?
@aux53                        	dd				?
@aux56                        	dd				?

.CODE 
START:  ;etiqueta de inicio de programa
	mov AX,@DATA ;inicializa el segmento de datos
	mov DS,AX
	mov es,ax
ET0:
	FLD _a
	FLD CTE_4
	FCOMP
	FSTSW AX
	SAHF
	FFREE
	JE ET8
	FLD _a
	FLD _c
	FCOMP
	FSTSW AX
	SAHF
	FFREE
	JE ET8
	JNE ET48
ET8:
	FLD _a
	FLD _b
	FCOMP
	FSTSW AX
	SAHF
	FFREE
	JAE ET40
	FLD _b
	FLD _c
	FCOMP
	FSTSW AX
	SAHF
	FFREE
	JAE ET40
	FLD _c
	FLD _b
	FCOMP
	FSTSW AX
	SAHF
	FFREE
	JNA ET35
	FLD _a
	FLD _b
	FCOMP
	FSTSW AX
	SAHF
	FFREE
	JE ET35
	FILD CTE_1
	FILD CTE_5
	FMUL
	FISTP @aux28
	FILD _b
	FILD @aux28
	FADD
	FISTP @aux29
	FILD CTE_6
	FILD CTE_2
	FMUL
	FISTP @aux32
	FILD @aux29
	FILD @aux32
	FADD
	FISTP @aux33
	FILD @aux33
	FISTP _a
ET35:
	FILD CTE_47
	FISTP _b
	FILD CTE_47
	FISTP _c
	FILD CTE_47
	FISTP _a
	JMP ET8
ET40:
	FILD CTE_33
	FISTP _b
	FILD CTE_33
	FISTP _d
	FILD CTE_33
	FISTP _a
	LEA DI, _f 	; Muevo a registro DI el comienzo de la cadena destino
	LEA SI, str0 	; Muevo a registro SI el comienzo de la cadena fuente
	STRCPY ; Macro, copia un string con maximo 31 caracteres
	LEA DI, _e 	; Muevo a registro DI el comienzo de la cadena destino
	LEA SI, str0 	; Muevo a registro SI el comienzo de la cadena fuente
	STRCPY ; Macro, copia un string con maximo 31 caracteres
	JMP ET0
ET48:
	GetInteger _a
	newLine 1
	DisplayInteger _b
	newLine 1
	displayString str1
	newLine 1
	FILD CTE_7
	FILD CTE_5
	FMUL
	FISTP @aux53
	FILD _a
	FILD CTE_1
	FDIV
	FISTP @aux56
	FLD _a
	FLD @aux56
	FCOMP
	FSTSW AX
	SAHF
	FFREE
	JE ET62
	FLD _a
	FLD @aux53
	FCOMP
	FSTSW AX
	SAHF
	FFREE
	JE ET62
	JNE ET63
ET62:
	displayString str2
	newLine 1
ET63:
	mov ax,4c00h ;indica que finaliza la ejecución
	Int 21h ;llamada al sistema operativo

END START
