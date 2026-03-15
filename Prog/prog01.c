#include <stdio.h>

int main() {
    char nome[40] = "Vanderlei Franke Liviz";
    int idade = 47;
    float altura = 1.75;

    printf("Nome: %s\n", nome);
    printf("Idade: %d\n", idade);
    printf("Altura: %e\n\n", altura);
    printf("%s tem %d anos e %.02f de altura.\n", nome, idade, altura);

    return 0;
}