#include <stdio.h>
#include <math.h>
float distanciaPuntos(float x1,float y1, float x2,float y2);
void leerCentroCircunferencia(float * Cx, float *Cy, float *radio);
void leerPunto(float * Px,float *Py);
int ubicacionPuntoCircunferencia(float Cx,float Cy, float radio, float Px, float Py);
float distanciaOrigenCoordenadas(float Px,float Py);

int main (){
    float Cx,Cy,radio;
    float Px,Py;
    char leyendoPuntos;
    printf("UBICACION DE UN PUNTO RESPECTO A UNA CIRCUNFERENCIA\n");
    leerCentroCircunferencia(&Cx,&Cy,&radio);
    printf("\nLa circunferencia se encuentra a %.2f del origen de coordenadas\n",distanciaOrigenCoordenadas(Cx,Cy));
    do {
        leerPunto(&Px,&Py);
        switch (ubicacionPuntoCircunferencia(Cx,Cy,radio,Px,Py) ) {
            case 1: printf("Punto (%.2f,%.2f) esta dentro de la circunferencia\n",Px,Py);break;
            case 0: printf("Punto (%.2f,%.2f) esta en la circunferencia \n",Px,Py);break;
            case -1: printf("Punto (%.2f,%.2f) esta fuera de la circunferencia \n",Px,Py);break;
        }
        printf("%\nIntroducir mas puntos ?  (s/n)");
        scanf("%s", &leyendoPuntos);
    } while (leyendoPuntos=='s');
return 0;
}
float distanciaPuntos(float x1,float y1, float x2,float y2){
    return sqrt( (y2-y1)+(y2-y1) + (x2-x1)+(x2-x1) );
}

float distanciaOrigenCoordenadas(float x,float y){
    return distanciaPuntos(0,0,x,y);
}

void leerCentroCircunferencia(float * Cx,float *Cy,float *radio){
    do {
        printf("\nCoordenadas maximas ejes de abscisas y de ordenadas: [-255,255]\n");
        printf("abscisa (x) del centro cirfunferencia? ");
        scanf("%f",Cx);
        printf("ordenada (y) del centro circunferencia ? ");
        scanf("%f",Cy);
        do {
            printf("radio circunferencia ? ");
            scanf("%f",radio);
        } while ((*radio)<0);
     } while( (fabs(*Cx)+(*radio) ) >255 || (fabs(*Cy)+(*radio) ) >255 ) ;
     printf("%f\n",*Cx);
     printf("%f\n",*Cy);
     printf("%f\n",*radio);
}

void leerPunto(float * Px,float *Py){
    do {
        printf("\nCoordenadas maximas ejes de abscisas y de ordenadas: [-255,255] \n");
        printf("abscisa (x) del punto ? ");
        scanf("%f",Px);
        printf("ordenada (y) del punto ? ");
        scanf("%f",Py);
    } while( fabs(*Px)>255 || fabs(*Py)>255 ) ;
}

int ubicacionPuntoCircunferencia(float Cx,float Cy,float radio,float Px,float Py) {
    if(radio>distanciaPuntos(Cx,Cy,Px,Py)) {
        printf("Punto (%.2f,%.2f) esta dentro de la circunferencia ",Px,Py);
        return 1;
    } else if(radio<distanciaPuntos(Cx,Cy,Px,Py)) {
        printf("Punto (%.2f,%.2f) esta fuera de la circunferencia",Px,Py);
        return -1;
    } else if(radio==distanciaPuntos(Cx,Cy,Px,Py)) {
        printf("Punto (%.2f,%.2f) esta en la circunferencia",Px,Py);
        return 0;
    }
}


