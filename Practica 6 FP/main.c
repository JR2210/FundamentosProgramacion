#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void leerCoeficientesParabola(float*a,float*b,float*c);
float valorY(float x, float a, float b, float c);
void printVerticeParabola(float a,float b,float c);
void printCorteEjeY(float a, float b, float c);
void printCorteEjeX(float a, float b, float c);
void leerCoordenadasPunto(float * x,float * y);
int pertenecePuntoParabola(float x,float y,float a,float b,float c);
void printTabla(float a,float b,float c);

int main(){
    char car;
    float x1,y1,a,b,c;
    leerCoeficientesParabola(&a,&b,&c);
    printVerticeParabola(a,b,c);
    printCorteEjeX(a,b,c);
    printCorteEjeY(a,b,c);
    while(car!='n'){
    leerCoordenadasPunto(&x1,&y1);
    pertenecePuntoParabola(x1,y1,a,b,c);
    printf("\nMas puntos?(s/n): ");
    scanf(" %c",&car);
    }
    printTabla(a,b,c);
    return 0;
}
void leerCoeficientesParabola(float*a,float*b,float*c){
    float x,y,z;
    printf("Coeficientes de y(x)=ax2+bx+c: \n");
    printf("a= ");
    scanf("%f",&x);
    printf("b= ");
    scanf("%f",&y);
    printf("c= ");
    scanf("%f",&z);
    *a=abs(x);
    *b=y;
    *c=z;
}

void printVerticeParabola(float a,float b,float c){
    float x=b/(2*a),y=((a*pow(x,2))+b*x+c);
    printf("V(Vx,Vy)= (%.2f,%.2f)",x,y);
}
float valorY(float x, float a, float b, float c){
    return ((a*pow(x,2))+b*x+c);
}
void printCorteEjeX(float a, float b, float c){
    if(valorY>0){
        printf("\nCorta en el eje x en %.2f y en %.2f",(-b+(sqrt(-4*a*c))/(2*a)),(-b-(sqrt(-4*a*c))/(2*a)));
    }else if(valorY==0){
        printf("\nCorta en el eje x en %.2f",(-b+(sqrt(-4*a*c))/(2*a)));
    }else if(valorY<0){
        printf("\n Ningun punto de corte del eje x");
    }
}
void printCorteEjeY(float a, float b, float c){
    printf("\nCorta en el eje y en %.2f\n",c);
}
void leerCoordenadasPunto(float *x,float *y){
    float x1,y1;
    printf("\nPunto: ");
    printf("\nX?= ");
    scanf("%f",&x1);
    printf("Y?= ");
    scanf("%f",&y1);
    *x=x1;
    *y=y1;
}
int pertenecePuntoParabola(float x,float y,float a,float b,float c){
    if(y==((a*pow(x,2))+b*x+c)){
        printf("(%.2f,%.2f) pertenece a la parabola.\n",x,y);
    }else if(y!=((-a*pow(x,2))+b*x+c)){
        printf("(%.2f,%.2f) no pertenece a la parabola.\n",x,y);
    }
}
void printTabla(float a,float b,float c) {
    printf("\nTabla de valores: \n");
    for(float x=-10;x<=10;x++){
        printf("%.2f ",x);
    }
    printf("\n");
    for(float x=-10;x<=10;x++){
        printf(" %.2f",valorY(x,a,b,c));
    }
}














