#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


char alfabeto[200];
int estados[200];
int transicao[200][200];
int a, e, ei, qef, op;
int ef[200];

void constroiAlfabeto(int);
void constroiEstados(int, int);
void construir();
void construirGoto();
void erro();
void sucesso();
void iniciaarquivo();

char* cleanName(char*);

FILE *arquivo;

int main(){
	iniciaarquivo();
	printf("Quantos simbolos tem o alfabeto? \n");
	scanf(" %d", &a);
	constroiAlfabeto(a);
	printf("Quantos estados? \n");
	scanf(" %d", &e);
	constroiEstados(e, a);
	printf("SELECIONE \n1 - Construir com functions \n2 - Construir com goto\n");
	scanf(" %d", &op);
	if(op == 1)
		construir();
	else
		construirGoto();
	return 0;
}

void iniciaarquivo(){
	char s[50];
	printf("Qual o nome do programa? \n");
	gets(s);	
	arquivo = fopen(cleanName(s), "wt");
	//includes
	fputs("#include <stdio.h>\n#include <stdlib.h>\n#include <conio.h>\n\n", arquivo);
}

void constroiAlfabeto(int a){
	int i =0;
	for(i=0; i < a; i++){	
		do {
			printf("Qual o simbolo %d ?\n", i+1);
			alfabeto[i] = getche();
			printf("\n");
						
		} while( (int)alfabeto[i] < 33 );
		
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
	fputs("void aceita();\n", arquivo);
	fputs("void rejeita();\n", arquivo);

	//inicia main
	fputs("int main(){\n", arquivo);

	//pergunta pela palavra
	fputs("  printf(\"Informe a palavra a ser testada\\n\");\n", arquivo);
	//recebe palavra
	fputs("  scanf(\"%s\", &palavra);\n", arquivo);
	//chama estado inicial
	fprintf(arquivo, "  e%d(0);\n", ei);
		//finaliza main
	fputs("}\n", arquivo);
	
	
	
	//funcoes
	fputs("\n\nvoid aceita(){\n  printf(\"aceita\");\n}", arquivo);
	fputs("\n\nvoid rejeita(){\n  printf(\"rejeita\");\n}", arquivo);
	int j, k;
	char* cond;
	for(j=0; j < e; j++){
		fprintf(arquivo, "\n\nvoid e%d(int idx){\n", j);
		for(k=0; k < a; k++){            
			fprintf(arquivo, "  if(palavra[idx] == '%c'){\n", alfabeto[k]);
			fprintf(arquivo, "    e%d(idx+1);", transicao[j][k]);
			fputs("\n  }\n", arquivo);	
		}
		for(i=0; i < qef; i++){
		//estado final?
			if(ef[i] == j){
				fputs("  if(palavra[idx] == '\\0'){\n    aceita();\n  }\n", arquivo);
			}
		}
		fputs("  else{\n    rejeita();\n  }", arquivo);
		fputs("\n}", arquivo);
	}
}

void construirGoto(){
	int i=0;
	//declaracoes
	fputs("char palavra[200];\nint idx = 0; \n\n", arquivo);
	
	//inicia main
	fputs("int main(){\n", arquivo);

	//pergunta pela palavra
	fputs("  printf(\"Informe a palavra a ser testada\\n\\n\");\n", arquivo);
	//recebe palavra
	fputs("  scanf(\"%s\", &palavra);\n", arquivo);
	//chama estado inicial
	fprintf(arquivo, "  idx = 0; \n goto e%d;\n", ei);
	
	//label
	fputs("\n  aceita:\n    printf(\"aceita\");\n    goto fim;", arquivo);
	fputs("\n\n  rejeita:\n    printf(\"rejeita\");\n    goto fim;", arquivo);
	int j, k;
	char* cond;
	for(j=0; j < e; j++){
		cond = "if";
		fprintf(arquivo, "\n\n  e%d:\n   ", j);
		for(k=0; k < a; k++){            
			fprintf(arquivo, " %s(palavra[idx] == '%c'){\n", cond, alfabeto[k]);
			fprintf(arquivo, "      idx++; \n      goto e%d;", transicao[j][k]);
			fputs("\n    }", arquivo);
			cond = "else if";	
		}
		for(i=0; i < qef; i++){
			//estado final?
			if(ef[i] == j){
				fputs("\n    if(palavra[idx] == '\\0'){\n      goto aceita;\n    }", arquivo);
			}
		}
		fputs(" else{\n      goto rejeita;\n    }", arquivo);
	}

	//fim
	fputs("\n  fim:\n    printf(\"\\n\");\n    system(\"pause\");\n    return 0;", arquivo);
	//finaliza main
	fputs("}\n", arquivo);
}

// deixa o nome do arquivo bonito :)
char* cleanName(char* str){
	int i;
	char* ret = str;

	for( i=0; i < strlen(str); i++){	   
		if(str[i] != ' '){
			ret[i] = str[i];
		} else {
			ret[i] = '_';
		}
	} 

	strcat(ret, ".c");
	return ret;
};
