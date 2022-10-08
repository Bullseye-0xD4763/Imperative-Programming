#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//def de structs

typedef struct lligada {
	int valor;
	struct lligada *prox;
} *LInt;

//Auxes de Listas
LInt newLInt (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct lligada));
    
    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}



//1
int length(LInt l){
	int count = 0;
	while(l != NULL){
		count++;
		l = l->prox;
	}
	return count;
}

//2
void freeL(LInt l){
    LInt tmp;

    while(l != NULL){
        tmp = l; //guarda nodo
        l = l->prox; // avança para prox
        free(tmp); //liberta nodo;
    }
}

//3
void imprimeL(LInt l){
	if(length(l) == 0) printf("\nVazia\n");

	putchar('\n'); putchar('[');
	while(l != NULL){
		printf("%d ",l->valor);
		l = l->prox;
	}
	putchar(']');
}

//4 REVERSE NAO DEU
LInt reverseL (LInt l){
    LInt before = NULL;
    LInt start    = l;
    LInt after;
    while(l != NULL){
        after = l->prox;
        l->prox = before;
        before = l;
        l = after;
    }
    start = before;
    return start;
}



//5
void insertOrd (LInt *l, int x){
    //Determina o local onde inserir um novo nodo
    while (*l!=NULL && (*l)->valor < x){
        l = &(*l)->prox;
    }
    //cria o novo nodo a inserir na lista
    *l= newLInt (x,*l);
}


int main(int argc, char const *argv[]){
	int escolha = 0, escolha_sec = 0; char string1[64], string2[64];
	LInt lGlobal = NULL;

	for(int i = 10; i > 0; i--) lGlobal = newLInt(i,lGlobal);



	printf("\nQue questão quer ?: \n"); scanf("%d" ,&escolha);
	
	switch (escolha){
		case 1:
			printf("Length da lista = %d" ,length(lGlobal));
			break;
		case 2:
			printf("Free, sem output\n");
			break;
		case 3:
		    imprimeL(lGlobal);
			break;
		case 4:
			printf("\nInverter Lista\nAntes: "); imprimeL(lGlobal);
			reverseL(lGlobal); printf("\nDepois: ");
			imprimeL(lGlobal);
			break;
		case 5:
		    printf("\nAntes: "); imprimeL(lGlobal);
			printf("\nº a inserir "); scanf("%d" ,&escolha_sec);
			printf("\nDepois: "); imprimeL(lGlobal);
			break;
		case 6:
			
			break;
		case 7:
			
			break;
		case 8:
			
			break;
		case 9:
			
			break;
		case 10:
			
			break;
		case 11:
			
			break;
		case 12:
			
			break;
		case 13:
			
			break;
		case 14:
			
			break;
		case 15:
			
			break;
		case 16:
			
			break;
		case 17:
			
			break;
		case 18:
			
			break;
		case 19:
			break;
		case 20:
			break;
		case 21:
			break;
		case 22:
			break;
		case 23:
			break;
		case 24:
			break;
		case 25:
			break;
		case 26:
			break;
		case 27:
			break;
		case 28:
			break;
		case 29:
			break;
		case 30:
			break;
		case 31:
			break;
		case 32:
			break;
		case 33:
			break;
		case 34:
			break;
		case 35:
			break;
		case 36:
			break;
		case 37:
			break;
		case 38:
			break;
		case 39:
			break;
		case 40:
			break;
		case 41:
			break;
		case 42:
			break;
		case 43:
			break;
		case 44:
			break;
		case 45:
			break;
		case 46:
			break;
		case 47:
			break;
		case 48:
			break;
		case 49:
			break;
		case 50:
			break;


		default:
			printf("\nNão existe.");
			break;
	}

	/*for (int i = 2; i<= 50;i++)
		printf("case %d:\n\tbreak;\n", i);*/






	return 0;
}