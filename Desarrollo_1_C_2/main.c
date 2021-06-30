#include "scheduler.h"

int main(int argc, char const *argv[]){
	pthread_t hilos[9];
	
	process *p1 = crear_Proceso(1, UN_SEGUNDO, "Proceso_1", hilos[0], "Reproduciendo música...", ACTIVO);
	process *p2 = crear_Proceso(1, DOS_SEGUNDOS, "Proceso_1", hilos[1], "Abriendo YouTube...", NO_ACTIVO);
	process *p3 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_2", hilos[2], "Escribiendo texto en Word...", ACTIVO);
	process *p4 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_3", hilos[3], "Descargando archivo...", ACTIVO);
	process *p5 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_4", hilos[4], "subiendo archivo...", ACTIVO);
	process *p6 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_5", hilos[5], "Compilando programa...", NO_ACTIVO);
	process *p7 = crear_Proceso(0, TRES_SEGUNDOS, "Proceso_6", hilos[6], "Ejecutando programa...", ACTIVO);
	process *p8 = crear_Proceso(2, CUATRO_SEGUNDOS, "Proceso_7", hilos[7], "Usando terminal...", ACTIVO);
	process *p9 = crear_Proceso(5, CUATRO_SEGUNDOS, "Proceso_8", hilos[8], "Usando terminal...", NO_ACTIVO);

	array_procesos *array = crear_ArrayProcesos();

	agregar_Proceso(array, *p1);
	agregar_Proceso(array, *p2);
	agregar_Proceso(array, *p3);
	agregar_Proceso(array, *p4);
	agregar_Proceso(array, *p5);
	agregar_Proceso(array, *p6);
	agregar_Proceso(array, *p7);
	agregar_Proceso(array, *p8);
	agregar_Proceso(array, *p9);

	ejecutar_Procesos(array);

	free(array);
	free(p1);
	free(p2);
	free(p3);
	free(p4);
	free(p5);
	free(p6);
	free(p7);
	free(p8);
	free(p9);

	return 0;
}
