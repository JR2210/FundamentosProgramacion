#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int numeroPagos(int anios);
float interesMensual(float interesAnualTantoPorCiento);
float pago(float capital, float interes, int numeroPagos);
void leerCondicionesHipoteca(float * capital, float * interesAnualTantoPorCiento, int * anios);
printTablaAmortizacion(float capital,float interesAnualTantoPorCiento,int anios,float pago);

int main(){
    float c,i,m,p1;
    int anios;
    leerCondicionesHipoteca(&c,&i,&anios); //devuelve un valor para capital,intereses y anios
    anios=numeroPagos(anios); //anios se convierte en meses
    m=interesMensual(i); //llamo a la función interesMensual para tener el %de interes mensual
    p1=pago(c,m,anios); //llamo a la función pago que me devuelve el total de la cuota de la hipoteca
    printf("Pago mensual: %.2f\n",p1);
    printTablaAmortizacion(c,m,anios,p1); //llamo a la función printTablaAmortizacion para desarrollar la tabla
    return 0;
}

void leerCondicionesHipoteca(float *capital, float *interesAnualTantoPorCiento, int *anios){
    float x,y;
    int z;
    printf("CALCULO DE HIPOTECA: \n");
    printf("Capital?: ");
    scanf("%f",&x);
    printf("Interes Anual?: ");
    scanf("%f",&y);
    printf("Anios?: ");
    scanf("%d",&z);
    *capital=x;
    *interesAnualTantoPorCiento=y;
    *anios=z;
}

int numeroPagos(int anios){
    return anios*12;
}

float interesMensual(float interesAnualTantoPorCiento){
    return (interesAnualTantoPorCiento/100)/12;
}

float pago(float capital, float interes, int numeroPagos){
    return capital/((1-pow(1+interes,-numeroPagos))/interes);
}

printTablaAmortizacion(float capital,float interesAnualTantoPorCiento,int anios,float pago){
    float amortizado,interes;
    printf("\n    PagoMensual         INTERESES         AMORTIZADO          CAPITALVIVO\n");
    for(int i=1;i<=anios;i++){
        interes=capital*interesAnualTantoPorCiento; //Me recoge el interes del 1er mes de la hipoteca
        amortizado=pago-interes; //Resto la cuota mensual al interes para hallar la amortizacion
        capital=capital-amortizado; //actualizo el valor del capital restandole la amortizacion
        printf(" %d      %.2f             %.2f            %.2f              %.2f\n",i,pago,interes,amortizado,capital);
    }
}


