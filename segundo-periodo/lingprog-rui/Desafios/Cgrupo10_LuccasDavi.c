#include <stdio.h>


typedef struct
{
    char nome[50];
    char autor[50];
    float preco;
    int qtd;
    int existe; // 1 = Ativo, 0 = Excluido
} Livro;

int saoIguais(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] == s2[i])
    {
        if (s1[i] == '\0')
            return 1; 
        i++;
    }
    return 0; // diferença
}

void copiarTexto(char *destino, char *origem)
{
    int i = 0;
    while (origem[i] != '\0')
    {
        destino[i] = origem[i];
        i++;
    }
    destino[i] = '\0'; // fecha
}

void inserir(FILE *f, Livro *l);
void listar(FILE *f, Livro *l);
void buscarNome(FILE *f, Livro *l);
void buscarAutor(FILE *f, Livro *l);
void buscarPreco(FILE *f, Livro *l);
void alterarQtd(FILE *f, Livro *l);
void alterarPreco(FILE *f, Livro *l);
void alterarTudo(FILE *f, Livro *l);
void excluir(FILE *f, Livro *l);

int main()
{
    FILE *arquivo;
    Livro reg;
    int op;

    if ((arquivo = fopen("livraria_v2.dat", "rb+")) == NULL)
    {
        arquivo = fopen("livraria_v2.dat", "wb+");
    }

    do
    {
        printf("\n=== Menu ===\n");
        printf("\t1-Inserir\t\n2-Listar\t\n3-Busca por nome\t\n4-Busca por Autor\t\n5-Buscapor faixa de preco\t\n6-Alterar quantidade\t\n7-Alter o preco\t\n8-Alterar tudo\t\n9-Excluir\t\n10-Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            inserir(arquivo, &reg);
            break;
        case 2:
            listar(arquivo, &reg);
            break;
        case 3:
            buscarNome(arquivo, &reg);
            break;
        case 4:
            buscarAutor(arquivo, &reg);
            break;
        case 5:
            buscarPreco(arquivo, &reg);
            break;
        case 6:
            alterarQtd(arquivo, &reg);
            break;
        case 7:
            alterarPreco(arquivo, &reg);
            break;
        case 8:
            alterarTudo(arquivo, &reg);
            break;
        case 9:
            excluir(arquivo, &reg);
            break;
        }
    } while (op != 10);

    fclose(arquivo);
    return 0;
}


void inserir(FILE *f, Livro *l)
{
    char tempNome[50];
    printf("Nome do Livro: ");
    scanf(" %49[^\n]", tempNome);

    rewind(f);
    while (fread(l, sizeof(Livro), 1, f))
    {
        if (l->existe == 1 && saoIguais(l->nome, tempNome))
        {
            printf("Erro: Livro ja existe!\n");
            return;
        }
    }

    copiarTexto(l->nome, tempNome);

    printf("Autor: ");
    scanf(" %49[^\n]", l->autor);
    printf("Preco: ");
    scanf("%f", &l->preco);
    printf("Qtd: ");
    scanf("%d", &l->qtd);
    l->existe = 1;

    fseek(f, 0, SEEK_END);
    fwrite(l, sizeof(Livro), 1, f);
}


void listar(FILE *f, Livro *l)
{
    rewind(f);
    while (fread(l, sizeof(Livro), 1, f))
    {
        if (l->existe == 1)
        {
            printf("Livro: %s | R$ %.2f | Qtd: %d\n", l->nome, l->preco, l->qtd);
        }
    }
}


void buscarNome(FILE *f, Livro *l)
{
    char busca[50];
    printf("Buscar nome: ");
    scanf(" %49[^\n]", busca);

    rewind(f);
    while (fread(l, sizeof(Livro), 1, f))
    {
        // Comparação manual
        if (l->existe == 1 && saoIguais(l->nome, busca))
        {
            printf("Achou: %s, Autor: %s, R$ %.2f\n", l->nome, l->autor, l->preco);
            return;
        }
    }
    printf("Nao encontrado.\n");
}


void buscarAutor(FILE *f, Livro *l)
{
    char letra;
    printf("Letra inicial: ");
    scanf(" %c", &letra);

    rewind(f);
    while (fread(l, sizeof(Livro), 1, f))
    {
        if (l->existe == 1 && l->autor[0] == letra)
        {
            printf("Autor: %s | Livro: %s\n", l->autor, l->nome);
        }
    }
}


void buscarPreco(FILE *f, Livro *l)
{
    float min, max;
    printf("Min e Max: ");
    scanf("%f %f", &min, &max);

    rewind(f);
    while (fread(l, sizeof(Livro), 1, f))
    {
        if (l->existe == 1 && l->preco >= min && l->preco <= max)
        {
            printf("Livro: %s | R$ %.2f\n", l->nome, l->preco);
        }
    }
}


void alterarQtd(FILE *f, Livro *l)
{
    char busca[50];
    int qtd, tipo;
    printf("Nome do livro: ");
    scanf(" %49[^\n]", busca);

    rewind(f);
    while (fread(l, sizeof(Livro), 1, f))
    {
        if (l->existe == 1 && saoIguais(l->nome, busca))
        {
            printf("Estoque atual: %d\n", l->qtd);
            printf("1-Soma 2-Subtrai: ");
            scanf("%d", &tipo);
            printf("Valor: ");
            scanf("%d", &qtd);

            if (tipo == 1)
                l->qtd += qtd;
            else
                l->qtd -= qtd;

            fseek(f, -sizeof(Livro), SEEK_CUR);
            fwrite(l, sizeof(Livro), 1, f);
            return;
        }
    }
}


void alterarPreco(FILE *f, Livro *l)
{
    char busca[50];
    printf("Nome do livro: ");
    scanf(" %49[^\n]", busca);

    rewind(f);
    while (fread(l, sizeof(Livro), 1, f))
    {
        if (l->existe == 1 && saoIguais(l->nome, busca))
        {
            printf("Novo preco: ");
            scanf("%f", &l->preco);
            fseek(f, -sizeof(Livro), SEEK_CUR);
            fwrite(l, sizeof(Livro), 1, f);
            return;
        }
    }
}


void alterarTudo(FILE *f, Livro *l)
{
    char busca[50];
    printf("Nome para editar: ");
    scanf(" %49[^\n]", busca);

    rewind(f);
    while (fread(l, sizeof(Livro), 1, f))
    {
        if (l->existe == 1 && saoIguais(l->nome, busca))
        {
            char novoNome[50];
            printf("Novo Nome: ");
            scanf(" %49[^\n]", novoNome);
            copiarTexto(l->nome, novoNome); // Cópia manual

            printf("Novo Autor: ");
            scanf(" %49[^\n]", l->autor);
            printf("Novo Preco: ");
            scanf("%f", &l->preco);
            printf("Nova Qtd: ");
            scanf("%d", &l->qtd);

            fseek(f, -sizeof(Livro), SEEK_CUR);
            fwrite(l, sizeof(Livro), 1, f);
            return;
        }
    }
}


void excluir(FILE *f, Livro *l)
{
    char busca[50];
    printf("Nome para excluir: ");
    scanf(" %49[^\n]", busca);

    rewind(f);
    while (fread(l, sizeof(Livro), 1, f))
    {
        if (l->existe == 1 && saoIguais(l->nome, busca))
        {
            l->existe = 0; // "Apaga"
            fseek(f, -sizeof(Livro), SEEK_CUR);
            fwrite(l, sizeof(Livro), 1, f);
            printf("Excluido!\n");
            return;
        }
    }
}