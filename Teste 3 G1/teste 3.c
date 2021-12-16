/***********************************************************************
NOME COMPLETO: Rafaela Maria Souza Carneiro
MATRICULA PUC-Rio: 2011483
DATA: 04/11/2020
DISCIPLINA: INF1007 TURMA: 33D
DECLARACAO DE AUTORIA:
 Declaro que este documento foi produzido em sua totalidade por mim,
 sem consultas a outros alunos, professores ou qualquer outra pessoa.
************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE * openFile(const char * file, const char * mode){
	FILE *p;
	p = fopen(file, mode);
	if (p==NULL){
		printf("Erro ao abrir o arquivo.");
		exit(1);
	}
	return p;
}

float calc_mediana(int vet[], int tam){
	int i = tam/2;
	float n;
	if(tam%2 != 0)
		return (float)vet[i];
	else{
		n = ((float)(vet[i-1]+vet[i]))/2.0;
		return n;
	}		
}

int main(){
	FILE *p_arq1, *p_arq2, *p_bin;
	char **vet,c;
	int n, i, *valores, result;
	float med;
	p_arq1 = openFile("rotulos.txt", "r");
	p_arq2 = openFile("valores.txt", "r");
	p_bin = openFile("eliminados.dat", "wb");
	while(!feof(p_arq1)){
		result = fscanf(p_arq1, "%d", &n);
		if (result<=0)
			break;
		printf("Numero de sensores do conjunto = %d\n", n); //imprimindo as leituras conforme pede o enunciado
		vet = (char**) malloc(n*sizeof(char*));
		for(i=0; i<n; i++){
			vet[i] = (char*) malloc(4*sizeof(char));
			fscanf(p_arq1, "%s", vet[i]);
			printf("VetorDeRotulos[%d] = %s\n",i, vet[i]); //imprimindo as leituras conforme pede o enunciado
		}
		valores = (int*) malloc(n*sizeof(int));
		for(i=0; i<n; i++){
			fscanf(p_arq2, "%d", &valores[i]);
			printf("VetorDeValores[%d] = %d\n", i, valores[i]); //imprimindo as leituras conforme pede o enunciado
		}
		med = calc_mediana(valores, n);
		printf("Mediana = %.2f\n", med); //imprimindo as leituras conforme pede o enunciado
		for(i=0; i<n; i++){
			if(valores[i]<med){
				fwrite(vet[i], sizeof(char), strlen(vet[i])+1, p_bin);
				free(vet[i]);
			}
			else
				free(vet[i]);
		}
		printf("******************************\n");
		free(vet);
		free(valores);		
	}
	printf("Arquivo gravado com sucesso\n");
	fclose(p_arq1);
	fclose(p_arq2);
	fclose(p_bin);
	printf("Conteudo do arquivo binario:\n");
	p_bin = openFile("eliminados.dat", "rb");
	while(!feof(p_bin)){
		fread(&c, sizeof(char), 1, p_bin);
		if(c=='\0')
			printf(" ");
		else
			printf("%c",c);
	}

	return 0;
}
