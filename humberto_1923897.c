#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct para o carro
typedef struct carro{
    int ano;
    char cambio, modelo[50], marca[20];
    double preco;
}TCarro;

void insereCarro(TCarro *carro);


void main(){
    int key, i, n, carro_select, acao;
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
        printf("Ol�! Seja bem-vindo � concession�ria PG DRIFT RE42!\n\nSelecione quais das op��es abaixo deseja realizar: \n1 - Inserir Carro;\n 2 - Selecionar Carro;\n3 - Sair;\n");
        scanf("%d", &key);
        //Inserir o carro
        if(key == 1){
                printf("Quantos carros deseja inserir?\n");
                scanf("%d", &n);
                    for(i = 0; i < n; i++){
                        setbuf(stdin, NULL);
                        fflush(stdin);
                        printf("\nInsira o nome do modelo: ");
                        gets(carro[i].modelo);
                        printf("\nInsira a marca: ");
                        gets(carro[i].marca);
                        printf("\nAutom�tico ou manual (digite A para autom�tico, M para manual): ");
                        scanf("%c", &carro[i].cambio);
                        printf("\nAno: ");
                        scanf("%d", &carro[i].ano);
                        printf("\nPre�o: R$ ");
                        scanf("%lf", &carro[i].preco);
                        printf("\nCarro %s %s inserido com sucesso!\n",carro[i].marca, carro[i].modelo);
                    }

        }else if(key == 2){
            printf("Carros dispon�veis: \n");
                    for(i = 0; i < n; i++){
                        printf("\n%d -\nMarca: %s\nModelo: %s\nCambio: %c\nAno: %d\nPreco: R$ %.2f\n", i+1, carro[i].marca, carro[i].modelo, carro[i].cambio, carro[i].ano, carro[i].preco);
        }
        printf("\nSelecione o carro: ");
        scanf("%d", &carro_select);
        carro_select = carro_select -
        1;
        printf("\nDeseja: \n1 - Vender Carro;\n2 - Deletar carro;\n");
        scanf("%d", &acao);
        if(acao == 1){
            printf("\n%d -\nMarca: %s\nModelo: %s\nCambio: %c\nAno: %d\nPreco: R$ %.2f\n", i+1, carro[carro_select].marca, carro[carro_select].modelo, carro[carro_select].cambio, carro[carro_select].ano, carro[carro_select].preco);
            printf("\nDeseja proceder? S ou N ");
            scanf("%c", &proc);
            if(proc == 'S'){
                printf("\nCarro vendido!\n");
            }else if(proc == 'N'){
                printf("\nVoltando.\n");
            }
        }else if(acao == 2){
            printf("\nDeseja proceder? S ou N ");
            scanf("%c", &proc);
            if(proc == 'S'){
                printf("\nCarro deletado!\n");
            }else if(proc == 'N'){
                printf("\nVoltando.\n");
            }
        }
    }
}
}