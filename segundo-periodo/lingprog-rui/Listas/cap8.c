#include <stdio.h>
#include <stdlib.h>

#define ex02
#ifdef ex01
int main() {
    
}
#endif // ex01


#ifdef ex02
int main() {

    int *pNumero, *pSoma = 0, *pQuantidade = 0;

    float *pMedia;

    printf("Instrucoes do programa: \n");
    printf("Se o numero inserido for POSITIVO: sera somado com os anteriores.\n");
    printf("Se o numero inserido for NEGATIVO: sera calculada a media entre os numeros  inseridos.\n\n");

    for (;;)
    {
        printf("Digite um numero: ");
        scanf("%d", pNumero);

        if (*pNumero < 0)
        {
            break;
        }
        else
        {
            *pSoma += *pNumero;
            *pQuantidade += 1;
        }
    }

    if (*pQuantidade > 0)
    {
        *pMedia = (float)*pSoma / *pQuantidade;
        printf("Media dos numeros positivos digitados: %.2f\n", *pMedia);
    }
    else
    {
        printf("Nenhum numero positivo foi digitado");
    }

    printf("\nPressione Enter para sair...");
    getchar();
    getchar();
    return 0;
}
#endif // ex02


#ifdef ex03
int main() {
    
}
#endif // ex03


#ifdef ex04
int main() {
    
}
#endif // ex04


#ifdef ex05
int main() {
    
}
#endif // ex05


#ifdef ex06
int main() {
    
}
#endif // ex06