#include <stdio.h>
#include <stdlib.h>

#define ex05
#ifdef ex01
int VerificaNeg(int num1, int num2){
    if(num1 == 0) {
        printf("\nPrimeiro numero: -1 (ou seja, igual a zero) \n");
    } else if (num1 < 0 ) {
        printf("\nPrimeiro numero: 0 (ou seja, negativo) \n");
    } else {
        printf("\nPrimeiro numero: 1 (ou seja, positivo) \n");
    }

    if(num2 == 0) {
        printf("Segundo numero: -1 (ou seja, igual a zero) \n");
    } else if (num2 < 0 ) {
        printf("Segundo numero: 0 (ou seja, negativo)\n");
    } else {
        printf("Segundo numero: 1 (ou seja, positivo) \n");
    }

    return 0;
}

void soma (int num1, int num2) {
    int soma = 0;
        for (int i = num1 + 1; i < num2; i++){
            soma += i;
        }
    printf("\nSomado: %d", soma);
}

void multiplica(int num1, int num2) {
    int multiplicar = 1;

        for(int i = num1 + 1; i < num2; i++){
            multiplicar *= i;
        }

    printf("\nMultiplicado: %d", multiplicar);
}

void dividir (int num1, int num2) {
    float divisao = (float)num1 / num2;
    printf("\nDividido: %.2f", divisao);
}

int main()
{
    char resposta;

    while(resposta != 'N' && resposta != 'n') {
    int num1, num2;

    printf("Digite um numero: ");
    scanf("%d", &num1);

    printf("Digite outro numero: ");
    scanf("%d", &num2);

    if(num1 > num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    VerificaNeg(num1, num2);

    if (num1 < 0 && num2 < 0) {
        multiplica(num1, num2);
    } else if (num1 > 0 && num2 > 0) {
        soma(num1, num2);
    } else if ((num1 < 0 && num2 > 0) || (num1 > 0 && num2 < 0)) {
        dividir(num1, num2);
    } else {
        printf("Nao foi possivel analisar.");
    }

    printf("\nDeseja continuar? (Y ou N)\n");
    scanf(" %c", &resposta);

    while (resposta != 'Y' && resposta != 'y' && resposta != 'N' && resposta != 'n') {
        printf("Digite Y para continuar ou N para parar de jogar.");
        scanf(" %c", &resposta);
    }

    if(resposta == 'Y' || resposta == 'y'){
        system("cls");
    }

    if(resposta == 'N' || resposta == 'n'){
        return 0;
    }

    }

}
#endif // ex01


#ifdef ex02
int fatorial (int N) {
    int resultado = 1;
    for(int i = N; i > 1; i--) {
        resultado *= i;
    }
    return resultado;
}

int soma_algarismo (int resultado) {
    int soma = 0;
    while (resultado > 0) {
        soma += resultado % 10;
        resultado /= 10;
    }
    return soma;
}

int main () {
    int N;
    char respostaFinal = 'Y'; // verificar se usuário deseja reiniciar o programa

    while (respostaFinal != 'N' && respostaFinal != 'n')
    {
        printf("Digite um numero: ");
        scanf("%i", &N);

        int fat = fatorial(N);
        int somado = soma_algarismo(fat);

        printf("A fatoracao eh %d \n", fat);
        printf("A soma dos algarismos eh %d", somado);
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
#endif // ex02


#ifdef ex03
int soma(int valor[], int tamanho) {
  int somar = 0;
  for(int i = 0; i < tamanho; i++) {
    somar += valor[i];
  }
  return somar;
}

int subtracao(int valor[], int tamanho) {
    int subtrai = valor[0];
    for(int i = 1; i < tamanho; i++) {
        subtrai -= valor[i];
    }
    return subtrai;
}

float divida(int valor[], int tamanho) {
    float dividir = valor[0];
    for (int i = 1; i < tamanho; i++) {
        dividir /= valor[i];
    }
    return dividir;
}

int multiplica (int valor[], int tamanho) {
    int multiplicar = valor[0];

    for(int i = 1; i < tamanho; i++) {
        multiplicar *= valor[i];
    }
    return multiplicar;
}

int main() {
    int valor[2];
    char respostaFinal = 'Y'; // verificar se usuário deseja reiniciar o programa

    while (respostaFinal != 'N' && respostaFinal != 'n')
    {
        for (int i = 0; i < 2; i++)
        {
            printf("Digite o %d numero: ", i + 1);
            scanf("%d", &valor[i]);
        }

        int somado = soma(valor, 2);
        float dividido = divida(valor, 2);
        int subtraido = subtracao(valor, 2);
        int multiplicado = multiplica(valor, 2);

        printf("\nA soma resulta em: %d\n", somado);
        printf("A divisao resulta em: %.2f\n", dividido);
        printf("A subtracao resulta em: %d\n", subtraido);
        printf("A multiplicacao resulta em: %d\n", multiplicado);

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
#endif // ex03


#ifdef ex04
int main() {
    char resposta = 'Y';

    while (resposta != 'N' && resposta != 'n')
    {
        int num, qtd = 0;
        int soma = 0, subtracao = 0, multiplicacao = 1;
        float divisao = 0;
        char continuar = 'S';

        printf("Digite n�meros inteiros (um por vez). Digite 'N' quando quiser parar.\n");

        while (continuar != 'N' && continuar != 'n')
        {
            printf("Digite um n�mero: ");
            scanf("%d", &num);

            if (qtd == 0)
            {
                // Primeiro n�mero inicializa todas as opera��es
                soma = num;
                subtracao = num;
                multiplicacao = num;
                divisao = num;
            }
            else
            {
                soma += num;
                subtracao -= num;
                multiplicacao *= num;
                if (num != 0)
                {
                    divisao /= num;
                }
                else
                {
                    printf("Aviso: n�o � poss�vel dividir por zero. Ignorado.\n");
                }
            }
            qtd++;

            printf("Deseja digitar outro n�mero? (S/N): ");
            getchar(); // limpa buffer
            scanf(" %c", &continuar);
            while (continuar != 'n' && continuar != 'N' && continuar != 's' && continuar != 'S')
            {
                printf("Digite um valor v�lido! \nDeseja digitar outro n�mero? (S/N): ");
                getchar(); // limpa buffer
                scanf(" %c", &continuar);
            }
        }

        printf("\nResultados:\n");
        printf("Soma: %d\n", soma);
        printf("Subtra��o: %d\n", subtracao);
        printf("Multiplica��o: %d\n", multiplicacao);
        printf("Divis�o: %.2f\n", divisao);

        // Pergunta se o usu�rio deseja continuar o programa
        printf("Deseja continuar o programa?\n");
        printf("Digite 'Y' para sim e 'N' para n�o: ");
        scanf(" %c", &resposta);
        // Verifica��o da resposta
        while (resposta != 'Y' && resposta != 'y' && resposta != 'N' && resposta != 'n')
        {
            printf("Digite um valor v�lido!\n");
            printf("Digite 'Y' para sim e 'N' para n�o: ");
            scanf(" %c", &resposta);
        }
        if (resposta == 'Y' || resposta == 'y')
        {
            system("cls");
        }
    }
}
#endif // ex04


#ifdef ex05
int soma(int valor1, int valor2)
{
    return valor1 + valor2;
}

int subtracao(int valor1, int valor2)
{
    return valor1 - valor2;
}

int multiplicacao(int valor1, int valor2)
{
    return valor1 * valor2;
}

int divisao(int valor1, int valor2)
{
    return valor1 / valor2;
}

int main()
{
    int valores, resultado;
    int cont = 2;
    char operador = ' ';
    char respostaFinal = 'Y';

    while (respostaFinal != 'N' && respostaFinal != 'n')
    {
        // Primeiro valor da calculadora
        printf("Digite o primeiro valor para o calculo: \n");
        scanf("%d", &resultado);

        // Para os demais valores
        while (operador != '=')
        {
            printf("Digite o valor numero %d para o calculo: \n", cont);
            scanf("%d", &valores);
            getchar();

            printf("Escolha uma operacao para calcular os valores digitado:\n");
            printf("\t '+' para soma;\n");
            printf("\t '-' para subtracao;\n");
            printf("\t '*' para multiplicacao;\n");
            printf("\t '/' para divisao;\n");
            scanf("%c", &operador);
            getchar();
            while (operador != '+' && operador != '-' && operador != '*' && operador != '/' && operador != '=')
            {
                printf("Digite um operador valido.");
                scanf("%c", &operador);
                getchar();
            }

            switch (operador)
            {
            case '+':
                resultado = soma(resultado, valores);
                break;

            case '-':
                resultado = subtracao(resultado, valores);
                break;

            case '*':
                resultado = multiplicacao(resultado, valores);
                break;

            case '/':
                if (valores == 0)
                {
                    printf("Operacao invalida! O segundo valor nao pode ser igual a 0!\n");
                    break;
                }
                resultado = divisao(resultado, valores);
                break;
            }
            cont++;
            if (cont > 2)
            {
                printf("Deseja continuar calculando?\n");
                printf("Digite '=' se nao e qualquer outro valor para prosseguir: ");
                scanf("%c", &operador);
                getchar();
            }
        }
        printf("Resultado final: %d\n", resultado);

        // Pergunta se o usu�rio deseja continuar o programa
        printf("Deseja continuar o programa?\n");
        printf("'Y' para sim e 'N' para nao: ");
        scanf("%c", &respostaFinal);
        getchar();
        // Verifica��o da resposta
        while (respostaFinal != 'Y' && respostaFinal != 'y' && respostaFinal != 'N' && respostaFinal != 'n')
        {
            printf("Digite um valor valido!\n");
            printf("Digite 'Y' para sim e 'N' para nao: ");
            scanf("%c", &respostaFinal);
            getchar();
        }
        if (respostaFinal == 'Y' || respostaFinal == 'y')
        {
            system("cls");
            operador = ' ';
        }
    }
}
#endif // ex05
