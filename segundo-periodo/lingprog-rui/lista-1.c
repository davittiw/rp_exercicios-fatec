#include <stdio.h>
#include <stdlib.h>

#define ex5

#ifdef ex1
int main()
{
    int A=10, B=5 ;
    printf("Valor de A: %d \n Valor de B: %d\n",A,B);

    A = A ^ B;
    B = A ^ B;
    A = A ^ B;

    printf("Valores Permutados: \n");
    printf("valor de A: %d\n Valor de B: %d", A,B);

}
#endif // ex1

#ifdef ex2

int main(){
    short s;
    long l;
    int i;
    float f;
    double d;
    char c;

    printf("Digite um valor short: ");
    scanf("%hd", &s);

    printf("Digite um valor long: ");
    scanf("%ld", &l);

    printf("Digite um valor int: ");
    scanf("%d", &i);

    printf("Digite um valor float: ");
    scanf("%f", &f);

    printf("Digite um valor double: ");
    scanf("%lf", &d);

    printf("Digite um caractere: ");
    getchar();
    scanf("%c", &c);

    printf("\n");
    printf("        10        20        30        40        50        60\n");
    printf("12345678901234567890123456789012345678901234567890123456789012345\n");
    printf("    %-15hd     %-15ld     %-15d\n", s, l, i);
    printf("              %-15.2f     %-15.5lf     %-15c\n", f, d, c);

}
#endif // ex2

#ifdef ex3

int main(){
int numero, multiplo, minimo;


printf("Digite um numero: ");
scanf("%d", &numero);

printf("Digite um numero limitador: ");
scanf("%d", &minimo);


if(numero==0)
{
    printf("Erro de Divisao");

}
else
{
multiplo = (minimo/numero + 1)* numero;

printf("O menor multiplo de %d maior que %d e: %d", numero, minimo, multiplo);
}
}
#endif // ex3

#ifdef ex4

int main()
{
    int hora, min, seg,tempo;

    printf("Digite um tempo em segundos: ");
    scanf("%d", &tempo);

    hora = tempo/3600;
    tempo= tempo % 3600;
    min= tempo/60;
    seg= tempo % 60;

    printf("A conversao e: %dh %dmin %ds", hora, min,seg);
}
#endif // ex4

#ifdef ex5
int inverter (int num)
{
    int invt = 0;

    while(num>0)
    {
        invt= 10 * invt + num % 10;
        num/=10;
    }
    return invt;
}
int main()
{
    int num, invert;

    do
    {
        printf("Digite um numero com 3 digitos: ");
        scanf("%d", &num);

        if(num<0)
        {
            printf("Valor Invalido! Digite um numero positivo (maior que zero)");
        }
    }while(num<0);

    invert= inverter(num);
    printf("O numero digitado invertido fica: %d", invert);
}
#endif // ex5
