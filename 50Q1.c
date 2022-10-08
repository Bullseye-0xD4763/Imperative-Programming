#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void um(){
	int i = -1, max = 0;
	printf("\nInsira números\n");
	while (i != 0){
		scanf("%d" ,&i);
		if(max < i) max = i;
	}
	printf("\nO max foi %d" ,max);
}


void dois(){
	double soma = 0; int counter= 0, i = -1;
	printf("\nInsira números\n");
	while (i != 0){
		scanf("%d" ,&i);
		counter++;
		soma += i;
	}
	counter--;
	printf("\nA média foi :%f" ,soma/counter);
}



//Auxiliar para exercicio 3
int array_max(int v[],int N){
	int max = 0;
	for(int i = 0; i < N;i++)
		if(v[i] > max) max = v[i]; 
	return max;
}

void array_delete(int v[], int N, int del){
	for (int i = 0; i<N; i++){
		if(v[i] == del) v[i] = v[i+1];
	}
}



void tres(){
	int i = -1, max = 0, vetor[256],index_vetor = 0;
	printf("\nInsira números\n");

	while (i != 0){
		scanf("%d" ,&i);
		vetor[index_vetor++] = i;
		if(max < i) max = i;
	}
	array_delete(vetor,index_vetor+1,max);
	printf("\nO max foi %d, e o segundo max foi %d" ,max,array_max(vetor,index_vetor));
}

int bitsUm_4 (unsigned int x){
    int r=0;
    
    while(x != 0){
        if(x%2 == 1) // se o resto de x por 2 for impar isto é, 1 o contador soma mais 1
            r++;
    x /= 2;
    }
    return r;
}

////Dúvida nesta
int trailingZ_5 (unsigned int n) {
    if(n==0)
        return 32;
    else{
        int contador = 0;
        do{
            if(n % 2 == 1)
                break;
            n /= 2;
            contador++;
        }while(n != 0);
 
        return contador;
    }
}


int qDig_6 (int n) {
    int r = 0;
    while(n > 0){
    	n /= 10;
    	r++;
    }
    return r;
}

//Aux Exercicio 7
int comprimento(char s1[]){
	int i;
	for(i = 0; s1[i] != '\0'; i++);
	return i;
}

char *strcat_7(char s1[], char s2[]) {
    int l1 = comprimento(s1), l2 = comprimento(s2), i = 0;
    for(i = 0; i < l2; i++) s1[l1+i] = s2[i];

    s1[l1+i] = '\0';
    return s1;
}

char *strcpy_8 (char *dest, char source[]){
	int i;
	for (i = 0; source[i] != '\0'; i++) dest[i] = source[i];
	dest[i] = '\0';
	return dest; //&(dest[0])
}


//Aux Exercicio 9
char *max_word(int i, char s1[], char s2[]){
	if(i > 0) return s1;
	if(i < 0) return s2;
	return "São iguais";
}

int strcmp_9(char s1[], char s2[]){
    int i;
    for(i=0; s1[i]!='\0' && s1[i]==s2[i]; i++);
    return s1[i]-s2[i];
 }


//s2 ocorre em s1
char *strstr_10 (char s1[], char s2[]){
	int i= 0,j = 0,pos = 0; char *r = NULL;

	if(s2[0] == '\0') return s1;

	for(i= 0; s1[i] != '\0'; i++){
		if (s1[i] == s2[0]) pos = i;
		if (s1[i] == s2[j]) j++;
		if (s2[j] == '\0') r = s1+pos;
	}
	return r;
}

/* Nota de como somas de inteiros a strings funcionam em c
Iteração s1+0 =  Macaco
Iteração s1+1 =  acaco
Iteração s1+2 =  caco
Iteração s1+3 =  aco
Iteração s1+4 =  co
Iteração s1+5 =  of
*/


void strrev_11(char s[]){
	int i,j; char temp[124];

	for(i = 0; s[i] != '\0'; i++) temp[i] = s[i];
	i--;	//e.g se a string tem 6 posições o ultimo indice é 5 logo temos de
			//fazer s[6--] = s[5]
	for(j = 0; i >= 0; j++) s[j] = temp[i--];

	printf(" %s",s);
}


void strnoV_12 (char s[]){
	int i,j = 0;
	for(i = 0; s[i] != '\0'; i++)
		if(s[i] != 'a' && s[i] !='e'&& s[i] != 'i'&& s[i] != 'o' && s[i] != 'u' && s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U'){
			s[j] = s[i];
			j++;
		}

	s[j] = '\0';
	printf("\nSem fica: %s",s);
}

void truncW_13 (char t[], int n){
 	int i,j,counter = n;
 	for(i = 0, j = 0; t[i] != '\0'; i++){
 		if(t[i] == ' '){
 			t[j++] = t[i];
 			counter = n;
 		}
 		else{
 			if (counter > 0){
 				t[j++] = t[i];
 				counter--;
 			}
 		}
 	}
 	t[j] = '\0';
 	printf("\nResultado: %s",t);
}

char charMaisfreq_14 (char s[]){
    int i,counters[128] = {0}; unsigned char r = 0;//unsined apenas para retirar erro //todo array a zeros
    for(i = 0; s[i] != '\0'; i++)
        counters[s[i]]++; //counters[66]++
    for(i=0; i<128; i++)
        if(counters[i] > counters[r]) r = i; //counters[2] > counters[0] = r = 2;
    return r;
}

int iguaisConsecutivos_15 (char s[]){
	int i,j, count = 0,max = 0;

	for(i = 0; s[i] != '\0'; i++){
		count = 0;
		for (j = i; s[j] != '\0' && s[i] == s[j]; j++) count++;
		if (count > max) max = count;	
	}
	return max;
}



int difConsecutivos_16 (char s[]){
	int i,j, count = 0, max = 0;

	for(i = 0; s[i] != '\0'; i++){
		int ocorr[256] = {0};
		for(j = i, count = 0; s[j] != '\0'; j++){
			if(ocorr[s[j]] == 0){ count++; ocorr[s[j]] = 1;}
			else break; 
		}
		max = (count > max) ? count : max;
	}
	return max;
}


int maiorPrefixo_17 (char s1 [], char s2 []) {
   	int i, count = 0;

   	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++){
   		if(s1[i] != s2[i]) break;
   		else count++;
   	}
    return count;
}

int maiorSufixo_18 (char s1 [], char s2 []){
	int i,j, count = 0;
	for(i = strlen(s1)-1, j = strlen(s2)-1; i >= 0 && j >= 0; i--,j--){
		if(s1[i] != s2[j]) break;
		else count++;
	}
	return count;
}

int sufPref_19 (char s1[], char s2[]){
	int i,j;

	for(i = 0, j = 0; s1[i] != '\0'; i++){
		if (s1[i] == s2[j]) j++;
		else j = 0;	
	}
	return j;
}

int contaPal_20 (char s[]){
	int i, count = 0;
	for(i = 0; i< strlen(s); i++)
		if(s[i]!=' ' && s[i]!='\n' && (s[i+1]==' ' || s[i+1]=='\0')) count++;
	return count;
}


int contaVogais_21 (char s[]){
	int i, count = 0;
	for(i = 0; i< strlen(s); i++)
		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A'|| s[i] == 'E'|| s[i] == 'I'|| s[i] == 'O'|| s[i] == 'U') count++;
	return count;
}



//Aux 22
int pertence (char c,char s[]) { // 0 nao pertence; 1 pertence
	int i, n = 0;
	for (i = 0; s[i] != '\0'; i++) {
		if (c == s[i]) {
			n = 1;
			break;
		}
	}
	return n;
}

int contida_22 (char a[], char b[]) { // 0 == False, 1== True
	int i,j;
	for (i = 0 ; a[i] != '\0'; i++) {
		if (pertence(a[i],b) == 1);
		else return 0;
		}
	return 1;
}

int palindrome_23(char s[]){
	int i,j;

	for(i = 0, j = strlen(s)-1; s[i] != '\0'; i++, j--)
		if (s[i] != s[j]) return 0;

	return 1;
}

int remRep_24 (char x[]){
	int i,j;

	for(i = 0, j =  0; x[i] != '\0'; i++)
		if (x[i] != x[i+1]) 
			x[j++] = x[i];

	x[j] = '\0';	
	return j;
}
  
int limpaEspacos_25 (char texto[]) {
    int i, j;
    
    for(i=0 ,j=0 ; texto[i]!='\0'; i++){
        if(texto[i]!=' ' || texto[i+1]!=' ')
            texto[j++] = texto[i];
    }
    texto[j] = '\0';
    return j;
}
/*
void insere (int v[], int N, int x){
	int i;
	for(i = 0; i < N; i++)
		if()
}*/


int main(int argc, char const *argv[]){
	int escolha = 0, escolha_sec = 0; char string1[64], string2[64];

	printf("\nQue questão quer ?: \n"); scanf("%d" ,&escolha);
	
	switch (escolha){
		case 1:
			um();
			break;
		case 2:
			dois();
			break;
		case 3:
			tres();
			break;
		case 4:
			printf("\nNº de 1's da representação binária de ? : "); scanf("%d",&escolha_sec);
			printf("\n%d vezes\n" ,bitsUm_4(escolha_sec));
			break;
		case 5:
		//	printf("\nNº de bits a 0 da representação binária de ? : "); scanf("%d",&escolha_sec);
		//	printf("\n%d vezes\n" ,bitsUm_4(escolha_sec));
			printf("In maintenance..\n");
			break;
		case 6:
			printf("\nqDigit: Insire um número ?\n"); scanf("%d",&escolha_sec);
			printf("\n%d vezes\n" ,qDig_6(escolha_sec));
			break;
		case 7:
			printf("\n1a Palavra: "); scanf("%s" ,string1);
			printf("\n2a Palavra: "); scanf("%s" ,string2);
			printf("\nPalavra resultante: %s\n" ,strcat_7(string1,string2));
			break;
		case 8:
			printf("\nPalavra a copiar : "); scanf("%s" ,string1);
			printf("\nPalavra original: %s\nCopiada: %s\n" ,string1,strcpy_8(string2,string1));
			break;
		case 9:
			printf("\n1a Palavra: "); scanf("%s" ,string1);
			printf("\n2a Palavra: "); scanf("%s" ,string2);
			printf("\nPalavra lexicograficamente maior: %s\n" ,max_word(strcmp_9(string1,string2),string1,string2));
			break;
		case 10:
			printf("\nS1(Palavra): "); scanf("%s" ,string1);
			printf("\nS2(Substring): "); scanf("%s" ,string2);
			printf("\nA Substring '%s' occore em '%s' da seguinte maneira: %s" ,string2,string1,strstr_10(string1,string2));
			break;
		case 11:
			printf("\nPalavra: "); scanf("%s" ,string1);
			printf("\nA string %s invertida é:" ,string1);
			strrev_11(string1);
			break;
		case 12:
			printf("\nPalavra: "); scanf("%s" ,string1);
			strnoV_12(string1);
			break;
		case 13:
			printf("\nFrase: (Tab pára a leitura): ");  scanf("%[^\t]",string1);
			truncW_13(string1,4);
			break;
		case 14:
			printf("\nPalavra: "); scanf("%s" ,string1);
			printf("\nChar mais frequente: %c",charMaisfreq_14(string1));
			break;
		case 15:
			printf("\nPalavra: "); scanf("%s" ,string1);
			printf("\nMaior Nº de chars iguais consecutivos: %d",iguaisConsecutivos_15(string1));
			break;
		case 16:
			printf("\nPalavra: "); scanf("%s" ,string1);
			printf("\nMaior Nº de chars diferentes consecutivos: %d",difConsecutivos_16(string1));
			break;
		case 17:
			printf("\n1a Palavra: "); scanf("%s" ,string1);
			printf("\n2a Palavra: "); scanf("%s" ,string2);
			printf("\nMaior prefixo: tem tamanho %d." ,maiorPrefixo_17(string1,string2));
			break;
		case 18:
			printf("\n1a Palavra: "); scanf("%s" ,string1);
			printf("\n2a Palavra: "); scanf("%s" ,string2);
			printf("\nMaior Sufixo: tem tamanho %d." ,maiorSufixo_18(string1,string2));
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