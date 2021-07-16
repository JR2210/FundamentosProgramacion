#include <stdio.h>
#include <math.h>

int main()
{
    int cantidad = 1, espacio = 10 * 2;
    for (int fila = 1; fila <= 10; fila++)
    { 
        for (int t = 0; t < espacio; t++)
        {
            printf("  "); 
        }
        for (int k = fila; k <= cantidad; k++)
        {                         
            printf("%d ", k % 10); 
        }
        for (int k = cantidad - 1; k >= fila; k--)
        { 
                printf("%d ", k % 10); 
        }
        printf("\n");            
        cantidad = cantidad + 2; 
        espacio--;               
    }
}
