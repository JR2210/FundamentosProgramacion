/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUCLEOTIDOS 90  // debe ser múltiplo de tres

struct Tnucleotido{
    char pentosa;
    char baseNitrogenada;
    char fosfato;
};

typedef struct Tnucleotido TacidoNucleico[NUCLEOTIDOS];
char randBaseNitrogenada(char pentosa);
void generarCadenaADN(TacidoNucleico *cadenaADN[NUCLEOTIDOS]);
void printAcidoNucleico(TacidoNucleico acidoNucleico[NUCLEOTIDOS]);

int main()
{
    TacidoNucleico adn[NUCLEOTIDOS];
    srand(time(NULL));
    generarCadenaADN(&adn);
    printf("%c",adn[0]);
    ///printAcidoNucleico(adn);
    return 0;
}

char randBaseNitrogenada(char pentosa){
    return "ACGT"[rand()%4];
}

void generarCadenaADN(TacidoNucleico *cadenaADN[NUCLEOTIDOS]){
    char c;
    for(int i=0;i<NUCLEOTIDOS;i++){
        c=randBaseNitrogenada(c);
        cadenaADN[i]=c;
    }
}*/
/*void printAcidoNucleico(TacidoNucleico acidoNucleico[NUCLEOTIDOS]){
    for(int i=0;i<NUCLEOTIDOS;i++){
        printf("%c",acidoNucleico[i]);
    }
}*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUCLEOTIDOS 90  // debe ser múltiplo de tres

struct Tnucleotido{
    char pentosa;
    char baseNitrogenada;
    char fosfato;
};

typedef struct Tnucleotido TacidoNucleico[NUCLEOTIDOS];

char randBaseNitrogenada(char pentosa);
void generarCadenaADN(TacidoNucleico *cadenaADN);
void printAcidoNucleico(TacidoNucleico  acidoNucleico);
char baseNitrogenadaComplementaria(char baseNitrogenada);
int main(){
        char c;
        srand(time(NULL));
        TacidoNucleico adn;
        printf("Cadena de ADN\n\n\nSeleccione un Acido Nucleico(D o R): ");
        scanf("%c",&c);
        switch(c){
            case 'D': generarCadenaADN(&adn);break;
            case 'R':break;
            default:printf("No es una opcion valida");
        }
}

char randBaseNitrogenada(char pentosa){
    return "ACGT"[rand()%4];
}

void generarCadenaADN(TacidoNucleico *cadenaADN){
    char c;
    char cadena[NUCLEOTIDOS];
    for (int i=0;i<NUCLEOTIDOS;i++){
        cadenaADN=randBaseNitrogenada(c);
        if(i%30==0)printf("\n");
        printAcidoNucleico(*cadenaADN);
        cadena[i]=cadenaADN;
    }
    printf("\n\nSu complementaria es: \n");
    for(int i=0;i<NUCLEOTIDOS;i++){
        c=cadena[i];
        if(i%30==0)printf("\n");
        printf("%c",baseNitrogenadaComplementaria(c));
    }
    printf("\n");
}

void printAcidoNucleico(TacidoNucleico  acidoNucleico){
        printf("%c",acidoNucleico);
}

char baseNitrogenadaComplementaria(char baseNitrogenada){
    char c;
    if(baseNitrogenada=='A'){
        c='T';
    }if(baseNitrogenada=='C'){
        c='G';
    }if(baseNitrogenada=='G'){
        c='C';
    }if(baseNitrogenada=='T'){
        c='A';
    }
    return c;
}
