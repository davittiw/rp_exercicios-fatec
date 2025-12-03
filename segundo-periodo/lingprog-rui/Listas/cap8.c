#include <stdio.h>
#include <stdlib.h>

#define ex06

#ifdef ex01
void main() {
    char op;

    do {
        char c;
        int i;
        long l;
        unsigned u;
        float f;
        double d;
        unsigned long ul;
        unsigned char uc;

        char *pc = &c;
        int *pi = &i;
        long *pl = &l;
        unsigned *pu = &u;
        float *pf = &f;
        double *pd = &d;
        unsigned long *pul = &ul;
        unsigned char *puc = &uc;

        printf("Digite um char: ");
        scanf(" %c", pc);

        printf("Digite um int: ");
        scanf(" %d", pi);

        printf("Digite um long: ");
        scanf(" %ld", pl);

        printf("Digite um unsigned: ");
        scanf(" %u", pu);

        printf("Digite um float: ");
        scanf(" %f", pf);

        printf("Digite um double: ");
        scanf(" %lf", pd);

        printf("Digite um unsigned long: ");
        scanf(" %lu", pul);

        printf("Digite um unsigned char: ");
        scanf(" %hhu", puc);


        printf("\n");
        printf("        10        20        30        40        50        60\n");
        printf("123456789012345678901234567890123456789012345678901234567890\n");

        printf("    %6d              %6ld              %6u\n", *pi, *pl, *pu);
        printf("             %6.1f              %6.1f              %c\n", *pf, *pd, *pc);
        printf("          %10lu       %10u\n", *pul, *puc);

        printf("\nDeseja continuar o Exercicio 1? (S/N): ");
        scanf(" %c", &op);
    } while(op == 'S' || op == 's');
}
#endif // ex01


#ifdef ex02
int main()
{
    int nums = 0, cont = 0, media = 0;
    int *pnums, *pmedia, *pcont;

    char resposta = 'Y';
    pnums = &nums;
    pmedia = &media;
    pcont = &cont;

    setlocale(LC_ALL, "Portuguese");
    while(resposta != 'N' && resposta != 'n'){
        //Usu�rio digita n�meros at� um ser negativo e j� calcula a m�dia
        while(nums>=0){
            printf("\nDigite um n�mero (negativo para finalizar): ");
            scanf("%d", &nums);
            getchar();

            //Condicional para desconsiderar n�mero negativo que encerrar� o c�lculo
            if(nums>=0){
            *pmedia += *pnums;
            (*pcont)++;
            }
        }
        //Printa a m�dia obtida
        printf("\t A m�dia tem valor de: %.2f\n",(float)*pmedia / *pcont);

        //Pergunta se o usu�rio deseja continuar o programa
        printf("\nDeseja continuar o programa?\n");
        printf("Digite 'Y' para sim e 'N' para n�o: \n");
        scanf(" %c", &resposta);
        getchar();
        //Verifica��o da resposta
        while(resposta != 'Y' && resposta != 'y' && resposta != 'N' && resposta != 'n'){
                printf("Digite um valor v�lido!\n");
                printf("Digite 'Y' para sim e 'N' para n�o: ");
                scanf(" %c", &resposta);
                getchar();
        }
        if (resposta == 'Y' || resposta == 'y'){
            system("cls");
            nums = 0;
            cont = 0;
            media = 0;
        }
    }
    return 0;
}
#endif // ex02


#ifdef ex03
char string1[11], string2[11];

int comparaString(){
    char *pstring1, *pstring2;

    pstring1 = string1;
    pstring2 = string2;

    while(*pstring1 != '\0' && *pstring2 != '\0'){
        if(*pstring1 == *pstring2){
            pstring1++;
            pstring2++;
        } else {
            return 0; //Diferentes
        }
    }
    return (*pstring1 == '\0' && *pstring2 == '\0'); /*garantia para ver se de fato s�o strings iguais*/
}

int main()
{
    char resposta = 'Y';

    while(resposta != 'N' && resposta != 'n'){
        //Input das strings
        printf("Digite a primeira string (ate 10 caract): ");
        scanf(" %10[^\n]", string1);
        getchar();

        printf("\nDigite a segunda string (ate 10 caract): ");
        scanf(" %10[^\n]",string2);
        getchar();

        int resultado = comparaString();

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

        while(resposta != 'Y' && resposta != 'y' && resposta != 'N' && resposta != 'n'){
                printf("Digite um valor valido!\n");
                printf("Digite 'Y' para sim e 'N' para n�o: ");
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
char vetor[] = {'b', 'd', 'f', 'h', 'j', 'k', 'm', 'o', 'q', 's', 'u', 'w', 'y'};

// Funcao de busca usando ponteiro
int busca_letra(char letra) {
    char *p = vetor;
    int tam = sizeof(vetor) / sizeof(vetor[0]);

    for (int i = 0; i < tam; i++) {
        if (*(p + i) == letra) {
            return 1; // Encontrou
        }
    } return 0; // Nao encontrou
}

int main() {
    char letra;
    char resposta = 'Y';

    while(resposta != 'N' && resposta != 'n'){
        printf("Digite uma letra: ");
        scanf(" %c", &letra);
        getchar();

        if (busca_letra(letra)) {
            printf("Letra %c encontrada no vetor!", letra);
        } else {
            printf("Letra %c NAO encontrada no vetor!", letra);
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
#endif // ex04


#ifdef ex05
struct Endereco {
    char nome[50];
    char end[50];
    char cidade[40];
    char estado[3]; // UF + /0  
    char cep[15];
};

// Vetor global de 4 estruturas
struct Endereco vetor[4];

// Funcao para ler os dados usando ponteiros    
void lerEnderecos(struct Endereco *p) {
    for (int i = 0; i < 4; i++) { // loop sobre o vetor
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

// Funcao para imprimir os dados usando ponteiros
void imprimirEnderecos(struct Endereco *p) {
    for (int i = 0; i < 4; i++) { // loop sobre o vetor
        printf("\nRegistro %d:", i + 1);
        printf("\n\tNome: %s",      (p + i)->nome);
        printf("\n\tEndereco: %s",  (p + i)->end);
        printf("\n\tCidade: %s",    (p + i)->cidade);
        printf("\n\tEstado: %s",    (p + i)->estado);
        printf("\n\tCEP: %s",     (p + i)->cep);
    }
}

int main() {
    char resposta = 'Y';

    while(resposta != 'N' && resposta != 'n'){
        lerEnderecos(vetor); // passa o vetor global (como ponteiro)
        imprimirEnderecos(vetor); // imprime tudo

        //Pergunta se o usu�rio deseja continuar o programa
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
#endif // ex05


#ifdef ex06
struct Data {
    int dia;
    int mes;
    int ano;
};

struct Data datas[2];

void lerDatas(struct Data *p) {
    for (int i = 0; i < 2; i++) {
        printf("Data: %d\n", i + 1);
        
        printf("Dia: ");
        scanf(" %d", &(p + i)->dia);

        printf("Mes: ");
        scanf(" %d", &(p + i)->mes);

        printf("Ano: ");
        scanf(" %d", &(p + i)->ano);
    }
};

int totalDias(struct Data *d){
    int dias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int total = 0;

    total += (d->ano -1) * 365; // anos completos

    for (int i = 0; i < d->mes - 1; i++) {
        total += dias[i]; // meses completos
    }

    total += d->dia; // dias do mes atual
    return total;
};

int calcularDiferenca(struct Data *p){
    int dias1 = totalDias(p);
    int dias2 = totalDias(p + 1);
    int diferenca = dias2 - dias1;

    if (diferenca < 0) {
        diferenca = -diferenca; // valor absoluto
    }

    return diferenca;
}

int main() {
    char resposta = 'Y';

    while (resposta != 'N' && resposta != 'n')
    {
        lerDatas(datas);

        int diferenca = calcularDiferenca(datas);

        printf("\nA diferenca entre as datas e de %d dias.\n", diferenca);

        // Pergunta se o usuario deseja continuar o programa
        printf("\nDeseja continuar o programa?\n");
        printf("Digite 'Y' para sim e 'N' para nao: \n");
        scanf(" %c", &resposta);
        getchar();

        // Verificacao da resposta
        while (resposta != 'Y' && resposta != 'y' && resposta != 'N' && resposta != 'n')
        {
            printf("Digite um valor valido!\n");
            printf("Digite 'Y' para sim e 'N' para nao: ");
            scanf(" %c", &resposta);
            getchar();
        }
        if (resposta == 'Y' || resposta == 'y')
        {
            system("cls");
        }
    }
    return 0;
}
#endif // ex06