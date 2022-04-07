#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char *buff; 
    char **punteroDeNombres;

    int cantidadNombres;

    buff = (char *) malloc(100 * sizeof(char));

    printf("Ingrese la cantidad de nombres a guardar: ");
    scanf("%d", &cantidadNombres);

    punteroDeNombres = (char **) malloc(cantidadNombres * sizeof(char *));

    for (int i = 0; i < cantidadNombres; i++)
    {
        printf("Ingrese el nombre %d: ", i+1);
        gets(buff);

        punteroDeNombres[i] = (char *) malloc((strlen(buff)+1) * sizeof(char));
        strcpy(punteroDeNombres[i], buff);
    }

    for (int i = 0; i < cantidadNombres; i++)
    {
        printf("Nombre %d: ", i+1);
        puts(punteroDeNombres[i]);   
    }
    
    free(buff);

    for (int i = 0; i < cantidadNombres; i++)
    {
        free(punteroDeNombres[i]);
    }
    
    free(punteroDeNombres);

    return 0;
}