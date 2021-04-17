# TPCompiladorGrupo06
Trabajo Practico Compilador para la materia Lenguajes y Compiladores - 1er Cuatrimestre 2021


Secuencias de comandos para ejecucion:

> flex Lexico.l
> bison -dyv Sintactico.y
> gcc lex.yy.c y.tab.c -o compilador
> .\compilador.exe prueba.txt 