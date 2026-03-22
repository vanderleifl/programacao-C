#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Jogo maior, menor ou igual
    int numeroJogador, numeroComputador, resultado;
    char tipoComparacao;

    // Gerar um número aleatório entre 1 e 100
    srand(time(0));
    numeroComputador = rand() % 100 + 1;

    // Inicio do jogo
    printf("Bem-vindo ao jogo Maior, Menor ou Igual!\n");
    printf("Você deve escolher um número entre 1 e 100 e o tipo de comparação.\n");
    printf("M. - Maior\n");
    printf("N. - Menor\n");
    printf("I. - Igual\n");
    scanf(" %c", &tipoComparacao);
    printf("Digite o número que você escolheu: ");
    scanf("%d", &numeroJogador);

    // Exibir o número do computador
    printf("O número do computador é: %d\n", numeroComputador);

    // Verificar o resultado do jogo
    switch (tipoComparacao)
    {
        case 'M':
        case 'm':
            if (numeroJogador > numeroComputador)
            {
                printf("Parabéns! Você ganhou!\n");
            }
            else
            {
                printf("Que pena! Você perdeu.\n");
            }
            break;
        case 'N':
        case 'n':
            if (numeroJogador < numeroComputador)
            {
                printf("Parabéns! Você ganhou!\n");
            }
            else
            {
                printf("Que pena! Você perdeu.\n");
            }
            break;
        case 'I':
        case 'i':
            if (numeroJogador == numeroComputador)
            {
                printf("Parabéns! Você ganhou!\n");
            }
            else
            {
                printf("Que pena! Você perdeu.\n");
            }
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }
    return 0;
}