#include <stdio.h>
#include <stdlib.h>

#define ex1

#ifdef ex1
int main()
{
    int baixo = 1, alto = 99, palpite;
    char operadores;

    char respostaFinal = 'Y'; // verificar se usuário deseja reiniciar o programa

    while (respostaFinal != 'N' && respostaFinal != 'n')
    {
        printf("LEITOR DE PENSAMENTOS\n");
        printf("Irei descobrir o numero que voce pensou\n\n");
        printf("Instrucoes: A cada numero digitado responda com um operador de comparacao.\nAbaixo estara a legenda par a consultar os operadores.\n\n");
        printf("LEGENDA:\n\n (<) Menor\n (>) Maior\n (=)Igual\n\n");

        while (baixo <= alto)
        {

            palpite = (baixo + alto) / 2;
            printf("O numero que voce pensou e: %d\n", palpite);
            printf("Digite a sua resposta (=, < ou >): \n");
            scanf(" %c", &operadores);

            if (operadores == '=')
            {
                printf("Eu advinhei o numero que voce pensou!");
                break;
            }
            else if (operadores == '>')
            {
                baixo = palpite + 1;
            }
            else if (operadores == '<')
            {
                alto = palpite - 1;
            }
            else
            {
                printf("Resposta Invalida! Digite apenas <, > ou =");
            }
            printf("\n");
        }

        // Pergunta se o usuário deseja continuar o programa
        printf("\nDeseja continuar o programa?\n");
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
#endif // ex 1

#ifdef ex2
int main()
{
    int baixo = 1, alto = 99, tentativas = 0, palpite;
    char operadores;

    char respostaFinal = 'Y'; // verificar se usuário deseja reiniciar o programa

    while (respostaFinal != 'N' && respostaFinal != 'n')
    {
        printf("LEITOR DE PENSAMENTOS\n\n");
        printf("Irei descobrir o numero que voce pensou\n\n");
        printf("Instrucoes: A cada numero digitado responda com um operador de comparacao.\nAbaixo estara a legenda par a consultar os operadores.\n\n");
        printf("LEGENDA:\n\n (<) Menor\n (>) Maior\n (=)Igual\n\n");

        while (baixo <= alto)
        {
            tentativas++;
            palpite = (baixo + alto) / 2;
            printf("O numero que voce pensou e: %d\n", palpite);
            printf("Digite a sua resposta (=, < ou >): \n");
            scanf(" %c", &operadores);

            if (operadores == '=')
            {
                printf("Eu advinhei o numero que voce pensou!\n");
                printf("Eu precisei de %d tentativa(s) para acertar o numero que voce digitou", tentativas);
                break;
            }
            else if (operadores == '>')
            {
                baixo = palpite + 1;
            }
            else if (operadores == '<')
            {
                alto = palpite - 1;
            }
            else
            {
                printf("Resposta Invalida! Digite apenas <, > ou =");
            }
            printf("\n");
        }

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

int main()
{
    int numero, soma = 0, quantidade = 0;
    float media;

    for (;;)
    {
        printf("Digite um numero inteiro(positivo ou negativo): ");
        scanf("%d", &numero);

        if (numero < 0)
        {
            break;
        }
        else
        {
            soma += numero;
            quantidade++;
        }
    }

    if (quantidade > 0)
    {
        media = (float)soma / quantidade;
        printf("Media dos numeros positivos digitados: %.2f\n", media);
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
#endif // ex3

#ifdef ex4
int main()
{
    int h1, m1, s1, h2, m2, s2, total_seg1, total_seg2, diff, dh, dm, ds;

    char respostaFinal = 'Y'; // verificar se usuário deseja reiniciar o programa

    while (respostaFinal != 'N' && respostaFinal != 'n')
    {
        printf("Digite  o horario de inicio da ligacao: ");
        scanf("%d", &h1);
        printf("Digite os minutos: ");
        scanf("%d", &m1);
        printf("Digite os segundos: ");
        scanf("%d", &s1);

        printf("Digite o horario final: ");
        scanf("%d", &h2);
        printf("Digite os minutos: ");
        scanf("%d", &m2);
        printf("Digite os segundos: ");
        scanf("%d", &s2);

        total_seg1 = h1 * 3600 + m1 * 60 + s1;
        total_seg2 = h2 * 3600 + m2 * 60 + s2;

        diff = total_seg2 - total_seg1;

        if (diff < 0)
        {
            diff += 24 * 3600;
        }

        dh = diff / 3600;
        diff %= 3600;
        dm = diff / 60;
        ds = diff % 60;

        printf("Intervalo decorrido: %02d:%02d:%02d\n", dh, dm, ds);

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
#endif // ex4

#ifdef ex5
int main()
{
    float distancia, litros, consumo;

    char respostaFinal = 'Y'; // verificar se usuário deseja reiniciar o programa

    while (respostaFinal != 'N' && respostaFinal != 'n')
    {
        printf("Digite a distancia percorrida em km: ");
        scanf("%f", &distancia);
        printf("Digite a quantidade de litros consumidos: ");
        scanf("%f", &litros);

        if (litros == 0)
        {
            printf("Quantidade de litros nao pode ser zero.\n");
            return 1;
        }

        consumo = distancia / litros;

        printf("Consumo: %.2f km/l\n", consumo);

        if (consumo < 8.0)
        {
            printf("Venda o carro!\n");
        }
        else if (consumo >= 8.0 && consumo <= 14.0)
        {
            printf("Economico!\n");
        }
        else
        {
            printf("Super economico!\n");
        }

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
