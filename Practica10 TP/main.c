#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 10
#define N 15
int rand_nay();
void inicializar(int matriz[M][N]);
void imprimir(int matriz[M][N]);
void rellenar(int matriz[M][N]);
void eliminar(int matriz[M][N]);
void eliminar_submatriz(int matriz[M][N]);
void contar(int matriz[M][N]);
int main(){ //declaración de vbles
    int matriz[M][N];
    srand(time(NULL));
    rellenar(matriz);
    imprimir(matriz);
    eliminar(matriz);
    eliminar_submatriz(matriz);
    contar(matriz);
}
//Poner aquí la implementación de todas las funciones
int rand_may() {
    return 65+ rand() % ((90 + 1) - 65);
}
void rellenar(int matriz[M][N]) {
    srand(time(NULL));
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            matriz[i][j]=rand_may();
        }
    }
}
void inicializar(int matriz[M][N]) {
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            matriz[i][j]=' ';
        }
    }
}
void imprimir(int matriz[M][N]) {
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            printf("%c ",matriz[i][j]);
        }
        printf("\n");
    }
}
void eliminar(int matriz[M][N]) {
    char c;
    printf("Escribe una letra que quieras eliminar de la matriz: ");
    scanf(" %c",&c);
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            if(matriz[i][j]==c) {
                matriz[i][j]=' ';
            }
        }
    }
    imprimir(matriz);
}
void eliminar_submatriz(int matriz[M][N]) {
    int x1,y1,x2,y2;
    printf("Escribe el límite inferior para las filas de la submatriz: ");
    scanf("%d",&x1);
    printf("Escribe el límite superior para las filas de la submatriz: ");
    scanf("%d",&x2);
    printf("Escribe el límite inferior para las columnas de la submatriz: ");
    scanf("%d",&y1);
    printf("Escribe el límite superior para las columnasde la submatriz: ");
    scanf("%d",&y2);
    rellenar(matriz);
    for(int i=x1; i<x2; i++) {
        for(int j=y1; j<y2; j++) {
            matriz[i][j]=' ';
        }
    }
    imprimir(matriz);
    printf("\n");
}
void contar(int matriz[M][N]) {
    char c,c1;
    int k=0;
    rellenar(matriz);
    imprimir(matriz);
    printf("Introduzca una letra Mayuscula: ");
    scanf(" %c",&c);
    printf("Introduzca una letra Mayuscula mayor a %c: ",c);
    scanf(" %c",&c1);
    printf("%c %c",c,c1);
    for(int i=0; i<M; i++) {
    for(int j=0; j<N; j++) {
            if(matriz[i][j]==c||matriz[i][j]==c
              ) {
                k++;
            } else {
                matriz[i][j]=' ';
            }
        }
    }
    imprimir(matriz);
    printf("\nEn la matriz hay %d caracteres %c y %c ",k,c,c1);
}
