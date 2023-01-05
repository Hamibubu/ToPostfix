#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stackEX.h"

apuntastack creastack(){
	apuntastack nuevo = malloc(sizeof(struct stack));
	nuevo->tam = 0;
	nuevo->tope = NULL;
	return nuevo;
}
void push(apuntastack stk, tipo dato){
	apuntanodo nuevonodo = malloc(sizeof(struct nodo));
	nuevonodo->dato = dato;
	nuevonodo->previo = stk->tope;
	stk->tope = nuevonodo;
	stk->tam++;
}
int vacio(apuntastack stk){
	return(stk->tope==NULL);
}
tipo pop(apuntastack stk){
	apuntanodo borra = malloc(sizeof(struct nodo));
	tipo reg = stk->tope->dato;
	stk->tope=stk->tope->previo;
	stk->tam--,
	free(borra);
	return(reg);
}
void destruye(apuntastack stk){
	while(!vacio(stk)){
		pop(stk);
	}
	free(stk);
}
STR string_create(STR str)
{
	int len = strlen(str);
	STR new = malloc(len);
	strcpy(new,str);
	return new;
}
CHAR creachar(char dato){
	CHAR new = malloc(sizeof(char *));
	*new = dato;
	return new;
}
void destruyedato(tipo dato){
	free(dato);
}
int precedencia(CHAR dato){
	int precedencia=0;
	switch (*dato)
	{
	case '+':
	case '-':
		precedencia=1;
		break;
	case '*':
	case '/':
		precedencia=2;
		break;
	default:
		precedencia=-1;
		break;
	}
	return precedencia;
}
int esoperando(CHAR dato){
	if(((*dato) >= 'a' && (*dato) <= 'z') || ((*dato) >= 'A' && (*dato) <= 'Z') || ((*dato) >= '0' && (*dato) <= '9')){
		return 1;
	}
	else{
		return 0;
	}
}
void leercadena(STR *dato){  // De pura curiosidad quismos escanear dinámicamente el texo
	char c;
	int i;
	STR aux = NULL;
	if((*dato) != NULL){
		free(*dato);
		(*dato)=NULL;
	}
	i=1;
	while((c=getchar())!='\n'){
		aux=(STR)realloc(aux,(i+2)*sizeof(char));
		aux[i-1]=c;
		aux[i]='\0';
		i++;
	}
	if(aux==NULL){
		aux = (STR) malloc(5*sizeof(char));
		strcpy(aux,"NULL");
	}else{
	(*dato) = (STR) realloc((*dato),(strlen(aux)+1)*sizeof(char));
	strcpy((*dato),aux);
	}
	free(aux);
}