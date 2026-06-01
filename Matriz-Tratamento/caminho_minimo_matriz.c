#include <stdio.h>

#define TAM 10
#define TAM2 100

int main()
{
    int i, j, k = 0;
    int i0 = 1, j0 = 1;
    int menor, menorI, menorJ;
    int soma = 0;
    int achou;

    int vetor[TAM2] = {0};
    int visitado[TAM][TAM] = {0};

    int matriz[10][10] = {  12, 16, 18, 77, 45, 65, 34, 11, 81, 90,
                            51, 5, 15, 88, 13, 33, 17, 9, 10, 54,
                            89, 1, 7, 23, 34, 15, 16, 18, 20, 19,
                            22, 6, 83, 25, 20, 14, 21, 18, 17, 18,
                            19, 3, 18, 8, 49, 6, 66, 8, 17, 22,
                            45, 33, 9, 17, 55, 80, 9, 5, 22, 31,
                            2, 45, 2, 3, 96, 14, 100, 4, 76, 54,
                            90, 85, 1, 99, 16, 3, 15, 3, 4, 25,
                            8, 44, 43, 20, 5, 7, 13, 44, 39, 112,
                            1, 23, 21, 32, 9, 31, 31, 2, 56, 2 };

    while (1)
    {
        visitado[i0][j0] = 1;

        vetor[k] = matriz[i0][j0];
        soma += matriz[i0][j0];
        k++;

        if (i0 == 0 || i0 == TAM - 1 || j0 == 0 || j0 == TAM - 1)
        {
            break;
        }

        menor = 99999;
        achou = 0;

        i = i0 - 1;
        j = j0;
        if (visitado[i][j] == 0 && matriz[i][j] < menor)
        {
            menor = matriz[i][j];
            menorI = i;
            menorJ = j;
            achou = 1;
        }

        i = i0 + 1;
        j = j0;
        if (visitado[i][j] == 0 && matriz[i][j] < menor)
        {
            menor = matriz[i][j];
            menorI = i;
            menorJ = j;
            achou = 1;
        }

        i = i0;
        j = j0 - 1;
        if (visitado[i][j] == 0 && matriz[i][j] < menor)
        {
            menor = matriz[i][j];
            menorI = i;
            menorJ = j;
            achou = 1;
        }

        i = i0;
        j = j0 + 1;
        if (visitado[i][j] == 0 && matriz[i][j] < menor)
        {
            menor = matriz[i][j];
            menorI = i;
            menorJ = j;
            achou = 1;
        }

        if (achou == 0)
        {
            break;
        }

        i0 = menorI;
        j0 = menorJ;
    }

    printf("Caminho:\n");

    for (i = 0; i < k; i++)
    {
        printf("%d ", vetor[i]);
    }

    printf("\n\nSomatorio: %d\n", soma);

    return 0;
}
