#ifndef STACKEX_H_
#define STACKEX_H_

typedef void * tipo;
typedef char * CHAR;
typedef char * STR;

struct nodo {
	tipo dato;
	int precedencia;
	struct nodo *previo;
};
typedef struct nodo * apuntanodo;
struct stack {
	int tam;
	apuntanodo tope;
};
typedef struct stack * apuntastack;

STR creastr(char dato[]);
CHAR creachar(char dato);
apuntastack creastack();
void push(apuntastack stk, tipo dato);
int vacio(apuntastack stk);
tipo pop(apuntastack stk);
void destruye(apuntastack stk);
void destruyedato(tipo dato);
int esoperando(CHAR dato);
int precedencia(CHAR dato);
void leercadena(STR *dato);

#define char_val(n) (*((char *) n))

#endif
