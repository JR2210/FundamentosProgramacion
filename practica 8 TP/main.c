#include <stdio.h>
#include <stdlib.h>


#define N 4
#define VACIA '-'

int leer_entero();
void leer_coordenada(int *fila, int *columna);
void leer_intro();
int coordenada_valida(int fila, int columna);
int tablero_vacio(const char tablero[][N], int fila, int columna);
int tablero_ocupado(const char tablero[][N], int fila, int columna,char ficha);
void poner_ficha(char tablero[][N], char ficha);
void mover_ficha(char tablero[][N], char ficha);
void iniciar_tablero(char tablero[N][N]);
void mostrar_tablero(const char tablero[][N]);
int hay_NenRaya(const char tablero[][N], char ficha);
int main()
{
    char tablero[N][N];
    char ficha_jugador[2] = {'X', 'O'};
    int turno = 0;
    int fichas_puestas = 0;
    int victoria = 0;

    iniciar_tablero(tablero);
    mostrar_tablero(tablero);

    do
    {
        if (fichas_puestas < 2 * N)
        {
            poner_ficha(tablero, ficha_jugador[turno]);
            fichas_puestas++;
        }
        else
        {
            mover_ficha(tablero, ficha_jugador[turno]);
        }
        victoria = hay_NenRaya(tablero, ficha_jugador[turno]);
        if (!victoria)
        {
            turno = (turno + 1) % 2;
        }
    }
    while (!victoria);

    printf("\n...........................................\n");
    printf("Victoria para las fichas %c\n", ficha_jugador[turno]);

    return 0;
}


int leer_entero() {
    int resultado;
    int entero;

    do {
        fflush(stdin);
        resultado = scanf("%d", &entero);
    } while (resultado <0);

    return entero;
}

void leer_coordenada(int *fila, int *columna) {
    printf("Introduzca la fila [1 - %d]: ", N);
    *fila = leer_entero();
    printf("Introduzca la columna [1 - %d]: ", N);
    *columna = leer_entero();
}

void leer_intro() {
    printf("<Pulse INTRO>: ");
    fflush(stdin);
    getchar();
}

int coordenada_valida(int fila, int columna) {
    return fila >= 1 && fila <= N && columna >=1 && columna <= N;
}

int tablero_vacio(const char tablero[][N], int fila, int columna) {
    return tablero[fila - 1][columna - 1] == VACIA;
}

int tablero_ocupado(const char tablero[][N], int fila, int columna, char ficha) {
    return tablero[fila - 1][columna - 1] == ficha;
}


void poner_ficha(char tablero[][N], char ficha) { //AQUI ESTA EL ERROR
    int fila, columna;
    int correcto = 1;

    printf("\n...........................................\n");
    printf("Le toca PONER al jugador con fichas %c\n\n", ficha);
    do {
        printf("Introduzca el destino de la ficha a poner\n");
        leer_coordenada(&fila, &columna);
        correcto = coordenada_valida(fila, columna);
        if (correcto!=1) {
            printf("La coordenada (%d, %d) no es valida ", fila, columna);
            leer_intro();
            mostrar_tablero(tablero);
        } else {
            correcto = tablero_vacio(tablero, fila, columna);
            if (!correcto) {
                printf("La coordenada (%d, %d) esta ocupada por otra ficha ", fila, columna);
                leer_intro();
                mostrar_tablero(tablero);
            }
        }
    } while (!correcto);

    tablero[fila - 1][columna - 1] = ficha;
    mostrar_tablero(tablero);
}

void mover_ficha(char tablero[][N], char ficha) {
    int fila_origen, columna_origen;
    int fila_destino, columna_destino;
    int correcto = 1;

    printf("\n...........................................\n");
    printf("Le toca MOVER al jugador con fichas %c\n\n", ficha);
    do {
        printf("Introduzca el origen de la ficha a mover\n");
        leer_coordenada(&fila_origen, &columna_origen);
        correcto  = coordenada_valida(fila_origen, columna_origen);
        if (!correcto) {
            printf("La coordenada (%d, %d) no es valida ", fila_origen, columna_origen);
            leer_intro();
            mostrar_tablero(tablero);

        } else {
            correcto = tablero_ocupado(tablero, fila_origen, columna_origen,ficha);
            if (!correcto) {
                printf("La coordenada (%d, %d) no esta ocupada por la ficha %c ", fila_origen, columna_origen, ficha);
                leer_intro();
                mostrar_tablero(tablero);

            }
        }
    } while (!correcto);

    do {
        printf("Introduzca el destino de la ficha a mover\n");
        leer_coordenada(&fila_destino, &columna_destino);
        correcto  = coordenada_valida(fila_destino, columna_destino);
        if (!correcto) {
            printf("La coordenada (%d, %d) no es valida ", fila_destino, columna_destino);
            leer_intro();
            mostrar_tablero(tablero);

        } else {
            correcto = tablero_vacio(tablero, fila_destino, columna_destino);
            if (!correcto) {
                printf("La coordenada (%d, %d) esta ocupada por otra ficha ", fila_destino, columna_destino);
                leer_intro();
                mostrar_tablero(tablero);
            }
        }
    } while (!correcto);

    tablero[fila_origen - 1][columna_origen - 1] = VACIA;
    tablero[fila_destino - 1][columna_destino - 1] = ficha;
    mostrar_tablero(tablero);
}
void iniciar_tablero(char tablero[N][N]){
    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < N ; j++)
        {
            tablero[i][j] = VACIA;
        }
    }
}
void mostrar_tablero(const char tablero[][N]){
    system("cls");
    printf("\n\t EL TABLERO ES: \n");
    for(int i=0;i<=N-1;i++){
            printf("             ");
        for(int j=0;j<=N-1;j++){
            printf("%c ",tablero[i][j]);
        }
        printf("\n");
    }
}
int hay_NenRaya(const char tablero[][N], char ficha)
{
    int i, j, contF = 0, contC = 0, contD = 0, contDi = 0, victoria = 0;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N - 1; j++)
        {
            if (tablero[i][j] == tablero[i][j + 1]) // FILAS
            {
                if (tablero[i][j] != VACIA)
                {
                    contF++;
                    if (contF == N - 1)
                    {
                        victoria = 1;
                    }
                }
            }
            else
            {
                contF = 0;
            }

            if (tablero[j][i] == tablero[j + 1][i]) // COLUMNAS
            {
                if(tablero [j][i] != VACIA)
                {
                    contC++;
                    if (contC == N - 1)
                    {
                        victoria = 1;
                    }
                }
            }
            else
            {
                contC = 0;
            }

            if (tablero[i][N - 1 - i] == tablero[i + 1][N - 2 - i]) // DIAGONAL INVERSA
            {
                if (tablero[i][N - i - 1] != VACIA)
                {
                    contDi++;
                    if (contDi == N - 1)
                    {
                        victoria = 1;
                    }

                }
            }
            else
            {
                contDi = 0;
            }

            if (tablero[j][j] == tablero[j + 1][j + 1]) // DIAGONAL 0 1 2
            {
                if (tablero[j][j] != VACIA)
                {
                    contD++;
                    if (contD == N - 1)
                    {
                        victoria = 1;
                    }
                }
            }
            else
            {
                contD = 0;
            }
        }
    }
    return victoria;
}

