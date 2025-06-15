#include <stdio.h>



int main()
{
    int index;

    char * nomesAlunos[3][3] = 
    {
        {"Aluno 1", "PT: 30", "MAT: 90"},
        {"Aluno 2", "PT: 60", "MAT: 60"},
        {"Aluno 3", "PT: 90", "MAT: 30"}
    };


    printf("0 - Aluno 1\n");
    printf("1 - Aluno 2\n");
    printf("2 - Aluno 3\n");
    printf("Digite o índice do aluno: ");
    scanf("%d", &index);


    switch (index)
    {
        case 0:
            printf("\nNome: %s\n", nomesAlunos[0][0]);
            printf("Nota de Português: %s\n", nomesAlunos[0][1]);
            printf("Nota de Matemática: %s\n", nomesAlunos[0][2]);
        break;


        case 1:
            printf("\nNome: %s\n", nomesAlunos[1][0]);
            printf("Nota de Português: %s\n", nomesAlunos[1][1]);
            printf("Nota de Matemática: %s\n", nomesAlunos[1][2]);
        break;


        case 2:
            printf("\nNome: %s\n", nomesAlunos[2][0]);
            printf("Nota de Português: %s\n", nomesAlunos[2][1]);
            printf("Nota de Matemática: %s\n", nomesAlunos[2][2]);
        break;


        default:
            printf("\nÍndice inválido!\n");
    }
}