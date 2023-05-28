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

void selection_sort(Pessoa* inicio) {
    if (inicio == NULL || inicio->prox == NULL) {
        return; // Lista vazia ou com apenas um elemento, retorna sem alterações
    }

    Pessoa* p1;
    Pessoa* p2;
    int id_menor;
    
    for (p1 = inicio; p1 != NULL; p1 = p1->prox) {
        id_menor = p1->id;

        for (p2 = p1->prox; p2 != NULL; p2 = p2->prox) {
            if (p2->id < id_menor) {
                id_menor = p2->id;

                // Troca os valores dos campos nome e id
                int temp_id = p1->id;
                p1->id = p2->id;
                p2->id = temp_id;

                char temp_nome[30];
                strcpy(temp_nome, p1->nome);
                strcpy(p1->nome, p2->nome);
                strcpy(p2->nome, temp_nome);
            }
        }
    }
}

void insertion_sort(Pessoa** inicio) {
    if (*inicio == NULL || (*inicio)->prox == NULL) {
        return; // Lista vazia ou com apenas um elemento, retorna sem alterações
    }

    Pessoa* atual = (*inicio)->prox;
    Pessoa* anterior = *inicio;

    while (atual != NULL) {
        Pessoa* chave = atual;
        int chave_id = chave->id;
        char chave_nome[30];
        strcpy(chave_nome, chave->nome);

        while (anterior != NULL && anterior->id > chave_id) {
            anterior->prox->id = anterior->id;
            strcpy(anterior->prox->nome, anterior->nome);

            anterior = anterior->prox;
        }

        if (anterior != chave) {
            anterior->id = chave_id;
            strcpy(anterior->nome, chave_nome);
        }

        atual = atual->prox;
        anterior = *inicio;
    }
}

void bubble_sort(Pessoa** inicio) {
    if (*inicio == NULL || (*inicio)->prox == NULL) {
        return; // Lista vazia ou com apenas um elemento, retorna sem alterações
    }

    int trocado;
    Pessoa* atual;
    Pessoa* anterior = NULL;

    do {
        trocado = 0;
        atual = *inicio;

        while (atual->prox != anterior) {
            if (atual->id > atual->prox->id) {
                // Troca os elementos
                int temp_id = atual->id;
                char temp_nome[30];
                strcpy(temp_nome, atual->nome);

                atual->id = atual->prox->id;
                strcpy(atual->nome, atual->prox->nome);

                atual->prox->id = temp_id;
                strcpy(atual->prox->nome, temp_nome);

                trocado = 1;
            }

            atual = atual->prox;
        }

        anterior = atual;

    } while (trocado);
}

// Função auxiliar para obter o elemento em determinada posição na lista encadeada
Pessoa* getNthElement(Pessoa* inicio, int pos) {
    Pessoa* temp = inicio;
    for (int i = 0; i < pos; i++) {
        if (temp == NULL) {
            return NULL; // Posição inválida
        }
        temp = temp->prox;
    }
    return temp;
}

void shell_sort(Pessoa* inicio) {
    int n = 0;
    Pessoa* temp = inicio;
    
    // Contar o número de elementos na lista
    while (temp != NULL) {
        n++;
        temp = temp->prox;
    }
    
    // Definir os intervalos de comparação
    int intervalo = n / 2;
    while (intervalo > 0) {
        for (int i = intervalo; i < n; i++) {
            Pessoa* atual = getNthElement(inicio, i);
            int atualId = atual->id;
            int j = i;
            
            // Realizar inserção por comparação
            while (j >= intervalo && getNthElement(inicio, j - intervalo)->id > atualId) {
                Pessoa* elementoAnterior = getNthElement(inicio, j - intervalo);
                Pessoa* elementoAtual = getNthElement(inicio, j);
                
                // Realizar troca de elementos
                elementoAtual->id = elementoAnterior->id;
                strcpy(elementoAtual->nome, elementoAnterior->nome);
                
                j -= intervalo;
            }
            
            Pessoa* elementoAtual = getNthElement(inicio, j);
            elementoAtual->id = atualId;
            strcpy(elementoAtual->nome, atual->nome);
        }
        
        intervalo /= 2;
    }
}

Pessoa* partition(Pessoa* inicio, Pessoa* fim, Pessoa** novoInicio, Pessoa** novoFim) {
    Pessoa* pivo = fim;
    Pessoa* i = NULL;
    Pessoa* j = inicio;
    Pessoa* anterior = NULL;
    
    // Realizar partição
    while (j != pivo) {
        if (j->id < pivo->id) {
            if (i == NULL) {
                i = inicio;
            } else {
                i = i->prox;
            }
            
            // Realizar troca de elementos
            int tempId = i->id;
            i->id = j->id;
            j->id = tempId;
            
            char tempNome[30];
            strcpy(tempNome, i->nome);
            strcpy(i->nome, j->nome);
            strcpy(j->nome, tempNome);
        }
        anterior = j;
        j = j->prox;
    }
    
    // Realizar troca do elemento pivô
    if (i == NULL) {
        i = inicio;
    } else {
        i = i->prox;
    }
    
    int tempId = i->id;
    i->id = pivo->id;
    pivo->id = tempId;
    
    char tempNome[30];
    strcpy(tempNome, i->nome);
    strcpy(i->nome, pivo->nome);
    strcpy(pivo->nome, tempNome);
    
    // Atualizar os ponteiros de início e fim da partição
    *novoInicio = inicio;
    *novoFim = i;
    
    return i;
}

// Função auxiliar para obter o último elemento da lista encadeada
Pessoa* getUltimo(Pessoa* inicio) {
    Pessoa* temp = inicio;
    while (temp->prox != NULL) {
        temp = temp->prox;
    }
    return temp;
}

void quick_sort(Pessoa* inicio, Pessoa* fim) {
    if (inicio != fim && inicio != NULL && fim != NULL) {
        Pessoa* novoInicio = NULL;
        Pessoa* novoFim = NULL;
        
        // Realizar partição e ordenar as partições recursivamente
        Pessoa* pivo = partition(inicio, fim, &novoInicio, &novoFim);
        if (novoInicio != pivo) {
            Pessoa* anterior = novoInicio;
            while (anterior->prox != pivo) {
                anterior = anterior->prox;
            }
            anterior->prox = NULL;
            quick_sort(novoInicio, anterior);
            anterior = getUltimo(novoInicio);
            anterior->prox = pivo;
        }
        if (novoFim != pivo->prox) {
            pivo->prox = NULL;
            quick_sort(pivo->prox, novoFim);
            pivo->prox = novoFim;
        }
    }
}


