#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(void)
{
  int i, A=0, C=0, G=0, T=0;
  char ADN[1000], feedBack;
 
  setlocale(LC_ALL,"");
 
 
  printf("Introduzca la cadena ADN:\n");
     scanf("%s", &ADN[0]);
     strupr(ADN);

     for (i=0; i<1000; ++i) {
     	if(ADN[i] == 'A'|| ADN[i] == 'C' || ADN[i] == 'G' || ADN[i] == 'T') {
		 switch(ADN[i]){
		 case 'A': A++; break;
		 case 'C': C++; break;
		 case 'G': G++; break;       
		 case 'T': T++; break;
		 default: break;
		 }
		}
	 }
     
    int charLeft = 1000 - strlen(ADN);
    
  printf("\n{\n A:%d\n C:%d\n G:%d\n T:%d\n}\n Tu Input:[%s]\n", A,C,G,T,ADN);
  printf("¿Desea auto generar los %d datos faltantes? [y/n]", charLeft);
  
  scanf("\n%c", &feedBack);
  
  if (feedBack == 'Y'|| feedBack == 'y') {
  	autocomplete(charLeft,ADN, A, C, G, T);
  }
  
  else {
  	return 0;
  }
   
}

int autocomplete(int charLeft, char ADN[], int A, int C, int G, int T) {
	char pool[4] = {'A','C','G','T'};
	int i;
	for (i=strlen(ADN);i<charLeft;i++){
		int dato = rand() % strlen(pool);
		ADN[i] = pool[dato];
	}
	printf("\n\n GENERANDO LOS %d DATOS RESTANTES\n\n NUEVA CADENA DE ADN:\n{\n%s\n}\n", charLeft, ADN);
	
	for (i=0; i<1000; ++i) {
     	if(ADN[i] == 'A'|| ADN[i] == 'C' || ADN[i] == 'G' || ADN[i] == 'T') {
		 switch(ADN[i]){
		 case 'A': A++; break;
		 case 'C': C++; break;
		 case 'G': G++; break;       
		 case 'T': T++; break;
		 default: break;
		 }
		}
	 }
	 printf(" Nuevo número de datos:\n{\n A:%d\n C:%d\n G:%d\n T:%d\n}\n", A,C,G,T);
}

