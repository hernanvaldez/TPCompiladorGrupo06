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
_nombre                       	db				35 dup (?),'$'
str0                          	db				"-suma dos enteros-",'$'
str1                          	db				"Ingrese 1er numero int",'$'
str2                          	db				"Ingrese segundo numero int",'$'
str3                          	db				"resultado: ",'$'
str4                          	db				"Ingrese su nombre: ",'$'
str5                          	db				"Hola ",'$'
str6                          	db				"Termino programa",'$'
@aux10                        	dd				?

.CODE 
START:  ;etiqueta de inicio de programa
	mov AX,@DATA ;inicializa el segmento de datos
	mov DS,AX
	mov es,ax
	displayString str0
	newLine 1
	displayString str1
	newLine 1
	GetInteger _a
	newLine 1
	displayString str2
	newLine 1
	GetInteger _var1
	newLine 1
	FILD _a
	FILD _var1
	FADD
	FISTP @aux10
	FILD @aux10
	FISTP _a
	FILD @aux10
	FSTP _c
	displayString str3
	DisplayFloat _c,2
	newLine 1
	displayString str4
	getString _nombre
	newLine 1
	newLine 1
	displayString str5
	displayString _nombre
	newLine 1
	displayString str6
	mov ax,4c00h ;indica que finaliza la ejecución
	Int 21h ;llamada al sistema operativo

END START
