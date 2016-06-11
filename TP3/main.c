#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "funcionestp3.h"
#define CANTIDAD 10

int main()
{
    eMovie movie[CANTIDAD];
    int opcion=0;

    iniciarArrays(movie,CANTIDAD);
    leerArchivoBinario(movie, CANTIDAD);

    do
    {
        system("cls");

        opcion = menu();

        switch(opcion)
        {
        case 1:
            agregarPelicula(movie , CANTIDAD);
            break;
        case 2:
            borrarPelicula(movie, CANTIDAD);
            getch();
            break;
        case 3:
            modificarPelicula(movie , CANTIDAD);
            getch();
            break;
        case 4:
            generarPaginaWeb(movie, CANTIDAD);
            getch();
            break;
        case 5:
            guardarArchivoBinario(movie, CANTIDAD);
            getch();
            break;
        case 6:
            imprimirListaPeliculas(movie, CANTIDAD);
            break;
        default:
            printf("Error, opcion no valida");
            break;
        }
    }while(opcion!=5);

    return 0;
}

