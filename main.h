#include <stdio.h>
#include <string.h>
#include <time.h>
#define TAM_LINE 100

typedef struct pessoa{
    char nome[30];
    int id;
    struct pessoa* prox;
}Pessoa;

Pessoa* inicializa_lista(FILE *fp){
    int quant_pessoas=0;
    char line[TAM_LINE];
    Pessoa* inicio= NULL;
    Pessoa* fim= NULL;
    if(fp == NULL){
        printf("Erro ao abrir arquivo\n");
    }
    else{
        while (fgets(line, TAM_LINE, fp) != NULL) {
            quant_pessoas++;
        }
        rewind(fp);
        for(int i=0;i <quant_pessoas; i++){
            Pessoa* nova_pessoa=(Pessoa*)malloc(sizeof(Pessoa));
            fgets(line, TAM_LINE, fp);
            sscanf(line, "%[^,],%d", nova_pessoa->nome,&nova_pessoa->id);
            nova_pessoa->prox=NULL;
            if(inicio==NULL){
                inicio=nova_pessoa;
                fim=nova_pessoa;
            }
            else{
                fim->prox=nova_pessoa;
                fim=nova_pessoa;
            }
        }
        fclose(fp);
        return inicio;
    }
}

void inserir_inicio(Pessoa** inicio){
    int c=0,m=0;
    clock_t inicio_execucao, fim_execucao;
    double tempo_execucao;


    Pessoa* nova_pessoa=(Pessoa*)malloc(sizeof(Pessoa));
    printf("Insira os dados do cliente:\n");
    scanf("%s %d",nova_pessoa->nome,&nova_pessoa->id);
    inicio_execucao = clock();
    nova_pessoa->prox=*inicio;
    m++;
    *inicio=nova_pessoa;
    m++;
    printf("Nome: %s\n", nova_pessoa->nome);
    printf("RG: %d\n", nova_pessoa->id);
    printf("Cliente adicionado com sucesso!\n");


    fim_execucao = clock();
    tempo_execucao = (double)(fim_execucao - inicio_execucao) / CLOCKS_PER_SEC;
    printf("Tempo de execucao da funcao: %f segundos\n",tempo_execucao);
    printf("%d comparacoes\n",c);
    printf("%d copias\n",m);
}
void inserir_final(Pessoa** inicio){
    int c=0,m=0;
    clock_t inicio_execucao,fim_execucao;
    Pessoa* nova_pessoa=(Pessoa*)malloc(sizeof(Pessoa));
    printf("Insira os dados do cliente:\n");
    scanf("%s %d",nova_pessoa->nome,&nova_pessoa->id);
    nova_pessoa->prox=NULL;

    inicio_execucao = clock();
    c++;
    if (*inicio==NULL){
        *inicio=nova_pessoa;
    }
    else{
        c++;
        Pessoa* atual= *inicio;
        m++;
        while(atual->prox!=NULL){
            atual=atual->prox;
            c++;
        }
        atual->prox=nova_pessoa;
        m++;
    }
    fim_execucao = clock();
    double tempo_execucao = (double)(fim_execucao - inicio_execucao) / CLOCKS_PER_SEC;
    printf("Cliente adicionado com sucesso!\n");
    printf("Nome: %s\n", nova_pessoa->nome);
    printf("RG: %d\n", nova_pessoa->id);
    printf("Tempo de execucao: %lf segundos\n", tempo_execucao);
    printf("%d comparacoes\n",c);
    printf("%d copias\n",m);
}


void inserir_N(Pessoa** inicio){
    int posicao,c=0,m=0;
    clock_t inicio_execucao, fim_execucao;
    double tempo_execucao;
    printf("Insira a posicao desejada:\n");
    scanf("%d",&posicao);
    c++;
    if(posicao<0){
        printf("Posicao invalida\n");
        return;
    }
    Pessoa* nova_pessoa=(Pessoa*)malloc(sizeof(Pessoa));
    printf("Insira os dados do cliente:\n");
    scanf("%s %d",nova_pessoa->nome,&nova_pessoa->id);
    inicio_execucao=clock();
    nova_pessoa->prox=NULL;

    c++;
    if(posicao==0){
        nova_pessoa->prox=*inicio;
        *inicio= nova_pessoa;
        m++;
    }
    else{
        Pessoa* atual=*inicio;
        m++;
        int i=0;
        while(i<posicao-1 && atual!=NULL){
            atual=atual->prox;
            i++;
        }
        c++;
        if(atual==NULL && i<=posicao-1){
            printf("Posicao invalida\n");
            free(nova_pessoa);
            return;
        }
        nova_pessoa->prox=atual->prox;
        m++;
        atual->prox=nova_pessoa;
        m++;
    }
    fim_execucao = clock();
    tempo_execucao = (double)(fim_execucao - inicio_execucao) / CLOCKS_PER_SEC;

    printf("Cliente adicionado com sucesso!\n");
    printf("Nome: %s\n", nova_pessoa->nome);
    printf("ID: %d\n", nova_pessoa->id);
    printf("Tempo de execucao: %lf segundos\n", tempo_execucao);
    printf("%d comparacoes\n",c);
    printf("%d copias\n",m);
}

void remover_inicio(Pessoa** inicio){
    int c=0,m=0;
    clock_t inicio_execucao, fim_execucao;
    double tempo_execucao;
    inicio_execucao=clock();

    c++;
    if(*inicio== NULL){
        printf("A lista esta vazia\n");
        return;
    }
    Pessoa* no_removido= *inicio;
    m++;
    *inicio=(*inicio)->prox;
    m++;
    fim_execucao = clock();

    tempo_execucao = (double)(fim_execucao - inicio_execucao) / CLOCKS_PER_SEC;
    printf("Cliente removido com sucesso!\n");
    printf("Nome: %s\n", no_removido->nome);
    printf("RG: %d\n", no_removido->id);
    printf("Tempo de execucao: %f segundos\n", tempo_execucao);
    printf("%d comparacoes\n",c);
    printf("%d copias\n",m);
    free(no_removido);
}

void remover_fim(Pessoa** inicio){
    int c=0,m=0;
    clock_t inicio_execucao, fim_execucao;
    double tempo_execucao;
    inicio_execucao = clock();

    if(*inicio== NULL){
        printf("A lista esta vazia\n");
        return;
    }
    Pessoa* atual=*inicio;
    Pessoa* anterior= NULL;
    while(atual->prox!=NULL){
        anterior=atual;
        m++;
        atual=atual->prox;
        m++;
    }
    if(anterior!=NULL){
        anterior->prox=NULL;
    }
    else{
        *inicio=NULL;
    }
    printf("Nome: %s\n", atual->nome);
    printf("RG: %d\n", atual->id);
    printf("Cliente removido com sucessso!\n");
    fim_execucao = clock();

    tempo_execucao = ((double) (fim_execucao - inicio_execucao)) / CLOCKS_PER_SEC;
    printf("Tempo de execu��o: %f segundos\n", tempo_execucao);
    printf("%d comparacoes\n",c);
    printf("%d copias\n",m);
    free(atual);

}
void remover_N(Pessoa** inicio){
    int posicao, pos_atual=1, c=0,m=0;
    clock_t inicio_execucao, fim_execucao;
    double tempo_execucao;

    Pessoa* atual=*inicio;
    m++;
    Pessoa* anterior=NULL;
    printf("Insira a posicao para remover:\n");
    scanf("%d",&posicao);
    inicio_execucao=clock();
    c++;
    if(posicao<0){
        printf("Posicao invalida\n");
        return;
    }
    while(atual!=NULL && pos_atual!=posicao){
        anterior=atual;
        m++;
        atual=atual->prox;
        m++;
        pos_atual++;
    }
    c++;
    if(atual==NULL){
        printf("Posicao inv�lida\n");
        return;
    }
    if(anterior==NULL){
        *inicio=atual->prox;
        m++;
    }
    else{
        anterior->prox=atual->prox;
        m++;
    }
    fim_execucao=clock();
    printf("Cliente removido com sucesso: %s %d\n", atual->nome, atual->id);
    tempo_execucao = ((double) (fim_execucao - inicio_execucao)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %f segundos\n", tempo_execucao);
    printf("%d comparacoes\n",c);
    printf("%d copias\n",m);

    free(atual);
}


void procura_cliente(Pessoa *inicio){
    Pessoa* atual=inicio;
    int id,c=0,m=0 ;
    clock_t inicio_execucao, fim_execucao;
    double total_time;

    printf("Digite o RG a ser procurado:\n");
    scanf("%d",&id);

    inicio_execucao = clock();

    while(atual!=NULL){
        if(atual->id==id){
            printf("Cliente encontrado:\n");
            printf("Nome: %s\nRG: %d\n",atual->nome,atual->id);
            fim_execucao= clock();
            total_time = ((double) (fim_execucao - inicio_execucao)) / CLOCKS_PER_SEC;
            printf("Tempo de execucao: %.6lf segundos.\n", total_time);
            printf("%d comparacoes\n",c);
            printf("%d copias\n",m);
            return;
        }
        c++;
        atual=atual->prox;
    }
    printf("Cliente nao encontrado\n");
}



void imprime_lista(Pessoa* inicio){
    Pessoa* atual=inicio;
    while(atual!=NULL){
        printf("\n");
        printf("%s,\n%d",atual->nome,atual->id);
        printf("\n");
        atual=atual->prox;
    }
}

void salva_lista(Pessoa *inicio, char *arquivo) {
    FILE *fp = fopen(arquivo, "w");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }
    Pessoa *atual = inicio;
    while (atual != NULL) {
        fprintf(fp, "%s,%d\n", atual->nome, atual->id);
        atual = atual->prox;
    }
    fclose(fp);
    printf("Lista salva com sucesso!\n");
}


void free_lista(Pessoa** inicio){
    Pessoa* atual= *inicio;
    while (atual!=NULL){
        Pessoa* proximo= atual->prox;
        free(atual);
        atual=proximo;
    }
}

void troca_pessoas(Pessoa* pessoa1, Pessoa* pessoa2){
    Pessoa temp=*pessoa1;
    *pessoa1=*pessoa2;
    *pessoa2=temp;
}

void selection_sort(Pessoa* inicio){
    Pessoa* p1;
    Pessoa* p2;
    int id_menor;
    for(p1=inicio; p1!=NULL; p1=p1->prox){
        id_menor=p1->id;
        for(p2=p1->prox;p2!=NULL;p2=p2->prox){
            if(p2->id<id_menor){
                id_menor=p2->id;
                troca_pessoas(p1,p2);
            }
        }
    }
}

void insertion_sort(Pessoa *inicio){
    Pessoa *atual,*anterior,*temp;
    int id_atual;

    if(inicio==NULL || inicio->prox==NULL) // Lista vazia ou com apenas um elemento
        return;

    atual=inicio->prox;

    while(atual!=NULL){
        id_atual=atual->id;
        anterior=inicio;
        temp=atual->prox;

        while(anterior!=atual && anterior->id<=id_atual){
            anterior=anterior->prox;
        }
        if(anterior!=atual){ // Encontrou posição para inserir elemento
            atual->prox=anterior;
            anterior=inicio;

            while(anterior->prox !=atual){
                anterior=anterior->prox;
            }
            anterior->prox=temp;
        }
        else{ // Elemento já está na posição correta
            anterior=atual;
        }
        atual=anterior->prox;
    }
}

