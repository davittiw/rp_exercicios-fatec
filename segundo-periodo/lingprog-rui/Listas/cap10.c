#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ex04

#ifdef ex01
int main()
{
 FILE *arquivo;
 char letra;
 char opMenu;

 do {
    arquivo = fopen("dados.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    printf("Digite caracteres um a um ou digite '0' para parar\n");
    
    do {
        printf("Letra: ");
        scanf(" %c", &letra);

        if(letra != '0') {
            fputc(letra, arquivo);
        }
    } while (letra != '0');

    fclose(arquivo);


    printf("Letrar armazenadas: ");

    arquivo = fopen("dados.txt", "r");

    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    } else {
        while((letra = fgetc(arquivo)) != EOF) {
            printf("%c ", letra);
        }
        printf("\n");
        fclose(arquivo);
    }

    printf("Deseja repetir o processo? (s/n): ");
    scanf(" %c", &opMenu);
 } while (opMenu == 's' || opMenu == 'S');
}
#endif //ex01


#ifdef ex02
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
    //Caso de erro e o arquivo nao abra
    if(arq == NULL){
        printf("ERRO! Arquivo nao foi aberto!");
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
    //Caso de erro e o arquivo nao abra
    if(arq == NULL){
        printf("ERRO! Arquivo nao foi aberto!\n");
    }
    //Escrita de todos as variaveis no arquivo
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
    //Input de todos os contatos do usuario
    for(cont=0; cont<4; cont++){
            printf("\nDigite o nome (%d/3): ", cont);
            scanf(" %19[^\n]", &(pcontato+cont)->nome);
            printf("\nDigite o telefone (modelo 00 99999-9999) (%d/3): ", cont);
            scanf(" %13[^\n]", &(pcontato+cont)->telefone);
            printf("\nDigite o anivers�rio (modelo DD) (%d/3): ", cont);
            scanf(" %2s", &(pcontato+cont)->aniversario_dia);
            printf("\nDigite o anivers�rio (modelo MM) (%d/3): ", cont);
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
        printf("\n\tAniversario(DD/MM)(%d/3): %s/%s\n", cont, (pcontato+cont)->aniversario_dia, (pcontato+cont)->aniversario_mes);
    }
}

void pesquisaNome(struct agenda *pcontato){
    int cont, cont2;
    char pesquisa[20];

    system("cls");
    //Input do nome para pesquisa
    printf("\nDigite o nome completo para pesquisar o contato: ");
    scanf(" %19[^\n]", pesquisa);

    //Garantindo que o programa ja tem os dados do arquivo
    leituraArquivo(pcontato);
    //Comparacao da variavel local pesquisa com a estrutura de dados
    for(cont=0; cont<4; cont++){
         cont2 = 0;
         while((pcontato+cont)->nome[cont2] != '\0' && pesquisa[cont2] != '\0'){
            if((pcontato+cont)->nome[cont2] == pesquisa[cont2]){
                //Caso o char em questao seja igual
                cont2++;
            } else{
                //Caso as strings nao sejam iguais
                break;
            }
        }
        //Caso as duas strings sejam de fato iguais
        if((pcontato+cont)->nome[cont2] == '\0' && pesquisa[cont2] == '\0'){
            printf("\tNome: %s", (pcontato+cont)->nome);
            printf("\n\tTelefone: %s", (pcontato+cont)->telefone);
            printf("\n\tAnivers�rio(DD/MM)): %s/%s\n", (pcontato+cont)->aniversario_dia, (pcontato+cont)->aniversario_mes);
            return;
        }
    }
    //Caso o for acabe sem nenhum return
    printf("Nenhum contato encontrado com esse nome...\n");
}

void pesquisaLetra(struct agenda *pcontato){
    int cont, check = 0; /*O check vai ser uma variavel para verificar se ha algum contato com a inicial ou nao*/
    char pesquisa;

    system("cls");
    //Garantindo que o programa ja tem os dados do arquivo
    leituraArquivo(pcontato);
    //Input da inicial que o usuario busca
    printf("Digite a primeira letra do(s) contato(s) que busca: ");
    scanf(" %c", &pesquisa);
    getchar();

    //Comparacao e output quando encontrado
    for(cont=0; cont<4; cont++){
        if(pesquisa == (pcontato+cont)->nome[0] || pesquisa - 32 == (pcontato+cont)->nome[0]){
            printf("\tNome: %s", (pcontato+cont)->nome);
            printf("\n\tTelefone: %s", (pcontato+cont)->telefone);
            printf("\n\tAnivers�rio(DD/MM): %s/%s\n", (pcontato+cont)->aniversario_dia, (pcontato+cont)->aniversario_mes);
            check++;
        }
    }
    //Caso o for acabe sem nenhum return
    if(check == 0)
        printf("Nenhum contato encontrado com essa inicial...\n");
}

void aniversarioMes(struct agenda *pcontato){
    int cont, cont2, check = 0; /*check vai ser uma variavel para verificar se tem algum aniversariante entre os vetores da estrutura de dados*/
    char pesquisa[3];

    system("cls");
    //Garantindo que o programa ja tem os dados do arquivo
    leituraArquivo(pcontato);
    //Input do m�s atual
    printf("\nDigite o mes atual(Modelo MM): ");
    scanf(" %2s", pesquisa);

    printf("\nAniversariante(s) do mes: \n");
    //Compara��o e output quando for encontrado os aniversariantes
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
            printf("\n\tAniversario(DD/MM): %s/%s\n", (pcontato+cont)->aniversario_dia, (pcontato+cont)->aniversario_mes);
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
    //Garantindo que o programa ja tem os dados do arquivo
    leituraArquivo(pcontato);
    //Input do nome que o usuario busca
    printf("\nDigite o nome que deseja alterar: ");
    scanf(" %19[^\n]", pesquisa);

    //Compara��o e processo de alteracao para quando o nome for encontrado
    for(cont=0; cont<4; cont++){
         cont2 = 0;
         while((pcontato+cont)->nome[cont2] != '\0' && pesquisa[cont2] != '\0'){
            if((pcontato+cont)->nome[cont2] == pesquisa[cont2]){
                //Caso o char em questao seja igual
                cont2++;
            } else{
                //Caso as strings nao sejam iguais
                break;
            }
        }
        //Caso as duas strings sejam de fato iguais, havera o input para remover o contato anterior
        if((pcontato+cont)->nome[cont2] == '\0' && pesquisa[cont2] == '\0'){
            printf("\nDigite o novo nome do contato: ");
            scanf(" %19[^\n]", &(pcontato+cont)->nome);
            printf("\nDigite o telefone: ");
            scanf(" %13[^\n]", &(pcontato+cont)->telefone);
            printf("\nDigite o dia do anivers�rio (DD): ");
            scanf(" %2s", &(pcontato+cont)->aniversario_dia);
            printf("\nDigite o m�s do anivers�rio (MM): ");
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
    //Garantindo que o programa ja tem os dados do arquivo
    leituraArquivo(pcontato);
    //Input do nome que o usuario busca
    printf("Digite o nome do contato que deseja excluir: ");
    scanf(" %19[^\n]", pesquisa);

    //Compara��o e exclus�o das strings para "(null)" se encontrado
    for(cont=0; cont<4; cont++){
    cont2 = 0;
        while(pesquisa[cont2] != '\0' && (pcontato+cont)->nome[cont2] != '\0'){
            if(pesquisa[cont2] == (pcontato+cont)->nome[cont2]){
                //Compara��o char por char da pesquisa com os contatos salvos
                cont2++;
            }else{
                //Caso os nomes n�o sejam os mesmos.
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
        printf("\t5 - imprimir os aniversariantes do m�s\n");
        printf("\t6 - altera contato pesquisando pelo nome completo\n");
        printf("\t7 - exclui contato pesquisando pelo nome completo\n");
        printf("\t8 - sa�da\n");
        printf("\nOp��o desejada: ");
        scanf(" %c", &menu);
        getchar();
        //Menu com cada fun��o de acordo com as op��es escolhidas
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
                //Caso o input seja uma op��o fora do menu
                printf("Op��o inv�lida! Digite uma das op��es do menu!\n");
        }
    }
}
#endif // ex02


#ifdef ex03
struct Cliente {
    char nome[50];
    char email[50];
    char celular[15];
    int ativo;
};

void incluir(struct Cliente *pCliente) {
    FILE *arq = fopen("clientes.dat", "ab");

    if (arq == NULL) {
        arq = fopen("clientes.dat", "wb");
    }

    printf("Novo Cadastro de Cliente\n");
    int c; while ((c = getchar()) != '\n' && c != EOF);

    printf("Nome: ");
    scanf(" %49[^\n]", pCliente->nome);
    getchar();

    printf("Email: ");
    scanf(" %49[^\n]", pCliente->email);
    getchar();

    printf("Celular: ");
    scanf(" %14[^\n]", pCliente->celular);

    pCliente->ativo = 1;

    fwrite(pCliente, sizeof(struct Cliente), 1, arq);

    fclose(arq);
    printf("Cliente cadastrado com sucesso!\n");
}

void listar(struct Cliente *pCliente) {
    FILE *arq = fopen("clientes.dat", "rb");

    if (arq == NULL) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    printf("Lista de Clientes:\n");
    while (fread(pCliente, sizeof(struct Cliente), 1, arq)) {
        if (pCliente->ativo) {
            printf("Nome: %s\n", pCliente->nome);
            printf("Email: %s\n", pCliente->email);
            printf("Celular: %s\n\n", pCliente->celular);
        }
    }

    fclose(arq);
}

void pesquisar(struct Cliente *pCliente) {
    FILE *arq = fopen("clientes.dat", "rb");

    char nomeBusca[50];
    int encontrado = 0;

    
    if (arq == NULL) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }
    
    int c; while ((c = getchar()) != '\n' && c != EOF);

    printf("Digite o nome do cliente para pesquisar: ");
    scanf(" %49[^\n]", nomeBusca);
    getchar();

    while (fread(pCliente, sizeof(struct Cliente), 1, arq)) {
        if (pCliente->ativo) {
            int i = 0, iguais = 1;
            while(pCliente->nome[i] != '\0' || nomeBusca[i] != '\0') {
                if (pCliente->nome[i] != nomeBusca[i]) {
                    iguais = 0;
                    break;
                }
                i++;
            }

            if(iguais) {
                printf("Cliente encontrado:\n");
                printf("Nome: %s\n", pCliente->nome);
                printf("Email: %s\n", pCliente->email);
                printf("Celular: %s\n", pCliente->celular);
                encontrado = 1;
                break;
            }
        }
    }

    if (!encontrado) {
        printf("Cliente nao encontrado.\n");
    }

    fclose(arq);
}

void alterar (struct Cliente *pCliente) {
    FILE *arq = fopen("clientes.dat", "r+b");

    char nomeBusca[50];
    int encontrado = 0;

    if (arq == NULL) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }
    
    int c; while ((c = getchar()) != '\n' && c != EOF);

    printf("Digite o nome do cliente para alterar: ");
    scanf(" %49[^\n]", nomeBusca);
    getchar();

    while (fread(pCliente, sizeof(struct Cliente), 1, arq)) {
        if (pCliente->ativo) {
            int i = 0, iguais = 1;
            while(pCliente->nome[i] != '\0' || nomeBusca[i] != '\0') {
                if (pCliente->nome[i] != nomeBusca[i]) {
                    iguais = 0;
                    break;
                }
                i++;
            }

            if(iguais) {
                printf("Alterando dados do cliente:\n");
                printf("Novo Email: ");
                scanf(" %49[^\n]", pCliente->email);
                getchar();

                printf("Novo Celular: ");
                scanf(" %14[^\n]", pCliente->celular);

                fseek(arq, -sizeof(struct Cliente), SEEK_CUR);
                fwrite(pCliente, sizeof(struct Cliente), 1, arq);
                encontrado = 1;
                printf("Dados alterados com sucesso!\n");
                break;
            }
        }
    }

    if (!encontrado) {
        printf("Cliente nao encontrado.\n");
    }

    fclose(arq);
}

void excluir(struct Cliente *pCliente) {
    FILE *arq = fopen("clientes.dat", "r+b");

    char nomeBusca[50];
    int encontrado = 0;

    if (arq == NULL) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }
    
    int c; while ((c = getchar()) != '\n' && c != EOF);

    printf("Digite o nome do cliente para excluir: ");
    scanf(" %49[^\n]", nomeBusca);
    getchar();

    while (fread(pCliente, sizeof(struct Cliente), 1, arq)) {
        if (pCliente->ativo) {
            int i = 0, iguais = 1;
            while(pCliente->nome[i] != '\0' || nomeBusca[i] != '\0') {
                if (pCliente->nome[i] != nomeBusca[i]) {
                    iguais = 0;
                    break;
                }
                i++;
            }

            if(iguais) {
                pCliente->ativo = 0;

                fseek(arq, -sizeof(struct Cliente), SEEK_CUR);
                fwrite(pCliente, sizeof(struct Cliente), 1, arq);
                encontrado = 1;
                printf("Cliente excluido com sucesso!\n");
                break;
            }
        }
    }

    if (!encontrado) {
        printf("Cliente nao encontrado.\n");
    }

    fclose(arq);
}

int main() {
    struct Cliente reg;

    int opcao;

    do {
        printf("Menu de Clientes:\n");
        printf("1. Incluir Cliente\n");
        printf("2. Listar Clientes\n");
        printf("3. Pesquisar Cliente\n");
        printf("4. Alterar Cliente\n");
        printf("5. Excluir Cliente\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1: incluir(&reg); break;
            case 2: listar(&reg); break;
            case 3: pesquisar(&reg); break;
            case 4: alterar(&reg); break;
            case 5: excluir(&reg); break;
            case 6: printf("Saindo do programa.\n"); break;
            default: printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 6);

    return 0;
}
#endif // ex03


#ifdef ex04
struct Produto {
    int codigo;
    char nome[50];
    int quantidade;
    int ativo;
}; 

void incluir(struct Produto *p) {
    FILE *arq = fopen("produtos.dat", "ab");

    if (arq == NULL) {
        arq = fopen("produtos.dat", "wb");
    }

    printf("Novo Cadastro de Produto\n");

    int c; while ((c = getchar()) != '\n' && c != EOF);

    printf("Codigo: ");
    scanf("%d", &p->codigo);

    printf("Nome: ");
    scanf(" %49[^\n]", p->nome);
    getchar();

    printf("Quantidade: ");
    scanf("%d", &p->quantidade);

    p->ativo = 1;

    fwrite(p, sizeof(struct Produto), 1, arq);

    fclose(arq);
    printf("Produto cadastrado com sucesso!\n");
}

void listar(struct Produto *p) {
    FILE *arq = fopen("produtos.dat", "rb");

    if (arq == NULL) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("Lista de Produtos:\n");
    while (fread(p, sizeof(struct Produto), 1, arq)) {
        if (p->ativo) {
            printf("Codigo: %d\n", p->codigo);
            printf("Nome: %s\n", p->nome);
            printf("Quantidade: %d\n\n", p->quantidade);
        }
    }

    fclose(arq);
}

void pesquisarDesc (struct Produto *p) {
    FILE *arq = fopen("produtos.dat", "rb");

    char nomeBusca[50];
    int encontrado = 0;
    
    if (arq == NULL) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    
    int c; while ((c = getchar()) != '\n' && c != EOF);

    printf("Digite o nome do produto para pesquisar: ");
    scanf(" %49[^\n]", nomeBusca);
    getchar();

    while (fread(p, sizeof(struct Produto), 1, arq)) {
        if (p->ativo) {
            int i = 0, iguais = 1;
            while(p->nome[i] != '\0' || nomeBusca[i] != '\0') {
                if (p->nome[i] != nomeBusca[i]) {
                    iguais = 0;
                    break;
                }
                i++;
            }

            if(iguais) {
                printf("Produto encontrado:\n");
                printf("Codigo: %d\n", p->codigo);
                printf("Nome: %s\n", p->nome);
                printf("Quantidade: %d\n", p->quantidade);
                encontrado = 1;
                break;
            }
        }
    }

    if (!encontrado) {
        printf("Produto nao encontrado.\n");
    }

    fclose(arq);
}

void listarIndis(struct Produto *p) {
    FILE *arq = fopen("produtos.dat", "rb");

    if (arq == NULL) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("Lista de Produtos Indisponiveis:\n");
    while (fread(p, sizeof(struct Produto), 1, arq)) {
        if (p->ativo == 0) {
            printf("Codigo: %d\n", p->codigo);
            printf("Nome: %s\n", p->nome);
            printf("Quantidade: %d\n\n", p->quantidade);
        }
    }

    fclose(arq);
}

void alterarQtd(struct Produto *p) {
    FILE *arq = fopen("produtos.dat", "r+b");

    int codigoBusca;
    int encontrado = 0;

    if (arq == NULL) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    
    int c; while ((c = getchar()) != '\n' && c != EOF);

    printf("Digite o codigo do produto para alterar a quantidade: ");
    scanf("%d", &codigoBusca);

    while (fread(p, sizeof(struct Produto), 1, arq)) {
        if (p->ativo) {
            if(p->codigo == codigoBusca) {
                printf("Alterando quantidade do produto:\n");

                printf("Nova Quantidade: ");
                scanf("%d", &p->quantidade);

                fseek(arq, -sizeof(struct Produto), SEEK_CUR);
                fwrite(p, sizeof(struct Produto), 1, arq);

                printf("Quantidade alterada com sucesso!\n");
                encontrado = 1;
                break;
            }
        }
    }

    if (!encontrado) {
        printf("Produto nao encontrado.\n");
    }

    fclose(arq);
}

void alterarProd(struct Produto *p) {
    FILE *arq = fopen("produtos.dat", "r+b");

    int codigoBusca;
    int encontrado = 0;

    if (arq == NULL) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    
    int c; while ((c = getchar()) != '\n' && c != EOF);

    printf("Digite o codigo do produto para alterar: ");
    scanf("%d", &codigoBusca);

    while (fread(p, sizeof(struct Produto), 1, arq)) {
        if (p->ativo) {
            if(p->codigo == codigoBusca) {
                printf("Alterando dados do produto:\n");

                printf("Novo Nome: ");
                scanf(" %49[^\n]", p->nome);
                getchar();

                printf("Nova Quantidade: ");
                scanf("%d", &p->quantidade);

                fseek(arq, -sizeof(struct Produto), SEEK_CUR);
                fwrite(p, sizeof(struct Produto), 1, arq);

                printf("Dados alterados com sucesso!\n");
                encontrado = 1;
                break;
            }
        }
    }

    if (!encontrado) {
        printf("Produto nao encontrado.\n");
    }

    fclose(arq);
}

void excluir (struct Produto *p) {
    FILE *arq = fopen("produtos.dat", "r+b");

    int codigoBusca;
    int encontrado = 0;

    if (arq == NULL) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    
    int c; while ((c = getchar()) != '\n' && c != EOF);

    printf("Digite o codigo do produto para excluir: ");
    scanf("%d", &codigoBusca);

    while (fread(p, sizeof(struct Produto), 1, arq)) {
        if (p->ativo) {
            if(p->codigo == codigoBusca) {
                p->ativo = 0;

                fseek(arq, -sizeof(struct Produto), SEEK_CUR);
                fwrite(p, sizeof(struct Produto), 1, arq);

                printf("Produto excluido com sucesso!\n");
                encontrado = 1;
                break;
            }
        }
    }

    if (!encontrado) {
        printf("Produto nao encontrado.\n");
    }

    fclose(arq);
}

int main() {
    struct Produto prod;

    int opcao;

    do {
        printf("Menu de Produtos:");
        printf("\t\n1. Incluir Produto\n2. Listar Produtos\n3. Pesquisar Produto por Descricao\n4. Listar Produtos Indisponiveis\n5. Alterar Quantidade do Produto\n6. Alterar Dados do Produto\n7. Excluir Produto\n8. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1: incluir(&prod); break;
            case 2: listar(&prod); break;
            case 3: pesquisarDesc(&prod); break;
            case 4: listarIndis(&prod); break;
            case 5: alterarQtd(&prod); break;
            case 6: alterarProd(&prod); break;
            case 7: excluir(&prod); break;
            case 8: printf("Saindo do programa.\n"); break;
            default: printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 8);

    return 0;
}
#endif // ex04
