/***********************************************************************
NOME COMPLETO: Rafaela Maria Souza Carneiro
MATRICULA PUC-Rio: 2011483
DATA: 26/11/2020
DISCIPLINA: INF1007 TURMA: 33D
DECLARACAO DE AUTORIA:
 Declaro que este documento foi produzido em sua totalidade por mim,
 sem consultas a outros alunos, professores ou qualquer outra pessoa.
************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10

struct atleta{
	char nome[21];
	int altura;
	int peso;
};
typedef struct atleta Atleta;

Atleta * montaVetor(){
	int i, result;
	FILE *p_arq;
	Atleta *vetor;
	vetor = (Atleta*) malloc(TAM*sizeof(Atleta));
	if (vetor==NULL)
		return NULL;
	p_arq = fopen("Rafaela_Carneiro_2011483_Teste02_G2.txt", "r");
	i=0;
	while(!feof(p_arq)){
		result = fscanf(p_arq, "%s %d %d", vetor[i].nome, &(vetor[i].altura), &(vetor[i]).peso);
		if(result<3)
			break;
		i++;
	}
	fclose(p_arq);
	return vetor;
}

void imprime(Atleta vetor[], int n){
	int i;
	printf("Vetor de atletas:\n");
	for (i=0; i<n; i++)
		printf("%d:\t%s %d %d\n", i, vetor[i].nome, vetor[i].altura, vetor[i].peso);
}

int compara(Atleta a, Atleta b){
	int c = strcmp(a.nome,b.nome);
	if (c!=0)
		return c;
	else{
		if (a.altura < b.altura)
			return -1;
		if (a.altura > b.altura)
			return 1;
	}
	return 0;
}

int busca_bin(Atleta vet[], int n, Atleta el){
	if (n<=0)
		return -1;
	int meio = n/2;
	if (compara(el, vet[meio])<0)
		return busca_bin(vet, meio, el);
	else if (compara(el,vet[meio])>=0){
		int r = busca_bin(&vet[meio+1], n-meio-1, el);
		return (meio+1+r);
	}
	return meio;
}

int main(){
	int i, n;
	Atleta*vetor=montaVetor();
	imprime(vetor, TAM);
	Atleta t1 = {"hellen", 170, 60};
	Atleta t2 = {"bianca", 160, 65};
	Atleta t3 = {"eduardo", 180, 90};
	Atleta t4 = {"camila", 180, 80};
	Atleta t5 = {"camila", 160, 60};
	Atleta t6 = {"ametista", 150, 50};
	Atleta vet_testes[]={t1, t2, t3, t4, t5, t6};
	printf("\n");
	for (i=0; i<6; i++){
		n = busca_bin(vetor, TAM, vet_testes[i]);
		if (n<0)
			printf("Teste %d: %s %d %d - Inserir antes de 0\n", i+1, vet_testes[i].nome, vet_testes[i].altura, vet_testes[i].peso);
		else
			printf("Teste %d: %s %d %d - Inserir apos %d\n", i+1, vet_testes[i].nome, vet_testes[i].altura, vet_testes[i].peso, n);
	}
	free(vetor);
	
	return 0;
}
