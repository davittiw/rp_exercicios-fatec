#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

char livro1[20];
int livro2[20];
int livro3[20];

int autor1[20];
int autor2[20];
int autor3[20];

int exclui()
{
    printf("esta sendo excluido");
}

int altera()
{
    printf("esta sendo alterado");
}

int pesquisaAutor()
{
    printf("esta sendo pesquisado por autor");
}

int pesquisaLivro()
{
    printf("esta sendo pesquisado por livro");
}

int lista()
{
    FILE *arquivo = fopen("livros1.bin", "rb");

    fread(livro1, sizeof(char), 20, arquivo);
    fclose(arquivo);

    for (int i = 0; i < 20; i++)
    {
        printf("Livro %d: %c\n", i+1, livro1[i]);
    }
}

int entrada()
{
    for (int i = 0; i < 20; i++)
    {
        printf("Digite o %d livro: ", i + 1);
        scanf(" %c", &livro1[i]);
    }

    FILE *arquivo = fopen("livros1.bin", "wb");

    fwrite(livro1, sizeof(char), 20, arquivo);
    fclose(arquivo);
}

int main()
{
    int menu;

    do {
    printf("Opcoes de entrada!\n");
    printf("\t1 - entrada de todos os dados; \n\t2 - lista todos os dados na tela; \n\t3 - pesquisa um livro completo; \n\t4 - pesquisa por autor; \n\t5 - altera todos os dados; \n\t6 - exclui dados; \n\t7 - sair.\n");
    printf("Digite como deseja prosseguir: ");
    scanf("%d", &menu);

    while (menu <= 0 || menu > 7)
    {
        printf("\nVoce so tem 7 opcoes.\nDigite corretamente: ");
        scanf("%d", &menu);
    }

    switch (menu)
    {
    case 1:
        entrada();
        break;
    case 2:
        lista();
        break;
    case 3:
        pesquisaLivro();
        break;
    case 4:
        pesquisaAutor();
        break;
    case 5:
        altera();
        break;
    case 6:
        exclui();
        break;
    case 7:
        exit(0);
        break;
    default:
        printf("Nao foi possivel direcionar para uma acao.");
        printf("Tente novamente.");
        break;
    }

    } while (menu != 7);
}

// FILE *arquivo;

// arquivo = fopen("numeros.bin", "wb");

// fwrite(numeros, sizeof(int), 3, arquivo);
// fclose(arquivo);

// arquivo = fopen("numeros.bin", "rb");

// fread(numerosLidos, sizeof(int), 3, arquivo);
// fclose(arquivo);