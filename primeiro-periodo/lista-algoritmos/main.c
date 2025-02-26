#include <stdio.h>
#include <stdlib.h>

#define ex04

#ifdef ex01
main (){
    int a, b, c;

    printf("Digite um numero: ");
    scanf("%d", &a);
    b = a + 1;
    c = a - 1;

    printf("O sucessor de %d, eh %d \nO antecessor eh %d", a, b, c);
}
#endif // ex01


#ifdef ex02
main (){
    int a, b;

    printf("Digite um numero: ");
    scanf("%d", &a);
    b = a * 1.10;

    printf("o valor acrescido eh %d", b);
}
#endif // ex02

#ifdef ex03
main (){
    float a, b, c;

    printf("Digite um preço: ");
    scanf("%f", &a);

    b = a * 0.09;
    c = a - b;

    printf("o novo valor do produto eh: %.2f", c);
}
#endif // ex03

#ifdef ex04
main (){
    float a, b, c;

    printf("Digite um preço: ");
    scanf("%f", &a);

    if (a<100){
        b = a * 0.10;
        c = b + a;

        printf("O novo valor eh: %.2f", c);
    } else {
        b = a * 0.20;
        c = b + a;

        printf("O novo valor eh: %.2f", c);
    }
}
#endif // ex04
