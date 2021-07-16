#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 15
#define M 10
void leer_letras(char *x,char *y);
int leer_palabras(char palabras[M][N]);
void reconocer_primera(char palabras[M][N],char x,char y);
int main(){
	char c=1,c1,string[M][N];
	leer_letras(&c,&c1);
	printf("%c %c",c,c1);
	leer_palabras(&string);
	reconocer_primera(string,c,c1);
}

void leer_letras(char *x,char *y){
    while(*x!=0){
        printf("Introduzca una mayuscula: ");
        scanf(" %c",x);
        if(64<*x && *x<91) { //rango del ascii de las mayusculas
            printf("Introduzca una mayuscula mayor a la anterior: ");
            scanf(" %c",y);
            if(64<*y && *y<91&&*y>*x){
                    break;
            }else{
                continue;
            }
        }else{
            continue;
        }
    }
}

int leer_palabras(char palabras[M][N]) {
    char palabras2[]= {"*"};
    printf("Introduzca palabras, * para acabar: ");
    //for(int i=0; i<M; i++) {
        //for(int j=0; j<N; j++) {
            while(strcmp(palabras,palabras2)!=0) { //funcion para comparar cadena
                scanf("%s",palabras); //si da 0 es que son iguales
            }
        //}
    //}
   for(int i=0;i<M;i++){
      for(int j=0; j<N; j++){
            printf("%c",palabras[i][j]);
       }
        printf("\n");
    }
}

void reconocer_primera(char palabras[M][N],char x,char y){
    int j=0,p=0;
    printf(" CAR\n");
    printf(" ---\n");
    for(int i=x;i<=y;i++){
        printf(" %c\n",i);
    }

}


