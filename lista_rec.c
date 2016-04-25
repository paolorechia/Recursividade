#include <stdio.h>
#include <stdlib.h>

typedef struct cel_struct{
    int chave;
    struct cel_struct * prox;
} tnodo;

void inicia_lista(tnodo * nodo, int new){
    nodo->chave=new;
    nodo->prox=NULL;
}

void imprime_lista(tnodo * nodo){
    printf("%d ", nodo->chave);
    if (nodo->prox==NULL)
    {
        putchar('\n');
        return; 
    }
    else
        imprime_lista(nodo->prox);
}

void imprime_inverso(tnodo *nodo){
    if (nodo->prox==NULL)
    {
        printf("%d ", nodo->chave);
        return;
    }
    else
    {
        imprime_inverso(nodo->prox);
        printf("%d ", nodo->chave);
    }
        
}

void insere_lista(tnodo * nodo, int new){
    if (nodo->prox!=NULL)
        insere_lista(nodo->prox, new);
    else
    {
        nodo->prox=malloc(sizeof(tnodo));
        nodo->prox->chave=new;
        nodo->prox->prox=NULL;
    }
    return;
}

void busca_lista(tnodo * nodo, int buscado){
    if (nodo->chave != buscado) 
        if (nodo->prox!=NULL)
            busca_lista(nodo->prox, buscado);
        else
        {
            puts("Elemento nao encontrado");
            return;
        }
    else
        puts("Elemento encontrado");
    return;
}

void remocao_lista(tnodo *nodo, int buscado, tnodo *ant){
    if (nodo->chave != buscado)
        if (nodo->prox != NULL)
            remocao_lista(nodo->prox, buscado, nodo);
        else
        {
            puts("Remocao impossivel, elemento nao encontrado");
            return;
        }
            
    else
    {
        printf("Removendo elemento %d...\n", nodo->chave);
        ant->prox=nodo->prox;
        free(nodo);
        return;
    }
    return;

}
    

int main(int argc, char * argv[])
{
    tnodo lista;
    tnodo aux;
    inicia_lista(&lista, 0);
    imprime_lista(&lista);
    insere_lista(&lista, 2);
    insere_lista(&lista, 3);
    insere_lista(&lista, 8);
    insere_lista(&lista, 10);
    imprime_lista(&lista);
    imprime_inverso(&lista);
    putchar('\n');
    busca_lista(&lista, 8);
    busca_lista(&lista, 7);
    remocao_lista(&lista, 8, &aux);
    imprime_lista(&lista);
    return 0;
}
