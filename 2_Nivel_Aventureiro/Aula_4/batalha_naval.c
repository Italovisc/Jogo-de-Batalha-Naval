#include <stdio.h>


#define TAM_TABULEIRO 10
#define TAM_NAVIO 3



// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) 
{
    // Percorre todas as linhas e colunas, preenchendo com 0 (água)
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
    // Exibe cada linha do tabuleiro
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


    // Vetor representando as partes do navio (valor 3)
    int navio[TAM_NAVIO] = {3, 3, 3};


    // --- Coordenadas iniciais dos navios ---
    // Navio 1: horizontal
    int navio1_linha = 2, navio1_coluna = 4;


    // Navio 2: vertical
    int navio2_linha = 6, navio2_coluna = 1;


    // Navio 3: diagonal principal (linha e coluna aumentam)


    int navio3_linha = 0, navio3_coluna = 0;
    // Navio 4: diagonal secundária (linha aumenta, coluna diminui)


    int navio4_linha = 7, navio4_coluna = 2;



    // --- Validação e posicionamento dos navios ---
    // 1. Navio horizontal
    int pode_horizontal = 1;


    for (int i = 0; i < TAM_NAVIO; i++) 
    {
        int coluna = navio1_coluna + i;


        // Verifica se está dentro dos limites e se não há sobreposição
        if (coluna >= TAM_TABULEIRO || tabuleiro[navio1_linha][coluna] != 0) 
        {
            pode_horizontal = 0;
            break;
        }
    }



    if (pode_horizontal) 
    {
        for (int i = 0; i < TAM_NAVIO; i++) 
        {
            tabuleiro[navio1_linha][navio1_coluna + i] = navio[i];
        }
    } else {
        printf("Erro ao posicionar navio horizontal!\n");
        return 1;
    }



    // 2. Navio vertical
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



    if (pode_vertical) 
    {
        for (int i = 0; i < TAM_NAVIO; i++) 
        {
            tabuleiro[navio2_linha + i][navio2_coluna] = navio[i];
        }
    } else 
    {
        printf("Erro ao posicionar navio vertical!\n");
        return 1;
    }



    // 3. Navio diagonal principal (linha e coluna aumentam)
    int pode_diagonal_principal = 1;


    for (int i = 0; i < TAM_NAVIO; i++)
    {
        int linha = navio3_linha + i;
        int coluna = navio3_coluna + i;


        if (linha >= TAM_TABULEIRO || coluna >= TAM_TABULEIRO || tabuleiro[linha][coluna] != 0)
        {
            pode_diagonal_principal = 0;
            break;
        }
    }


    
    if (pode_diagonal_principal)
    {
        for (int i = 0; i < TAM_NAVIO; i++)
        {
            tabuleiro[navio3_linha + i][navio3_coluna + i] = navio[i];
        }
    }
    else
    {
        printf("Erro ao posicionar navio diagonal principal!\n");
        return 1;
    }



    // 4. Navio diagonal secundária (linha aumenta, coluna diminui)
    int pode_diagonal_secundaria = 1;


    for (int i = 0; i < TAM_NAVIO; i++)
    {
        int linha = navio4_linha + i;
        int coluna = navio4_coluna - i;


        if (linha >= TAM_TABULEIRO || coluna < 0 || tabuleiro[linha][coluna] != 0)
        {
            pode_diagonal_secundaria = 0;
            break;
        }
    }



    if (pode_diagonal_secundaria)
    {
        for (int i = 0; i < TAM_NAVIO; i++)
        {
            tabuleiro[navio4_linha + i][navio4_coluna - i] = navio[i];
        }
    }
    else
    {
        printf("Erro ao posicionar navio diagonal secundaria!\n");
        return 1;
    }



    // Exibe o tabuleiro final com todos os navios posicionados
    exibirTabuleiro(tabuleiro);


    
    return 0;
}