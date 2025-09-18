#include <stdio.h>
#include <string.h>
#define ex4

#ifdef ex1
char str1[11];
char str2[11];

int compararStrings()
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            return 0;
        }
        i++;
    }

    if (str1[i] == '\0' && str2[i] == '\0')
    {
        return 1; // iguais
    }
    else
    {
        return 0; // diferente
    }
}

int main()
{
    char respostaFinal = 'Y'; // verificar se usuário deseja reiniciar o programa

    while (respostaFinal != 'N' && respostaFinal != 'n')
    {
        printf("Digite a primeira string (max 10 caracteres): ");
        fgets(str1, sizeof(str1), stdin);
        str1[strcspn(str1, "\n")] = '\0'; // remove \n

        if (strlen(str1) > 10)
        {
            printf("Erro: voce digitou mais que 10 caracteres!\n");
            return 1; // encerra programa
        }

        printf("Digite a segunda string (max 10 caracteres): ");
        fgets(str2, sizeof(str2), stdin);
        str2[strcspn(str2, "\n")] = '\0';

        if (strlen(str2) > 10)
        {
            printf("Erro: voce digitou mais que 10 caracteres!\n");
            return 1;
        }

        int resultado = compararStrings();
        if (resultado == 1)
        {
            printf("As strings sao IGUAIS.\n");
        }
        else
        {
            printf("As strings sao DIFERENTES.\n");
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
#endif ex1

#ifdef ex2
char nome1[8];
char nome2[8];
char nome3[8];
char nome4[8];
char nome5[8];

int main()
{
    char respostaFinal = 'Y'; // verificar se usuário deseja reiniciar o programa

    while (respostaFinal != 'N' && respostaFinal != 'n')
    {
        printf("Digite o nome 1 (max 7 caracteres): ");
        scanf("%7s", nome1);
        printf("Digite o nome 2 (max 7 caracteres): ");
        scanf("%7s", nome2);
        printf("Digite o nome 3 (max 7 caracteres): ");
        scanf("%7s", nome3);
        printf("Digite o nome 4 (max 7 caracteres): ");
        scanf("%7s", nome4);
        printf("Digite o nome 5 (max 7 caracteres): ");
        scanf("%7s", nome5);
        printf("\n");

        printf("         10        20        30        40        50\n");
        printf("12345678901234567890123456789012345678901234567890\n");
        printf("  %-7s   %33s\n", nome1, nome5);
        printf("            %-7s    %15s\n", nome2, nome4);
        printf("                      %-7s\n", nome3);

        // Pergunta se o usuário deseja continuar o programa
        printf("\n\nDeseja continuar o programa?\n");
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
#endif // ex2

#ifdef ex3
char texto[41];

int comprimentoString()
{
    int i = 0;
    while (texto[i] != '\0')
    {
        i++;
    }
    return i;
}

int main()
{
    char respostaFinal = 'Y'; // verificar se usuário deseja reiniciar o programa

    while (respostaFinal != 'N' && respostaFinal != 'n')
    {
        printf("Digite uma string (max 40 caracteres): ");
        scanf("%40s", texto);
        int tamanho = comprimentoString();
        printf("O comprimento da string e: %d\n", tamanho);

        // Pergunta se o usuário deseja continuar o programa
        printf("\n\nDeseja continuar o programa?\n");
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
#endif // ex3

#ifdef ex4
char texto[11]; // 10 caracteres + '\0'

void Maiusculas()
{
    int i = 0;
    while (texto[i] != '\0')
    {
        if (texto[i] >= 'a' && texto[i] <= 'z')
        {
            texto[i] = texto[i] - ('a' - 'A');
        }
        i++;
    }
}

int main()
{
    char respostaFinal = 'Y'; // verificar se usuário deseja reiniciar o programa

    while (respostaFinal != 'N' && respostaFinal != 'n')
    {
        printf("Digite uma string (max 10 caracteres): ");
        scanf(" %10s", texto);

        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;

        Maiusculas();
        printf("String em maiusculas: %s\n", texto);

        // Pergunta se o usuário deseja continuar o programa
        do
        {
            printf("\n\nDeseja continuar o programa? (Y/N): ");
            scanf(" %c", &respostaFinal);

            while ((c = getchar()) != '\n' && c != EOF)
                ;
        } while (respostaFinal != 'Y' && respostaFinal != 'y' && respostaFinal != 'N' && respostaFinal != 'n');

        if (respostaFinal == 'Y' || respostaFinal == 'y')
        {
            system("cls");
        }
    }
}
#endif // ex4

#ifdef ex5
char texto[11]; // 10 caracteres + '\0'
void minuscula()
{
    int i = 0;
    while (texto[i] != '\0')
    {
        if (texto[i] >= 'A' && texto[i] <= 'Z')
        {
            texto[i] = texto[i] - ('A' - 'a');
        }
        i++;
    }
}
int main()
{
    char respostaFinal = 'Y'; // verificar se usuário deseja reiniciar o programa

    while (respostaFinal != 'N' && respostaFinal != 'n')
    {
        printf("Digite uma string (max 10 caracteres): ");
        scanf("%10s", texto);

        minuscula();

        printf("String em minuscula: %s\n", texto);

        // Pergunta se o usuário deseja continuar o programa
        printf("\n\nDeseja continuar o programa?\n");
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
#endif // ex5
