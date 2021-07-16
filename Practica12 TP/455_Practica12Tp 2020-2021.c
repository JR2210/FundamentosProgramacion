


/*************************SOLUCIÓN CON LOS PARAMETROS DEL ENUNCIADO****************************/
#include <stdio.h>
#include <stdlib.h>
#define N 20

struct Fecha {
    int dia, mes, anio;
};
struct Lista {
    int tamanio; //Cantidad de valores del array siguiente
    struct Fecha vectorFechas[N];     // Array de fechas
};

//Añade al final de una lista de fechas una nueva fecha
int insertar (struct Lista , struct Fecha);

/*Rellenar una lista mediante lectura de teclado. El usuario introducirá por teclado
máximo N (20) fechas, cada fecha en una línea con tres valores enteros
que representan un día, mes y un año, y las inserta utilizando la función anterior.
Se dejarán de introducir datos si se escriben tres ceros o se completa la lista.*/
void rellenarLista (struct Lista *listaFechas);

/*Función que a partir de una fecha y una lista, busca la fecha en la lista y nos devuelva la posición de la lista en la que se encuentra. Si no existe devolverá el valor -1. */
int buscarFecha (struct Lista lista, struct Fecha *fechaBuscada);

/*Escribir las fechas almacenadas en la lista: una fecha en cada línea, con el formato dd/mm/aa. Si la lista está vacía se indicará mediante un mensaje.*/
void escribirListaFechas (struct Lista);

int main(){
    int cont=0,resultado;
    struct Lista fecha;
    struct Fecha fecha1;
    rellenarLista(&fecha);
    escribirListaFechas(fecha);
    do{
    resultado=buscarFecha(fecha,&fecha1);
    printf("Buscamos %d/%d/%d con resultado %d\n",fecha1.dia,fecha1.mes,fecha1.anio,resultado);
    cont++;
    }while(cont<2);
    return 0;
}


int buscarFecha (struct Lista lista, struct Fecha *fechaBuscada){
    int encontrada,tamanio=lista.tamanio;
        printf("Introduce dos fechas para buscarlas en la lista: ");
        scanf("%d %d %d",&fechaBuscada->dia,&fechaBuscada->mes,&fechaBuscada->anio);
        for(int i=0;i<tamanio;i++){
            if(lista.vectorFechas[i].dia==fechaBuscada->dia&&lista.vectorFechas[i].mes==fechaBuscada->mes&&lista.vectorFechas[i].anio==fechaBuscada->anio){
                encontrada=i;
                break;
            }else{encontrada=-1;}
        }
    return encontrada;
}


void rellenarLista(struct Lista *listaFechas){
    int cont=0,dia,mes,anio;
    printf("Introduce fechas, 0 0 0 para acabar.\n");
    while((dia!=0||mes!=0||anio!=0)&&cont<N){
        printf("%d.Introduce dia mes anio: ",cont+1);
        scanf("%d %d %d",&listaFechas->vectorFechas[cont].dia,&listaFechas->vectorFechas[cont].mes,&listaFechas->vectorFechas[cont].anio);
        dia=listaFechas->vectorFechas[cont].dia;
        mes=listaFechas->vectorFechas[cont].mes;
        anio=listaFechas->vectorFechas[cont].anio;
        cont++;
    }
    listaFechas->tamanio=cont-1;
}

void escribirListaFechas (struct Lista listaFechas){
    int cont=listaFechas.tamanio;
    if(cont>0){
    printf("La lista contiene %d datos\n",listaFechas.tamanio);

    for(int i=0;i<cont;i++){
        printf("\t%d.%d/%d/%d\n",i+1,listaFechas.vectorFechas[i].dia,listaFechas.vectorFechas[i].mes,listaFechas.vectorFechas[i].anio);

    }
    }else{printf("La lista esta vacia");}
}


/*
*************************** ACTUALIZACIÓN DE INSERTAR ************************************

No entiendo el enunciado de la función insertar porque ella, tal y como se explica, no actualiza la lista de fechas.
Para que se actualice la lista de fechas es necesario, o que la función devuelva una estructura lista de fechas para actualizar la nuestra,
o que se le pase como parámetro el puntero a nuestra lista.


Aquí te dejo el programa entero con el cambio necesario que veo yo a la hora de, el problema de actualizar la lista:
#include <stdio.h>
#include <stdlib.h>
#define N 20

struct Fecha {
    int dia, mes, anio;
};
struct Lista {
    int tamanio; //Cantidad de valores del array siguiente
    struct Fecha vectorFechas[N];     // Array de fechas
};

//Añade al final de una lista de fechas una nueva fecha
struct Lista insertar (struct Lista cont , struct Fecha fecha);

/*Rellenar una lista mediante lectura de teclado. El usuario introducirá por teclado
máximo N (20) fechas, cada fecha en una línea con tres valores enteros
que representan un día, mes y un año, y las inserta utilizando la función anterior.
Se dejarán de introducir datos si se escriben tres ceros o se completa la lista.
void rellenarLista (struct Lista *listaFechas);

/*Función que a partir de una fecha y una lista, busca la fecha en la lista y nos devuelva la posición de la lista en la que se encuentra. Si no existe devolverá el valor -1.
int buscarFecha (struct Lista lista, struct Fecha *fechaBuscada);

/*Escribir las fechas almacenadas en la lista: una fecha en cada línea, con el formato dd/mm/aa. Si la lista está vacía se indicará mediante un mensaje.
void escribirListaFechas (struct Lista);

int main(){
    int cont=0,resultado;
    struct Lista fecha;
    struct Fecha fecha1;
    rellenarLista(&fecha);
    escribirListaFechas(fecha);
    do{
    resultado=buscarFecha(fecha,&fecha1);
    printf("Buscamos %d/%d/%d con resultado %d\n",fecha1.dia,fecha1.mes,fecha1.anio,resultado);
    cont++;
    }while(cont<2);
    return 0;
}

struct Lista insertar (struct Lista cont , struct Fecha fecha){
    int x;
    if(cont.tamanio<N){
        cont.vectorFechas[cont.tamanio].dia=fecha.dia;
        cont.vectorFechas[cont.tamanio].mes=fecha.mes;
        cont.vectorFechas[cont.tamanio].anio=fecha.anio;
    }
    return cont; //para que la lista de fechas se actualiza hace falta que se retorne la estructura lista, o que se pase como puntero
}

int buscarFecha (struct Lista lista, struct Fecha *fechaBuscada){
    int encontrada,tamanio=lista.tamanio;
        printf("Introduce dos fechas para buscarlas en la lista: ");
        scanf("%d %d %d",&fechaBuscada->dia,&fechaBuscada->mes,&fechaBuscada->anio);
        for(int i=0;i<tamanio;i++){
            if(lista.vectorFechas[i].dia==fechaBuscada->dia&&lista.vectorFechas[i].mes==fechaBuscada->mes&&lista.vectorFechas[i].anio==fechaBuscada->anio){
                encontrada=i;
                break;
            }else{encontrada=-1;}
        }
    return encontrada;
}

void rellenarLista(struct Lista *listaFechas){
    struct Fecha guardado;
    int cont=0,insertado,dia,mes,anio;
    printf("Introduce fechas, 0 0 0 para acabar.\n");
    while((dia!=0||mes!=0||anio!=0)&&cont<N){
        printf("%d.Introduce dia mes anio: ",cont+1);
        scanf("%d %d %d",&dia,&mes,&anio);
        cont++;
        listaFechas->tamanio=cont-1;
        guardado.dia=dia;guardado.mes=mes;guardado.anio=anio;
        *listaFechas=insertar(*listaFechas,guardado);
    }
    listaFechas->tamanio=cont-1;
}

void escribirListaFechas (struct Lista listaFechas){
    int cont=listaFechas.tamanio;
    if(cont>0){
    printf("La lista contiene %d datos\n",listaFechas.tamanio);
    for(int i=0;i<cont;i++){
        printf("\t%d.%d/%d/%d\n",i+1,listaFechas.vectorFechas[i].dia,listaFechas.vectorFechas[i].mes,listaFechas.vectorFechas[i].anio);

    }
    }else{printf("La lista esta vacia");}
}
*/

