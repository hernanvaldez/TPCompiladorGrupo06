include macros2.asm
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
str0                          	db				"Prueba"
str0                          	dd				?
str1                          	db				"Prueba WRT"
str1                          	dd				?
CTE_7                         	dd				7
str2                          	db				"condicion inlist"
str2                          	dd				?
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
	FLD CMP
	FCOMP _a
	FSTSW AX
	SAHF
	FFREE
	JE ET8
	FLD CMP
	FCOMP _a
	FSTSW AX
	SAHF
	FFREE
	JE ET8
	JNE ET48
ET8:
	FLD CMP
	FCOMP _a
	FSTSW AX
	SAHF
	FFREE
	JAE ET40
	FLD CMP
	FCOMP _b
	FSTSW AX
	SAHF
	FFREE
	JAE ET40
	FLD CMP
	FCOMP _c
	FSTSW AX
	SAHF
	FFREE
	JNA ET35
	FLD CMP
	FCOMP _a
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
ET35:
	JMP ET8
ET40:
	JMP ET0
ET48:
	FILD CTE_7
	FILD CTE_5
	FMUL
	FISTP @aux53
	FILD _a
	FILD CTE_1
	FDIV
	FISTP @aux56
	FLD CMP
	FCOMP _a
	FSTSW AX
	SAHF
	FFREE
	JE ET62
	FLD CMP
	FCOMP _a
	FSTSW AX
	SAHF
	FFREE
	JE ET62
	JNE ET63
ET62:
ET63:
	mov ax,4c00h ;indica que finaliza la ejecución
	Int 21h ;llamada al sistema operativo

END START
