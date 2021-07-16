#include <stdio.h>
#include <stdlib.h>
#include <math.h> //libreria de mates  funciones como pow,sqrt.
float distanciaPuntos(float x1,float y1, float x2,float y2);
void leerCentroCirfunferencia(float * Cx, float *Cy, float *radio);
float distanciaOrigenCoordenadas(float Px,float Py);
void leerPunto(float * Px,float *Py);
int ubicacionPuntoCircunferencia(float Cx,float Cy, float radio, float Px, float Py);
int main() {
    float Cx,Cy,r,x,y; //variables locales
    char c; //variable caracter
    while (c!='n') {

        leerCentroCirfunferencia(&Cx,&Cy,&r);//Llamo a leerCentroCirfunferencia

        if(Cx>255||Cy>255||Cx<-255||Cy<-255||r<0) {

            continue; //Pasa forzosamente a la siguiente iteración del bucle más cercano

        } else {
            printf("Distancia punto al origen es %.2f \n",distanciaOrigenCoordenadas(Cx,Cy));
        }
        do {
            leerPunto(&x,&y);
        } while(x>255||y>255||x<-255||y<-255);
        ubicacionPuntoCircunferencia(Cx,Cy,r,x,y);
        printf("\nQuiere seguir (s/n): ");
        scanf(" %c",&c);
    }
    return 0;
}

float distanciaPuntos(float x1,float y1, float x2,float y2) {
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2)); //retorna un valor
}
void leerCentroCirfunferencia(float*Cx,float*Cy,float*radio) {
    float x,y,r;
    printf("Coordenadas maximas ejes de abcisas y de ordenadas:[-255,255] \n");
    printf("Abcisa(x) del centro de la circunferencia:");
    scanf("%f",&x);//guardo el valor escrito por teclado en las variables en vez de en los punteros
    printf("Abcisa(y) del centro de la circunferencia:");
    scanf("%f",&y);
    printf("Radio de la circunferencia:");
    scanf("%f",&r);
    *Cx=x;
    *Cy=y;
    *radio=r;

}
float distanciaOrigenCoordenadas(float Px,float Py) {
    return sqrt(pow(Px-0,2)+pow(Py-0,2));
}
void leerPunto(float *Px,float *Py) {
    float x,y;
    printf("Coordenadas maximas ejes de abcisas y de ordenadas:[-255,255] \n");
    printf("Abcisa(x) del Punto:");
    scanf("%f",&x);//guardo el valor escrito por teclado en las variables en vez de en los punteros
    printf("Abcisa(y) del Punto:");
    scanf("%f",&y);
    *Px=x;
    *Py=y;
}
int ubicacionPuntoCircunferencia(float Cx,float Cy, float radio, float Px, float Py) {
    if(radio>distanciaPuntos(Cx,Cy,Px,Py)) {
        printf("Punto (%.2f,%.2f) esta dentro de la circunferencia ",Px,Py);
        return 1;
    } else if(radio<distanciaPuntos(Cx,Cy,Px,Py)) {
        printf("Punto (%.2f,%.2f) esta fuera de la circunferencia",Px,Py);
        return 0;
    } else if(radio==distanciaPuntos(Cx,Cy,Px,Py)) {
        printf("Punto (%.2f,%.2f) esta en la circunferencia",Px,Py);
        return -1;
    }
}
