#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Definimos la variable de tipo FILE para tratar el archivo y la variable tipo char para recorrerlo
	FILE *file;
	char character;
	//Usamos el metodo fopen con r para la lectura del archivo
	file = fopen("ejemplo","r");
	//Comprobamos si existe el archivo, si existe y la ruta es correcta lo abre y muestra el mensaje
	if (file == NULL)
    {
        //Si el archivo no abre mostramos el error
        printf("El archivo no se puede abrir o no existe.\n");
    }
    else
    {
        //Si el archivo se puede abrir y leer lo muestra
        printf("El archivo tiene el siguiente texto\n");
        //Recorremos el archivo hasta que no hay ningun caracter para analizar
        while((character = fgetc(file)) != EOF)
	    {
		    printf("%c",character);
	    }
    }
        //Cerramos el archivo
        fclose(file);
	return 0;
}