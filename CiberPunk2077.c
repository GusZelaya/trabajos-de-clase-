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

char * nombres(char * ruta,int n)
{
	printf("j");
	static char str[700];
	sprintf (str,"%s/foto %d.jpg",ruta,n);
	return(str);
}
//(Estas son las rutas en mi maquina)
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
	int tamano,tamtotal,cant=0;
	char str[512];
	printf("a");
	if((Archivo=fopen(ruta,"r"))==NULL)
	{
		printf("Error\n");
		return 0;
	}
	while(feof(Archivo)==0)
	{
		for(;fread(str,1,bytes,Archivo)==bytes;)
		{
			if(str[0]==0xff && str[1]==0xd8 && str[2]==0xff && (str[3]==0xe0 || str[3]==0xe1))
			{
				if((Fotos=fopen(nombres(destino,cant),"w"))==NULL)
				{
					printf("Error\n");
					return 0;
				}
				do{
        cant++;
				fwrite(str,1,bytes,Fotos);
				tamano+=bytes;
				tamtotal+=bytes;
				}while(str[0]!=0xff || str[1]!=0xd8 || str[2]!=0xff || (str[3]!=0xe0 || str[3]!=0xe1));
				printf("foto %d\t.jpg tamano: %d\n",cant,tamano);
				tamano=0;
				fclose(Fotos);
			}
		}
	}
	//
	printf("cantidad de fotos recuperadas: %d\n tamano total: %d\n",cant,tamtotal);
	fclose(Archivo);
	return 0;
}
