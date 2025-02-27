#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    float c;

    do {
    printf("Digite um numero positivo: ");
    scanf("%d", &a);

    printf("Digite outro numero positivo: ");
    scanf("%d", &b);

    } while(a<=0 || b<= 0);

    c = a * b;
    printf("A multiplicacao entre os dois numeros eh: %.2f", c);

}
