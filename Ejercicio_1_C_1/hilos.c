#include <stdio.h>
#include <pthread.h>

#define A 1
#define B 1
#define C 1
#define D 1
#define E 1
#define F 1
#define G 1
#define H 1
#define I 1


const char *mensaje[9] = {"Ejecutando Hilo1", "Ejecutando Hilo2", "Ejecutando Hilo3", "Ejecutando Hilo4", "Ejecutando Hilo5", "Ejecutando Hilo6", "Ejecutando Hilo7", "Ejecutando Hilo8", "Ejecutando Hilo9"};
const int cantidad[9] = {A,B,C,D,E,F,G,H,I};

void imprime_mensaje(void *ptr) {
        int i;
        int id;

        id = *(int *) ptr;
        for(i=0; i<cantidad[id]; i++)
                printf("%s\n",mensaje[id]);
        return;
}


int main(int argc, char *argv[])
{
        pthread_t hilo0, hilo1, hilo2, hilo3, hilo4, hilo5, hilo6, hilo7, hilo8;
        int id0=0, id1=1, id2=2, id3=3, id4=4, id5=5, id6=6, id7=7, id8=8;

        pthread_create(&hilo0, NULL, (void *) &imprime_mensaje, (void *) &id0);
        pthread_create(&hilo1, NULL, (void *) &imprime_mensaje, (void *) &id1);
        pthread_create(&hilo2, NULL, (void *) &imprime_mensaje, (void *) &id2);
        pthread_create(&hilo3, NULL, (void *) &imprime_mensaje, (void *) &id3);
        pthread_create(&hilo4, NULL, (void *) &imprime_mensaje, (void *) &id4);
        pthread_create(&hilo5, NULL, (void *) &imprime_mensaje, (void *) &id5);
        pthread_create(&hilo6, NULL, (void *) &imprime_mensaje, (void *) &id6);
        pthread_create(&hilo7, NULL, (void *) &imprime_mensaje, (void *) &id7);
        pthread_create(&hilo8, NULL, (void *) &imprime_mensaje, (void *) &id8);


        pthread_join(hilo0, NULL);
        pthread_join(hilo1, NULL);
        pthread_join(hilo2, NULL);
        pthread_join(hilo3, NULL);
        pthread_join(hilo4, NULL);
        pthread_join(hilo5, NULL);
        pthread_join(hilo6, NULL);
        pthread_join(hilo7, NULL);
        pthread_join(hilo8, NULL);

        return 0;
}