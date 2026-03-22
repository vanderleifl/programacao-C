#include <stdio.h>

int main() {
    float temperatura, umidade;
    unsigned int estoque;
    printf("Digite a temperatura: ");
    scanf("%f", &temperatura);
    printf("Digite a umidade: ");
    scanf("%f", &umidade);
    printf("Digite o estoque disponível: ");
    scanf("%u", &estoque);

    return 0;
}