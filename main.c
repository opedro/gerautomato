#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char alfabeto[200];
int estados[200];
int transicao[200][200];
int a, e, ei, qef;
int ef[200];

void constroiAlfabeto(int);
void constroiEstados(int, int);
void construir();
void erro();
void sucesso();
FILE *arquivo;

int main(){
	printf("Qual o nome do programa? \n");
	char s[50];
	scanf(" %s", &s);
    arquivo = fopen(s, "wt");
    
	fputs("cacete", arquivo);
	
	printf("Quantos simbolos tem o alfabeto? \n");
	scanf(" %d", &a);
	constroiAlfabeto(a);

	printf("Quantos estados? \n");
	scanf(" %d", &e);
	constroiEstados(e, a);
	return 0;
}

void constroiAlfabeto(int a){
	int i =0;
	for(i=0; i < a; i++){
		printf("Qual o simbolo %d ?\n", i+1);
		scanf(" %c", &alfabeto[i]);
	}
//	alfabeto[i] = '\0';
}

void constroiEstados(int e, int a){

	int j =0, k = 0;

	printf("Qual o estado inicial?\ne");
	scanf(" %d", &ei);
	
	printf("Quantos estados finais?\n");
	scanf(" %d", &qef);
	
	for(j=0; j < qef; j++){
		printf("Qual o estado final %d \ne", j+1);
	    scanf(" %d", &ef[j]);
	}
	
	for(j=0; j < e; j++){
		for(k=0; k < a; k++){
			printf("Para o estado e%d e simbolo %c, qual o proximo estado?\ne", j, alfabeto[k]);
			scanf(" %d", &transicao[j][k]);
		}
	}
}

void construir(){
	/*if(f[p] == 'a')
	{
		p++;
		if(f[p] == 0){
			aceita();
		}else{
			e0();
		}
	}
	if(f[p] == 'b'){
		p++;
		if(f[p] == 0){
			aceita();
		}else{
			e0();
		}
	}
	if(f[p] == '+'){
        p++;
		if(f[p] == 0){
			aceita();
		}else{
			e0();
		}
	}
	if(f[p]== '='){
        p++;
		if(f[p] == 0){
			aceita();
		}else{
			e0();
		}
 }
	else{
		p++;
        if(f[p] == 0){
			rejeita();
		}else{
			e0();
		}
	}*/
}
