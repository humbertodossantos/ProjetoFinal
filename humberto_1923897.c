//Humberto Correia Gomes dos Santos
//1923897
//O código abaixo tem como objetivo simular um sistema de concessionária de automóveis.
//Utiliza: vetor, arquivo, structs, estruturas de decisão e repetição, junto a ferramentas da linguagem C.
//A nota fiscal da compra encontra-se no mesmo diretório que o código em C.
//Não possui um arquivo executável.
//https://github.com/humbertodossantos/ProjetoFinal/blob/main/humberto_1923897.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct para o carro
typedef struct carro{
    int ano;
    char cambio, modelo[50], marca[20];
    double preco;
}TCarro;


void main(){
    int key, i, n, carro_select, acao, insert_check = 0;
    char proc;
    TCarro carro[100];
    FILE *arq;
    arq = fopen("humberto1923897_notafiscal_concessionaria_pg_drift_re42.txt", "w");
    //abertura do arquivo
    if (arq == NULL)
        {
          printf("Erro!");
        }
        else{
          fprintf(arq, "-----------------NOTA FISCAL - CONCESSIONARIA PG DRIFT RE42------------------------\n");
        }


    //menu principal
    while (key != 3){ 
        printf("\nOlá! Seja bem-vindo à concessionária PG DRIFT RE42!\n\nSelecione quais das opções abaixo deseja realizar: \n1 - Inserir Carro;\n 2 - Selecionar Carro;\n3 - Sair;\n");
        setbuf(stdin, NULL);
        fflush(stdin);
        scanf("%d", &key);
        //Inserir o carro
        if(key == 1){
            insert_check++;
            printf("\nA inserção só pode ser realizada uma vez.\nQuantos carros deseja inserir?\n");
            scanf("%d", &n);
                for(i = 0; i < n; i++){
                    setbuf(stdin, NULL);
                    fflush(stdin);
                    printf("\nInsira o nome do modelo: ");
                    gets(carro[i].modelo);
                    printf("\nInsira a marca: ");
                    gets(carro[i].marca);
                    printf("\nAutomático ou manual (digite A para automático, M para manual): ");
                    scanf("%c", &carro[i].cambio);
                    printf("\nAno: ");
                    scanf("%d", &carro[i].ano);
                    printf("\nPreço: R$ ");
                    scanf("%lf", &carro[i].preco);
                    printf("\nCarro %s %s inserido com sucesso!\n",carro[i].marca, carro[i].modelo);
                    setbuf(stdin, NULL);
                    fflush(stdin);
                }

        }else if(key == 2){
            if(insert_check == 0){
                printf("\nAinda não foi inserido nenhum carro. Volte ao Menu Inicial e insira!\n");
            }else{
            printf("Carros disponíveis: \n");
            for(i = 0; i < n; i++){
                printf("\n%d -\nMarca: %s\nModelo: %s\nCambio: %c\nAno: %d\nPreco: R$ %.2f\n", i+1, carro[i].marca, carro[i].modelo, carro[i].cambio, carro[i].ano, carro[i].preco);
            }
            printf("\nSelecione o carro: ");
            scanf("%d", &carro_select);
            carro_select = carro_select - 1;
            printf("\nDeseja: \n1 - Vender Carro;\n2 - Deletar carro;\n");
            setbuf(stdin, NULL);
            fflush(stdin);
            scanf("%d", &acao);
            if(acao == 1){
                printf("\n%d -\nMarca: %s\nModelo: %s\nCambio: %c\nAno: %d\nPreco: R$ %.2f\n", i+1, carro[carro_select].marca, carro[carro_select].modelo, carro[carro_select].cambio, carro[carro_select].ano, carro[carro_select].preco);
                printf("\nDeseja proceder? S ou N ");
                setbuf(stdin, NULL);
                fflush(stdin);
                scanf("%c", &proc);
                if(proc == 'S'){
                    printf("\nCarro vendido!\n");
                    insert_check--;
                    fprintf(arq, "\nMarca: %s\nModelo: %s\nCambio: %c\nAno: %d\nPreco: R$ %.2f\n", carro[carro_select].marca, carro[carro_select].modelo, carro[carro_select].cambio, carro[carro_select].ano, carro[carro_select].preco);
                    printf("\nObrigado! Para acessar a nota fiscal da sua compra, procure o arquivo texto com o nome \nhumberto1923897_notafiscal_concessionaria_pg_drift_re42.txt\n, no mesmo diretório onde se encontra o arquivo C.\n");
                }else if(proc == 'N'){
                    printf("\nVoltando.\n");
                }
            }else if(acao == 2){
                printf("\nDeseja proceder? S ou N ");
                setbuf(stdin, NULL);
                fflush(stdin);
                scanf("%c", &proc);
                if(proc == 'S'){
                    printf("\nCarro deletado!\n");
                    insert_check--;
                }else if(proc == 'N'){
                    printf("\nVoltando.\n");
                }
            }
        }
    
    }
}
}