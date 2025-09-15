#include <stdio.h>
#include <stdlib.h>

#define ex02

#ifdef ex01
int calculaData(int m, int a, int d)
{
    if (m == 1) {
        m = 13;
        a--;
    } else if (m == 2) {
        m = 14;
        a--;
    }

    int K = a % 100;
    int J = a / 100;

    int h = (d + (13 * (m + 1)) / 5 + K + (K / 4) + (J / 4) + (5 * J)) % 7;

    switch (h)
    {
    case 0:
        printf("O dia eh sabado.");
        break;
    case 1:
        printf("O dia eh domingo.");
        break;
    case 2:
        printf("O dia eh segunda.");
        break;
    case 3:
        printf("O dia eh terca.");
        break;
    case 4:
        printf("O dia eh quarta.");
        break;
    case 5:
        printf("O dia eh quinta.");
        break;
    case 6:
        printf("O dia eh sexta.");
        break;
    default:
        printf("Nao foi possivel calcular o dia.");
        break;
    }

    return 0;
}

int main()
{
    int dia, mes, ano;
    char respostaFinal = 'Y';

    while (respostaFinal != 'N' && respostaFinal != 'n'){

        printf("\t1 - Janeiro \t 2 - Fevereiro \t 3 - Março \n\t4 - Abril \t 5 - Maio \t 6 - Junho \n\t7 - Julho \t 8 - Agosto \t 9 - Setembro \n\t10 - Outubro \t 11 - Novembro \t 12 - Dezembro\n");
        printf("Digite o mes: ");
        scanf("%d", &mes);
    
        if (mes > 12 || mes <= 0)
        {
            printf("Ei, cara! Digite o mes corretamente: ");
            scanf("%d", &mes);
        }
    
        printf("Digite o dia: ");
        scanf("%d", &dia);
    
        if (mes == 2 && dia > 28)
        {
            printf("Fevereiro so contem 28 dias! \nDigite o dia corretamente: ");
            scanf("%d", &dia);
        }
    
        printf("Digite o ano: ");
        scanf("%d", &ano);
    
        calculaData(mes, ano, dia);

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
#endif // ex01

#ifdef ex02
int main()
{
}
#endif // ex02

#ifdef ex03
int main()
{
}
#endif // ex03

#ifdef ex04
int main()
{
}
#endif // ex04

#ifdef ex05
int main()
{
}
#endif // ex05