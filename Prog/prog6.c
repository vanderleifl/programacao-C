#include <stdio.h>

int main() {
    // Declarar variáveis produto, estoque, valor, total, quantidade mínima
    char produtoA[30] = "Produto A";
    char produtoB[30] = "Produto B";

    unsigned int estoqueA = 1000;
    unsigned int estoqueB = 2000;

    float valorA = 10.50;
    float valorB = 20.40;

    unsigned int estoqueMinimoA = 500;
    unsigned int estoqueMinimoB = 2500;

    double totalA = estoqueA * valorA;
    double totalB = estoqueB * valorB;

    int resultadoA, resultadoB;

    // Exibir os dados dos produtos
    printf("Produto: %s\n", produtoA);
    printf("Estoque: %u\n", estoqueA);
    printf("Valor: R$ %.2f\n", valorA);
    printf("Total em estoque: R$ %.2f\n", totalA);
    printf("Estoque mínimo: %u\n", estoqueMinimoA);
    printf("\n");
    printf("Produto: %s\n", produtoB);
    printf("Estoque: %u\n", estoqueB);
    printf("Valor: R$ %.2f\n", valorB);
    printf("Total em estoque: R$ %.2f\n", totalB);
    printf("Estoque mínimo: %u\n", estoqueMinimoB);

    // Comparações com o valor mínimo de estoque
    resultadoA = estoqueA > estoqueMinimoA;
    resultadoB = estoqueB > estoqueMinimoB;

    printf("O produto %s tem estoque minimo? %d\n", produtoA, resultadoA);
    printf("O produto %s tem estoque minimo? %d\n", produtoB, resultadoB);

    // Comparação entre os valores totais dos produtos
    printf("O valor total de A é maior que o valor total de B? %d\n", totalA > totalB);
    return 0;
}