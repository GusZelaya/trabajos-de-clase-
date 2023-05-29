/*
 ============================================================================
 Name        : Leerescribir.c
 Author      : ezequiel zelaya
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char * nombres(char * ruta,int n)
{
	static char str[700];
	sprintf (str,"%s/foto %d.jpg",ruta,n);
	return(str);
}

char titulo1[]={0xff,0xd8,0xff,0xe0};
char titulo2[]={0xff,0xd8,0xff,0xe1};
//claves: 0xff 0xd8 0xff 0xe0,0xff 0xd8 0xff 0xe1
//RUTA:/home/lp1-2023/Descargas/Fotos.raw
//destino:/home/lp1-2023/Escritorio/tareas de la clase

int main(int agrc,char **argv)
{
	int bytes=512;
	char *ruta=argv[1];
	char *destino=argv[2];
	FILE * Archivo=NULL;
	FILE * Fotos=NULL;
	int tamano,tamtotal,bandera=0;
	unsigned int cant=0;
	char str[512];
	if((Archivo=fopen(ruta,"r"))==NULL)
	{
		printf("Error\n");
		return 0;
	}
	while(feof(Archivo)==0)
	{
		for(;fread(str,1,bytes,Archivo)==bytes;)
		{
			if(strncmp(str,titulo1,4)==0||strncmp(str,titulo2,4)==0)
			{
				bandera++;
				do
				{
				cant++;
				while((Fotos=fopen(nombres(destino,cant),"w"))==NULL)
				{
					printf("Error\n");
					return 0;
				}
				//if()
				do{
				fwrite(str,1,bytes,Fotos);
				tamano+=bytes;
				tamtotal+=bytes;
				fread(str,1,bytes,Archivo);
				if(strncmp(str,titulo1,4)==0||strncmp(str,titulo2,4)==0)
				{
					bandera++;
					break;
				}
				}while(1);
				printf("foto %d.jpg\ttamano: %d\n",cant,tamano);
				tamano=0;
				fclose(Fotos);
				}while(bandera<31);
				break;
			}
		}
	}
	printf("cantidad de fotos recuperadas: %d\n tamano total: %d bytes",cant,tamtotal);
	fclose(Archivo);
	return 0;
}
