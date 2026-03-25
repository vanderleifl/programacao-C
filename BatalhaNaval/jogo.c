// Nível Mestre - Habilidades Especiais com Matrizes
// Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
// Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
// Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

// Exemplos de exibição das habilidades:
// Exemplo para habilidade em cone:
// 0 0 1 0 0
// 0 1 1 1 0
// 1 1 1 1 1
    
// Exemplo para habilidade em octaedro:
// 0 0 1 0 0
// 0 1 1 1 0
// 0 0 1 0 0

// Exemplo para habilidade em cruz:
// 0 0 1 0 0
// 1 1 1 1 1
// 0 0 1 0 0

#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10
#define HORIZONTAL 0
#define VERTICAL 1
#define DIAGONAL 3
#define DIAGONAL_SECUNDARIA 4
#define ALCANCE_HABILIDADE 5

void InicializarTabuleiro(int tabuleiro[LINHAS][COLUNAS])
{
    // Isso funciona de forma diferente com arrays em C, se fosse uma variável comum,
    // só alimentaria localmente, mas arrays podem ser alimentados como parametros
    for (int l = 0; l < LINHAS; l++)
    {
        for (int c = 0; c < COLUNAS; c++)
        {
            tabuleiro[l][c] = 0;
        }
    }
}

void MostrarTabuleiro(int tabuleiro[LINHAS][COLUNAS])
{
    // Preparando os títulos de colunas
    printf("\nC/L  ");
    for (int c = 0; c < COLUNAS; c++)
    {
        // Definindo letras, começando por A, para cada coluna
        // mas isso é apenas para o usuário. No nosso código,
        // identificaremos as colunas por números, assim como as linhas
        char col = 'A';
        printf("%c ", col+c);
    }
    // Separando os títulos do tabuleiro
    printf("\n");
    for (int l = 0; l < LINHAS; l++)
    {
        // Aqui inserimos numeração de linhas (títulos de linhas), com 2 dígitos sempre
        // para evitar diferença de tamanho quando o número de linhas for maior que 9
        printf("\n%02d   ", l+1);
        for (int c = 0; c < COLUNAS; c++)
        {
            printf("%d ", tabuleiro[l][c]);
        }
    }
}

// Tenta inserir o navio no tabuleiro, se coincidir com uma coordenada já ocupada,
// retorna 0 (falha ao inserir)
int InserirNavioNoTabuleiro(int tabuleiro[LINHAS][COLUNAS], int coord[2], int direcao)
{
    int linhaInicial = coord[0];
    int colunaInicial = coord[1];

    for (int i = 0; i < 3; i++)
    {
        int linha = linhaInicial;
        int coluna = colunaInicial;
        // Definindo os valores para linha e coluna, conforme a direção e o ponto atual do navio
        if (direcao == HORIZONTAL)
        {
            // Aqui a coluna aumenta e a linha permanece a mesma
            linha = linhaInicial;
            coluna = colunaInicial + i;
        }
        else if (direcao == VERTICAL)
        {
            // Aqui a linha aumenta e a coluna permanece a mesma
            linha = linhaInicial + i;
            coluna = colunaInicial;
        }
        else if (direcao == DIAGONAL)
        {
            // Aqui tanto linha quanto coluna aumentam
            linha = linhaInicial + i;
            coluna = colunaInicial + i;
        }
        else if (direcao == DIAGONAL_SECUNDARIA)
        {
            // Aqui linha aumenta, mas coluna diminui
            linha = linhaInicial + i;
            coluna = colunaInicial - i;
        }

        // Aqui verificamos se a posição atual está livre
        if (tabuleiro[linha][coluna] == 0)
        {
            tabuleiro[linha][coluna] = 3;
        }
        else
        {
            // Este espaço já está ocupado
            return 0; // Retorno equivalente a false
        }
    }
    return 1; // Retorno equivalente a true
}

int ConferirCoordenadas(int coord[2], int direcao)
{
    int adicaoVertical, adicaoHorizontal;
    // Definindo valores para adicao à coordenada inicial x ou y conforme posicionamento do navio
    if (direcao == VERTICAL)
    {
        adicaoVertical = 2;
        adicaoHorizontal = 0;
    }
    else if (direcao == HORIZONTAL)
    {
        adicaoVertical = 0;
        adicaoHorizontal = 2;
    }
    else if (direcao == DIAGONAL)
    {
        adicaoVertical = 2;
        adicaoHorizontal = 2;
    }
    else if (direcao == DIAGONAL_SECUNDARIA)
    {
        adicaoVertical = 2;
        adicaoHorizontal = -2;
    }
    // Verificação de limites
    if (coord[0]+adicaoVertical > LINHAS-1 || coord[1]+adicaoHorizontal > COLUNAS-1 || coord[0] < 0 || coord[1] < 0)
    {
        // Se as coordenadas estiverem fora dos limites do tabuleiro, retorna falha (0)
        return 0;
    }
    return 1;
}

void AjustarCoordenadasParaIndiceZero(int coord[2])
{
    // Isso é necessário porque para o usuário vamos usar número iniciando por 1,
    // mas para nossa programação, iniciaremos de 0, que é como funcionam os arrays
    coord[0]--;
    coord[1]--;
}

void PreencherCone(int cone[ALCANCE_HABILIDADE][ALCANCE_HABILIDADE])
{
    int meio = (ALCANCE_HABILIDADE / 2);
    
    for (int l = 0; l < ALCANCE_HABILIDADE; l++)
    {
        int ciH = meio - l;
        int cfH = meio + l; 
        for (int c = 0; c < ALCANCE_HABILIDADE; c++)
        {
            if (l >= 0 && l <= meio && c >= ciH && c <= cfH)
            {
                cone[l][c] = 1;
            }
            else
            {
                cone[l][c] = 0;
            }
        }
    }
}

void PreencherCruz(int cruz[ALCANCE_HABILIDADE][ALCANCE_HABILIDADE])
{
    int meio = (ALCANCE_HABILIDADE / 2);

    for (int l = 0; l < ALCANCE_HABILIDADE; l++)
    {
        for (int c = 0; c < ALCANCE_HABILIDADE; c++)
        {
            if (l == meio || c == meio)
            {
                cruz[l][c] = 1;
            }
            else
            {
                cruz[l][c] = 0;
            }
        }
    }
}

void PreencherOctaedro(int octaedro[ALCANCE_HABILIDADE][ALCANCE_HABILIDADE])
{
    int meio = (ALCANCE_HABILIDADE / 2);
    
    for (int l = 0; l < ALCANCE_HABILIDADE; l++)
    {
        int ciH = meio - l;
        int cfH = meio + l;
        if (l > meio)
        {
            ciH = l - meio;
            cfH = (ALCANCE_HABILIDADE - 1) - ciH;
        }
        for (int c = 0; c < ALCANCE_HABILIDADE; c++)
        {
            if (l >= 0 && c >= ciH && c <= cfH)
            {
                octaedro[l][c] = 1;
            }
            else
            {
                octaedro[l][c] = 0;
            }
        }
    }
}

void UsarHabilidade(int tabuleiro[LINHAS][COLUNAS], int habilidade[ALCANCE_HABILIDADE][ALCANCE_HABILIDADE], int coord[2])
{
    // Encontrando o meio da habilidade (sem considerar o resto da divisão)
    int meio = (ALCANCE_HABILIDADE / 2);

    if (meio < 0 || meio >= LINHAS || meio >= COLUNAS)
    {
        // Se o ponto central estiver fora do tabuleiro, a habilidade não será usada
        return;
    }

    // Encontrando as coordenadas do início da habilidade, a partir das coordenadas do meio
    int linhaInicial = coord[0] - meio;
    int colunaInicial = coord[1] - meio;

    // Fazendo a varredura da habilidade
    for (int lh = 0; lh < ALCANCE_HABILIDADE; lh++)
    {
        for (int ch = 0; ch < ALCANCE_HABILIDADE; ch++)
        {
            int valorH = habilidade[lh][ch];
            if (valorH)
            {
                // Se o valor encontrado for diferente de zero
                // vamos encontrar a coordenada correspondente no tabuleiro
                // e inserir o valor de ação da habilidade
                int linhaTabuleiro = linhaInicial + lh;
                int colunaTabuleiro = colunaInicial + ch;
                if (linhaTabuleiro >= 0 && colunaTabuleiro >= 0 && linhaTabuleiro < LINHAS && colunaTabuleiro < COLUNAS)
                {
                    // Apenas se a coordenada atual estiver dentro do tabuleiro
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = valorH;
                }
            }
        }
    }
}

int main() {
    // Criar o tabuleiro 10x10 e inicializar todas as posições com o 
    // valor que representa água (0)
    int tabuleiro[LINHAS][COLUNAS];
    InicializarTabuleiro(tabuleiro);
    
    printf("\n\n--- Batalha Naval ---\n\n");
    
    // Declarar os navios que serão representados por vetores de tamanho 3
    // e para cada navio, um vetor coordenadas com tamanho 2 para linha e coluna inicial
    int navio1[3] = {3,3,3}; // Horizontal
    int coordN1[2];
    int navio2[3] = {3,3,3}; // Vertical
    int coordN2[2];
    int navio3[3] = {3,3,3}; // Diagonal
    int coordN3[2];
    int navio4[3] = {3,3,3}; // Diagonal secundária
    int coordN4[2];
            
    // O navio 1 deve ficar posicionado horizontalmente e o 2 verticalmente
    // já o navio 3 e o 4 deverão ser posicionados na diagonal
    
    // Definindo coordenadas dos navios, onde os indices 0 = linha e 1 = coluna
    // Navio 1
    coordN1[0] = 5;
    coordN1[1] = 2;
    // Navio 2
    coordN2[0] = 8;
    coordN2[1] = 3;
    // Navio 3
    coordN3[0] = 1;
    coordN3[1] = 1;
    // Navio 4
    coordN4[0] = 6;
    coordN4[1] = 8;

    // Como a matriz inicia do indice zero, ajustar as coordenadas para uso no tabuleiro
    AjustarCoordenadasParaIndiceZero(coordN1);
    AjustarCoordenadasParaIndiceZero(coordN2);
    AjustarCoordenadasParaIndiceZero(coordN3);
    AjustarCoordenadasParaIndiceZero(coordN4);
    
    // Validando as coordenadas dos navios
    if (!ConferirCoordenadas(coordN1, HORIZONTAL))
    {
        printf("\nAs coordenadas do navio 1 estão fora dos limites do tabuleiro!");
        return 1; // saindo com código de erro
    }
    if (!ConferirCoordenadas(coordN2, VERTICAL))
    {
        printf("\nAs coordenadas do navio 2 estão fora dos limites do tabuleiro!");
        return 1; // saindo com código de erro
    }
    if (!ConferirCoordenadas(coordN3, DIAGONAL))
    {
        printf("\nAs coordenadas do navio 3 estão fora dos limites do tabuleiro!");
        return 1; // saindo com código de erro
    }
    if (!ConferirCoordenadas(coordN4, DIAGONAL_SECUNDARIA))
    {
        printf("\nAs coordenadas do navio 3 estão fora dos limites do tabuleiro!");
        return 1; // saindo com código de erro
    }

    // Verificando se os navios não se sobrepõem e inserindo-os no tabuleiro
    if (!InserirNavioNoTabuleiro(tabuleiro, coordN1, HORIZONTAL))
    {
        // Em teoria, por ser o primeiro navio a ser inserido, nunca vai entrar aqui,
        // mas para efeito de consistência, faremos a verificação em todos os navios
        printf("\nO navio 1 se sobrepõe a outro navio que já estava no tabuleiro!");
        return 1; // saindo com código de erro
    }
    if (!InserirNavioNoTabuleiro(tabuleiro, coordN2, VERTICAL))
    {
        printf("\nO navio 2 se sobrepõe a outro navio que já estava no tabuleiro!");
        return 1; // saindo com código de erro
    }
    if (!InserirNavioNoTabuleiro(tabuleiro, coordN3, DIAGONAL))
    {
        printf("\nO navio 3 se sobrepõe a outro navio que já estava no tabuleiro!");
        return 1; // saindo com código de erro
    }
    if (!InserirNavioNoTabuleiro(tabuleiro, coordN4, DIAGONAL_SECUNDARIA))
    {
        printf("\nO navio 4 se sobrepõe a outro navio que já estava no tabuleiro!");
        return 1; // saindo com código de erro
    }

    // Mostrar o tabuleiro preenchido na tela
    MostrarTabuleiro(tabuleiro);
    
    // Criar as matrizes de habilidades
    // aqui vou considerar o mesmo valor para horizonal e vertical (quadrado)
    int cone[ALCANCE_HABILIDADE][ALCANCE_HABILIDADE];
    int cruz[ALCANCE_HABILIDADE][ALCANCE_HABILIDADE];
    int octaedro[ALCANCE_HABILIDADE][ALCANCE_HABILIDADE];

    // Coordenadas para cada habilidade
    int coordCone[2];
    int coordCruz[2];
    int coordOctaedro[2];
    coordCone[0] = 3;
    coordCone[1] = 3;
    coordCruz[0] = 2;
    coordCruz[1] = 8;
    coordOctaedro[0] = 7;
    coordOctaedro[1] = 3;
    
    AjustarCoordenadasParaIndiceZero(coordCone);
    AjustarCoordenadasParaIndiceZero(coordCruz);
    AjustarCoordenadasParaIndiceZero(coordOctaedro);

    // Preencher as habilidades
    PreencherCone(cone);
    PreencherCruz(cruz);
    PreencherOctaedro(octaedro);

    char enter;
    printf("\nPressiona <enter> para usar o cone...");
    scanf("%c", &enter);

    UsarHabilidade(tabuleiro, cone, coordCone);
    MostrarTabuleiro(tabuleiro);

    printf("\nPressiona <enter> para usar a cruz...");
    scanf("%c", &enter);

    UsarHabilidade(tabuleiro, cruz, coordCruz);
    MostrarTabuleiro(tabuleiro);

    printf("\nPressiona <enter> para usar o octaedro...");
    scanf("%c", &enter);

    UsarHabilidade(tabuleiro, octaedro, coordOctaedro);
    MostrarTabuleiro(tabuleiro);

    printf("\n\n");

    return 0;
}