#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define ex002

#ifdef ex001
int main()
{

}
#endif //ex001

#ifdef ex002
struct agenda{
    char nome[20];
    char telefone[14];
    char aniversario_dia[3];
    char aniversario_mes[3];
};

void leituraArquivo(struct agenda *pcontato){
    int cont;
    FILE *arq;

    arq = fopen("contato.txt", "r");
    //Caso dê erro e o arquivo não abra
    if(arq == NULL){
        printf("ERRO! Arquivo não foi aberto!");
    }
    //Leitura de todos os dados salvos no arquivo
    for(cont=0; cont<4; cont++){
        fread((pcontato+cont)->nome,sizeof((pcontato+cont)->nome),1,arq);
        fread((pcontato+cont)->telefone,sizeof((pcontato+cont)) -> telefone,1,arq);
        fread((pcontato+cont) -> aniversario_dia,sizeof((pcontato+cont) -> aniversario_dia),1,arq);
        fread((pcontato+cont) -> aniversario_mes,sizeof((pcontato+cont) -> aniversario_mes),1,arq);
    }
    fclose(arq);
}

void escritaArquivo(struct agenda *pcontato){
    int cont;
    FILE *arq;

    arq = fopen("contato.txt", "w");
    //Caso dê erro e o arquivo não abra
    if(arq == NULL){
        printf("ERRO! Arquivo não foi aberto!\n");
    }
    //Escrita de todos as variáveis no arquivo
    for(cont=0; cont<4; cont++){
        fwrite((pcontato+cont) -> nome,sizeof((pcontato+cont)->nome),1,arq);
        fwrite((pcontato+cont) -> telefone,sizeof((pcontato+cont) -> telefone),1,arq);
        fwrite((pcontato+cont) -> aniversario_dia,sizeof((pcontato+cont) -> aniversario_dia),1,arq);
        fwrite((pcontato+cont) -> aniversario_mes,sizeof((pcontato+cont) -> aniversario_mes),1,arq);
    }
    fclose(arq);
}

void entradaContatos(struct agenda *pcontato){
    int cont;

    system("cls");
    //Input de todos os contatos do usuário
    for(cont=0; cont<4; cont++){
            printf("\nDigite o nome (%d/3): ", cont);
            scanf(" %19[^\n]", &(pcontato+cont)->nome);
            printf("\nDigite o telefone (modelo 00 99999-9999) (%d/3): ", cont);
            scanf(" %13[^\n]", &(pcontato+cont)->telefone);
            printf("\nDigite o aniversário (modelo DD) (%d/3): ", cont);
            scanf(" %2s", &(pcontato+cont)->aniversario_dia);
            printf("\nDigite o aniversário (modelo MM) (%d/3): ", cont);
            scanf(" %2s", &(pcontato+cont)->aniversario_mes);
    }
    escritaArquivo(pcontato);
}

void listarContatos(struct agenda *pcontato){
    int cont;

    system("cls");
    //Output dos contatos salvos, registrados no arquivo
    leituraArquivo(pcontato);
    for(cont=0; cont<4; cont++){
        printf("\n\tNome(%d/3): %s", cont, (pcontato+cont)->nome);
        printf("\n\tTelefone(%d/3): %s", cont, (pcontato+cont)->telefone);
        printf("\n\tAniversário(DD/MM)(%d/3): %s/%s\n", cont, (pcontato+cont)->aniversario_dia, (pcontato+cont)->aniversario_mes);
    }
}

void pesquisaNome(struct agenda *pcontato){
    int cont, cont2;
    char pesquisa[20];

    system("cls");
    //Input do nome para pesquisa
    printf("\nDigite o nome completo para pesquisar o contato: ");
    scanf(" %19[^\n]", pesquisa);

    //Garantindo que o programa já tem os dados do arquivo
    leituraArquivo(pcontato);
    //Comparação da variável local pesquisa com a estrutura de dados
    for(cont=0; cont<4; cont++){
         cont2 = 0;
         while((pcontato+cont)->nome[cont2] != '\0' && pesquisa[cont2] != '\0'){
            if((pcontato+cont)->nome[cont2] == pesquisa[cont2]){
                //Caso o char em questão seja igual
                cont2++;
            } else{
                //Caso as strings não sejam iguais
                break;
            }
        }
        //Caso as duas strings sejam de fato iguais
        if((pcontato+cont)->nome[cont2] == '\0' && pesquisa[cont2] == '\0'){
            printf("\tNome: %s", (pcontato+cont)->nome);
            printf("\n\tTelefone: %s", (pcontato+cont)->telefone);
            printf("\n\tAniversário(DD/MM)): %s/%s\n", (pcontato+cont)->aniversario_dia, (pcontato+cont)->aniversario_mes);
            return;
        }
    }
    //Caso o for acabe sem nenhum return
    printf("Nenhum contato encontrado com esse nome...\n");
}

void pesquisaLetra(struct agenda *pcontato){
    int cont, check = 0; /*O check vai ser uma variável para verificar se há algum contato com a inicial ou não*/
    char pesquisa;

    system("cls");
    //Garantindo que o programa já tem os dados do arquivo
    leituraArquivo(pcontato);
    //Input da inicial que o usuário busca
    printf("Digite a primeira letra do(s) contato(s) que busca: ");
    scanf(" %c", &pesquisa);
    getchar();

    //Comparação e output quando encontrado
    for(cont=0; cont<4; cont++){
        if(pesquisa == (pcontato+cont)->nome[0] || pesquisa - 32 == (pcontato+cont)->nome[0]){
            printf("\tNome: %s", (pcontato+cont)->nome);
            printf("\n\tTelefone: %s", (pcontato+cont)->telefone);
            printf("\n\tAniversário(DD/MM): %s/%s\n", (pcontato+cont)->aniversario_dia, (pcontato+cont)->aniversario_mes);
            check++;
        }
    }
    //Caso o for acabe sem nenhum return
    if(check == 0)
        printf("Nenhum contato encontrado com essa inicial...\n");
}

void aniversarioMes(struct agenda *pcontato){
    int cont, cont2, check = 0; /*check vai ser uma variável para verificar se tem algum aniversariante entre os vetores da estrutura de dados*/
    char pesquisa[3];

    system("cls");
    //Garantindo que o programa já tem os dados do arquivo
    leituraArquivo(pcontato);
    //Input do mês atual
    printf("\nDigite o mês atual(Modelo MM): ");
    scanf(" %2s", pesquisa);

    printf("\nAniversariante(s) do mês: \n");
    //Comparação e output quando for encontrado os aniversariantes
    for(cont=0;cont<4;cont++){
        cont2=0;
        while((pcontato+cont)->aniversario_mes[cont2] != '\0' && pesquisa[cont2] != '\0')
            if((pcontato+cont)->aniversario_mes[cont2] == pesquisa[cont2]){
                cont2++;
            } else{
                break;
            }
        if((pcontato+cont)->aniversario_mes[cont2]=='\0'){
            printf("\tNome: %s", (pcontato+cont)->nome);
            printf("\n\tTelefone: %s", (pcontato+cont)->telefone);
            printf("\n\tAniversário(DD/MM): %s/%s\n", (pcontato+cont)->aniversario_dia, (pcontato+cont)->aniversario_mes);
            check++;
        }
    }
    if(check==0){
        printf("\tNenhum...\n");
    }
}

void alteraNome(struct agenda *pcontato){
    int cont, cont2;
    char pesquisa[20];

    system("cls");
    //Garantindo que o programa já tem os dados do arquivo
    leituraArquivo(pcontato);
    //Input do nome que o usuário busca
    printf("\nDigite o nome que deseja alterar: ");
    scanf(" %19[^\n]", pesquisa);

    //Comparação e processo de alteração para quando o nome for encontrado
    for(cont=0; cont<4; cont++){
         cont2 = 0;
         while((pcontato+cont)->nome[cont2] != '\0' && pesquisa[cont2] != '\0'){
            if((pcontato+cont)->nome[cont2] == pesquisa[cont2]){
                //Caso o char em questão seja igual
                cont2++;
            } else{
                //Caso as strings não sejam iguais
                break;
            }
        }
        //Caso as duas strings sejam de fato iguais, haverá o input para remover o contato anterior
        if((pcontato+cont)->nome[cont2] == '\0' && pesquisa[cont2] == '\0'){
            printf("\nDigite o novo nome do contato: ");
            scanf(" %19[^\n]", &(pcontato+cont)->nome);
            printf("\nDigite o telefone: ");
            scanf(" %13[^\n]", &(pcontato+cont)->telefone);
            printf("\nDigite o dia do aniversário (DD): ");
            scanf(" %2s", &(pcontato+cont)->aniversario_dia);
            printf("\nDigite o mês do aniversário (MM): ");
            scanf(" %2s", &(pcontato+cont)->aniversario_mes);
            escritaArquivo(pcontato);
            return;
        }
    }
}

void excluiNome(struct agenda *pcontato){
    int cont, cont2;
    char pesquisa[20];

    system("cls");
    //Garantindo que o programa já tem os dados do arquivo
    leituraArquivo(pcontato);
    //Input do nome que o usuário busca
    printf("Digite o nome do contato que deseja excluir: ");
    scanf(" %19[^\n]", pesquisa);

    //Comparação e exclusão das strings para "(null)" se encontrado
    for(cont=0; cont<4; cont++){
    cont2 = 0;
        while(pesquisa[cont2] != '\0' && (pcontato+cont)->nome[cont2] != '\0'){
            if(pesquisa[cont2] == (pcontato+cont)->nome[cont2]){
                //Comparação char por char da pesquisa com os contatos salvos
                cont2++;
            }else{
                //Caso os nomes não sejam os mesmos.
                break;
            }
        }
        if(pesquisa[cont2] == '\0' && (pcontato+cont)->nome[cont2] == '\0'){
            (pcontato+cont)->nome[0] = '*';
            (pcontato+cont)->telefone[0] = '*';
            (pcontato+cont)->aniversario_dia[0] = '*';
            (pcontato+cont)->aniversario_mes[0] = '*';

            escritaArquivo(pcontato);
            return;
        }
    }
    //Caso o for acabe sem nenhum return
    printf("Nenhum contato encontrado com esse nome...\n");
}

void saida(){
    exit(0);
}

int main(){
    struct agenda contato[4];
    char menu = '1';

    setlocale(LC_ALL, "Portuguese");
    while(menu != '8'){
        printf("Menu:\n");
        printf("\t1 - inserir contato\n");
        printf("\t2 - listar todos os contatos\n");
        printf("\t3 - pesquisar um contato pelo nome completo\n");
        printf("\t4 - listar os contatos cujo nome inicia com uma letra digitada\n");
        printf("\t5 - imprimir os aniversariantes do mês\n");
        printf("\t6 - altera contato pesquisando pelo nome completo\n");
        printf("\t7 - exclui contato pesquisando pelo nome completo\n");
        printf("\t8 - saída\n");
        printf("\nOpção desejada: ");
        scanf(" %c", &menu);
        getchar();
        //Menu com cada função de acordo com as opções escolhidas
        switch(menu){
            case '1':
                entradaContatos(contato);
                break;
            case '2':
                listarContatos(contato);
                break;
            case '3':
                pesquisaNome(contato);
                break;
            case '4':
                pesquisaLetra(contato);
                break;
            case '5':
                aniversarioMes(contato);
                break;
            case '6':
                alteraNome(contato);
                break;
            case '7':
                excluiNome(contato);
                break;
            case '8':
                saida();
                break;
            default:
                //Caso o input seja uma opção fora do menu
                printf("Opção inválida! Digite uma das opções do menu!\n");
        }
    }
}
#endif // ex002

#ifdef ex003

#endif // ex003

#ifdef ex004

#endif // ex004
