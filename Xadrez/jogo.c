#include <stdio.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

void moverTorreRecursivo(int casas) {
    if (casas > 0) {
        printf("Direita\n");
        moverTorreRecursivo(casas - 1);
    }
}

void moverBispoRecursivo(int casas) {
    if (casas > 0) {
        printf("Cima, Direita\n");
        moverBispoRecursivo(casas - 1);
    }
}

void moverRainhaRecursivo(int casas) {
    if (casas > 0) {
        printf("Esquerda\n");
        moverRainhaRecursivo(casas - 1);
    }
}

void moverCavaloRecursivo(int casasParaCima, int casasParaDireita) {
    if (casasParaCima > 0) {
        printf("Cima ");
        moverCavaloRecursivo(casasParaCima - 1, casasParaDireita);
    } else if (casasParaDireita > 0) {
        printf("Direita ");
        moverCavaloRecursivo(casasParaCima, casasParaDireita - 1);
    }
}

void moverCavalo(int casasParaCima, int casasParaDireita) {
    moverCavaloRecursivo(casasParaCima, casasParaDireita);
    printf("\n");
}

int main() {
    // Nível Novato - Movimentação das Peças - concluído

    // Nível Aventureiro - Movimentação do Cavalo - concluído
    
    // Nível Mestre - Funções Recursivas e Loops Aninhados - atual
    
    printf("Bem-vindo ao jogo de xadrez!\n");
    // Variavel para o usuário escolher a peça a mover
    char peca;
    // Constantes com o número de casas a mover para cada peça
    const int casasTorre = 5;
    const int casasBispo = 5;
    const int casasRainha = 8;
    const int casasCavaloParaCima = 2;
    const int casasCavaloParaDireita = 1;
    
    do {
        // Exibindo o menu para o usuário
        printf("Entre com a letra correspondente à peça que você deseja mover:\n");
        printf("T - Torre\n");
        printf("B - Bispo\n");
        printf("R - Rainha\n");
        printf("C - Cavalo\n");
        printf("F - Finalizar o jogo\n");
        // Lendo a opção
        scanf(" %c", &peca);

        // Verificando a opção escolhida
        switch (peca)
        {
            case 'T':
            case 't':
                moverTorreRecursivo(casasTorre);
                break;
            case 'B':
            case 'b':
                moverBispoRecursivo(casasBispo);
                break;
            case 'R':
            case 'r':
                moverRainhaRecursivo(casasRainha);
                break;
            case 'C':
            case 'c':
                moverCavalo(casasCavaloParaCima, casasCavaloParaDireita);
                break;
            case 'F':
            case 'f':
                printf("Finalizando o jogo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }

    } while (peca != 'F' && peca != 'f');

    printf("Jogo finalizado. Obrigado por jogar!\n");
        
    return 0;
}
