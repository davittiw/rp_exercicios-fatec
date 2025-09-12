#include <stdio.h>
#define ex5

#ifdef ex1
char str1[11];
char str2[11];

int compararStrings() {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0;
        }
        i++;
    }

    if (str1[i] == '\0' && str2[i] == '\0') {
        return 1; // iguais
    } else {
        return 0; // diferente
    }
}
int main() {
    printf("Digite a primeira string (max 10 caracteres): ");
    scanf("%10s", str1);
    printf("Digite a segunda string (max 10 caracteres): ");
    scanf("%10s", str2);

    int resultado = compararStrings();

    if (resultado == 1) {
        printf("As strings sao IGUAIS.\n");
    } else {
        printf("As strings sao DIFERENTES.\n");
    }
}
#endif ex1

#ifdef ex2
char nome1[8];
char nome2[8];
char nome3[8];
char nome4[8];
char nome5[8];

int main() {
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
}
#endif // ex2

#ifdef ex3
char texto[41];

int comprimentoString() {
    int i = 0;
    while (texto[i] != '\0') {
        i++;
    }
    return i;
}
int main() {
    printf("Digite uma string (max 40 caracteres): ");
    scanf("%40s", texto);
    int tamanho = comprimentoString();
    printf("O comprimento da string e: %d\n", tamanho);
}
#endif // ex3

#ifdef ex4
char texto[11]; // 10 caracteres + '\0'
void Maiusculas() {
    int i = 0;
    while (texto[i] != '\0') {
        if (texto[i] >= 'a' && texto[i] <= 'z') {
            texto[i] = texto[i] - ('a' - 'A');
        }
        i++;
    }
}
int main() {
    printf("Digite uma string (max 10 caracteres): ");
    scanf("%10s", texto);
    Maiusculas();
    printf("String em maiusculas: %s\n", texto);
}
#endif // ex4

#ifdef ex5
char texto[11]; // 10 caracteres + '\0'
void minuscula() {
    int i = 0;
    while (texto[i] != '\0') {
        if (texto[i] >= 'A' && texto[i] <= 'Z') {
            texto[i] = texto[i] - ('A' - 'a');
        }
        i++;
    }
}
int main() {
    printf("Digite uma string (max 10 caracteres): ");
    scanf("%10s", texto);
    minuscula();
    printf("String em minuscula: %s\n", texto);
}
#endif // ex5
