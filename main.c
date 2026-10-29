#include <stdio.h>
#include <stdlib.h>

int main() 
{
	float n1, n2, soma;
	printf("Digite o valor de n1\n");
	scanf("%f", &n1);
	printf("Digite o valor de n2\n");
	scanf("%f", &n2);
	
	soma = n1+n2;
	printf("Soma = %.2f", soma);
	
	system("pause");
	return 0;
}