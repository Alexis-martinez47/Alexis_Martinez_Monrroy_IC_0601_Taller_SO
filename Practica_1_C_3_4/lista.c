#include "lista.h"

Palabra* crearNodo(char *word) {
	Palabra *nuevaP = NULL;
	nuevaP = (Palabra*)malloc(sizeof(Palabra));
	nuevaP->palabra = (char *) malloc (MAXLONG * sizeof (char));
	
	if(nuevaP != NULL){
		strcpy(nuevaP->palabra, word);
		nuevaP->sig = NULL;
	}
	return nuevaP;
}

void imprimirLista(Palabra *cabeza){
	Palabra *nodAux = cabeza;

	while(nodAux != NULL){
		printf("\t%s\n", nodAux->palabra);
		nodAux = nodAux->sig;
	}
}


void ordenarLista(Palabra *cabeza, int numP){
	Palabra *nodAux = cabeza;
	char aux[MAXLONG];
	
	for(int i = 0; i < numP; i++){
		while(nodAux != NULL && nodAux->sig != NULL){
			if(strcmp(nodAux->palabra, nodAux->sig->palabra)>0){
				strcpy(aux, nodAux->palabra);
				strcpy(nodAux->palabra,nodAux->sig->palabra);
				strcpy(nodAux->sig->palabra,aux);
			}
			nodAux = nodAux->sig;
		}
		nodAux = cabeza;
	}
}

int escribirLista(Palabra *cabeza, FILE *archivoSalida){
	Palabra *nodAux = cabeza;

	while(nodAux != NULL){
		fprintf(archivoSalida, "%s\n", nodAux->palabra);
		nodAux = nodAux->sig;
	}
	return 0;
}

void agregarPalabra(Palabra **cabeza, char *word){
	Palabra* nuevaP = NULL, *nodAux = *cabeza;
	nuevaP = crearNodo(word);

	if(*cabeza == NULL){
		nuevaP->sig = *cabeza;
		*cabeza = nuevaP;
	} else {
		if( nuevaP != NULL){
			while(nodAux->sig != NULL){
				nodAux = nodAux->sig;
			}
			nodAux->sig = nuevaP;
		}
	}
}
