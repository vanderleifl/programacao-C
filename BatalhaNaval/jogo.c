#include <stdio.h>

void InicializarTabuleiro(int tabuleiro[10][10])
{
    // Isso funciona de forma diferente com arrays em C, se fosse uma variável comum,
    // só alimentaria localmente, mas arrays podem ser alimentados como parametros
    for (int l = 0; l < 10; l++)
    {
        for (int c = 0; c < 10; c++)
        {
            tabuleiro[l][c] = 0;
        }
    }
}

void MostrarTabuleiro(int tabuleiro[10][10])
{
    printf("\nC/L  1 2 3 4 5 6 7 8 9 10\n");
    for (int l = 0; l < 10; l++)
    {
        printf("\n%02d   ", l+1);
        for (int c = 0; c < 10; c++)
        {
            printf("%d ", tabuleiro[l][c]);
        }
    }
}

// Tenta inserir o navio no tabuleiro, se coincidir com uma coordenada já ocupada,
// retorna 0 (falha ao inserir)
int InserirNavioNoTabuleiro(int tabuleiro[10][10], int coord[2], int vertical)
{
    if (vertical)
    {
        for (int i = coord[0]; i < coord[0] + 3; i++)
        {
            if (tabuleiro[i][coord[1]] == 0)
            {
                tabuleiro[i][coord[1]] = 3;
            }
            else
            {
                // Este espaço já está ocupado
                return 0;
            }
        }
    }
    else
    {
        for (int i = coord[1]; i < coord[1] + 3; i++)
        {
            if (tabuleiro[coord[0]][i] == 0)
            {
                tabuleiro[coord[0]][i] = 3;
            }
            else
            {
                // Este espaço já está ocupado
                return 0;
            }
        }
    }
    return 1;
}

int ConferirCoordenadas(int coord[2], int vertical)
{
    int adicaoVertical, adicaoHorizontal;
    // Definindo valores para adicao à coordenada inicial x ou y conforme posicionamento do navio
    if (vertical)
    {
        adicaoVertical = 2;
        adicaoHorizontal = 0;
    }
    else
    {
        adicaoVertical = 0;
        adicaoHorizontal = 2;
    }
    // Verificação de limites
    if (coord[0]+adicaoVertical > 9 || coord[1]+adicaoHorizontal > 9 || coord[0] < 0 || coord[1] < 0)
    {
        // Se as coordenadas estiverem fora dos limites do tabuleiro, retorna falha (0)
        return 0;
    }
    return 1;
}

void AjustarCoordenadasParaIndiceZero(int coord[2])
{
    coord[0]--;
    coord[1]--;
}

int main() {
    // 1. Criar o tabuleiro 10x10 e inicializar todas as posições com o 
    //    valor que representa água (0)
    int tabuleiro[10][10];
    InicializarTabuleiro(tabuleiro);
    
    printf("\n\n--- Batalha Naval ---\n\n");
    
    // 2. Declarar os navios (2) que serão representados por vetores
    int navio1[3] = {3,3,3};
    int coordN1[2];
    int navio2[3] = {3,3,3};
    int coordN2[2];
        
    // O navio 1 deve ficar posicionado horizontalmente e o 2 verticalmente
    
    // Definindo coordenadas dos navios, onde 0 = linha e 1 = coluna
    // Navio 1
    coordN1[0] = 4;
    coordN1[1] = 2;
    // Navio 2
    coordN2[0] = 8;
    coordN2[1] = 3;

    // Como a matriz inicia do indice zero, ajustar as coordenadas para uso no tabuleiro
    AjustarCoordenadasParaIndiceZero(coordN1);
    AjustarCoordenadasParaIndiceZero(coordN2);
    
    // Validando as coordenadas dos navios
    if (!ConferirCoordenadas(coordN1, 0)) // 0 indica que vertical é false, ou seja, é horizontal
    {
        printf("\nAs coordenadas do navio 1 estão fora dos limites do tabuleiro!");
        return 1; // saindo com código de erro
    }
    if (!ConferirCoordenadas(coordN2, 1)) // 1 indica que vertical é true
    {
        printf("\nAs coordenadas do navio 2 estão fora dos limites do tabuleiro!");
        return 1; // saindo com código de erro
    }

    // Verificando se os navios não se sobrepõem e inserindo-os no tabuleiro
    if (!InserirNavioNoTabuleiro(tabuleiro, coordN1, 0)) // aqui o 0 indica que vertical é falso, ou seja, é horizontal
    {
        // Em teoria, por ser o primeiro navio a ser inserido, nunca vai entrar aqui,
        // mas para efeito de consistência, faremos a verificação em todos os navios
        printf("\nO navio 1 se sobrepõe a outro navio que já estava no tabuleiro!");
        return 1; // saindo com código de erro
    }
    if (!InserirNavioNoTabuleiro(tabuleiro, coordN2, 1)) // aqui o 1 indica que é vertical
    {
        printf("\nO navio 2 se sobrepõe a outro navio que já estava no tabuleiro!");
        return 1; // saindo com código de erro
    }    

    // 3. Mostrar o tabuleiro preenchido na tela
    MostrarTabuleiro(tabuleiro);
    
    printf("\n\n");

    return 0;
}