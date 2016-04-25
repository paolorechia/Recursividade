#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int aux;
    aux = *a;
    *a=*b;
    *b=aux;
    return;
}

void imprime_vetor(int * vet, int n){
    if (n == 0)
        return;
    else
    {
        printf("%d ", vet[0]);
        imprime_vetor(++vet, --n);
    }
}

int soma_vetor(int * vet, int n){
    if (n == 0)
        return 0;
    else
        return vet[0] + soma_vetor(++vet, --n);
}

int maior_vetor(int *vet, int n){
    if (n == 0)
        return -1000000;
    else
    {
        vet++;
        n--;
        if (vet[-1] > maior_vetor(vet, n))
           return vet[-1];
        else
           return maior_vetor(vet, n);
    }
}    

int menor_vetor(int *vet, int n){
    if (n == 0)
        return 1000000;
    else
    {
        vet++;
        n--;
        if (vet[-1] < menor_vetor(vet, n))
           return vet[-1];
        else return menor_vetor(vet, n);
    }
}    

int * busca_vetor(int *vet, int n, int chave){
    if (n==0)
        return vet;
    else
    {
       if (chave == vet[0])
           return vet;
       else
           busca_vetor(++vet, --n, chave);
    }
}

void selectsort(int *vet, int n){
    int * pter;
    int aux;
    if (n == 0)
        return;
    else
    {
        aux = (menor_vetor(vet,n));
        pter=busca_vetor(vet, n, aux);
        swap(&vet[0], pter); 
        selectsort(++vet, --n);
        return;
    }
}

void bubble_step(int *vet, int n){
    if (n == 0)
        return;
    else
    {
        if (vet[0] > vet[1])
            swap(&vet[0], &vet[1]);
        bubble_step(++vet, --n);
    }
}
void bubblesort_iterativo(int * vet, int n){
    int i;
    for (i=0; i<n;i++)
        bubble_step(vet, n-1);
    return;
}
void bubblesort(int * vet, int n, int i){
    if (i == 0)
        return;
    else
        {
        bubble_step(vet, n-1);
        i--;
        bubblesort(vet, n, i);
        }
    return;
}

void bubble_revs(int *vet, int n){
    if (n==0)
        return;
    else
    {
        if (vet[n] < vet[n-1])
            swap(&vet[n], &vet[n-1]);
        bubble_revs(vet, --n);
    }
}


/* algoritmo iterativo, repensar recursivamente
void insertion_sort(int *vet, int n, int i){
    int j; int item;
    bubble_revs(vet, n-1);
    for(i=2; i< n; i++){
    {
        j = i; item = vet[i];
        while (item < vet[j-1]){
            vet[j] = vet[j - 1];
            j--;
        }
        vet[j]=item;
    }
    }
}
*/

void desloca_e_insere(int *vet, int item, int j, int n)
{
    if (item < vet[j-1])
    {
        vet[j]=vet[j-1];
        desloca_e_insere(vet, item, --j, n);
    }
    else
        vet[j] = item;
}

void insertion_sort(int *vet, int n, int i){
    bubble_revs(vet, n-1);
    for(i=2; i< n; i++){
        desloca_e_insere(vet, vet[i], i, n);
    }
}

        
int main(int argc, char * argv[]){
     int * vetor;
     int * aux;
     int n, i; 
    if (argc < 2)
    {
        printf("Usage: %s [Tam_vetor] [num1] [num2] ... [numN]\n", \
                argv[0]);
        return(EXIT_SUCCESS);
    }
    
    n = atoi(argv[1]);
    if (argc != n + 2)
    {
        printf("Usage: %s [Tam_vetor] [num1] [num2] ... [numN]\n", \
                argv[0]);
        return(EXIT_SUCCESS);
    }

    vetor = (int * )malloc(sizeof(int) * n);
    
    printf("Vetor lido: ");
    for (i=0; i<n; i++){
        vetor[i]= atoi(argv[i+2]);
    }
    imprime_vetor(vetor, n);
    putchar('\n');
    printf("Soma do vetor: %d \n", soma_vetor(vetor, n));
    printf("Maior do vetor: %d \n", maior_vetor(vetor, n));
    printf("Menor do vetor: %d \n", menor_vetor(vetor, n));
//    puts("Select Sort:");
//    selectsort(vetor, n);
    imprime_vetor(vetor, n);
    putchar('\n');
    puts("Insertion Sort:");
    insertion_sort(vetor, n, i); 
    imprime_vetor(vetor, n);
    putchar('\n');

    return 0;
}
