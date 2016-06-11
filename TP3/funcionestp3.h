#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[1000];
    int estado;
}eMovie;

void iniciarArrays(eMovie *movie, int largoArray);
int menu();
void agregarPelicula(eMovie *movie, int largoArray);
void borrarPelicula(eMovie *movie,int largoArray);
void modificarPelicula(eMovie *movie,int largoArray);
int validarDuracion(int* num, char mensaje[], char msgError[]);
int getIntP(int *num, char mensaje[], char msgError[]);
void generarPaginaWeb(eMovie *movie, int largoArray);
void guardarArchivoBinario(eMovie *movie, int largoArray);
void leerArchivoBinario(eMovie *movie, int largoArray);
void imprimirListaPeliculas(eMovie *peliculas, int length);

