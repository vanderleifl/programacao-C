#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int opcaoUsuario, opcaoComputador;

    printf("Menu Principal:\n");
    printf("1. Pedra\n");
    printf("2. Papel\n");
    printf("3. Tesoura\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcaoUsuario);

    // Gerar opção do computador
    srand(time(0));
    opcaoComputador = rand() % 3 + 1;

    // Exibir a escolha do computador
    printf("Computador escolheu: ");
    switch (opcaoComputador)
    {
        case 1:
            printf("Pedra\n");
            break;
        
        case 2:
            printf("Papel\n");
            break;
        
        case 3:
            printf("Tesoura\n");
            break;
    }
    
    // Determinar o vencedor
    if (opcaoUsuario < 1 || opcaoUsuario > 3) {
        printf("Opção inválida. Por favor, escolha uma opção entre 1 e 3.\n");
        return 1; // Encerra o programa com código de erro
    }   
    else if (opcaoUsuario == opcaoComputador) {
        printf("Empate!\n");
    } else if ((opcaoUsuario == 1 && opcaoComputador == 3) || 
               (opcaoUsuario == 2 && opcaoComputador == 1) || 
               (opcaoUsuario == 3 && opcaoComputador == 2)) {
        printf("Você venceu!\n");
    } else {
        printf("Computador venceu!\n");
    }

    return 0;
}