#include <stdio.h>

#define MAX_COLUMNAS 10
#define MAX_RESULTADO 100
void escribir(const int lista[], int num_elementos);
void copiar(int resultado[], const int lista[], int num_elementos);
int minimo(const int lista[],const int lista2[],int num_elementos2, int num_elementos);
void ordenar(int lista[], int num_elementos,int lista2[],int num_elementos2);
void mezclar(int resultado[], int *num_elementos_resultado,const int lista1[], int num_elementos1,const int lista2[], int num_elementos2);
void escribir_matriz(const int matriz[][MAX_COLUMNAS], int num_filas,const int num_columnas[]);
void mezclarN(int resultado[], int *num_elementos_resultado,const int matriz[][MAX_COLUMNAS], int num_filas,const int num_columnas[]);
void ordenar1(int lista[], int num_elementos);

int main() {
    int lista1[] = {4, -3, 6, 8, 5, 2, 7};
    const int num_elementos1 = 7;
    int lista2[] = {-4, 1, -1, -2, 3};
    const int num_elementos2 = 5;
    int min;
    int resultado[MAX_RESULTADO];
    int num_elementos_resultado;
    minimo(lista1,lista2,num_elementos2,num_elementos1);
    ordenar1(lista1,num_elementos1);

    int matriz[][MAX_COLUMNAS] = {
        { -1, 2, 3, -4},
        { 6, 5},
        { 8, -7, 9},
        { -10},
    };
    const int num_filas = 4;
    const int num_columnas[] = {4, 2, 3, 1};
}
void escribir(const int lista[], int num_elementos)
{
		int i;

		for (i = 0; i < num_elementos; i++) {
			printf("%d ", lista[i]);
		}
		printf("\n");
}
void copiar(int resultado[], const int lista[], int num_elementos)
{
		int i;

		for (i = 0; i < num_elementos; i++) {
			resultado[i] = lista[i];
		}
}
int minimo(const int lista[],const int lista2[],int num_elementos2, int num_elementos){
    int min=0,min2=0;
    printf("Lista1: \n");
    for(int i=0;i<=num_elementos-1;i++){
        printf("%d ",lista[i]);
        if(lista[i]<min){
            min=lista[i];
        }
    }
    printf("\nEl minimo es: %d\n",min);
    printf("\nLista2: \n");
    for(int i=0;i<=num_elementos2-1;i++){
        printf("%d ",lista2[i]);
        if(lista2[i]<min2){
            min2=lista2[i];
        }
    }
    printf("\nEl minimo es: %d\n",min2);
}
void ordenar(int lista[], int num_elementos,int lista2[],int num_elementos2) {
    int aux,i,x;
    for(i=0; i<num_elementos; i++) {
        for(x=i+1; x<num_elementos-1; x++) {
            if(lista[i]>lista[x]) {
                aux=lista[i];
                lista[i]=lista[x];
                lista[x]=aux;
            }
        }
    }
    printf("\nTras ordenar la lista1: \n");
    for(i=0; i<num_elementos; i++) {
        printf("%d ",lista[i]);
    }
    for(i=0; i<num_elementos2; i++) {
        for(x=i+1; x<num_elementos2-1; x++) {
            if(lista2[i]>lista2[x]) {
                aux=lista2[i];
                lista2[i]=lista2[x];
                lista2[x]=aux;
            }
        }
    }
    printf("\n\nTras ordenar la lista2: \n");
    for(i=0; i<num_elementos2; i++) {
        printf("%d ",lista2[i]);
    }
}
void ordenar1(int lista[], int num_elementos) {
    int p,min,lista1[7];
    for(int i=0; i<num_elementos; i++) {
        for(p=0; p<num_elementos; p++) {
            if(lista[p]<lista[p-1]) {
                if(lista[p]<min) {
                    min=lista[p];
                    break;
                }
            }
        }lista[p]=8;lista1[i]=min;
    }
    printf("\nLa lista ordenada es:");
    for(int j=0; j<7; j++) {
        printf("%d",lista1[j]);
    }
    for(int j=0; j<7; j++) {
        printf("%d",lista[j]);
    }

}










