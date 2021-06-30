#include "lista.h"

int main(int argc, char *argv[]){
	Palabra *cabeza = NULL;
	FILE *archivoEntrada, *archivoSalida;
	char sAux[MAXLONG]="";
	int numP = 0;
	
	archivoEntrada = fopen(argv[1], "r");
	archivoSalida = fopen(argv[2], "w");
	
	if (archivoEntrada == NULL || archivoSalida == NULL){
		if (argv[1]){
			if(argv[2]){
				printf("El archivo [%s] no existe...\n", argv[1]);
			} else {
				printf("Debe indicar el archivo de entrada y salida...\n");
			}
		} else {
			printf("Debe indicar el archivo de entrada y salida...\n");
		}
	} else {
		while (fscanf(archivoEntrada, "%s", sAux) != EOF){
			agregarPalabra(&cabeza, sAux);
			numP++;
		}
		fclose(archivoEntrada);
		printf("\nPalabras en [%s]:\n", argv[1]);
		imprimirLista(cabeza);
		ordenarLista(cabeza, numP);
		if(escribirLista(cabeza, archivoSalida) == 0){
			printf("\nLas palabras ordenadas se encuentran en el archivo [%s]...\n", argv[2]);
		} else {
			printf("\nNo se pudo escribir las palabras en el archivo [%s]...\n", argv[2]);
		}
		fclose(archivoSalida);
	}
	return 0;
}
