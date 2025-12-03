#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define ex004

#ifdef ex001

#endif //ex001

#ifdef ex002
int main()
{
    int nums = 0, cont = 0, media = 0;
    int *pnums, *pmedia, *pcont;

    char resposta = 'Y';
    pnums = &nums;
    pmedia = &media;
    pcont = &cont;

    setlocale(LC_ALL, "Portuguese");
    while(resposta != 'N' && resposta != 'n'){
        //Usu�rio digita n�meros at� um ser negativo e j� calcula a m�dia
        while(nums>=0){
            printf("\nDigite um n�mero (negativo para finalizar): ");
            scanf("%d", &nums);
            getchar();

            //Condicional para desconsiderar n�mero negativo que encerrar� o c�lculo
            if(nums>=0){
            *pmedia += *pnums;
            (*pcont)++;
            }
        }
        //Printa a m�dia obtida
        printf("\t A m�dia tem valor de: %.2f\n",(float)*pmedia / *pcont);

        //Pergunta se o usu�rio deseja continuar o programa
        printf("\nDeseja continuar o programa?\n");
        printf("Digite 'Y' para sim e 'N' para n�o: \n");
        scanf(" %c", &resposta);
        getchar();
        //Verifica��o da resposta
        while(resposta != 'Y' && resposta != 'y' && resposta != 'N' && resposta != 'n'){
                printf("Digite um valor v�lido!\n");
                printf("Digite 'Y' para sim e 'N' para n�o: ");
                scanf(" %c", &resposta);
                getchar();
        }
        if (resposta == 'Y' || resposta == 'y'){
            system("cls");
            nums = 0;
            cont = 0;
            media = 0;
        }
    }
    return 0;
}
#endif // ex002

#ifdef ex003
char string1[10], string2[10];
int comparaString(){
    char *pstring1, *pstring2;
    int cont = 0;
    pstring1 = &string1;
    pstring2 = &string2;

    while(*pstring1 != '\0' && *pstring2 != '\0'){
        if(*pstring1 == *pstring2){
            pstring1++;
            pstring2++;
        } else {
            return 0; //Diferentes
        }
    }
    return (*pstring1 == '\0' && *pstring2 == '\0'); /*garantia para ver se de fato s�o strings iguais*/
}

int main()
{
    char resposta = 'Y';

    setlocale(LC_ALL, "Portuguese");
    while(resposta != 'N' && resposta != 'n'){
        //Input das strings
        printf("Digite a primeira string: ");
        scanf(" %9[^\n]", string1);

        printf("\nDigite a segunda string: ");
        scanf(" %9[^\n]",string2);

        //Chama a fun��o para comparar strings
        int resultado = comparaString();
        //Condicional para printar o resultado da fun��o
        if(!resultado){
            printf("\nAs strings s�o DIFERENTES 0!\n");
        } else {
            printf("\nAs strings s�o IGUAIS 1!\n");
        }

        //Pergunta se o usu�rio deseja continuar o programa
        printf("\nDeseja continuar o programa?\n");
        printf("Digite 'Y' para sim e 'N' para n�o: \n");
        scanf(" %c", &resposta);
        getchar();
        //Verifica��o da resposta
        while(resposta != 'Y' && resposta != 'y' && resposta != 'N' && resposta != 'n'){
                printf("Digite um valor v�lido!\n");
                printf("Digite 'Y' para sim e 'N' para n�o: ");
                scanf(" %c", &resposta);
                getchar();
        }
        if (resposta == 'Y' || resposta == 'y'){
            system("cls");
        }
    }
    return 0;
}
#endif // ex003

#ifdef ex004
// Vetor global com as letras
char vetor[] = {'b', 'd', 'f', 'h', 'j', 'k', 'm', 'o', 'q', 's', 'u', 'w', 'y'};

// Fun��o de busca usando ponteiro
int busca_letra(char letra) {
    char *p = vetor;
    int tam = sizeof(vetor) / sizeof(vetor[0]);
    for (int i = 0; i < tam; i++) {
        if (*(p + i) == letra) {
            return 1; // Encontrou
        }
    }
    return 0; // N�o encontrou
}

int main() {
    char letra;
    char resposta = 'Y';

    setlocale(LC_ALL, "Portuguese");
    while(resposta != 'N' && resposta != 'n'){
        printf("Digite uma letra: ");
        scanf(" %c", &letra);

        if (busca_letra(letra)) {
            printf("Letra %c encontrada no vetor!", letra);
        } else {
            printf("Letra %c NAO encontrada no vetor!", letra);
        }

        //Pergunta se o usu�rio deseja continuar o programa
        printf("\nDeseja continuar o programa?\n");
        printf("Digite 'Y' para sim e 'N' para n�o: \n");
        scanf(" %c", &resposta);
        getchar();
        //Verifica��o da resposta
        while(resposta != 'Y' && resposta != 'y' && resposta != 'N' && resposta != 'n'){
                printf("Digite um valor v�lido!\n");
                printf("Digite 'Y' para sim e 'N' para n�o: ");
                scanf(" %c", &resposta);
                getchar();
        }
        if (resposta == 'Y' || resposta == 'y'){
            system("cls");
        }
    }
    return 0;
}
#endif // ex004

#ifdef ex005
// Estrutura com os campos pedidos
struct Endereco {
    char nome[50];
    char end[50];
    char cidade[40];
    char estado[3];
    char cep[15];
};

// Vetor global de 4 estruturas
struct Endereco vetor[4];

// Fun��o para ler os dados usando ponteiros
void lerEnderecos(struct Endereco *p) {
    for (int i = 0; i < 4; i++) { // loop sobre o vetor
        printf("Registro %d:", i + 1);

        printf("\nNome: ");
        scanf(" %[^\n]", (p + i)->nome); // l� linha com espa�os [web:7]

        printf("Endereco: ");
        scanf(" %[^\n]", (p + i)->end); // usa ponteiro para struct [web:4]

        printf("Cidade: ");
        scanf(" %[^\n]", (p + i)->cidade);

        printf("Estado: ");
        scanf(" %[^\n]", (p + i)->estado);

        printf("CEP: ");
        scanf(" %[^\n]", (p + i)->cep);

        printf("");
    }
}

// Fun��o para imprimir os dados usando ponteiros
void imprimirEnderecos(struct Endereco *p) {
    for (int i = 0; i < 4; i++) { // loop sobre o vetor
        printf("\nRegistro %d:", i + 1);
        printf("\n\tNome: %s",      (p + i)->nome);
        printf("\n\tEndereco: %s",  (p + i)->end);
        printf("\n\tCidade: %s",    (p + i)->cidade);
        printf("\n\tEstado: %s",    (p + i)->estado);
        printf("\n\tCEP: %s",     (p + i)->cep);
    }
}

int main() {
    char resposta = 'Y';

    setlocale(LC_ALL, "Portuguese");
    while(resposta != 'N' && resposta != 'n'){
        lerEnderecos(vetor); // passa o vetor global (como ponteiro)
        imprimirEnderecos(vetor); // imprime tudo

        //Pergunta se o usu�rio deseja continuar o programa
        printf("\nDeseja continuar o programa?\n");
        printf("Digite 'Y' para sim e 'N' para n�o: \n");
        scanf(" %c", &resposta);
        getchar();
        //Verifica��o da resposta
        while(resposta != 'Y' && resposta != 'y' && resposta != 'N' && resposta != 'n'){
                printf("Digite um valor v�lido!\n");
                printf("Digite 'Y' para sim e 'N' para n�o: ");
                scanf(" %c", &resposta);
                getchar();
        }
        if (resposta == 'Y' || resposta == 'y'){
            system("cls");
        }
    }
    return 0;
}
#endif // ex005

#ifdef ex006

#endif // ex006
