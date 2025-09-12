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

    printf("Digite um numero: ");
    scanf("%i", &N);

    int fat = fatorial(N);
    int somado = soma_algarismo(fat);

    printf("A fatoracao eh %d \n", fat);
    printf("A soma dos algarismos eh %d", somado);
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

    for (int i = 0; i < 2; i++) {
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
}
#endif // ex03


#ifdef ex04
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
    int N;

    printf("Digite a quantidade de numeros: ");
    scanf("%d", &N);

    int valor[N];

    for (int i = 0; i < N; i++) {
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &valor[i]);
    }

    int somado = soma(valor, N);
    float dividido = divida(valor, N);
    int subtraido = subtracao(valor, N);
    int multiplicado = multiplica(valor, N);

    printf("\nA soma resulta em: %d\n", somado);
    printf("A divisao resulta em: %.2f\n", dividido);
    printf("A subtracao resulta em: %d\n", subtraido);
    printf("A multiplicacao resulta em: %d\n", multiplicado);
}
#endif // ex04


#ifdef ex05
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
    int N; // quantidade de numeros que usuario quer inserir
    char resposta, play; // qual operacao o usuario quer realizar

    printf("Digite a quantidade de numeros: ");
    scanf("%d", &N);

    int valor[N];

    for (int i = 0; i < N; i++) {
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &valor[i]);
    }

    // escolha sobre qual operacao utilizar
    printf("\nQual operacao voce deseja realizar?");
    printf("\n\t+ para somar \n\t- para subtrair \n\t/ para dividir \n\t* para multiplicar\n");
    scanf(" %c", &resposta);

        int somado = soma(valor, N);
        float dividido = divida(valor, N);
        int subtraido = subtracao(valor, N);
        int multiplicado = multiplica(valor, N);

    // faz a operacao de acordo com a escolha
    switch(resposta){
    case '+':
        printf("\nA soma resulta em: %d\n", somado);
        break;
    case '/':
        printf("A divisao resulta em: %.2f\n", dividido);
        break;
    case '-':
        printf("A subtracao resulta em: %d\n", subtraido);
        break;
    case '*':
        printf("A multiplicacao resulta em: %d\n", multiplicado);
        break;
    default:
        printf("Nao foi possivel realizar a operacao selecionada.");
    }
}
#endif // ex05
