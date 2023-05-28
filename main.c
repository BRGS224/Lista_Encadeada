#include <stdlib.h>
#include "main.h"

int main(){
    FILE *fp;
    int op=-1;
    fp=fopen("NomeRG10.txt","r");
    Pessoa* cliente=inicializa_lista(fp);
    quick_sort(cliente, getUltimo(cliente));
    while (op!=0)
    {
        printf("Informe a sua opcao:\n");
        printf("1 - Inserir um cliente no inicio\n");
        printf("2 - Inserir um cliente no final da lista\n");
        printf("3 - Inserir um cliente na posicao desejada\n");
        printf("4 - Remover uma pessoa no inicio da lista\n");
        printf("5 - Remover uma pessoa no final da lista\n");
        printf("6 - Remover uma pessoa na posicao desejada\n");
        printf("7 - Procurar uma pessoa\n");
        printf("8 - Mostrar a lista na tela\n");
        printf("9 - Salvar a lista\n");
        printf("0 - Sair do Sistema\n");
        scanf("%d",&op);

        switch (op){
        case 0:{
            printf("Fim do programa  \n");
        }
            break;
        case 1:{
            inserir_inicio(&cliente);
        }
            break;
        case 2:{
            inserir_final(&cliente);
        }
            break;
        case 3:{
            inserir_N(&cliente);
        }
            break;
        case 4:{
            remover_inicio(&cliente);
        }
            break;
        case 5:{
            remover_fim(&cliente);
        }
            break;
        case 6:{
            remover_N(&cliente);
        }
            break;
        case 7:{
            procura_cliente(cliente);
        }
            break;
        case 8:{
            imprime_lista(cliente);
            
        }
            break;
        case 9:{
            salva_lista(cliente,"NomeRG10.txt");
        }
            break;
        default:
            break;
        }

    }
    free_lista(&cliente);
    return 0;
}
