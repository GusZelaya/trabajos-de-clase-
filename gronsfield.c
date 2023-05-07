#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * busca caracteres!=numeros
 */

/*
 * verifica si en la cadena de caracteres perteneciente a la clave de la encriptación existen caracteres
 * diferentes a números
 * recibe:
 * char *sms-->tercer argumento que contiene a los numeros clave
 * retorna:
 * 0-->si el programa se ejecuto correctamente
 * 1-->si ocurrio un error
 */
int verNum(char *sms)
{
	for (int i=0; i<strlen(sms); i++)
	{
		if((sms[i]<'0') || (sms[i]>'9'))
		{
			printf("código ingresado inválido");
			return 1;
		}
	}
	return 0;
}

/*
 * cuenta la cantidad de caracteres que hay dentro de la cadena
 */
int contarChar(int tam) //tamaño de argv[i]
{
	int cant = 0;

	for (int i=0; i<tam; i++)
		cant+=1;

	return cant; //retorna la cantidad de caracteres que se encuentran en la linea
}
/*
funcion encargada de crear el vector con la clave numerica
len-->tama;o de la cadena de argumentos concatenada
clave-->clave numerica para el cifrado
*/
char *clave01(int len,char *clave)
{
	int ban1=0;	//variables para ir llenando el vector si hace falta 
	int ban2=1;//
	char *aaa=(char*)malloc(len*sizeof(char));//se crea un vector de tama;o igual a el mensaje a cifrar
	for(int i=0;i<strlen(aaa);i++)	//se carga el primer ciclo de la clave numerica
								   //si la strlen(clave)==strlen(mensaje a cifrar) la funcion termina 
		aaa[i]=clave[i];
		/*
		si el ultimo espacio del vector creado se encuentra con un valor distinto a un numero es por que el mensaje y la clave 
		no son del mismo tama;o, por ende se necesita ciclar la clave numerica para poder hacer el encriptado 
		*/
	while(1)	
	{
		if(aaa[len-1]<'0' || aaa[len-1]>'9')    //se revisa el valor del ultimo espacio del vector
			aaa[strlen(clave)+ban2]=clave[ban1];	// si condicion verdadera se carga el primer siguiente valor de la clave numerica
		if(aaa[len-1]>'0' || aaa[len-1]<'9')	//si la condicion no se cumple (el ultimo espacio del vector es un valor correcto)
												//se corta el ciclo while
			break;
		ban1++;
		ban2++;
	}
	return aaa;
}
/*
 * recibe la clave de desencriptación y el mensaje a desencriptar
 * va sumando cada caracter con su respectivo par numérico
 * como indica el método Gronsfeld.
 * recibe:
 * sms--> el mensaje que desea desencriptar 
 * numEncrip--> la clave de numeros que se tienen que utilizar para encriptar el mensaje 
 * retorna:
 * la nueva cadena encriptada
 */
void desencriptar(char *sms, char *numEncrip)
{
	//Aquí se implementa el código para desencriptar
}
/*
funcion encargada de transformar el array del argumento en una string 
recibe:
arr--> array de caracteres perteneciente a la clave numerica
retorna:
str--> la clave numerica transformada en string
*/
char* transString(char* arr) 
{
    int length = strlen(arr);
    char* str = (char*)malloc(length + 1); // reservar memoria para la cadena
    int i;
    for (i = 0; i < length; i++) {
        str[i] = arr[i]; // copiar cada carácter del array en la cadena
    }
    str[length] = '\0'; // agregar el carácter nulo para indicar el final de la cadena
    return str; // devolver la cadena
}

/*
 * recibe la clave de encriptación y el mensaje a encriptar
 * va sumando cada caracter con su respectivo par numérico
 * como indica el método Gronsfeld.\
 * recibe:
 * sms--> el mensaje a ser encriptado 
 * numEncrip--> la clave numerica
 * retorna:
 * no retorna nada, simplemente imprime el mensaje ingresado ahora escriptado
 */
void encriptar(char *sms, char *numEncrip)
{
	//char *str=transString(numEncrip);//transforma el array de la clave numerica para a string para poder usar atoi
    int tam = strlen(sms); //ingresa el tamaño de sms
    char a[tam]; //crea vector para imprimir mensaje codificado

    for (int i = 0; i < tam; i++) {
		printf("%c,%c\n",sms[i],numEncrip[i]);
        a[i]= sms[i] + numEncrip[i]-48 ; //se pueden sumar caracteres con números, 48 valor numerico del caracter 0
		printf("%c\n",a[i]);
    }

    printf("El mensaje encriptado queda: %s\n", a);
}
/*
 * el usuario va ingresando los datos necesarios mediante la consola
 * -->argv[0]: nombre del programa
 * -->argv[1]: c si quiere encriptar, d si quiere desencriptar
 * -->argv[2]: ingresa la clave de encriptación
 * -->argv[3]: ingresa el mensaje a encriptar/desencriptar
 */
/*
agarrar todos los argumentos despues del argv[2]
concatenarlos todos 
sumar la cantidad de caracteres que contiene la cadena 
crear un vector del tama;o obtenido
cargar el numero clave dentro de ese vector para realizar la encriptacion 
pasar la concatenacion a encriptar 
pasar la concatenacion de la clave numerica a encriptar

*/
int main(int argc, char **argv)
{
	char ayoyo[1000];//cadena donde se cargaran los argumentos concatenados
	if (verNum(argv[2])==1) return 0; //verifica si la clave consta de unicamente numeros, de lo contrario termina el programa
	for (int wololo=3;wololo<argc;wololo++)
	{
		strcat(ayoyo,argv[wololo]);
		if ((wololo+1)!=argc)
			strcat(ayoyo," ");
	}
	int tamCad=contarChar(strlen(ayoyo));
	char *claveNum=clave01(tamCad,argv[2]);
	if (*argv[1]=='c')// si argv[1] es c, ejecuta la funcion de encriptar
		encriptar(ayoyo, claveNum);
	else if (*argv[1]=='d')// si argv[1] es d, ejecuta la funcion de desencriptar
		desencriptar(ayoyo, claveNum);
	else//si el usuario ingresa cualquier otro caracter se avisa el error y termina el programa 
	{
		printf("Opción inválida\n");
		return 0;
	}

	return 0;
}

