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
void iniciaarquivo();
FILE *arquivo;

int main(){
	iniciaarquivo();
	printf("Quantos simbolos tem o alfabeto? \n");
	scanf(" %d", &a);
	constroiAlfabeto(a);
	printf("Quantos estados? \n");
	scanf(" %d", &e);
	constroiEstados(e, a);
	construir();
	return 0;
}

void iniciaarquivo(){
	printf("Qual o nome do programa? \n");
	char s[50];
	scanf(" %s.cpp", &s);
    arquivo = fopen(s, "wt");
	//includes
	fputs("#include <stdio.h>\n#include <stdlib.h>\n#include <conio.h>\n\n", arquivo);
}

void constroiAlfabeto(int a){
	int i =0;
	for(i=0; i < a; i++){
		printf("Qual o simbolo %d ?\n", i+1);
		scanf(" %c", &alfabeto[i]);
	}
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
     int i=0;
	//declaracoes
	fputs("char palavra[200];\n\n", arquivo);
	for (i=0; i<e; i++){
		fprintf(arquivo, "void e%d(int);\n", i);
	};   
    fputs("void aceita();", arquivo);
    fputs("void rejeita();", arquivo);
    
	//inicia main
	fputs("\nint main(){\n", arquivo);

	//pergunta pela palavra
	fputs("  printf(\"Informe a palavra a ser testada\");\n", arquivo);
	//recebe palavra
	fputs("  scanf(\"%s\", &palavra);\n", arquivo);
	//chama estado inicial
	fprintf(arquivo, "  e%d(0);\n", ei);
    //finaliza main
	fputs("}\n", arquivo);
	
	
	
	//funcoes
	fputs("\n\nvoid aceita(){\n  printf(\"aceita\");\n  exit 0;\n}", arquivo);
    fputs("\n\nvoid rejeita(){\n  printf(\"rejeita\");\n  exit 0;\n}", arquivo);
    int j, k;
    char* cond;
    for(j=0; j < e; j++){
        cond = "if";
        fprintf(arquivo, "\n\nvoid e%d(int idx){\n", j);
		for(k=0; k < a; k++){            
			fprintf(arquivo, "  %s(palavra[idx] == '%c'){\n", cond, alfabeto[k]);
		    fprintf(arquivo, "    e%d(idx+1);", transicao[j][k]);
            fputs("\n  }", arquivo);
            cond = "elsif";	
		}
		for(i=0; i < qef; i++){
            //estado final?
            if(ef[i] == j){
            fputs("  elsif(palavra[idx] == '\\0'){\n    aceita();\n  }", arquivo);
            }
        }
		fputs("  else{\n    rejeita();\n  }", arquivo);
		fputs("\n}", arquivo);
	}

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
