flex Lexico.l
bison -dyv Sintactico.y
gcc lex.yy.c y.tab.c -o Segunda.exe
pause
Segunda.exe prueba_tercetos.txt
pause
