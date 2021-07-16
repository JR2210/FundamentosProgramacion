#include <stdio.h>
#include <stdlib.h>
int main()
{
 int dia,mes;//defino variables enteras
 printf("Escriba dia y mes(formato dd/mm): ");
 scanf("%d/%d",&dia,&mes); //guardado en memoria cada variable
 if(mes>=1&&mes<=12){//Defino el rango de meses posibles
 if(mes==4||mes==6||mes==9||mes==11){//meses que tienen 30 dias
 if(dia>=1&&dia<=30){
 printf("La fecha %d/%d es correcta",dia,mes);
 }else{
 printf("La fecha %d/%d no es correcta",dia,mes);
 }
 }
 if(mes==1||mes==3||mes==5||mes==7||mes==8||mes==10||mes==12){//meses
 if(dia>=1&&dia<=31){
 printf("La fecha %d/%d es correcta",dia,mes);
 }else{
 printf("La fecha %d/%d no es correcta",dia,mes);
 }
 }
 if(mes==2){//FEBRERO
 if(dia>=1&&dia<=28){
 printf("La fecha %d/%d es correcta",dia,mes);
 }else{
 printf("La fecha %d/%d no es correcta",dia,mes);
 }
 }
 } else{
 printf("Mes incorrecto");
 }
}















