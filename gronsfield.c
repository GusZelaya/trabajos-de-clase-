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
nota: por el planteamiento del problema en el tp el usuario puede ingresar una clave numerica de menor cantidad de caracteres que el mensaje que
quiere encriptar, de ser este el caso, tenemos que crear un bucle para que se llenen los espacios de la clave numerica con los numeros que ingreso el
usuario.
ejemplo:
1-)
clave:1234
mensaje:hola
resultado:
h o l a
1 2 3 4
2-)
clave 1234
mensaje:hola que tal
resultado:
h o l a   q u e   t a l
1 2 3 4 1 2 3 4 1 2 3 4
3-)
clave:1
mensaje:artritis
resultado:
a r t r i t i s
1 1 1 1 1 1 1 1
*/

/*
 * posibles fuentes del problema:
 * --> no se crea el puntero aaa correctamente
 * --> los valores de clave no se cargan correctamente en aaa
 * --> si strlen(aaa)>strlen(clave) no se cargan los valores correctamente en el bucle
 * --> no se retorna aaa de la manera correcta
 * --> en el mejor de los casos, no llega wololo a la funcion encriptar, de manera correcta
 *
 * 		chequear el valor de wololo para revisar si se soluciona o no el problema
 */
char* clave01(int len, const char* clave) {
    char* aaa = malloc(len + 1); // Se crea un vector de tamaño igual al mensaje a cifrar más uno para el caracter nulo.
    int clave_len = strlen(clave);

    // Si la longitud de la clave es menor que la longitud del mensaje a cifrar, se repite la clave.
    for (int i = 0; i < len; i++) {
        aaa[i] = clave[i % clave_len]; // Se utiliza el operador módulo (%) para obtener el índice de la clave correspondiente.
    }
    aaa[len] = '\0'; // Se agrega el caracter nulo al final del vector.
	printf("\n%s\n",aaa);
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
	int tam = strlen(sms);//ingresa el tamaño de sms
	char a[tam];//crea vector para imprimir mensaje decodificado
	for (int i = 0; i<tam; i++){
		printf("sms:%c,num:%c",sms[i],numEncrip[i]);
		a[i]= sms[i] - numEncrip[i] + 48;//se restar caracteres con números, 48 valor numerico del caracter 0
		printf("val.a:%c \n",a[i]);
	}
	printf ("El mensaje desencriptado es: %s\n",a);
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

/*
 * problema:
 *-->no llegan los valores de numEncrip
 *
 * comentarios con posibles soluciones al problema en la linea 73
 */
void encriptar(char *sms, char *numEncrip)
{
	//char *str=transString(numEncrip);//transforma el array de la clave numerica para a string para poder usar atoi
    int tam = strlen(sms); //ingresa el tamaño de sms
    char a[tam]; //crea vector para imprimir mensaje codificado

    for (int i = 0; i < tam; i++) {
		printf("sms:%c,num:%c",sms[i],numEncrip[i]);
        a[i]= sms[i] + numEncrip[i]- 48 ; //se pueden sumar caracteres con números, 48 valor numerico del caracter 0
		printf("val.a:%c \n",a[i]);
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
	char ayoyo[40];//cadena donde se cargaran los argumentos concatenados
	if (verNum(argv[2])==1) return 0; //verifica si la clave consta de unicamente numeros, de lo contrario termina el programa
	for (int N=3;N<argc;N++)
	{
		strcat(ayoyo,argv[N]);
		if ((N+1)!=argc)
			strcat(ayoyo," ");
	}
	int tamCad=contarChar(strlen(ayoyo));
	char *wololo=clave01(tamCad,argv[2]);
	if (*argv[1]=='c')// si argv[1] es c, ejecuta la funcion de encriptar
		encriptar(ayoyo, wololo);
	else if (*argv[1]=='d')// si argv[1] es d, ejecuta la funcion de desencriptar
		desencriptar(ayoyo, wololo);
	else//si el usuario ingresa cualquier otro caracter se avisa el error y termina el programa
	{
		printf("Opción inválida\n");
		return 0;
	}

	return 0;
}
