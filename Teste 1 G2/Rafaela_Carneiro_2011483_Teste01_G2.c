/***********************************************************************
NOME COMPLETO: Rafaela Maria Souza Carneiro
MATRICULA PUC-Rio: 2011483
DATA: 24/11/2020
DISCIPLINA: INF1007 TURMA: 33D
DECLARACAO DE AUTORIA:
 Declaro que este documento foi produzido em sua totalidade por mim,
 sem consultas a outros alunos, professores ou qualquer outra pessoa.
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct cliente{
	int exames;
	int *resultados;
};
typedef struct cliente Cliente;

Cliente * preencheVetor(int vet[], int tam){
	Cliente *p_cliente;
	int i;
	p_cliente = (Cliente*) malloc(sizeof(Cliente));
	if (p_cliente == NULL)
		return NULL;
	p_cliente->exames = tam;
	p_cliente->resultados = (int*) malloc(tam*sizeof(int));
	if (p_cliente->resultados == NULL)
		return NULL;
	for (i=0; i<tam; i++)
		p_cliente->resultados[i] = vet[i];
	return p_cliente;
}

void imprimeVetor(Cliente **vetor, int n){
	int i,j;
	for (i=0; i<n; i++){
		printf("Cliente %d:",i);
		for (j=0; j< vetor[i]->exames; j++)
			printf(" %d", vetor[i]->resultados[j]);
		printf("\n");
	}
}

void imprimeMenores(Cliente **vet, int n, int menor){
	int i, j;
	printf("\nClientes com menor numero de exames:\n");
	for (i=0; i<n; i++)
		if (vet[i]->exames == menor){
			printf("Cliente %d:", i);
			for (j=0; j<vet[i]->exames; j++)
				printf(" %d", vet[i]->resultados[j]);
			printf("\n");
		}
}

void libera(Cliente **vet, int n){
	int i;
	for (i=0; i<n; i++){
		free(vet[i]->resultados);
		free(vet[i]);
	}
	free(vet);
	printf("\nMemoria Liberada!\n");
}

int main(){
	FILE *p_arq;
	int n, pos, *aux, j, i, menor=MAX;
	Cliente **vetor;
	aux = (int*) malloc(MAX*sizeof(int));
	if (aux == NULL)
		exit(1);
	p_arq = fopen("Rafaela_Carneiro_2011483_Teste01_G2.txt", "r");
	if (p_arq == NULL){
		printf("Erro ao abrir o arquivo.");
		exit(2);
	}
	fscanf(p_arq, "Clientes: %d", &n);
	vetor = (Cliente**) malloc(n*sizeof(Cliente*));
	i=0;
	while (i<n){
		fscanf(p_arq, "%d", &pos);
		j=0;
		while (1){
			if(fgetc(p_arq) == '\n' || feof(p_arq))
				break;
			fscanf(p_arq, "%d", &aux[j]);
			j++;
		}
		if (j < menor)
			menor = j;
		vetor[pos] = preencheVetor(aux, j);
		i++;	
	}
	free(aux);
	fclose(p_arq);
	imprimeVetor(vetor, n);
	imprimeMenores(vetor, n, menor);
	libera(vetor, n);
	return 0;
}
