#include <stdio.h>
#include <stdlib.h>
int simular_tirada_dado();
int simular_jugada(int i,int r,int t);
int main(){
    int total=0,x,i=0,r=0,t=0,u=0;
    char z;
    while(z!='n'){
            i++;
            x=simular_jugada(i,r,t);
            if(i==1){
                r=r+x;
            }else if(i==2){
                t=t+x;
                total=r+t;
            }else if(i==3){
                u=u+x;
                total=t+u;
            }
            if(total>=7&&total<=11&&i==2&&t!=r) {
                printf("ENHORABUENA HAS GANADO!!! TU PUNTUACI%cN ES %d",224,total);
                i=0;total=0;r=0;t=0;u=0;    //REINICIO TODAS LAS VARIABLES
                printf("\n\nDesea continuar? (S/N): ");
                scanf(" %c",&z);
                getchar(); //ESPERAR A QUE LE METAS ALGO POR TECLADO
            } else if(t==r&&i==2){
                continue;
            } else if(i==2&&t!=r&&(total<=7||total>=11)) {
                printf("LO SIENTO, HAS PERDIDO!!! TU PUNTUACI%cN ES %d",224,total);
                i=0;total=0;r=0;t=0;u=0;    //REINICIO TODAS LAS VARIABLES
                printf("\n\nDesea continuar? (S/N): ");
                scanf("%c",&z);
                getchar(); //ESPERAR A QUE LE METAS ALGO POR TECLADO
            }
            if(total>=7&&total<=11&&i==3) {
                printf("ENHORABUENA HAS GANADO, TU PUNTUACI%cN ES %d",224,total);
                i=0;total=0;r=0;t=0;u=0;    //REINICIO TODAS LAS VARIABLES
                printf("\n\nDesea continuar? (S/N): ");
                scanf("%c",&z);
                getchar(); //ESPERAR A QUE LE METAS ALGO POR TECLADO
            } else if(i==3&&(total<=7||total>=11)) {
                printf("LO SIENTO, HAS PERDIDO!!! TU PUNTUACI%cN ES %d",224,total);
                i=0;total=0;r=0;t=0;u=0;    //REINICIO TODAS LAS VARIABLES
                printf("\n\nDesea continuar? (S/N): ");
                scanf("%c",&z);
                getchar(); //ESPERAR A QUE LE METAS ALGO POR TECLADO
            }
    }
    return 0;
}

int simular_jugada(int i,int r,int t){
    int x;
    char z;
    while(i<=3){
    if(i==1){
        printf("Lance el primer dado pulsando una tecla ");
        scanf("%c",&z);
        x=simular_tirada_dado(); //5
        printf("%d PUNTOS!!\n",x);
        return x;
    }else if(i==2){
        printf("Lance el segundo dado pulsando una tecla ");
        scanf("%c",&z);
        x=simular_tirada_dado();
        printf("%d PUNTOS!!\n",x);
        return x;
    }else if(i==3&&t==r){
        printf("Lance el segundo dado de nuevo pulsando una tecla ");
        scanf("%c",&z);
        x=simular_tirada_dado();
        printf("%d PUNTOS!!\n",x);
        return x;
    }
}
}
int simular_tirada_dado() {
    int li=1,ls=6;
    srand(time(NULL));
    return li+rand()%((ls+1)-li);
}
