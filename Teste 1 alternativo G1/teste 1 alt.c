#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* inverte_palavra(char *p2, char *pi, char *p1){
	while (p1 != pi){
		*p2 = *p1;
		p2++;
		p1--;
	}
	*p2 = *pi;
	return (p2+1);
}

char* altera_palavra(char *p2, char *pi, char *p1){
		pi+=2;
		while (pi != p1){
			*p2 = *pi;
			p2++;
			pi++;
		}
		*p2 = 'n';
		p2++;
		*p2 = 'd';
		p2++;
		*p2 = 'o';
		return (p2+1);
}

char* copia_separadores(char *p2, char *p1, char c){
	while (*p1 == c){
		*p2 = c;
		p2++;
		p1++;
	}
	return p2;
}

char* copia_palavra(char *p2, char *pi, char *p1){
	while (pi != p1){
		*p2 = *pi;
		p2++;
		pi++;
	}
	*p2 = *pi;
	p2++;
	return p2;
}

char* altera_sentenca(char *s1, char c){
	int tam, comp, flag;
	char *s2, *p1, *p2, *pi, *pf;
	tam = strlen(s1);
	s2 = (char *) malloc(tam*sizeof(char));
	if (s2== NULL)
		return NULL;
	p1 = s1;
	p2 = s2;
	while (*p1 != '|'){
		flag=0;
		p2 = copia_separadores(p2, p1, c);
		while (*p1 == c)
		  p1++;
		comp=0;
		pi = p1;
		while (*p1 != c && *p1 != '|'){
			comp++;
			p1++;
			flag =1;			
		}
		if (flag==1){
			p1--;
			if (comp>3 && *p1 == 'r'){
				if (*(p1-1) == 'a'|| *(p1-1)=='e'||*(p1-1)=='i'||*(p1-1)=='o')
					p2 = altera_palavra(p2, pi, p1);
				else
					p2 = inverte_palavra(p2, pi, p1);
			}
			else if (comp>3)
				p2 = inverte_palavra(p2, pi, p1);
			else 
				p2 = copia_palavra(p2, pi, p1);
			p1++;
		}
	}
	*p2 = '|';
	p2++;
	*p2 = '\0';
	return s2;
}
int main() {
	char *s1;
	char c;
	s1 = (char *) malloc(100*sizeof(char));
	if (s1 == NULL){
		printf("Erro. Memória insuficiente.");
		exit(1);
	}
	char *s2;
	printf("Entre com o caractere delimitador:\n");
	c = getc(stdin);
	fflush(stdin);
	printf("Entre com a string a ser alterada:\n");
	scanf("%[^\n]",s1);
	s2 = altera_sentenca(s1, c);	
	printf("Sentenca original: %s\nSentenca alterada: %s\n",s1, s2);
	free(s1);
	free(s2);
	return 0;
}
