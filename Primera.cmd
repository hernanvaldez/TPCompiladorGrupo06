flex Lexico.l
bison -dyv Sintactico.y
gcc lex.yy.c y.tab.c -o Primera.exe
pause
Primera.exe prueba.txt