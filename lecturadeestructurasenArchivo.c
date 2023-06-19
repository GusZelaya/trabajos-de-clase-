#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define archivo "/home/lp1-2023/Escritorio/locurazelaya"

FILE *Archivo=NULL;

struct empresa{
	char nombre[50];// nombre del cliente
	char direccion[100];//direccion del cliente
	unsigned int telefono;//numero de telefono
	float estado_pago;//lo que debe el cliente

};

int main(void) {
	int valor;
	typedef struct empresa cliente;
	cliente data;
	printf("Bienvenido al menu de LP S.A\n");
	do{
		printf ("Agregar cliente -> 1\n");
		printf("Ver datos de clienmtes -> 2\n");
		printf("Salir -> 0\n");
		scanf ("%d",&valor);
		switch (valor){
		case 0:
			break;
		case 1:
			cliente a;
			printf ("Ingrese ");
			printf("Nombre:");
			scanf("%s",a.nombre);
			printf ("Direccion:");
			scanf("%s",a.direccion);
			printf("Nmero de telefono:");
			scanf("%d",&a.telefono);
			printf ("Deuda a pagar:");
			scanf("%f",&a.estado_pago);
			Archivo=fopen(archivo,"a");
			fwrite(&a,sizeof(cliente),1,Archivo);
			fclose(Archivo);
			break;
		case 2:
			Archivo=fopen(archivo,"r");
			if(Archivo==NULL){
				//se abre el archivo de estadisticas en modo lectura y escritura
				printf("Error al abrir la carpeta de estadisticas para la lectura \n");
			}
			do{
				if((fread(&data,sizeof(cliente),1,Archivo))!=1)
					break;
				printf("nombre:%s  direccion: %s  Num: %d deuda: %f \n",data.nombre,data.direccion,data.telefono,data.estado_pago);
			}while(feof(Archivo)==0);
			fclose(Archivo);
			break;
		}
		break;
	}while(valor!=0);
	return EXIT_SUCCESS;
}
