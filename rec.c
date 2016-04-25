#include <stdio.h>
#include <stdlib.h>


// op elementares com recursao
int soma(int a, int b){
    return (a + b);
}

int mult(int a, int b){
    if (a == 1)
        return b;
    else
        return b + mult(a - 1, b);
}

int divi(int a, int b){
    if (a < b)
        return 0;
    else
        return 1 + divi(a-b, b);
}

int mod(int a, int b){
    if (a < b)
        return a;
    else
        mod(a-b,b);
}

// algoritmos recursivos simples
int fat(int n){
    if (n == 1)
        return 1;
    else
        return n*(fat(n-1));
}

int gcd(int m, int n){
    if ((m%n)==0)
        return n;
    else
        return gcd(n, m%n);
}

int log_2(int n){
    if (n == 1)
        return 1;
    else 
        return 1 + log_2(n>>1);
}
int pow_n(int x, int n){
    if (n == 1)
        return x;
    else
        return x * pow_n(x, n-1); 
}
        
    

// programa principal para testá-las

int main(int argc, char * argv[]){
    int x, y;
    if (argc != 3)
    {
        exit(EXIT_FAILURE);
    }
    x = atoi(argv[1]);
    y = atoi(argv[2]);
    printf("Soma = %d\n", soma(x,y));
    printf("Mult = %d\n", mult(x,y));
    printf("Divi = %d\n", divi(x,y));
    printf("Mod = %d\n", mod(x,y));
    printf("GCD = %d\n", gcd(x,y));
    printf("Fat = %d\n", fat(y));
    printf("Log2 = %d\n", log_2(y));
    printf("Pow_%d = %d\n", y, pow_n(x, y));
    
    return 0;
}
