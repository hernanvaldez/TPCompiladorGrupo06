include macros.asm
include number.asm

.MODEL  LARGE 		;tipo de modelo de memoria usado
.386
.STACK 200h 			; bytes en el stack

.DATA 				; comienzo de la zona de datos
_a                            	dd				?
_var1                         	dd				?
_c                            	dd				?
_d                            	dd				?
_base                         	dd				?
_b                            	db				35 dup (?),'$'
_e                            	db				35 dup (?),'$'
_q                            	db				35 dup (?),'$'
_w                            	db				35 dup (?),'$'
str0                          	db				"@sdADaSjfladfg",'$'
CTE_5                         	dd				5
CTE_99_                       	dd				99.
CTE_99_45                     	dd				99.45
CTE__999                      	dd				.999
CTE_35                        	dd				35
CTE_33                        	dd				33
str1                          	db				"a es distinto de 35",'$'
CTE_4                         	dd				4
CTE_1                         	dd				1
str2                          	db				"a es igual a 35",'$'
CTE_34                        	dd				34
str3                          	db				"condicion inlist",'$'
str4                          	db				"NO inlist",'$'
str5                          	db				"Hola mundo",'$'
str6                          	db				"correcto",'$'
str7                          	db				"Chau mundo",'$'
@aux39                        	dd				?
@aux51                        	dd				?

.CODE 
START:  ;etiqueta de inicio de programa
	mov AX,@DATA ;inicializa el segmento de datos
	mov DS,AX
	mov es,ax
	LEA DI, _b 	; Muevo a registro DI el comienzo de la cadena destino
	LEA SI, str0 	; Muevo a registro SI el comienzo de la cadena fuente
	STRCPY ; Macro, copia un string con maximo 31 caracteres
	FILD CTE_5
	FISTP _a
	FLD CTE_99_
	FSTP _c
	FLD CTE_99_45
	FSTP _d
	FLD CTE__999
	FSTP _base
	FLD CTE_35
	FLD _a
	FCOMP
	FSTSW AX
	SAHF
	FFREE
	JAE ET17
	JMP ET19
ET17:
	FLD CTE_35
	FLD _a
	FCOMP
	FSTSW AX
	SAHF
	FFREE
	JNA ET46
ET19:
	FLD CTE_35
	FLD _a
	FCOMP
	FSTSW AX
	SAHF
	FFREE
	JE ET28
	FILD CTE_33
	FISTP _a
	displayString str1
	newLine 1
	JMP ET30
ET28:
	FILD CTE_4
	FISTP _a
ET30:
	FLD CTE_35
	FLD _a
	FCOMP
	FSTSW AX
	SAHF
	FFREE
	JAE ET44
	DisplayInteger _a
	newLine 1
	FILD _a
	FILD CTE_1
	FADD
	FISTP @aux39
	FILD @aux39
	FISTP _a
	DisplayInteger _a
	newLine 1
	JMP ET30
ET44:
	displayString str2
	newLine 1
ET46:
	FILD CTE_34
	FISTP _a
	FILD _a
	FILD CTE_1
	FSUB
	FISTP @aux51
	FLD @aux51
	FLD _a
	FCOMP
	FSTSW AX
	SAHF
	FFREE
	JE ET57
	FLD CTE_35
	FLD _a
	FCOMP
	FSTSW AX
	SAHF
	FFREE
	JE ET57
	JNE ET60
ET57:
	displayString str3
	newLine 1
	JMP ET62
ET60:
	displayString str4
	newLine 1
ET62:
	FLD CTE_35
	FLD _a
	FCOMP
	FSTSW AX
	SAHF
	FFREE
	JE ET79
	displayString str5
	newLine 1
	FILD CTE_35
	FISTP _a
	FLD CTE_35
	FLD _a
	FCOMP
	FSTSW AX
	SAHF
	FFREE
	JNE ET78
	LEA DI, _b 	; Muevo a registro DI el comienzo de la cadena destino
	LEA SI, str6 	; Muevo a registro SI el comienzo de la cadena fuente
	STRCPY ; Macro, copia un string con maximo 31 caracteres
	displayString str7
	newLine 1
ET78:
	JMP ET81
ET79:
	displayString str7
	newLine 1
ET81:
	GetFloat _base,2
	newLine 1
	DisplayInteger _a
	mov ax,4c00h ;indica que finaliza la ejecución
	Int 21h ;llamada al sistema operativo

END START
