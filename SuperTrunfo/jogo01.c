#include <stdio.h>

// Desafio Super Trunfo - Cidades
// Inserindo os dados de duas cidades e calculando a densidade populacional e o PIB per capita para cada cidade, além de exibir todas as informações.

int main() {
    char estadoCidade1, estadoCidade2;
    char codigoCidade1[3], codigoCidade2[3];
    char nomeCidade1[20], nomeCidade2[20];
    unsigned long int populacaoCidade1, populacaoCidade2;
    float areaCidade1, areaCidade2;
    float PIBCidade1, PIBCidade2;
    int pontosCidade1 = 0, pontosCidade2 = 0;
    float densidadePopulacionalCidade1, densidadePopulacionalCidade2;
    float pibPerCapitaCidade1, pibPerCapitaCidade2;
    unsigned long int superPoderCidade1, superPoderCidade2;

    // Leitura dos dados da Cidade 1
    printf("Digite o estado da Cidade 1 (Letra): ");
    scanf(" %c", &estadoCidade1);
    printf("Digite o código da Cidade 1 (3 caracteres): ");
    scanf("%s", codigoCidade1);
    printf("Digite o nome da Cidade 1: ");
    scanf("%s", nomeCidade1);
    printf("Digite a população da Cidade 1: ");
    scanf("%lu", &populacaoCidade1);
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
    scanf("%lu", &populacaoCidade2);
    printf("Digite a área da Cidade 2 (em km²): ");
    scanf("%f", &areaCidade2);
    printf("Digite o PIB da Cidade 2 (em bilhões): ");
    scanf("%f", &PIBCidade2);
    printf("Digite o número de pontos turísticos da Cidade 2: ");
    scanf("%d", &pontosCidade2);

    densidadePopulacionalCidade1 = (float) populacaoCidade1 / areaCidade1;
    densidadePopulacionalCidade2 = (float) populacaoCidade2 / areaCidade2;
    // Aqui multiplicamos o PIB por 1 bilhão (1000000000) para converter de bilhões para unidades monetárias antes de dividirmos pela população para obter o PIB per capita.
    pibPerCapitaCidade1 = (float) (PIBCidade1 * 1000000000) / populacaoCidade1;
    pibPerCapitaCidade2 = (float) (PIBCidade2 * 1000000000) / populacaoCidade2;
    // Para o super poder, vamos usar a soma da população, area, PIB per capita e pontos turísticos e o inverso da densidade populacional (1/densidade) para criar um valor único que representa a cidade.
    superPoderCidade1 = populacaoCidade1 + areaCidade1 + pibPerCapitaCidade1 + pontosCidade1 + (1.0f / densidadePopulacionalCidade1);
    superPoderCidade2 = populacaoCidade2 + areaCidade2 + pibPerCapitaCidade2 + pontosCidade2 + (1.0f / densidadePopulacionalCidade2);

    // Exibição dos dados da cidade 1
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estadoCidade1);
    printf("Código: %s\n", codigoCidade1);
    printf("Nome: %s\n", nomeCidade1);
    printf("População: %lu\n", populacaoCidade1);
    printf("Área: %.2f km²\n", areaCidade1);
    printf("PIB: %.2f bilhões\n", PIBCidade1);
    printf("Pontos turísticos: %d\n", pontosCidade1);
    printf("Densidade populacional: %.2f habitantes/km²\n", densidadePopulacionalCidade1);
    printf("PIB per capita: %.2f\n", pibPerCapitaCidade1);
    printf("Super Poder: %lu\n", superPoderCidade1);

    // Exibição dos dados da cidade 2
    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estadoCidade2);
    printf("Código: %s\n", codigoCidade2);
    printf("Nome: %s\n", nomeCidade2);
    printf("População: %lu\n", populacaoCidade2);
    printf("Área: %.2f km²\n", areaCidade2);
    printf("PIB: %.2f bilhões\n", PIBCidade2);
    printf("Pontos turísticos: %d\n", pontosCidade2);
    printf("Densidade populacional: %.2f habitantes/km²\n", densidadePopulacionalCidade2);
    printf("PIB per capita: %.2f\n", pibPerCapitaCidade2);
    printf("Super Poder: %lu\n", superPoderCidade2);

    // Comparação dos resultados
    printf("\nComparação das cartas:\n");
    printf("População: Carta 1 venceu (%d)\n", populacaoCidade1 > populacaoCidade2);
    printf("Área: Carta 1 venceu (%d)\n", areaCidade1 > areaCidade2);
    printf("PIB: Carta 1 venceu (%d)\n", PIBCidade1 > PIBCidade2);
    printf("Pontos turísticos: Carta 1 venceu (%d)\n", pontosCidade1 > pontosCidade2);
    printf("Densidade populacional: Carta 1 venceu (%d)\n", densidadePopulacionalCidade1 < densidadePopulacionalCidade2);
    printf("PIB per capita: Carta 1 venceu (%d)\n", pibPerCapitaCidade1 > pibPerCapitaCidade2);
    printf("Super Poder: Carta 1 venceu (%d)\n", superPoderCidade1 > superPoderCidade2);

    return 0;
}