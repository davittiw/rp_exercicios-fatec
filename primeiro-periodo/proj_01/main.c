#include <stdio.h> => entrada e saída
#include <stdlib.h> => controle de processo

int main()
{
    /* Marcador de posição de números inteiros: %d
       Marcador de posição de números floats: %f */

    printf("Eu quero ser um aluno nota %d", 10);

    printf("A soma das idades de Maria  e Joao eh: %d", 40 + 52);

    printf("Marcelo gastou %2.2f reais", 5 * 2.3);

    printf("O preco da caixa de leite era: %2.1f", 57.5 / 23);
    return 0;
}
