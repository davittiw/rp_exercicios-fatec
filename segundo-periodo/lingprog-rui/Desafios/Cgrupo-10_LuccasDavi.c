#include <stdio.h>
#include <stdlib.h>

char livro1[20], livro2[20], livro3[20];
char autor1[20], autor2[20], autor3[20];

int comparaString(char str1[], char str2[])
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0;
        }
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0') {
        return 1;
    }
    return 0;
}

int exclui()
{
    int selectExclui;

    FILE *arquivo = fopen("biblioteca.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    fread(livro1, sizeof(char), 20, arquivo);
    fread(autor1, sizeof(char), 20, arquivo);
    fread(livro2, sizeof(char), 20, arquivo);
    fread(autor2, sizeof(char), 20, arquivo);
    fread(livro3, sizeof(char), 20, arquivo);
    fread(autor3, sizeof(char), 20, arquivo);
    fclose(arquivo);

    printf("Opcoes de exclusao: \n");
    printf("\t1 - %s \n\t2 - %s \n\t3 - %s", livro1, livro2, livro3);

    do {
        printf("\nSelecione qual livro deseja excluir: ");
        scanf("%d", &selectExclui);
    } while (selectExclui < 1 || selectExclui > 3);

    if (selectExclui == 1) {
        livro1[0] = '\0';
        autor1[0] = '\0';
    } else if (selectExclui == 2) {
        livro2[0] = '\0';
        autor2[0] = '\0';
    } else {
        livro3[0] = '\0';
        autor3[0] = '\0';
    }

    arquivo = fopen("biblioteca.bin", "wb");
    fwrite(livro1, sizeof(char), 20, arquivo);
    fwrite(autor1, sizeof(char), 20, arquivo);

    fwrite(livro2, sizeof(char), 20, arquivo);
    fwrite(autor2, sizeof(char), 20, arquivo);

    fwrite(livro3, sizeof(char), 20, arquivo);
    fwrite(autor3, sizeof(char), 20, arquivo);

    fclose(arquivo);

    printf("Dado excluido com sucesso. \n\n");
    return 1;
}

void lista()
{
    FILE *arquivo = fopen("biblioteca.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fread(livro1, sizeof(char), 20, arquivo);
    fread(autor1, sizeof(char), 20, arquivo);

    fread(livro2, sizeof(char), 20, arquivo);
    fread(autor2, sizeof(char), 20, arquivo);

    fread(livro3, sizeof(char), 20, arquivo);
    fread(autor3, sizeof(char), 20, arquivo);

    fclose(arquivo);

    printf("\n\nLista de livros registrados: \n");

    if (livro1[0] != '\0') {
        printf("\tLivro 1: %s\n", livro1);
        printf("\tAutor do livro: %s\n\n", autor1);
    }
    if (livro2[0] != '\0') {
        printf("\tLivro 2: %s\n", livro2);
        printf("\tAutor do livro: %s\n\n", autor2);
    }
    if (livro3[0] != '\0') {
        printf("\tLivro 3: %s\n", livro3);
        printf("\tAutor do livro: %s\n\n", autor3);
    }
}

void entrada()
{
    printf("\nDigite o nome do 1 livro: ");
    scanf(" %19[^\n]", livro1);
    printf("Digite o autor do livro %s: ", livro1);
    scanf(" %19[^\n]", autor1);

    printf("\nDigite o nome do 2 livro: ");
    scanf(" %19[^\n]", livro2);
    printf("Digite o autor do livro %s: ", livro2);
    scanf(" %19[^\n]", autor2);

    printf("\nDigite o nome do 3 livro: ");
    scanf(" %19[^\n]", livro3);
    printf("Digite o autor do livro %s: ", livro3);
    scanf(" %19[^\n]", autor3);

    FILE *arquivo = fopen("biblioteca.bin", "wb");
    fwrite(livro1, sizeof(char), 20, arquivo);
    fwrite(autor1, sizeof(char), 20, arquivo);

    fwrite(livro2, sizeof(char), 20, arquivo);
    fwrite(autor2, sizeof(char), 20, arquivo);

    fwrite(livro3, sizeof(char), 20, arquivo);
    fwrite(autor3, sizeof(char), 20, arquivo);

    fclose(arquivo);

    printf("Dados salvos com sucesso.\n\n");
}

void pesquisaLivro()
{
    char pesquisa[20];

    FILE *arquivo = fopen("biblioteca.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fread(livro1, sizeof(char), 20, arquivo);
    fread(autor1, sizeof(char), 20, arquivo);

    fread(livro2, sizeof(char), 20, arquivo);
    fread(autor2, sizeof(char), 20, arquivo);

    fread(livro3, sizeof(char), 20, arquivo);
    fread(autor3, sizeof(char), 20, arquivo);

    fclose(arquivo);

    printf("\nDigite o nome do livro desejado: ");
    scanf(" %19[^\n]", pesquisa);

    int encontrado = 0;

    if (comparaString(pesquisa, livro1)) {
        printf("\tNome do livro: %s\n", livro1);
        printf("\tNome do autor: %s\n", autor1);
        encontrado = 1;
    } else if (comparaString(pesquisa, livro2)) {
        printf("\tNome do livro: %s\n", livro2);
        printf("\tNome do autor: %s\n", autor2);
        encontrado = 1;
    } else if (comparaString(pesquisa, livro3)) {
        printf("\tNome do livro: %s\n", livro3);
        printf("\tNome do autor: %s\n", autor3);
        encontrado = 1;
    }

    if (!encontrado) {
        printf("Livro nao foi encontrado.\n");
    }
}

void pesquisaAutor()
{
    char pesquisa[20];

    FILE *arquivo = fopen("biblioteca.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fread(livro1, sizeof(char), 20, arquivo);
    fread(autor1, sizeof(char), 20, arquivo);

    fread(livro2, sizeof(char), 20, arquivo);
    fread(autor2, sizeof(char), 20, arquivo);

    fread(livro3, sizeof(char), 20, arquivo);
    fread(autor3, sizeof(char), 20, arquivo);

    fclose(arquivo);

    printf("\nDigite o nome do autor desejado: ");
    scanf(" %19[^\n]", pesquisa);

    int encontrado = 0;

    if (comparaString(pesquisa, autor1)) {
        printf("\tNome do autor: %s\n", autor1);
        printf("\tNome do livro: %s\n\n", livro1);
        encontrado = 1;
    }
    if (comparaString(pesquisa, autor2)) {
        printf("\tNome do autor: %s\n", autor2);
        printf("\tNome do livro: %s\n\n", livro2);
        encontrado = 1;
    }
    if (comparaString(pesquisa, autor3)) {
        printf("\tNome do autor: %s\n", autor3);
        printf("\tNome do livro: %s\n\n", livro3);
        encontrado = 1;
    }

    if (!encontrado) {
        printf("Autor nao foi encontrado.\n");
    }
}

void altera()
{
    char nomeLivro[20];

    FILE *arquivo = fopen("biblioteca.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fread(livro1, sizeof(char), 20, arquivo);
    fread(autor1, sizeof(char), 20, arquivo);

    fread(livro2, sizeof(char), 20, arquivo);
    fread(autor2, sizeof(char), 20, arquivo);

    fread(livro3, sizeof(char), 20, arquivo);
    fread(autor3, sizeof(char), 20, arquivo);

    fclose(arquivo);

    printf("\nDigite o nome do livro que deseja alterar: ");
    scanf(" %19[^\n]", nomeLivro);

    int encontrado = 0;

    if (comparaString(nomeLivro, livro1)) {
        printf("\nLivro encontrado:\n");
        printf("\tNome do livro: %s\n", livro1);
        printf("\tNome do autor: %s\n\n", autor1);
        
        printf("Digite o nome do novo livro: ");
        scanf(" %19[^\n]", livro1);
        printf("Digite o novo nome do autor: ");
        scanf(" %19[^\n]", autor1);
        encontrado = 1;
    } else if (comparaString(nomeLivro, livro2)) {
        printf("\nLivro encontrado:\n");
        printf("\tNome do livro: %s\n", livro2);
        printf("\tNome do autor: %s\n\n", autor2);
        
        printf("Digite o nome do novo livro: ");
        scanf(" %19[^\n]", livro2);
        printf("Digite o novo nome do autor: ");
        scanf(" %19[^\n]", autor2);
        encontrado = 1;
    } else if (comparaString(nomeLivro, livro3)) {
        printf("\nLivro encontrado:\n");
        printf("\tNome do livro: %s\n", livro3);
        printf("\tNome do autor: %s\n\n", autor3);
        
        printf("Digite o nome do novo livro: ");
        scanf(" %19[^\n]", livro3);
        printf("Digite o novo nome do autor: ");
        scanf(" %19[^\n]", autor3);
        encontrado = 1;
    }

    if (!encontrado) {
        printf("Livro nao foi encontrado.\n");
        return;
    }

    arquivo = fopen("biblioteca.bin", "wb");
    fwrite(livro1, sizeof(char), 20, arquivo);
    fwrite(autor1, sizeof(char), 20, arquivo);

    fwrite(livro2, sizeof(char), 20, arquivo);
    fwrite(autor2, sizeof(char), 20, arquivo);

    fwrite(livro3, sizeof(char), 20, arquivo);
    fwrite(autor3, sizeof(char), 20, arquivo);
    
    fclose(arquivo);

    printf("Dado alterado com sucesso. \n\n");
}

int main()
{
    int menu;

    do {
        printf("Opcoes de entrada!\n");
        printf("\t1 - entrada de todos os dados; \n\t2 - lista todos os dados na tela; \n\t3 - pesquisa um livro completo; \n\t4 - pesquisa por autor; \n\t5 - altera todos os dados; \n\t6 - exclui dados; \n\t7 - sair.\n");
        printf("Digite como deseja prosseguir: ");
        scanf("%d", &menu);

        while (menu <= 0 || menu > 7) {
            printf("\nVoce so tem 7 opcoes.\nDigite corretamente: ");
            scanf("%d", &menu);
        }

        switch (menu) {
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

    return 0;
}