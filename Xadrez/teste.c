#include <stdio.h>

void recursiveLoop(int n)
{
    if (n > 0) {
        printf("%d ", n);
        recursiveLoop(n - 1);
    }
}

int main() {
    int numero = 5;
    printf("Contagem regressiva: ");
    recursiveLoop(numero);
    
    return 0;
}