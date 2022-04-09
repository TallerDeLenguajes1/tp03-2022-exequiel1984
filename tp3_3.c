#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
};

struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente[100]; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    struct Producto *Productos; //El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”
};

int main(){
    int cantidadClientesaCargar;
    struct Cliente **datosPorCliente;
    struct Producto **Productos;
    char *Buff;

    Buff = (char *) malloc(100 * sizeof(char));

    srand(time(NULL));

    printf("Ingrese la cantidad de clientes a cargar: ");
    scanf("%d", &cantidadClientesaCargar);

    datosPorCliente = (struct Cliente **) malloc(cantidadClientesaCargar * sizeof(struct Cliente *));

//Carga de clientes

    for (int i = 0; i < cantidadClientesaCargar; i++)
    {
        datosPorCliente[i]->ClienteID = i+1;
        printf("***Cliente %d***", datosPorCliente[i]->ClienteID);

        printf("Ingrese el nombre del cliente: ");
        gets(datosPorCliente[i]->NombreCliente);

        datosPorCliente[i]->CantidadProductosAPedir = 1 + rand() % 5;

//Carga de productos

        Productos = (struct Producto **) malloc(datosPorCliente[i]->CantidadProductosAPedir * sizeof(struct Producto));

        for (int j = 0; j < datosPorCliente[i]->CantidadProductosAPedir; j++)
        {
            Productos[j]->ProductoID = j+1;
            Productos[j]->Cantidad = 1 + rand()%10;
            Productos[j]->TipoProducto = TiposProductos[rand()%5];
            Productos[j]->PrecioUnitario = 10 + (float)(rand()%90)/100;
        }

    }
 

//Libero memoria reservada

    free(datosPorCliente);

    for (int i = 0; i < cantidadClientesaCargar; i++)
    {
        free(datosPorCliente[i]);
    }

    free(Productos);

    for (int i = 0; i < cantidadClientesaCargar; i++)
    {
        for (int j = 0; j < datosPorCliente[i]->CantidadProductosAPedir; j++){
            free(Productos[j]);
        }    
    }

    getchar();
    return 0;
}