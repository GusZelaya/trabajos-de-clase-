 La empresa LP S.A. solicitó crear un programa para gestionar una agenda de clientes, debe contar con una base de datos

que contenga los siguientes campos:


“nombre (50 caracteres)”,

“dirección (100 caracteres)”,
“teléfono (entero sin signo)”,

“estado_pagos (float con signo)”.


El estado de pagos será un número negativo indicando la cantidad de dinero que debe el cliente.
El programa debe presentar al usuario un menú con las siguientes opciones:
1) Agregar cliente.

2) ver datos de todos los clientes.
El programa trabajará con un archivo (clientes.db por ejemplo) que debe crear la
primera vez que se ejecute el programa e ir actualizando cada vez que se agregue un nuevo cliente con el menú.
 */

#include <stdio.h>
#include <stdlib.h>
#define archivo "/home/lp1-2023/Escritorio/aaa"
#define encabezado "               base de datos de la empresa"

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
	char v[80];
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
			printf ("Ingrese\n");
			printf("Nombre:\n");
			scanf("%s",a.nombre);
			printf ("Direccion:\n");
			scanf("%s",a.direccion);
			printf("Nmero de telefono:\n");
			scanf("%d",&a.telefono);
			printf ("Deuda a pagar:\n");
			scanf("%f",&a.estado_pago);
			if((Archivo=fopen(archivo,"w"))==NULL)
			{
				fwrite(encabezado,1,sizeof(cliente),Archivo);
				fclose(Archivo);
			}
			fwrite(&a,1,sizeof(a),Archivo);
			fclose(Archivo);
			break;
		case 2:
			Archivo=fopen(archivo,"r");
			if(Archivo==NULL){
				//se abre el archivo de estadisticas en modo lectura y escritura
				printf("Error al abrir la carpeta de estadisticas para la lectura \n");
			}
			while(feof(Archivo)==0){
				fread(v,1,80,Archivo);
				printf("%s",v);
				fclose(Archivo);
			}
		}break;
	}while(valor!=0);
	return EXIT_SUCCESS;
}
