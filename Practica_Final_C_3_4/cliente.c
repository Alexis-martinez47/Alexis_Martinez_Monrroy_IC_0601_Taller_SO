#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX 100
#define SA struct sockaddr

void enviarNums(int miSocket, char *n1, char *n2);

int main(int argc, char *argv[]){
	int miSocket, puerto;
	struct sockaddr_in dirServ;
	
	if(argc != 4){
		printf("Debe indicar el puerto y los números a enviar al servidor...\n\n");
		exit(-1);
	}
	
	puerto = atoi(argv[1]);
	
	miSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (miSocket == -1) {
		printf("No se pudo crear el socket...\n");
		exit(-1);
	} else {
		printf("Socket creado exitosamente...\n");	
	}
		
	bzero(&dirServ, sizeof(dirServ));

	dirServ.sin_family = AF_INET;
	dirServ.sin_addr.s_addr = inet_addr("127.0.0.1");
	dirServ.sin_port = htons(puerto);

	if (connect(miSocket, (SA*)&dirServ, sizeof(dirServ)) != 0) {
		printf("No se pudo conectar con el servidor...\n");
		exit(0);
	} else {
		printf("Conectado al servidor exitosamente...\n");
	}

	enviarNums(miSocket, argv[2], argv[3]);

	close(miSocket);
}

void enviarNums(int miSocket, char *n1, char *n2){
	char buff[MAX], res[MAX]={'0'}, num1[strlen(n1)], num2[strlen(n2)];
	
	strcpy(num1, n1);
	strcpy(num2, n2);

	strcpy(buff, num1);
	write(miSocket, buff, sizeof(buff));
	
	strcpy(buff, num2);
        write(miSocket, buff, sizeof(buff));
        
	read(miSocket, buff, sizeof(buff));
	strcpy(res, buff);

	printf("El resultado de la suma es:\n\t%s\n",res);
}
