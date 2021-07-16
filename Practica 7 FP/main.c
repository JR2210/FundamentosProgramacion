#include <stdio.h>
#include <stdlib.h>
void escribir(const int lista[], int num_elementos);
int posicion(const int lista[], int num_elementos, int elemento);
void invertir(int lista[], int num_elementos);
void rotarN(int lista[], int num_elementos, int posiciones);
void rotar(int lista[], int num_elementos);
int main()
{
		int lista[10] = {1,-2,3,4,-5,-6,7};
		int num_elementos = 7;
		escribir(lista, num_elementos);

        printf("\nEl elemento %d esta en la posicion %d de lista\n", -2,posicion(lista, num_elementos, -2));
        printf("El elemento %d esta en la posicion %d de lista\n", 7,posicion(lista, num_elementos, 7));
        printf("El elemento %d esta en la posicion %d de lista\n", 2,posicion(lista, num_elementos, 2));

        printf("Tras invertir la lista:\n");
		invertir(lista, num_elementos);

        printf("\nTras rotar la lista:\n");
		rotar(lista, num_elementos);

        printf("\nTras rotar la lista 3 veces:\n");
		rotarN(lista, num_elementos, 3);

		return 0;
}

void escribir(const int lista[], int num_elementos){
    for(int i=0;i<=num_elementos-1;i++){
        printf("%d ",lista[i]);
    }
}
int posicion(const int lista[], int num_elementos, int elemento){
     for(int i=0;i<=num_elementos;i++){
        if(lista[i]==elemento){
            return i;
        }else if(i>=7){
            return -1;
        }
     }
}
void invertir(int lista[], int num_elementos){
    for(int i=num_elementos-1;i>=0;i--){
        printf("%d ",lista[i]);
    }
}
void rotar(int lista[], int num_elementos){
    for(int i=0;i<=0;i++){
        printf("%d ",lista[i]);
        for(int i=num_elementos-1;i>=1;i--){
            printf("%d ",lista[i]);
        }
    }
}
void rotarN(int lista[], int num_elementos, int posiciones){
    for(int i=posiciones;i>=0;i--){
        printf("%d ",lista[i]);
    }
        for(int i=num_elementos-1;i>=posiciones+1;i--){
            printf("%d ",lista[i]);
        }



}
