#ifndef __LISTA_H
#define __LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLONG 50

typedef struct nodo{
	char *palabra;
	struct nodo *sig;
} Palabra;

Palabra* crearNodo(char *word);
void imprimirLista(Palabra *cabeza);
void ordenarLista(Palabra *cabeza, int numP);
int escribirLista(Palabra *cabeza, FILE *archivoSalida);
void agregarPalabra(Palabra **cabeza, char *word);

#endif
