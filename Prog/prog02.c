#include <stdio.h>

int main() {
    char nome[50];
    int idade;

    printf("Digite seu nome: ");
    scanf("%s", nome);
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    printf("\n\nOlá, %s! Você tem %d anos.\n", nome, idade);
    return 0;
}