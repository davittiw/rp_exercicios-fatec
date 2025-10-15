#include <math.h>
#include <stdio.h>

#define ex02

#ifdef ex01
main()
{
}
#endif

#ifdef ex02
// def a struct
struct infos
{
    char nome[15];
    char end[50]; // endereço
    char cidade[30];
    char estado[30];
    char cep[12];
};

// declaro o vetor de estruturas global
struct infos infoUser[4];

// funcao que vai receber os dados
void recebeDados (int i) {
    printf("Digite seu nome: ");
    scanf(" %14[^\n]", infoUser[i].nome);

    printf("Digite seu endereco: ");
    scanf(" %49[^\n]", infoUser[i].end);

    printf("Digite sua cidade: ");
    scanf(" %29[^\n]", infoUser[i].cidade);

    printf("Digite seu estado: ");
    scanf(" %29[^\n]", infoUser[i].estado);

    printf("Digite seu CEP: ");
    scanf(" %11[^\n]", infoUser[i].cep);
}

void mostraDados (int i) {

}

int main()
{
    char resposta = 'Y';
    
    while(resposta == 'Y' || resposta == 'y') {
        for(int i=0; i < 4; i++) {
            printf("CADASTRO: %d \n", i + 1);
            recebeDados(i);
        }

        printf("\nFim do Programa!\n");

        printf("Deseja continuar?");
        printf("\t\n Y - Continuar \nN - Finalizar");
        scanf("%s", &resposta);

        if (resposta != 'Y' && resposta != 'y' && resposta != 'N' && resposta !='n') {
            printf("Digite as opcoes corretamente!\n");

            printf("Deseja continuar o programa?");
            printf("\t\n Y - Continuar \nN - Finalizar");
            scanf(" %c", &resposta);
        }
    }
}
#endif

#ifdef ex03
main()
{
}
#endif

#ifdef ex04
main()
{
}
#endif