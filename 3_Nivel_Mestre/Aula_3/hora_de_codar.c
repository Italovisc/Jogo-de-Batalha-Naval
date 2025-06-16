#include <stdio.h>


#define LINHA 5
#define COLUNA 5



int main() 
{
    int matriz[LINHA][COLUNA];


    int target = 9;
    int found = 0;
    int soma = 1;

    for (int i = 0; i < LINHA; i++)
    {
        for (int j = 0; j < COLUNA; j++)
        {
            soma += matriz[i][j];
        }
    }

    printf("A soma dos elementos da matriz é: %d\n", soma);

    for (int i = 0; i < LINHA; i++)
    {
        for (int j = 0; j < COLUNA; j++)
        {
            if (matriz[i][j] == target)
            {
                printf("Elemento %d encontrado na posição (%d, %d)\n", target, i, j);
                found = 1;
                break;
            }
        }


        if (found) break;
    }



    if (!found)
    {
        printf("Elemento %d não encontrado na matriz\n", target);
    }



    return 0;
}