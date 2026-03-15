#include <stdio.h>
#include <string.h>

int main() {
    char nome[50];
    int idade;

    printf("\nDigite seu nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0; // Remove o caractere de nova linha
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    printf("\nOlá, %s! Você tem %d anos.\n\n", nome, idade);
    return 0;
}