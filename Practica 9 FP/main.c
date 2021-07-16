#include <stdio.h>
#include <stdlib.h>
void inicializar_matriz(int patio[50][20], float prob_p);
int tiene_vecino_riendose(int patio[50][20], int prob_r);
void actualizar_matriz(int patio[50][20], float prob_p, float prob_r);
void print(int patio[50][20]);
int lanza_moneda(float p);

int main(int argc, char *argv[])
{

    int patio[50][20], i = 0;
    float prob_p, prob_r;
    char salida;

    printf("EPIDEMIA DE RISA\n");

    // Entradas
    do
    {
        printf("Probabilidad P de empezar a reir? (Entre 0 y 1): ");
        scanf("%f", &prob_p);
        getchar();
    } while (prob_p > 1 || prob_p < 0);

    do
    {
        printf("Probabilidad R de contagio? (Entre 0 y 1): ");
        scanf("%f", &prob_r);
        getchar();
    } while (prob_r > 1 || prob_r < 0);
    //Inicialización
    printf("Situacion inicial: \n");
    inicializar_matriz(patio, prob_p);
    print(patio);

    printf("Presionar ENTER para empezar la simulacion.");
    getchar();

    //Iteraciones
    do
    {
        actualizar_matriz(patio, prob_p, prob_r);

        printf("\nMinuto %d: \n\n", ++i);
        print(patio);
        if (i % 2 == 0)
        { //minutos que se rien
            tiene_vecino_riendose(patio, prob_r);
        }
        printf("Presionar ENTER para continuar la simulacion. (q para salir)\n");
        salida = getchar();
    } while (salida != 'q');
}

int lanza_moneda(float p)
{
    return rand() <= p * RAND_MAX;
}

void inicializar_matriz(int patio[50][20], float prob_p)
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            if (lanza_moneda(prob_p) == 1)
            {
                patio[i][j] = '*';
            }
            else
            {
                patio[i][j] = ' ';
            }
        }
    }
}

void print(int patio[50][20])
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            printf("%c ", patio[i][j]);
        }
        printf("\n");
    }
}

int tiene_vecino_riendose(int patio[50][20], int prob_r)
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            if (patio[i + 1][i - 1] == '*' || patio[j + 1][j - 1] == '*')
            {
                if (lanza_moneda(prob_r) == 1)
                {
                    patio[i][j] = '.';
                }
            }
            if (patio[i][j] == '.')
            {
                patio[i][j] = ' ';
            }
            if (lanza_moneda(prob_r) == 1 && patio[i][j] != '.' && patio[i][j] == ' ')
            {
                patio[i][j] = '*';
            }
        }
    }
}

void actualizar_matriz(int patio[50][20], float prob_p, float prob_r)
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            if (patio[i + 1][i - 1] == '*' || patio[j + 1][j - 1] == '*')
            {
                if (lanza_moneda(prob_r) == 1)
                {
                    patio[i][j] = '.';
                }
            }
            if (patio[i][j] == '*')
            {
                patio[i][j] = '.';
            }
            if (lanza_moneda(prob_p) == 1 && patio[i][j] != '.' && patio[i][j] == ' ')
            { /* Si en ese hueco de la matriz hay una persona que ni se estña empezando a reir ni se está riendo, aplicamos la probabilidad de que empieze a reirse*/
                patio[i][j] = '*';
            }
        }
    }
}
