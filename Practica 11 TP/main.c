#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Funciones que operan con cadenas de caracteres
#include <time.h>

#define SIZE_DATABASE        12    // Numero maximo de cadenas en la base de datos
#define SIZE_DATABASE_STRING 50    // Longitud maxima de las cadenas en base de datos
#define SIZE_STRING_GROUP    4     // Numero maximo de palabras en cada grupo
#define MAX_USER_TRIALS      2     // Numero maximo de intentos hasta que se dar una pista

int rand_cadena();
int generar_cadena_aleatoria(char array[SIZE_DATABASE][SIZE_DATABASE_STRING], char*cadenaAleatoria);
int imprimir_cadena(const char *palabra, unsigned *tamanio);
void leer_cadena(char *escrita);
int comprobar_cadena(const char* cad1,const char* cad2);

int main() {
    // Declaracion de variables
    int user=6, trials_counter=0, passw_basedatos=0, check=1;
    char basedatos[SIZE_DATABASE][SIZE_DATABASE_STRING]= {"obligatorio", // Grupo 0: gato
                                                          "alegato",
                                                          "interrogatorio",
                                                          "purgatorio",
                                                          "apilado",      // Grupo 1: pila
                                                          "compila",
                                                          "papila",
                                                          "recopilar",
                                                          "ayudar",       // Grupo 2: dar
                                                          "anudara",
                                                          "acordarme",
                                                          "andarin"
                                                         };
    // Nombre de grupos en el mismo orden en el que aparecen en la base de datos
    char basedatos_group[][SIZE_DATABASE_STRING]= {"gato", "pila", "dar"}; // Grupos de base datos
    char palabra,aleatoria[SIZE_DATABASE_STRING];
    unsigned tamanio;
    printf("PRACTICA 11: JUEGO AHORCADO DE PALABRAS\n");
    srand(time(NULL));
    passw_basedatos=generar_cadena_aleatoria(basedatos,&aleatoria);
    do {
        printf("\n");
        printf("1.- Reiniciar juego.\n");
        printf("2.- Lanzar nuevo intento (palabras en minusculas).\n");
        printf("3.- Comprobar intento.\n");
        printf("       0.- Salir.");
        printf("\n");
        scanf("%d", &user);
        fflush(stdin);
        system("cls");
        switch(user) {
        case 1:
            passw_basedatos=generar_cadena_aleatoria(basedatos,&aleatoria);
            trials_counter=0;
            break;
        case 2:
            if(trials_counter>=MAX_USER_TRIALS) // Se da una pista antes de introducir una cadena
                printf("\nSu numero de intentos ha llegado o superado %d, una pista es: %s\n", MAX_USER_TRIALS, basedatos_group[passw_basedatos/SIZE_STRING_GROUP]);
            leer_cadena(&palabra);
            imprimir_cadena(&palabra,&tamanio);
            break;
        case 3:
            check=comprobar_cadena(&palabra,&aleatoria);
            if(check==1) {
                printf("\nUyyy, su palabra es casi correcta!\n");
                ++trials_counter;
            } else if(check==2) {
                printf("\nLo siento, su palabra no es correcta!\n");
                ++trials_counter;
            } else {
                printf("\nEnhorabuena, ha ganado!\n");
                // Cuando se gana el juego, tambien se reinicia en numero de intentos
                trials_counter=0;
            }
            break;
        }

    } while(user);

    return 0;
}

int rand_cadena() {
    return rand()%SIZE_DATABASE;
}

void leer_cadena(char *escrita) {
    printf("Escribe una palabra: ");
    gets(escrita);
}

int imprimir_cadena(const char *palabra, unsigned *tamanio) {
    *tamanio=strlen(palabra); //determino el tamaño de la palabra que se introduce por teclado con la funcion strlen
    printf("La palabra es: ");
    for(int i=0; i<*tamanio; i++) {
        printf("%c",palabra[i]);
    }
    printf("\nCadena %s (TAMANIO %d)",palabra,*tamanio);
}

int comprobar_cadena(const char* cad1,const char* cad2) {
    int j=0,x,y;
    y=strlen(cad2); //devuelve la longitud de la cadena aleatoria
    char cad1x[SIZE_DATABASE_STRING],cad2x[SIZE_DATABASE_STRING];
    strcpy(cad1x,cad1); //como son const char no puedo modificarlas, por lo que creo dos cadenas locales y copio el contenido de los const a estas
    strcpy(cad2x,cad2); //lo mismo con const cad2
    for(int i=0; i<y; i++) { //sabiendo el tamaño de la cadena que quieres encontrar (y)
        if(cad1x[i]==cad2x[i]){ //comparamos carácter a carácter cada cadena auxiliar
            cad2x[i]=cad1x[i]; //si son iguales, el contenido de cad1x pasa a cad2x
        } else {
            cad2x[i]='_'; //si son diferentes ese espacio en la cadena de cad2x estará sustituido por un _
            j++; //aumento el contador j para determinar la cantidad de carácteres que ha fallado el usuario
        }
    }
    for(int i=0; i<y; i++) {
        printf("%c ",cad2x[i]); //imprimo el resultado de comparar las dos cadenas
    }
    if(j==y) { //si j es igual al tamaño de la palabra aleatoria significa que no has acertado nada
        x=2;
    } else if(j>0&&j<y) {  //si j esta comprendido entre 0 e y-1  significa que has acertado algo     /* j es un contador de _ , por lo tanto haciendo estas sentencias podemos determinar el resultado*/
        x=1;
    } else if(j==0) { //si j es 0 significa que has acertado
        x=0;
    }
    return x; //devuelves el valor x que has determinado su valor en las sentencias anteriores
}

int generar_cadena_aleatoria(char array[][SIZE_DATABASE_STRING], char *cadenaAleatoria) {
    int x=rand_cadena(); //declaro una variable entera en la que guardo un valor aleatorio que me proporciona la funcion rand_cadena()
    for(int i=0; i<14; i++) {
        cadenaAleatoria[i]=array[x][i]; //guardo en cadenaAleatoria la cadena de la matriz basedatos sabiendo que quiero la cadena de la fila x determinada por la línea anterior y recorriendo en el for las columnas de esa fila
    }
    return x; //retorno el valor entero que me proporciona la funcion rand_cadena()
}

