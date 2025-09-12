#include <stdio.h>
#include <stdlib.h>

#define ex02

#ifdef ex01
int main()
{
    int entradaint[3];
    float entradafloat[3];
    long int entradalong[3];
    double entradadouble[3];
    unsigned int entradaunsigned[3];

    int cont;                 // contador do for
    char respostaFinal = 'Y'; // verificar se usuário deseja reiniciar o programa

    while (respostaFinal != 'N' && respostaFinal != 'n')
    {
        // entrada das variáveis
        for (cont = 0; cont < 3; cont++)
        {
            printf("\nDigite um valor int para o vetor [%d/2]:\n", cont);
            scanf("%d", &entradaint[cont]);

            printf("\nDigite um valor float para o vetor [%d/2]:\n", cont);
            scanf("%f", &entradafloat[cont]);

            printf("\nDigite um valor long para o vetor [%d/2]:\n", cont);
            scanf("%ld", &entradalong[cont]);

            printf("\nDigite um valor double para o vetor [%d/2]:\n", cont);
            scanf("%lf", &entradadouble[cont]);

            printf("\nDigite um valor unsigned para o vetor [%d/2]:\n", cont);
            scanf("%u", &entradaunsigned[cont]);
        }

        // alinhamento
        for (cont = 0; cont < 3; cont++)
        {
            printf("%6d%20ld%20u\n", entradaint[cont], entradalong[cont], entradaunsigned[cont]);
            printf("%20.2f%20.2lf\n", entradafloat[cont], entradadouble[cont]);
        }

        // Pergunta se o usuário deseja continuar o programa
        printf("Deseja continuar o programa?\n");
        printf("'Y' para sim e 'N' para nao: ");
        scanf(" %c", &respostaFinal);

        // Verificação da resposta
        while (respostaFinal != 'Y' && respostaFinal != 'y' && respostaFinal != 'N' && respostaFinal != 'n')
        {
            printf("Digite um valor valido!\n");
            printf("Digite 'Y' para sim e 'N' para nao: ");
            scanf(" %c", &respostaFinal);
        }
        if (respostaFinal == 'Y' || respostaFinal == 'y')
        {
            system("cls");
        }
    }
}
#endif // ex01

#ifdef ex02
void ordena(int v[], int tam)
{
    int par[5];
    int impar[5];

    int i, a = 0, b = 0;

    for (i = 0; i < tam; i++)
    {
        if (i % 2 == 0)
        {
            impar[a++] = v[i];
        }
        else
        {
            par[b++] = v[i];
        }
    }

    printf("\nVetor Par \n");
    for (i = 0; i < a; i++)
    {
        printf("%d ", par[i]);
    }

    printf("\n\nVetor Impar \n");
    for (i = 0; i < b; i++)
    {
        printf("%d ", impar[i]);
    }
}

int main()
{
    int v[10] = {3, 5, 6, 8, 1, 4, 2, 3, 7, 9};

    char resposta = 'Y';

    while (resposta != 'N' && resposta != 'n')
    {

        ordena(v, 10);

        do
        {
            printf("\n\nDeseja continuar? \t\n N - Parar \t\n Y - Continuar\n");
            scanf(" %c", &resposta);
        } while (resposta != 'Y' && resposta != 'y' && resposta != 'N' && resposta != 'n');

        // se a resposta for Y, ele limpa  tela e repete
        if (resposta == 'Y' || resposta == 'y')
        {
            system("cls");
        }
        // se a resposta for N, ele encerra o programa
        else
        {
            return 0;
        }
    }
}
#endif // ex02

#ifdef ex03
int ordena(int v[], int tam)
{
    int par[tam], impar[tam];
    int i, a = 0, b = 0;

    for (i = 0; i < tam; i++)
    {
        if (v[i] % 2 == 0)
        {
            par[a++] = v[i];
        }
        else
        {
            impar[b++] = v[i];
        }
    }

    printf("\nVetor Par \n");
    for (i = 0; i < a; i++)
    {
        printf("%d ", par[i]);
    }

    printf("\n\nVetor Impar \n");
    for (i = 0; i < b; i++)
    {
        printf("%d ", impar[i]);
    }
}

int main()
{
    int vetor[10];
    int i;
    char resposta = 'Y';

    // verificação se o usuário deseja continuar
    while (resposta != 'N' && resposta != 'n')
    {

        // recebe os valores do usuário
        for (i = 0; i < 10; i++)
        {
            int n; // variável temporária
            while (1)
            {
                printf("Digite o %d numero inteiro: ", i + 1);
                if (scanf("%d", &n) == 1)
                { // retorna 1 se número inteiro válido
                    vetor[i] = n;
                    break;
                }
                else
                {
                    printf("\nEntrada invalida!\nDigite apenas numeros inteiros.\n\n");
                    // limpa o buffer do teclado para evitar loop infinito
                    while (getchar() != '\n')
                        ;
                }
            }
        }

        ordena(vetor, 10);

        do
        {
            printf("\n\nDeseja continuar? \t\n N - Parar \t\n Y - Continuar\n");
            scanf(" %c", &resposta);
        } while (resposta != 'Y' && resposta != 'y' && resposta != 'N' && resposta != 'n');

        // se a resposta for Y, ele limpa  tela e repete
        if (resposta == 'Y' || resposta == 'y')
        {
            system("cls");
            // se a resposta for N, ele encerra o programa
        }
        else
        {
            return 0;
        }
    }
}
#endif // ex03

#ifdef ex04
#define LINHAS 2
#define COLUNAS 3

void imprime(int A[LINHAS][COLUNAS], int B[LINHAS][COLUNAS], int R[LINHAS][COLUNAS])
{
    system("cls");

    printf("O valores digitados:\n");

    printf("\nMatriz A \n");
    for (int x = 0; x < LINHAS; x++)
    {
        for (int w = 0; w < COLUNAS; w++)
        {
            printf("%d\t", A[x][w]);
        }
    }

    printf("\n\nMatriz B \n");
    for (int x = 0; x < LINHAS; x++)
    {
        for (int w = 0; w < COLUNAS; w++)
        {
            printf("%d\t", B[x][w]);
        }
    }

    printf("\n\nMatriz da soma: \n");
    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            printf("%d\t", R[i][j]);
        }
    }
}

void calcula(int A[LINHAS][COLUNAS], int B[LINHAS][COLUNAS], int R[LINHAS][COLUNAS])
{
    for (int j = 0; j < LINHAS; j++)
    {
        for (int i = 0; i < COLUNAS; i++)
        {
            R[j][i] = A[j][i] + B[j][i];
        }
    }
}

int main()
{
    int vetorA[LINHAS][COLUNAS];
    int vetorB[LINHAS][COLUNAS];
    int vetorResultado[LINHAS][COLUNAS];

    int linhas, colunas;
    char resposta = 'Y';

    while (resposta != 'N' && resposta != 'n')
    {
        for (linhas = 0; linhas < LINHAS; linhas++)
        {
            for (colunas = 0; colunas < COLUNAS; colunas++)
            {
                printf("\nDigite a entrada da linha %d e coluna %d do vetor A: \n", linhas + 1, colunas + 1);
                scanf("%d", &vetorA[linhas][colunas]);
            }
        }

        for (linhas = 0; linhas < LINHAS; linhas++)
        {
            for (colunas = 0; colunas < COLUNAS; colunas++)
            {
                printf("\nDigite a entrada da linha %d e coluna %d do vetor B: \n", linhas + 1, colunas + 1);
                scanf("%d", &vetorB[linhas][colunas]);
            }
        }

        calcula(vetorA, vetorB, vetorResultado);
        imprime(vetorA, vetorB, vetorResultado);

        do
        {
            printf("\n\nDeseja continuar? \t\n N - Parar \t\n Y - Continuar\n");
            scanf(" %c", &resposta);
        } while (resposta != 'Y' && resposta != 'y' && resposta != 'N' && resposta != 'n');

        // se a resposta for Y, ele limpa  tela e repete
        // se a resposta for N, ele encerra o programa
        if (resposta == 'Y' || resposta == 'y')
        {
            system("cls");
        }
        else
        {
            return 0;
        }
    }
}
#endif // ex04

#ifdef ex05
int ordena(int v[], int tam)
{
    int ordenador[10];
    int i;

    // "varre o vetor"
    for (i = 0; i < tam; i++)
    {
        // compara elemtentos
        for (int j = 0; j < tam - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }

    // mostra na tela em ordem crescente
    for (i = 0; i < tam; i++)
    {
        printf("%d ", v[i]);
    }

    return 0;
}

int main()
{
    int vetor[10];
    int i;
    char resposta = 'Y';

    // verificação se o usuário deseja continuar
    while (resposta != 'N' && resposta != 'n')
    {
        // recebe os valores do usuário
        for (i = 0; i < 10; i++)
        {
            printf("Digite o %d numero inteiro: ", i + 1);
            scanf("%d", &vetor[i]);
        }

        ordena(vetor, 10);

        do
        {
            printf("\n\nDeseja continuar? \t\n N - Parar \t\n Y - Continuar\n");
            scanf(" %c", &resposta);
        } while (resposta != 'Y' && resposta != 'y' && resposta != 'N' && resposta != 'n');

        // se a resposta for Y, ele limpa  tela e repete
        // se a resposta for N, ele encerra o programa
        if (resposta == 'Y' || resposta == 'y')
        {
            system("cls");
        }
        else
        {
            return 0;
        }
    }
}
#endif // ex05