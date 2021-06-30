#include<stdio.h>

void ejercicio1(void);
void ejercicio2(void);

int main(){
	printf("---------------------> Ejercicio 1 <----------------------\n");
	ejercicio1();
	printf("\n---------------------> Ejercicio 2 <----------------------\n");
	ejercicio2();
	return 0;
}

void ejercicio1(){
	int x = 10;
	int *p;
	int y = 20;
	int *puntero;
	p = &x;
	printf("Contenido de 'p': %i\n",*p);
	*p += 1;
	printf("-> p + 1 <-\n");
	printf("Contenido de 'p': %i\n",*p);
	*p += 2;
	printf("-> p + 2 <-\n");
	printf("Contenido de 'p': %i\n",*p);
	puntero = &y;
	printf("Contenido de 'puntero': %i\n",*puntero);
}

void ejercicio2(){
	int arrayInt[5];
	int i;
	for (i = 0; i < 5; i++){
		arrayInt[i] = i;
	}
	int *punteroInt = arrayInt;
	int *punteroIntDos = &arrayInt[0];
	printf("Contenido de 'arrayInt[0]': %i\n", arrayInt[0]);
	printf("Contenido de 'punteroInt[0]': %i\n", punteroInt[0]);
	printf("Contenido de 'punteroIntDos[0]': %i\n", punteroIntDos[0]);
	printf("\nContenido de 'arrayInt[4]': %i\n", arrayInt[4]);
	printf("Contenido de 'punteroInt[4]': %i\n", *(punteroInt + 4));
	printf("Contenido de 'punteroIntDos[4]': %i\n", *(punteroIntDos + 4));
	printf("\nContenido de 'punteroIntDos':\n");
	for (i = 0; i < 5; i++){
		printf("\tpunteroInt[%i] = %i\n", i, *(punteroIntDos + i));
	}
	printf("\nContenido de 'punteroIntDos':\n");
	for (i = 0; i < 5; i++){
		printf("\tpunteroIntDos[%i] = %i\n", i, *(punteroIntDos + i));
	}
}
