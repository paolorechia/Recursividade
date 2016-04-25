#include <stdio.h>
#include <stdlib.h>

/* primeira versao
void imprime_matriz(int ** mat, int n, int m, int *aux){

    if (n == 0)
    {
        putchar('\n');
        return;
    }        
    if (m == 0)
    {
        m = *aux;
        mat++;
        putchar('\n');
        imprime_matriz(mat, n, m, aux); 
    }
    else{ 
        printf("%d ", mat[0][*aux-m]);
        imprime_matriz(mat, --n, --m, aux);
        }
}        
*/

/* impressao em linha
void imprime_matriz(int * mat, int n){
    if (n == 0)
        return;
    imprime_matriz(mat, --n);
    printf("%d ", *(mat+n));
}
*/

void imprime_matriz(int * mat, int n, int m){
    if (n == 0)
        return;
    imprime_matriz(mat, --n, m);
    if ((n % m) == 0)
        putchar('\n');
    printf("%d ", *(mat+n));
}



int soma_matriz(int ** mat, int n, int m, int *aux){

    if (n == 0)
        return 0;

    if (m != 0)
    {
        return mat[0][*aux-m] + soma_matriz(mat, --n, --m, aux);
    }
    else{
        m = *aux;
        return soma_matriz(++mat, n, m, aux);
    }
}



int maior_matriz(int ** mat, int n, int m, int * aux){
    if (n == 0)
        return -1000000;
    else
    {
        if (m == 0 )
        {
           m = * aux;
           mat++;
           maior_matriz(mat, --n, m, aux);
        }
        else
        {
           if (mat[0][*aux - m] > maior_matriz(mat, --n, --m, aux))
                return mat[0][*aux - m];
           else
                return maior_matriz(mat, --n, m, aux);
        }
    }    
}

int menor_matriz(int ** mat, int n, int m, int * aux){
    if (n == 0)
        return 1000000;
    else
    {
        if (m != 0 )
           if (mat[0][*aux-m] < menor_matriz(mat, --n, --m, aux))
                return mat[0][*aux-m];
           else
                return menor_matriz(mat, n, m, aux);
        else
           m = * aux;
           return menor_matriz(++mat, n, m, aux);
    }
}    




int main(int argc, char * argv[]){
     int ** matriz;
     int n, m, i, j, k; 
    if (argc < 2)
    {
        printf("Usage: %s [N] [M] [num1] [num2] ... [num(N*M)]\n", \
                argv[0]);
        return(EXIT_SUCCESS);
    }
   
    n = atoi(argv[1]);
    m = atoi(argv[2]); 
    if (argc != (n*m + 3))
    {
        printf("Usage: %s [N] [M] [num1] [num2] ... [num(N*M)]\n", \
                argv[0]);
        return(EXIT_SUCCESS);
    }

    matriz = (int ** )malloc(sizeof(int *) * n + ((sizeof(int) * m)*n));
    int *data = (int*) (matriz + n);
    printf("Matriz lida: \n");
    for (i=0; i<n; i++){
        matriz[i] = data + i * n;
    }
    k = 0;
    for (i=0; i<m; i++){
        for (j=0; j<n; j++){
            matriz[i][j]= atoi(argv[k+3]);
            k++;
        }
    }
    putchar('\n');
    for (i=0; i<m; i++){
        for (j=0; j<n; j++){
            printf("%d ", matriz[i][j]);
        }
        putchar('\n');
    
    }

    imprime_matriz(&matriz[0][0], n*m, n);
    putchar('\n');
    printf("Soma da matriz: %d \n", soma_matriz(matriz, n*m, n, &n));
//    imprime_matriz(matriz, n*m, n, &n);
    putchar('\n');

    printf("Maior da matriz: %d \n", maior_matriz(matriz, n*m, n, &n));

//    imprime_matriz(matriz, n*m, n, &n);
    putchar('\n');

    printf("Menor da matriz: %d \n", menor_matriz(matriz, n*m, n, &n));

//    imprime_matriz(matriz, n*m, n, &n);
    putchar('\n');
    return 0;
}
