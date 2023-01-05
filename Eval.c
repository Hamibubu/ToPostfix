#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stackEX.h"
#include "stackEX.c"

STR buff; // Como extra escaneamos de forma dinámica el texo para no especificar tamaño

int main(){
	apuntastack st1 = creastack();
	apuntastack stacknum = creastack();
	apuntastack stackop = creastack();
    CHAR c;
	printf("Dame una cadena\n> ");
	leercadena(&buff);
	int i;
	int pre=0;
	int tm = strlen(buff);
	//Añadimos al stack los valores dependiendo de si son operandos u operadores 
	for(i=0;i<tm;i++){
		c = creachar(buff[i]);
		if(esoperando(c)){
			push(stacknum,c);
		}else if(((*c)=='(')){
			push(stackop,c);
		}
		else if((buff[i]=='+') || (buff[i]=='-') || (buff[i]=='*') || (buff[i]=='/')){
			while(!vacio(stackop)){
				if(precedencia(c) <= precedencia(stackop->tope->dato)){
					push(stacknum, pop(stackop));
				}else{
					break;
				}
			}
			push(stackop,c);
		}else if(buff[i]==')'){
			while(!vacio(stackop) && (char_val((CHAR) stackop->tope->dato) != '(')){
				push(stacknum, pop(stackop));
			}
			pop(stackop);
		}
	}
	//Vaciamos lo que quedó en el stack
	while(!vacio(stackop))
	{
		push(stacknum, pop(stackop));
	}
	i=0;
	tm=stacknum->tam;
	// Creamos la lista para almacenar e imprimir el stack de num al reves
	STR res = malloc(stacknum->tam*sizeof(char));
	while(!vacio(stacknum))
	{
		c = pop(stacknum);
		res[i]=char_val(c);
		i++;
	}
	printf("\n---------------------------EXPRESION DE ENTRADA INFIJA---------------------------\n");
	printf("\n%s\n",buff);
	printf("\n---------------------------EXPRESION DE SALIDA POSFIJA---------------------------\n\n");
	//Imprimimos el stack al reves para la expresion posfija
	for(i=0;i<tm+1;i++){
		if(res[tm-i]!='('){
			printf("%c",res[tm-i]);
		}
	}
	printf("\n\n-------GRACIAS-------\n\n~EQUIPO:\n\n- ABRAHAM DE LEON GUTIERREZ\n- LUIS SANTIAGO ZAMORA VARGAS\n\n");
}