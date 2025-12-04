#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

#define ex01

#ifdef ex01
// Estrutura global
struct Dados {
    char c;
    int i;
    long l;
    float f;
    double d;
    unsigned char uc;
    unsigned int ui;
    unsigned long ul;
};

// Variável global
struct Dados dados;

// Função para ler os dados
void lerDados() {
    printf("Digite um caractere: ");
    scanf(" %c", &dados.c);

    printf("Digite um número inteiro: ");
    scanf("%d", &dados.i);

    printf("Digite um valor long: ");
    scanf("%ld", &dados.l);

    printf("Digite um valor de ponto flutuante: ");
    scanf("%f", &dados.f);

    printf("Digite um valor double: ");
    scanf("%lf", &dados.d);

    printf("Digite um valor unsigned char (0 a 255): ");
    scanf("%hhu", &dados.uc);

    printf("Digite um valor unsigned int: ");
    scanf("%u", &dados.ui);

    printf("Digite um valor unsigned long: ");
    scanf("%lu", &dados.ul);
}


void imprimirDados() {
    printf("\n====================================================================\n");
    printf("1234567890123456789012345678901234567890123456789012345678901234567890\n");
    printf("%4c%6d%7ld%16.2f%15.2lf\n",
           dados.c, dados.i, dados.l, dados.f, dados.d);
    printf("%10u%12u%13lu\n", dados.uc, dados.ui, dados.ul);
    printf("======================================================================\n");
}


int main() {
    char resposta = 'Y';
    setlocale(LC_ALL, "Portuguese");
    while(resposta != 'N' && resposta != 'n'){
        lerDados();
        imprimirDados();

        printf("\nPrograma finalizado pelo usuario.\n");

        //Pergunta se o usuário deseja continuar o programa
        printf("\nDeseja continuar o programa?\n");
        printf("Digite 'Y' para sim e 'N' para não: \n");
        scanf(" %c", &resposta);
        getchar();
        //Verificação da resposta
        while(resposta != 'Y' && resposta != 'y' && resposta != 'N' && resposta != 'n'){
                printf("Digite um valor válido!\n");
                printf("Digite 'Y' para sim e 'N' para não: ");
                scanf(" %c", &resposta);
                getchar();
        }
        if (resposta == 'Y' || resposta == 'y'){
            system("cls");
        }
    }
    return 0;
}
#endif

#ifdef ex02
// def a struct
struct infos
{
    char nome[15];
    char end[50]; // endereço
    char cidade[30];
    char estado[30];
    char cep[12];
};

// declaro o vetor de estruturas global
struct infos infoUser[4];

// funcao que vai receber os dados
void recebeDados (int i) {
    printf("Digite seu nome: ");
    scanf(" %14[^\n]", infoUser[i].nome);

    printf("Digite seu endereco: ");
    scanf(" %49[^\n]", infoUser[i].end);

    printf("Digite sua cidade: ");
    scanf(" %29[^\n]", infoUser[i].cidade);

    printf("Digite seu estado: ");
    scanf(" %29[^\n]", infoUser[i].estado);

    printf("Digite seu CEP: ");
    scanf(" %11[^\n]", infoUser[i].cep);
}

// funcao que mostra os dados
void mostraDados () {
    printf("\n--- DADOS CADASTRADOS ---\n");

    for(int j = 0; j < 4; j++) {
        printf("\nCADASTRO: %d \n", j + 1);
        printf("Nome: %s\n", infoUser[j].nome);
        printf("Endereco: %s\n", infoUser[j].end);
        printf("Cidade: %s\n", infoUser[j].cidade);
        printf("Estado: %s\n", infoUser[j].estado);
        printf("CEP: %s\n", infoUser[j].cep);
    }
}

int main()
{
    char resposta = 'Y';
    
    // loop para continuar o programa
    while(resposta == 'Y' || resposta == 'y') {
        // loop para receber os dados
        for(int i=0; i < 4; i++) {
            printf("\nCADASTRO: %d \n", i + 1);
            recebeDados(i);
        }

        mostraDados();

        printf("\nFim do Programa!\n");

        printf("Deseja continuar?");
        printf("\t\nY - Continuar \nN - Finalizar\n");
        scanf(" %c", &resposta);

        // valida a resposta do usuario
        if (resposta != 'Y' && resposta != 'y' && resposta != 'N' && resposta !='n') {
            printf("\nDigite as opcoes corretamente!\n");

            printf("Deseja continuar o programa?");
            printf("\t\nY - Continuar \nN - Finalizar\n");
            scanf(" %c", &resposta);
        }
    }
}
#endif

#ifdef ex03
struct data
{
    int dia;
    int mes;
    int ano;
};

struct data calendario[2];

int calculaDatas() {
    // array com os dias de cada mes
    int diasPorMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int totalDias[2];

    // calcula o total de dias para cada data
    for(int i = 0; i < 2; i++) {
        int total = calendario[i].dia;

        for(int j = 1; j < calendario[i].mes; j++) {
            total += diasPorMes[j];
        }

        // adiciona os dias dos anos
        total += calendario[i].ano * 365;

        totalDias[i] = total;
    }

    // calcula a diferenca absoluta entre as duas datas
    int diferenca = fabs(totalDias[0] - totalDias[1]);

    return diferenca;
}

int main()
{
    char resposta = 'Y';

    // loop para continuar o programa
    while (resposta == 'Y' || resposta == 'y')
    {

        // loop para receber os dados
        for(int i = 0; i < 2; i++) {
            printf("\nCadastro da %d data\n", i + 1);
            printf("Digite o dia: ");
            scanf("%d", &calendario[i].dia);

            printf("Digite o mes: ");
            scanf("%d", &calendario[i].mes);

            printf("Digite o ano: ");
            scanf("%d", &calendario[i].ano);
        }

        // chama a funcao que calcula as datas
        int diferenca = calculaDatas();

        printf("\nA diferenca entre as datas eh de %d dias\n", diferenca);

        printf("\nFim do Programa!\n");

        // pergunta se o usuario deseja continuar
        printf("Deseja continuar?");
        printf("\t\nY - Continuar \nN - Finalizar\n");
        scanf(" %c", &resposta);

        // valida a resposta do usuario
        if (resposta != 'Y' && resposta != 'y' && resposta != 'N' && resposta !='n') {
            printf("\nDigite as opcoes corretamente!\n");

            printf("Deseja continuar o programa?");
            printf("\t\nY - Continuar \nN - Finalizar\n");
            scanf(" %c", &resposta);
        }
    }
    
}
#endif

#ifdef ex04
struct paciente
{
    char nome[50];
    float peso;
    float altura;
};

struct paciente pacientes[4];

void recebeDados() {
    for (int i = 0; i < 4; i++) {
        printf("\nDigite o nome do paciente: ");
        scanf(" %49[^\n]", pacientes[i].nome);

        printf("Digite o peso do paciente (kg): ");
        scanf("%f", &pacientes[i].peso);

        printf("Digite a altura do paciente (m): ");
        scanf("%f", &pacientes[i].altura);
    }
}

void imprimeDados() {
    printf("\n--- DADOS DOS PACIENTES ---\n");
    for (int i = 0; i < 4; i++) {
        printf("\nNome: %s\n", pacientes[i].nome);
        printf("Peso: %.2f kg\n", pacientes[i].peso);
        printf("Altura: %.2f m\n", pacientes[i].altura);
    }
}

void calculaIMC() {
    printf("\n--- INDICE DE MASSA CORPORAL (IMC) ---\n");
    for (int i = 0; i < 4; i++) {
        float imc = pacientes[i].peso / (pacientes[i].altura * pacientes[i].altura);
        printf("IMC de %s: %.2f\n", pacientes[i].nome, imc);
    }
}

int main()
{
    int resposta;

    do {
        printf("Menu de Opcoes: \n");
        printf("\t\n1 - receber dados \n2 - mostrar dados \n3 - calcular IMC \n4 - sair do programa\n");
        printf("Opcao escolhida: ");
        scanf("%d", &resposta);
    
        switch (resposta)
        {
        case 1:
            recebeDados();
            break;
        case 2:
            imprimeDados();
            break;
        case 3:
            calculaIMC();
            break;
        case 4:
            return 0;
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    } while (resposta != 4);
}
#endif