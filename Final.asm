.MODEL  LARGE 		;tipo de modelo de memoria usado
.386
.STACK 200h 			; bytes en el stack
.DATA 				; comienzo de la zona de datos
a                             	dd				?
b                             	dd				?
c                             	dd				?
d                             	dd				?
e                             	dd				?
f                             	dd				?
__4                           	dd				4
__1                           	dd				1
__5                           	dd				5
__6                           	dd				6
__2                           	dd				2
__47                          	dd				47
__33                          	dd				33
Prueba                        	db				"Prueba"
Prueba_WRT                    	db				"Prueba WRT"
__7                           	dd				7
condicion_inlist              	db				"condicion inlist"

.CODE 
