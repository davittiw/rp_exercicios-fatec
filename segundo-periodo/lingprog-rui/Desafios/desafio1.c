#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

char livro1[20], livro2[20], livro3[20];
char autor1[20], autor2[20], autor3[20];

char *livros[] = {livro1, livro2, livro3};
char *autores[] = {autor1, autor2, autor3};

int exclui()
{
    int selectExclui;

    FILE *arquivoLivro = fopen("livro.bin", "rb");
    FILE *arquivoAutor = fopen("autor.bin", "rb");

    for (int i = 0; i < 3; i++)
    {
        fread(livros[i], sizeof(char), 20, arquivoLivro);
        fread(autores[i], sizeof(char), 20, arquivoAutor);
    }

    fclose(arquivoLivro);
    fclose(arquivoAutor);

    printf("Opções de exclusão: \n");
    printf("\t1 - %s \n\t2 - %s \n\t3 - %s", livros[0], livros[1], livros[2]);

    do
    {
        printf("\nSelecione qual livro deseja excluir: ");
        scanf("%d", &selectExclui);
    } while (selectExclui < 1 || selectExclui > 3);

    livros[selectExclui - 1][0] = '\0';
    autores[selectExclui - 1][0] = '\0';

    arquivoLivro = fopen("livro.bin", "wb");
    arquivoAutor = fopen("autor.bin", "wb");

    for (int i = 0; i < 3; i++)
    {
        fwrite(livros[i], sizeof(char), 20, arquivoLivro);
        fwrite(autores[i], sizeof(char), 20, arquivoAutor);
    }

    fclose(arquivoLivro);
    fclose(arquivoAutor);

    printf("Dado excluido com sucesso. \n\n");
    return 1;
}

void lista()
{
    FILE *arquivoLivro = fopen("livro.bin", "rb");
    FILE *arquivoAutor = fopen("autor.bin", "rb");

    for (int i = 0; i < 3; i++)
    {
        fread(livros[i], sizeof(char), 20, arquivoLivro);
        fread(autores[i], sizeof(char), 20, arquivoAutor);
    }

    fclose(arquivoLivro);
    fclose(arquivoAutor);

    printf("\n\nLista de livros registrados: \n");

    for (int i = 0; i < 3; i++)
    {
        printf("\tLivro %d: %s\n", i + 1, livros[i]);
        printf("\tAutor do livro: %s\n\n", autores[i]);
    }
}

void entrada()
{
    for (int i = 0; i < 3; i++)
    {
        printf("\nDigite o nome do %d livro: ", i + 1);
        scanf(" %19[^\n]", livros[i]);

        printf("Digite o autor do livro %s: ", livros[i]);
        scanf(" %19[^\n]", autores[i]);
    }

    FILE *arquivoLivro = fopen("livro.bin", "wb");
    FILE *arquivoAutor = fopen("autor.bin", "wb");

    for (int i = 0; i < 3; i++)
    {
        fwrite(livros[i], sizeof(char), 20, arquivoLivro);
        fwrite(autores[i], sizeof(char), 20, arquivoAutor);
    }

    fclose(arquivoLivro);
    fclose(arquivoAutor);

    printf("Dados salvos com sucesso.\n\n");
}

void pesquisaLivro()
{
    char pesquisa[20];
    
    FILE *arquivoLivro = fopen("livro.bin", "rb");
    FILE *arquivoAutor = fopen("autor.bin", "rb");
    
    for (int i = 0; i < 3; i++)
    {
        fread(livros[i], sizeof(char), 20, arquivoLivro);
        fread(autores[i], sizeof(char), 20, arquivoAutor);
    }
    
    fclose(arquivoLivro);
    fclose(arquivoAutor);
    
    printf("\nDigite o nome do livro desejado: ");
    scanf(" %19[^\n]", pesquisa);

    int encontrado = 0;

    for(int j = 0; j < 3; j++) {
        int i = 0, iguais = 1;

        while(pesquisa[i] != '\0' || livros[j][i] != '\0') {
            if(pesquisa[i] != livros[j][i]) {
                iguais = 0;
                break;
            }
            i++;
        }

        if(iguais) {
            printf("\tNome do livro: %s\n", livros[j]);
            printf("\tNome do autor: %s\n", autores[j]);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("livro não foi encontrado.");
    }
    
}

void pesquisaAutor()
{
    char pesquisa[20];
    
    FILE *arquivoLivro = fopen("livro.bin", "rb");
    FILE *arquivoAutor = fopen("autor.bin", "rb");
    
    for (int i = 0; i < 3; i++)
    {
        fread(livros[i], sizeof(char), 20, arquivoLivro);
        fread(autores[i], sizeof(char), 20, arquivoAutor);
    }
    
    fclose(arquivoLivro);
    fclose(arquivoAutor);
    
    printf("\nDigite o nome do autor desejado: ");
    scanf(" %19[^\n]", pesquisa);

    int encontrado = 0;

    for(int j = 0; j < 3; j++) {
        int i = 0, iguais = 1;

        while(pesquisa[i] != '\0' || autores[j][i] != '\0') {
            if(pesquisa[i] != autores[j][i]) {
                iguais = 0;
                break;
            }
            i++;
        }

        if(iguais) {
            printf("\tNome do autor: %s\n", autores[j]);
            printf("\tNome do livro: %s\n\n", livros[j]);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("autor nao foi encontrado.");
    }
    
}

void altera()
{
    printf("sadadad");
}

int main()
{
    int menu;

    do
    {
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