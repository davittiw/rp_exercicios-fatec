#include <stdio.h>
#include <stdlib.h>

#define ex14

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

#ifdef ex05
main () {

    float valorAula, salarioTotal;
    int totalAula;

    printf("Digite o valor por aula: ");
    scanf("%f", &valorAula);

    printf("Digite a quantidade de aulas: ");
    scanf("%i", &totalAula);

    salarioTotal = valorAula * totalAula;

    printf("O salario total do professor eh %.2f", salarioTotal);
    }
#endif // ex05

#ifdef ex07
main () {
    float num;

    printf("Digite um numero: ");
    scanf("%f", &num);

    if (num < 0) {
        printf("Esse numero eh negativo");
    } else if (num > 0) {
        printf("Esse numero eh positivo");
    } else {
        printf("Esse numero eh igual a 0");
    }
}
#endif // ex07

#ifdef ex08
int nota1, nota2, nota3, nota4, res;

main () {
   printf("Insira a primeira nota: ");
   scanf("%i", &nota1);

   printf("Insira a segunda nota: ");
   scanf("%i", &nota2);

   printf("Insira a terceira nota: ");
   scanf("%i", &nota3);

   printf("Insira a quarta nota: ");
   scanf("%i", &nota4);

   calcule();
}

calcule () {
    res = (nota1 + nota2 + nota3 + nota4) / 4;

    if (res >= 0 && res < 6) {
        printf("Aluno reprovado! \nSua media: %i", res);
    } else if (res >= 6 && res <= 10) {
        printf("Aluno aprovado! \nSua media: %i", res);
    }else {
        printf("Nao foi possivel calcular");
    }
}
#endif // ex08

#ifdef ex09
main () {
    int a, b;

    printf("Digite um numero: ");
    scanf("%i", &a);

    printf("Digite outro numero: ");
    scanf("%i", &b);

    if (a > b) {
        printf("%i eh maior que %i", a, b);
    } else {
        printf("%i eh maior que %i", b, a);
    }
}
#endif // ex09

#ifdef ex14
    float totalSalario, nivel1 = 55, nivel2 = 67, nivel3 = 78;
    int nivelPr, totalHoras;
main (){

    printf("Digite o nivel do professor: ");
    scanf("%i", &nivelPr);

    printf("Digite o total de horas: ");
    scanf("%i", &totalHoras);

    calcule();
}

calcule (){
    if (nivelPr == 1){
        totalSalario = nivel1 * totalHoras;
        printf("O salario desse professor eh %.2f", totalSalario);
    } else if (nivelPr == 2) {
        totalSalario = nivel2 * totalHoras;
        printf("O salario desse professor eh %.2f", totalSalario);
    } else if (nivelPr == 3) {
        totalSalario = nivel3 * totalHoras;
        printf("O salario desse professor eh %.2f", totalSalario);
    } else {
        printf("Nao foi possivel calcular o salario.");
    }
}
#endif // ex14
