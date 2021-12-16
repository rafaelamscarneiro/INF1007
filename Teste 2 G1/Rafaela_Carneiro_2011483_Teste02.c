#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char * vira_dec_zonado(int n, char s[])
{
	char *p;
	if (n<10)
	{
		*s = (char)(n+48);
		s--;
		*s = 'F';
		p = s + strlen(s);
		*p = '\0';
		return p;
	}
	else
	{
		*s = (char)(n%10+48);
		s--;
		*s = 'F';		
		vira_dec_zonado(n/10,s-1);
	}
}

int pega_numero(char s[]){
	int n, pos;
	pos = (strlen(s)-1)/2;
	if (s[0] == '\0'){
		return n;
	}
	else{
		if (s[0] <= '9'&& s[0] >= '0'){
			n = (((int)s[0]) - 48) * pow(10, pos);
			return n + pega_numero(&s[1]);
		}
		else{
			return pega_numero(&s[1]);
		}
	}
}

int main() {
	char *str, *p;
	str = (char *) malloc(10*sizeof(char));
	char s[] = "F9F3F9F8F5";
	int n, l;
	n = pega_numero(s);
	printf("Decimal zonado = %s\nNumero = %d\n",s, n);
	p = vira_dec_zonado(n,str);
	printf("*************************\n");
	str-=strlen(s)-1;
	printf("Numero = %d\nDecimal zonado = %s\n",n, str);
	l = strlen(str);
	//printf("Comprimento da string = %d\n",l);
	//printf("%d\n", p-str); //diferenca entre a pos do terminador e o inicio da string = comprimento da string
	return 0;
}
