#include <stdio.h>

int main() {
    char estadoCidade1, estadoCidade2;
    char codigoCidade1[3], codigoCidade2[3];
    char nomeCidade1[20], nomeCidade2[20];
    int populacaoCidade1, populacaoCidade2;
    float areaCidade1, areaCidade2;
    float PIBCidade1, PIBCidade2;
    int pontosCidade1 = 0, pontosCidade2 = 0;

    // Leitura dos dados da Cidade 1
    printf("Digite o estado da Cidade 1 (Letra): ");
    scanf(" %c", &estadoCidade1);
    printf("Digite o código da Cidade 1 (3 caracteres): ");
    scanf("%s", codigoCidade1);
    printf("Digite o nome da Cidade 1: ");
    scanf("%s", nomeCidade1);
    printf("Digite a população da Cidade 1: ");
    scanf("%d", &populacaoCidade1);
    printf("Digite a área da Cidade 1 (em km²): ");
    scanf("%f", &areaCidade1);
    printf("Digite o PIB da Cidade 1 (em bilhões): ");
    scanf("%f", &PIBCidade1);
    printf("Digite o número de pontos turísticos da Cidade 1: ");
    scanf("%d", &pontosCidade1);

    // Leitura dos dados da Cidade 2
    printf("Digite o estado da Cidade 2 (Letra): ");
    scanf(" %c", &estadoCidade2);
    printf("Digite o código da Cidade 2 (3 caracteres): ");
    scanf("%s", codigoCidade2);
    printf("Digite o nome da Cidade 2: ");
    scanf("%s", nomeCidade2);
    printf("Digite a população da Cidade 2: ");
    scanf("%d", &populacaoCidade2);
    printf("Digite a área da Cidade 2 (em km²): ");
    scanf("%f", &areaCidade2);
    printf("Digite o PIB da Cidade 2 (em bilhões): ");
    scanf("%f", &PIBCidade2);
    printf("Digite o número de pontos turísticos da Cidade 2: ");
    scanf("%d", &pontosCidade2);

    // Exibição dos dados da cidade 1
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estadoCidade1);
    printf("Código: %s\n", codigoCidade1);
    printf("Nome: %s\n", nomeCidade1);
    printf("População: %d\n", populacaoCidade1);
    printf("Área: %.2f km²\n", areaCidade1);
    printf("PIB: %.2f bilhões\n", PIBCidade1);
    printf("Pontos turísticos: %d\n", pontosCidade1);

    // Exibição dos dados da cidade 2
    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estadoCidade2);
    printf("Código: %s\n", codigoCidade2);
    printf("Nome: %s\n", nomeCidade2);
    printf("População: %d\n", populacaoCidade2);
    printf("Área: %.2f km²\n", areaCidade2);
    printf("PIB: %.2f bilhões\n", PIBCidade2);
    printf("Pontos turísticos: %d\n", pontosCidade2);

    return 0;
}