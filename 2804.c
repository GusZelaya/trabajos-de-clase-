#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * el trabajo de este programa es recibir los argumentos que carga el usuario, meterlos todos dentro de una cadena e imprimirla
 * ademas tambien debe imprimir la cantidad de carateres de cada argumento
 */

/*
 * funcion encargada de concatenar
 * **a--> argv (puntero a vector de punteros)
 * *l--> matriz en la que se quiere guardar la longitud de cada argumento
 * argc--> cantidad de argumentos
 * *c--> la intencion es que sea utilizado para hacer la string (fernando pidio que lo hagamos asi para practicar con la memoria dinamica)
 */

typedef struct dato{
char* string;
int* cant;
}dato;

dato concatenar(char **a,int argc, datos respuesta)
{
int sum=0;

respuesta.cant=(int*)malloc(argc*sizeof(int));

for (int i=0;i<argc;i++)//en esta parte se carga en l la cantidad de caracteres de cada argumento
{
respuesta.cant[i]=strlen(a[i]);
sum+=respuesta.cant[i];
}
    respuesta.string=malloc(sum*sizeof(char)); //se reserva el espacio en c para almacenar todos los caracteres de las cadenas ingresadas
    (respuesta.string)[0]= '\0';
    for (int m=0;m<argc;m++) //para recorrer todos los argumentos
{
strcat(respuesta.string,a[m]);
}

    return respuesta;

}




int main(int argc, char **argv){

dato respuesta;
respuesta  = concatenar(argv,argc,respuesta);
printf("Resultado: %s\nChars/Arg:\n",respuesta.string);
for(int i=0;i<argc;i++)
printf("\tArg[%d]: %d\n",i,respuesta.cant[i]);

}
