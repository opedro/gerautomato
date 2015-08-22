include <stdio.h>

#include <stdlib.h>

#include <conio.h>



char alfabeto[200];

int estados[200];

int transicao[200][200];

int a;

int e;



void constroiAlfabeto(int);

void constroiEstados(int, int);

void construir();

void erro();

void sucesso();



int main(){

	printf("Quantos símbolos tem o alfabeto? \n");

	scanf("%d", &a);

	constroiAlfabeto(a);

	

	printf("Quantos estados? \n");

	scanf("%d", &e);

	constroiEstados(e, a);

	return 0;

}



void constroiAlfabeto(int a){

	int i =0;

	for(i=0; i < a; i++){

		printf("Qual é o símbolo %d ?", i);

		scanf("%d", &alfabeto[i]);

	}

}



void constroiEstados(int e, int a){

	int j =0, k = 0;

	for(j=0; j < e; j++){

		for(k=0; k<a; k++){

			printf("Para o estado e%d e símbolo %c, qual o próximoestado?", j, alfabeto[k]);

			scanf("e%d", transicao[e][a]);

			

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
