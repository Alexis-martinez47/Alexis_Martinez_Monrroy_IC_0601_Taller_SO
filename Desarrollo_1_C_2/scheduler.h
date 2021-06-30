#ifndef __SCHEDULER_H
#define __SCHEDULER_H

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_STRING				100
#define MAX_PROCESOS			100

#define UN_SEGUNDO				1
#define DOS_SEGUNDOS			2
#define TRES_SEGUNDOS			3
#define CUATRO_SEGUNDOS			4
	
#define ACTIVO 					1
#define NO_ACTIVO				0

int cont_procesos;

typedef struct PROCESS process;
typedef struct ARRAY_PROCESS array_procesos;

// Definición de la estructura PROCESS
struct PROCESS{
	int id;
	int delay;
	char nombrePROCESO[MAX_STRING];
	char accion[MAX_STRING];
	pthread_t hilo;
	int estado;
};

struct ARRAY_PROCESS{
	process proceso;
	int empty;
};

process *crear_Proceso(int _id, int _delay, char *_nombreProceso, pthread_t _hilo, char *_accion, int _estado);
void agregar_Proceso(array_procesos *_array, process _p);
void ejecutar_Procesos(array_procesos *_array);
void *thread_accion(void *arg);

array_procesos *crear_ArrayProcesos(void);

#endif
