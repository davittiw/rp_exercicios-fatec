#include <stdio.h>
#include <stdlib.h>

#define ex04

#ifdef ex01
    struct Dados {
        char c;
        long l;
        int i;
        float f;
        double d;
        unsigned char uc;
        unsigned long ul;
        unsigned int ui;
    };

    void lerDados (struct Dados *p) {
        printf("Digite um char: ");
        scanf(" %c", &p->c);

        printf("Digite um int: ");
        scanf(" %d", &p->i);

        printf("Digite um long: ");
        scanf(" %ld", &p->l);

        printf("Digite um float: ");
        scanf(" %f", &p->f);

        printf("Digite um double: ");
        scanf(" %lf", &p->d);

        printf("Digite um unsigned char: ");
        scanf(" %hhu", &p->uc);

        printf("Digite um unsigned int: ");
        scanf(" %u", &p->ui);

        printf("Digite um unsigned long: ");
        scanf(" %lu", &p->ul);
    }

    void imprimirDados (struct Dados *p) {
        printf("\n");
        printf("        10        20        30        40        50        60        70\n");
        printf("1234567890123456789012345678901234567890123456789012345678901234567890\n");

        printf("  %c     %5d           %10ld          %10.2f  %10.2lf\n",p->c, p->i, p->l, p->f, p->d);
    }

    int main() {
        struct Dados dados;
        char resposta = 'Y';

        while(resposta != 'N' && resposta != 'n'){
            lerDados(&dados);
            imprimirDados(&dados);

            //Pergunta se o usuario deseja continuar o programa
            printf("\nDeseja continuar o programa?\n");
            printf("Digite 'Y' para sim e 'N' para n�o: \n");
            scanf(" %c", &resposta);
            getchar();

            //Verificacao da resposta
            while(resposta != 'Y' && resposta != 'y' && resposta != 'N' && resposta != 'n'){
                    printf("Digite um valor valido!\n");
                    printf("Digite 'Y' para sim e 'N' para nao: ");
                    scanf(" %c", &resposta);
                    getchar();
            }
            if (resposta == 'Y' || resposta == 'y'){
                system("cls");
            }
        }
        return 0;
    }
#endif //ex01

#ifdef ex02
void inputString(char *pstr1, char *pstr2);
int comparaString(char *pstr1, char *pstr2);

void inputString(char *pstr1, char *pstr2){
        //Input das strings 1 e 2 a partir de ponteiros
        printf("Digite a primeira string: ");
        scanf(" %9[^\n]", pstr1);

        printf("\nDigite a segunda string: ");
        scanf(" %9[^\n]", pstr2);
}

int comparaString(char *pstr1, char *pstr2){
    //Comparacao a partir dos ponteiros pstr1 e pstr2
    while(*pstr1 != '\0' && *pstr2 != '\0'){
        if(*pstr1 == *pstr2){
            pstr1++;
            pstr2++;
        } else{
            return 0; //Diferentes
        }
    } return (*pstr1 == '\0' && *pstr2 == '\0');
}

int main()
{
    char resposta = 'Y';
    char string1[10], string2[10];

    while(resposta != 'N' && resposta != 'n'){
        inputString(string1, string2);

        //Chamada da funcao para comparar as strings
        int resultado = comparaString(string1, string2);

        //Condicional para printar o resultado da funcao
        if(!resultado){
            printf("\nAs strings sao DIFERENTES (0)!\n");
        } else {
            printf("\nAs strings sao IGUAIS (1)!\n");
        }

        //Pergunta se o usuario deseja continuar o programa
        printf("\nDeseja continuar o programa?\n");
        printf("Digite 'Y' para sim e 'N' para nao: \n");
        scanf(" %c", &resposta);
        getchar();

        //Verificacao da resposta
        while(resposta != 'Y' && resposta != 'y' && resposta != 'N' && resposta != 'n'){
                printf("Digite um valor valido!\n");
                printf("Digite 'Y' para sim e 'N' para nao: ");
                scanf(" %c", &resposta);
                getchar();
        }

        if (resposta == 'Y' || resposta == 'y'){
            system("cls");
        }
    }
    return 0;
}
#endif // ex02

#ifdef ex03
void inputNumeros(float *pvalores){
    printf("Digite um valor: ");
    scanf(" %f", pvalores);
    getchar();
}

void inputOperador(char *pop){
    int valido = 0;

    do{
        printf("MENU:\n");
        printf("\t[+]: Soma\n\t[-]: Subtracao\n\t[*]: Multiplicacao\n\t[/]: Divisao\n\t[=]: Finalizar o calculo\n");
        printf("\nEscolha: ");
        scanf(" %c", pop);
        getchar();

        if(*pop == '+' || *pop == '-' || *pop == '/' || *pop == '*' || *pop == '=') {
            valido = 1;
        } else {
            printf("Operador invalido! Tente novamente.\n");
        }
    } while(!valido);
}

void calculo(char *pop, float *presultado, float *pvalores){
    switch(*pop){
        case '+':
            *presultado += *pvalores;
            break;
        case '-':
            *presultado -= *pvalores;
            break;
        case '*':
            *presultado *= *pvalores;
            break;
        case '/':
            if(*pvalores != 0){
                *presultado /= *pvalores;
            } else {
                printf("Divisao por 0 impossivel!\n");
            }
            break;
    }
}

int main()
{
    char resposta = 'Y';

    float resultado, valores, *presultado, *pvalores;
    char operador;

    presultado = &resultado;
    pvalores = &valores;

    while(resposta != 'N' && resposta != 'n'){
        operador = ' ';
        resultado = 0;

        inputNumeros(&valores);
        *presultado = *pvalores;

        while(operador != '='){
            inputOperador(&operador);
            if(operador == '=')
                break;
            inputNumeros(&valores);
            calculo(&operador, &resultado, &valores);
        }
        printf("\nO resultado final eh de %.2f\n", resultado);

        //Pergunta se o usuario deseja continuar o programa
        printf("\nDeseja continuar o programa?\n");
        printf("Digite 'Y' para sim e 'N' para nao: \n");
        scanf(" %c", &resposta);
        getchar();

        //Verificacao da resposta
        while(resposta != 'Y' && resposta != 'y' && resposta != 'N' && resposta != 'n'){
                printf("Digite um valor valido!\n");
                printf("Digite 'Y' para sim e 'N' para nao: ");
                scanf(" %c", &resposta);
                getchar();
        }
        if (resposta == 'Y' || resposta == 'y'){
            system("cls");
        }
    }
    return 0;
}
#endif // ex03

#ifdef ex04
int pesquisar(char *p, int tam, char *pLetra) {
    for(int i = 0; i < tam; i++) {
        if (*(p + i) == *pLetra) {
            return 1;
        }
    } return 0;
}

int main() {
    char p[] = {'b', 'd', 'f', 'h', 'j', 'l', 'k', 'm', 'o', 'q', 's', 'u', 'w', 'y'};
    int tam = 13;

    char letra;
    char op;
    char *pLetra = &letra;

    do {
        printf("\nDigite uma letra para pesquisar no vetor: ");
        scanf(" %c", pLetra);

        int resultado = pesquisar(p, tam, pLetra);

        if(resultado == 1) {
            printf("Resultado: A letra '%c' existe no vetor \n", *pLetra);
        } else {
            printf("Resultado: A letra '%c' NAO existe no vetor. \n", *pLetra);
        }

        printf("\n\nDeseja pesquisar outra letra? (S/N): ");
        scanf(" %c", &op);
    } while (op == 's' || op == 'S');

    return 0;
}
#endif // ex04

#ifdef ex05
// Definicao da estrutura
struct Endereco {
    char nome[50];
    char end[50];
    char cidade[40];
    char estado[3];
    char cep[15];
};

// Ler os 4 registros usando ponteiro para vetor de estruturas
void lerRegistros(struct Endereco *p) {

    system("cls");

    for (int i = 0; i < 4; i++) {
        printf("Registro %d:", i + 1);

        printf("\nNome: ");
        scanf(" %49[^\n]", (p + i)->nome);

        printf("Endereco: ");
        scanf(" %49[^\n]", (p + i)->end);

        printf("Cidade: ");
        scanf(" %39[^\n]", (p + i)->cidade);

        printf("Estado: ");
        scanf(" %2[^\n]", (p + i)->estado);

        printf("CEP: ");
        scanf(" %14[^\n]", (p + i)->cep);
    }
}

// Imprime todos os registros usando ponteiro
void imprimirRegistros(struct Endereco *p) {

    system("cls");

    for (int i = 0; i < 4; i++) {
        printf("\nRegistro %d: ", i + 1);
        printf("\n\tNome: %s", (p + i)->nome);
        printf("\n\tEndereco: %s", (p + i)->end);
        printf("\n\tCidade: %s", (p + i)->cidade);
        printf("\n\tEstado: %s", (p + i)->estado);
        printf("\n\tCEP: %s", (p + i)->cep);
    }
}

int main() {
    struct Endereco p[4]; // vetor de estruturas LOCAL em main
    int opcao = 0;

    do {
        printf("\nMENU");
        printf("\n\t1 - Ler registros");
        printf("\n\t2 - Imprimir registros");
        printf("\n\t3 - Sair");
        printf("\n\tOpcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) { // menu com switch [web:13]
            case 1:
                lerRegistros(p); // passa vetor (ponteiro) [web:17]
                break;
            case 2:
                imprimirRegistros(p);
                break;
            case 3:
                printf("Saindo...");
                break;
            default:
                printf("Opcao invalida!");
        }
    } while (opcao != 3);

    return 0;
}
#endif // ex05

#ifdef ex06
struct Endereco {
    char nome[50];
    char end[50];
    char cidade[40];
    char estado[3];
    char cep[15];
};

void lerRegistros(struct Endereco *p) {
    system("cls");

    for (int i = 0; i < 4; i++) {
        printf("Registro %d:", i + 1);

        printf("\nNome: ");
        scanf(" %49[^\n]", (p + i)->nome);

        printf("Endereco: ");
        scanf(" %49[^\n]", (p + i)->end);

        printf("Cidade: ");
        scanf(" %39[^\n]", (p + i)->cidade);

        printf("Estado: ");
        scanf(" %2[^\n]", (p + i)->estado);

        printf("CEP: ");
        scanf(" %14[^\n]", (p + i)->cep);
    }
}

void imprimirRegistros(struct Endereco *p) {
    system("cls");

    for (int i = 0; i < 4; i++) {
        printf("\nRegistro %d: ", i + 1);
        printf("\n\tNome: %s", (p + i)->nome);
        printf("\n\tEndereco: %s", (p + i)->end);
        printf("\n\tCidade: %s", (p + i)->cidade);
        printf("\n\tEstado: %s", (p + i)->estado);
        printf("\n\tCEP: %s", (p + i)->cep);
    }
}

int procuraRegistro(struct Endereco *p, char *nomeProcurado) {
    for (int i = 0; i < 4; i++) {
        int j = 0;

        while (nomeProcurado[j] != '\0' && (p + i)->nome[j] != '\0') {
            if (nomeProcurado[j] == (p + i)->nome[j]) {
                j++;
            } else {
                break;
            }
        }

        if (nomeProcurado[j] == '\0' && (p + i)->nome[j] == '\0') {
            return i; // Retorna o indice do registro encontrado
        }
    } return -1; // Nao encontrado
}

void alteraRegistro(struct Endereco *p, int indice) {
    printf("Alterando registro %d:", indice + 1);

    printf("\nNome: ");
    scanf(" %49[^\n]", (p + indice)->nome);

    printf("Endereco: ");
    scanf(" %49[^\n]", (p + indice)->end);

    printf("Cidade: ");
    scanf(" %39[^\n]", (p + indice)->cidade);

    printf("Estado: ");
    scanf(" %2[^\n]", (p + indice)->estado);

    printf("CEP: ");
    scanf(" %14[^\n]", (p + indice)->cep);
}

void excluirRegistro(struct Endereco *p, int indice) {
    for (int i = indice; i < 3; i++) {
        *(p + i) = *(p + i + 1);
    }

    (p + 3)->nome[0] = '\0';
    (p + 3)->end[0] = '\0';
    (p + 3)->cidade[0] = '\0';
    (p + 3)->estado[0] = '\0';
    (p + 3)->cep[0] = '\0';
}

void buscaRegistro(struct Endereco *p) {
    char nomeProcurado[50];
    printf("Digite o nome do registro a ser procurado: ");
    scanf(" %49[^\n]", nomeProcurado);

    int indice = procuraRegistro(p, nomeProcurado);
    if (indice != -1) {
        printf("Registro encontrado:\n");
        printf("\n\tNome: %s",      (p + indice)->nome);
        printf("\n\tEndereco: %s",  (p + indice)->end);
        printf("\n\tCidade: %s",    (p + indice)->cidade);
        printf("\n\tEstado: %s",    (p + indice)->estado);
        printf("\n\tCEP: %s\n",     (p + indice)->cep);
    } else {
        printf("Registro nao encontrado.\n");
    }
}

int main() {
    struct Endereco p[4]; // vetor de estruturas LOCAL em main
    int opcao = 0;

    for (int i = 0; i < 4; i++) {
        p[i].nome[0] = '\0'; // Inicializa os registros como vazios
    }

    do {
        printf("\nMENU");
        printf("\n\t1 - Ler registros");
        printf("\n\t2 - Imprimir registros");
        printf("\n\t3 - Buscar registro");
        printf("\n\t4 - Alterar registro");
        printf("\n\t5 - Excluir registro");
        printf("\n\t6 - Sair");
        printf("\n\tOpcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                lerRegistros(p);
                break;
            case 2:
                imprimirRegistros(p);
                break;
            case 3:
                buscaRegistro(p);
                break;
            case 4: {
                char nomeProcurado[50];

                printf("Digite o nome do registro a ser alterado: ");
                scanf(" %49[^\n]", nomeProcurado);

                int indice = procuraRegistro(p, nomeProcurado);

                if (indice != -1) {
                    alteraRegistro(p, indice);
                } else {
                    printf("Registro nao encontrado.\n");
                }
                break;
            }
            case 5: {
                char nomeProcurado[50];

                printf("Digite o nome do registro a ser excluido: ");
                scanf(" %49[^\n]", nomeProcurado);

                int indice = procuraRegistro(p, nomeProcurado);

                if (indice != -1) {
                    excluirRegistro(p, indice);
                    printf("Registro excluido.\n");
                } else {
                    printf("Registro nao encontrado.\n");
                }
                break;
            }
            case 6:
                printf("Saindo...");
                break;
            default:
                printf("Opcao invalida!");
        }
    } while(opcao != 6);
}

#endif // ex06
