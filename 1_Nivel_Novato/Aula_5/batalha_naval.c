#include <stdio.h>



#define TAM_TABULEIRO 10
#define TAM_NAVIO 3



// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) 
{
    for (int i = 0; i < TAM_TABULEIRO; i++) 
    {
        for (int j = 0; j < TAM_TABULEIRO; j++) 
        {
            tabuleiro[i][j] = 0;
        }
    }
}



// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) 
{
    printf("Tabuleiro Batalha Naval:\n\n");


    for (int i = 0; i < TAM_TABULEIRO; i++) 
    {
        for (int j = 0; j < TAM_TABULEIRO; j++) 
        {
            printf("%d ", tabuleiro[i][j]);
        }


        printf("\n");
    }
}



int main() 
{
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];


    // Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);


    // Vetores para representar os navios (cada posição vale 3)
    int navio_horizontal[TAM_NAVIO] = {3, 3, 3};
    int navio_vertical[TAM_NAVIO] = {3, 3, 3};


    // Coordenadas iniciais dos navios (definidas diretamente)
    int navio1_linha = 2, navio1_coluna = 4; // Navio horizontal
    int navio2_linha = 6, navio2_coluna = 1; // Navio vertical


    // Validação para o navio horizontal
    int pode_horizontal = 1;


    for (int i = 0; i < TAM_NAVIO; i++) 
    {
        int coluna = navio1_coluna + i;


        if (coluna >= TAM_TABULEIRO || tabuleiro[navio1_linha][coluna] != 0) 
        {
            pode_horizontal = 0;
            break;
        }
    }



    // Validação para o navio vertical
    int pode_vertical = 1;


    for (int i = 0; i < TAM_NAVIO; i++) 
    {
        int linha = navio2_linha + i;


        if (linha >= TAM_TABULEIRO || tabuleiro[linha][navio2_coluna] != 0) 
        {
            pode_vertical = 0;
            break;
        }
    }



    // Posiciona o navio horizontal se possível
    if (pode_horizontal) 
    {
        for (int i = 0; i < TAM_NAVIO; i++) 
        {
            tabuleiro[navio1_linha][navio1_coluna + i] = navio_horizontal[i];
        }
    } else {
        printf("Erro ao posicionar navio horizontal!\n");
        return 1;
    }



    // Posiciona o navio vertical se possível
    if (pode_vertical) 
    {
        for (int i = 0; i < TAM_NAVIO; i++) 
        {
            tabuleiro[navio2_linha + i][navio2_coluna] = navio_vertical[i];
        }
    } else 
    {
        printf("Erro ao posicionar navio vertical!\n");


        return 1;
    }



    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);


    
    return 0;
}