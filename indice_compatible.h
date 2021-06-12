// MATRIZ[fila][columna]
// 												derecha
// 									0	|VAR_INTEGER	|CONST_INTEGER  | VAR_FLOAT	|CONST_FLOAT|VAR_STRING	|CONST_STRING
//	izquierda	     0			|		|				|				|			|			|			|	
//				VAR_INTEGER		|		|				|				|			|			|			|
//				CONST_INTEGER 	|		|				|				|			|			|			|
//				VAR_FLOAT		|		|				|				|			|			|			|
//				CONST_FLOAT 	|		|				|				|			|			|			|
//				VAR_STRING		|		|				|				|			|			|			|
//				CONST_STRING	|		|				|				|			|			|			|
//

const int MAT_SUMA[7][7]={0,0,0,0,0,0,0,
						  0,1,1,3,3,0,0,
						  0,1,1,3,3,0,0,
						  0,3,3,3,3,0,0,
						  0,3,3,3,3,0,0,
						  0,0,0,0,0,0,0,
						  0,0,0,0,0,0,0};
						  
const int MAT_RESTA[7][7]={0,0,0,0,0,0,0,
						  0,1,1,3,3,0,0,
						  0,1,1,3,3,0,0,
						  0,3,3,3,3,0,0,
						  0,3,3,3,3,0,0,
						  0,0,0,0,0,0,0,
						  0,0,0,0,0,0,0};

const int MAT_MULT[7][7]={0,0,0,0,0,0,0,
						  0,1,1,3,3,0,0,
						  0,1,1,3,3,0,0,
						  0,3,3,3,3,0,0,
						  0,3,3,3,3,0,0,
						  0,0,0,0,0,0,0,
						  0,0,0,0,0,0,0};

const int MAT_DIV[7][7]={0,0,0,0,0,0,0,
						  0,1,1,3,3,0,0,
						  0,1,1,3,3,0,0,
						  0,3,3,3,3,0,0,
						  0,3,3,3,3,0,0,
						  0,0,0,0,0,0,0,
						  0,0,0,0,0,0,0};			

const int MAT_ASIG[7][7]={0,0,0,0,0,0,0,
						  0,1,1,0,0,0,0,
						  0,0,0,0,0,0,0,
						  0,3,3,3,3,0,0,
						  0,0,0,0,0,0,0,
						  0,0,0,0,0,5,5,
						  0,0,0,0,0,0,0};

const int MAT_CMP[7][7]={0,0,0,0,0,0,0,
						 0,7,7,7,7,0,0,
						 0,7,7,7,7,0,0,
						 0,7,7,7,7,0,0,
						 0,7,7,7,7,0,0,
						 0,0,0,0,0,7,7,
						 0,0,0,0,0,7,7};						  