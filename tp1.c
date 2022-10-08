#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//1 - 12 16
//2 - 0 -231232
/*3 - A 65
	  B 66 2 50
	  b 98*/
//4 100 200

//2 - Estruturas de controlo
//1. 3 5
//2. 11 66
//3. _#_#_#_#_#_#_#_#_#_#
//4. 
/*
1
01
11
001
101
011
111
0001
1001
0101
1101
0011
1011
0111
1111
*/


void quadrado(int N){
	int i,j;

	for(i = 0; i <N; i++){
		putchar('\n');
		for(j = 0; j<N; j++){
			putchar('#');
		}
	}
}

void xadrez(int N){
	int i;

	for (i=0; i< (N*N); i++){
		if(i % N == 0 ) putchar('\n');
		if(i % 2 == 0) putchar('#');
		else putchar('_');
	}
}


void trianguloVertical(int n){
	int i,j;

	for (i = 1; i <= 2*n-1; i++){
		if (i <= n) 
			for (j = 0; j < n-(n-i); j++) putchar('#');
		else 
			for (j = 0; j < n+(n-i); j++) putchar('#');
		putchar('\n');
	}
}

void trianguloHorizontal(int n){
	int i,j;
	
	for (i = 1; i <= n; i++){
		for (j = 0; j < n-i; j++) putchar(' ');
		for (j = 0; j < 2*i-1; j++) putchar('#');
		putchar('\n');	
	}

}


void circulo(int N){
	float dist; int i,j;

	for(i = 0; i <= 2*N; i++){
		for (j = 0;j <= 2*N; j++){
			dist = sqrt((i-N)*(i-N)+(j-N)*(j-N));

			if (dist > N - 0.5 && dist < N + 0.5)
				putchar('#');
			else 
				putchar('');
		}
		putchar('\n');
	}
}




int main(int argc, char const *argv[]){
	///quadrado(4);
	//xadrez(5);
	circulo(8);
	return 0;
}