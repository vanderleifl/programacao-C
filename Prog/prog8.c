#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int opcao;
    int numeroSecreto, palpite;

    printf("Menu Principal:\n");
    printf("1. Iniciar Jogo\n");
    printf("2. Ver Regras\n");
    printf("3. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
        case 1:
            // Iniciar Jogo
            srand(time(0));
            numeroSecreto = rand() % 10 + 1; // Número aleatório entre 1 e 10
            printf("Adivinhe o número secreto (entre 1 e 10): ");
            scanf("%d", &palpite);

            if (palpite == numeroSecreto) {
                printf("Parabéns! Você acertou o número secreto!\n");
            } else {
                printf("Que pena! O número secreto era: %d\n", numeroSecreto);
            }
            break;
        case 2:
            // Ver Regras
            printf("Regras do Jogo:\n");
            printf("1. O computador irá gerar um número secreto entre 1 e 10.\n");
            printf("2. Você deve tentar adivinhar o número secreto.\n");
            printf("3. Se você acertar, ganha o jogo. Caso contrário, perde.\n");  
            break;
        case 3:
            // Sair
            printf("Saindo do jogo. Até a próxima!\n");
            break;    
        default:
            printf("Opção inválida. Por favor, escolha uma opção válida.\n");
            break;
    }

    return 0;
}