#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "funcionestp3.h"

/**
* \brief Inicializa el campo estado del array.
* \param Carga todos los estados en 0
* \return Void.
*/
void iniciarArrays(eMovie *movie, int largoArray)
{
    int i;

    if(movie != NULL && largoArray>0)
    {
        for(i=0; i<largoArray; i++)
        {
            movie[i].estado = 0;
        }
    }
}

/**
* \brief Muestra el menú de opciones.
* \param
* \return la opcion seleccionada.
*/
int menu()
{
    int opcion;

    printf("Elija una opcion:\n1- Agregar pelicula\n2- Borrar pelicula\n3- Modificar pelicula\n4- Generar pagina web\n5- Salir\n6- imprimir lista peliculas\n");
    scanf("%d", &opcion);

    return opcion;
}

/**
* \brief Agregar una pelicula
* \param estructura tipo movie y largo del array.
* \return void
*/
void agregarPelicula(eMovie *movie, int largoArray)
{
    int i;

    if(movie != NULL && largoArray>0)
    {

        for(i=0; i<largoArray; i++)
        {
            if(movie[i].estado == 0)
            {

                printf("Ingrese titulo: ");
                fflush(stdin);
                gets(movie[i].titulo);
                strupr(movie[i].titulo);


                printf("Ingrese genero: ");
                fflush(stdin);
                gets(movie[i].genero);
                strupr(movie[i].genero);

                fflush(stdin);
                validarDuracion(&movie[i].duracion, "Duracion: ", "Error, ingresar duracion en minutos:\n");

                printf("Sinopsis: ");
                fflush(stdin);
                gets(movie[i].descripcion);

                fflush(stdin);
                getIntP(&movie[i].puntaje, "Ingrese puntaje (01/10):\n", "Error, ingresar puntaje entre de 1 a 10: ");

                printf("Ingrese link de imagen de la pelicula: ");
                fflush(stdin);
                gets(movie[i].linkImagen);

                movie[i].estado = 1;
                system("cls");
                break;
            }
        }
         if(i==largoArray)
        {
            printf("Memoria insuficiente para agregar peliculas.");
            system("cls");
        }
    }
}

/** \brief Borrar una pelicula
 * \param  Estructura tipo movie y largo del array
 * \return void
 */

 void borrarPelicula(eMovie *movie,int largoArray)
{
    int i;
    char buffer[300];

    printf("Ingrese el titulo de la pelicula a eliminar: ");
    fflush(stdin);
    gets(buffer);

    strupr(buffer);

    for(i=0; i<largoArray; i++)
    {
        if(movie[i].estado==1)
        {
            if(strcmp(buffer, movie[i].titulo) == 0)
            {
                movie[i].estado = 0;
                printf("Pelicula borrada exitosamente");
                break;
            }
            else
            {
                printf("La pelicula que desea eliminar no existe.");
                break;
            }
        }
    }
}

/** \brief Modificar una pelicula
 * \param estructura tipo movie y largo del array
 * \return void
 */

 void modificarPelicula(eMovie *movie,int largoArray)
{
    int indexModificar = -1;
    int i;
    int opcion = 0;
    char buffer[300];

    printf("Ingrese el titulo de la pelicula que desea modificar: ");
    fflush(stdin);
    gets(buffer);
    strupr(buffer);


    for(i=0;i<largoArray;i++)
    {
        if(movie[i].estado == 1 && strcmp(buffer, movie[i].titulo)==0)
        {
            indexModificar = i;
            break;
        }
    }

    if(indexModificar >= 0)
    {
        printf("Ingrese opcion que desee modificar:\n1. Titulo\n2. Genero\n3. Duracion\n4. Descripcion\n5. Puntaje\n6. Salir\n\n* Ingrese una opcion:\n");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                printf("Ingrese modificacion del titulo:");
                fflush(stdin);
                gets(movie[i].titulo);
                break;

            case 2:
                printf("Ingrese modificacion del genero:");
                fflush(stdin);
                gets(movie[i].genero);
                break;

            case 3:
                printf("Ingrese modificacion de la duracion:");
                fflush(stdin);
                gets(movie[i].duracion);
                break;

            case 4:
                printf("Ingrese modificacion de la descripcion:");
                fflush(stdin);
                gets(movie[i].descripcion);
                break;

            case 5:
                printf("Ingrese modificacion del puntaje:");
                fflush(stdin);
                gets(movie[i].puntaje);
                break;

            case 6:
                break;

            default:
                printf("No existe la opcion ingresada");
                break;
        }
    }
    else if(indexModificar == -1)
    {
        printf("No existe la pelicula ingresada);
    }
}

/**
 * \brief verifica que la duracion sea en minutos
 * \param puntero a entero
 * \return la duracion ingresada en minutos.
 */

int validarDuracion(int* num, char mensaje[], char msgError[])
{
    char buffer[300];
    int aux;

    printf("%s", mensaje);
    gets(buffer);
    aux = atoi(buffer);

    if(!(aux>=1 && aux<=500))
     {
       system("cls");
       printf("%s", msgError);
       gets(buffer);
       return -1;
     }
     else
     {
      * num = aux;
      return 0;
     }
}

/**
 * \brief Solicita un número al usuario y devuelve el resultado.
 * \param num. Puntero que recibe un número entero.
 * \return El número ingresado por el usuario.
 */

int getIntP(int *num, char mensaje[], char msgError[])
{
    char buffer[300];
    int aux;

    printf("%s", mensaje);
    gets(buffer);
    aux = atoi(buffer);

    if(!(aux>=1 && aux<=10))
     {
       system("cls");
       printf("%s", msgError);
       gets(buffer);
       return -1;
     }
     else
     {
      * num = aux;
      return 0;
     }
}


/** \brief genera pagina web con las peliculas cargadas
 * \param estructura tipo movie y largo del array
 * \return void
 */
void generarPaginaWeb(eMovie *movie, int largoArray)
{
    int i;

    FILE *arch;

    arch = fopen("peliculas.html", "w");

    if(arch == NULL)
    {
        printf("Error al abrir el archivo");
        exit(1);
    }

    fprintf(arch,"<!DOCTYPE html><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><title>Lista peliculas</title><link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'></head><body><div class='container'><div class='row'>");

    for(i=0;i<largoArray;i++)
    {
        if(movie[i].estado == 1)
        {
         fprintf(arch,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''>", movie[i].linkImagen);
         fprintf(arch,"</a><h3><a href='#'>%s</a></h3><ul>",movie[i].titulo);
         fprintf(arch,"<li>Genero:%s</li><li>Puntaje:%d</li><li>Duracion:%d</li></ul>", movie[i].genero, movie[i].puntaje,movie[i].duracion);
         fprintf(arch,"<p>%s</p></article>",movie[i].descripcion);
        }
    }
    fprintf(arch,"</div></div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body></html>");
    fclose(arch);
    printf("Archivo guardado.");
}

/** \brief genera archivo binario
 * \param estructura tipo movie y largo del array.
 * \return void
 */


void guardarArchivoBinario(eMovie *movie, int largoArray)
{
    FILE *archBin;

    archBin = fopen("movie.dat", "wb");

    if(archBin == NULL)
    {
        printf("No se pudo abrir el archivo.");
        exit(1);
    }

    fwrite(movie, sizeof(eMovie), largoArray, archBin);

    printf("Datos guardados.");

    fclose(archBin);
}

/** \brief Leer archivo binario
 * \param estructura tipo movie y largo del array
 * \return void
 */

void leerArchivoBinario(eMovie *movie, int largoArray)
{
    FILE *archBin;

    archBin = fopen("movie.dat", "rb");

    if(archBin == NULL)
    {
        archBin = fopen("movie.dat", "wb");
    }
    if(archBin == NULL)
    {
        printf("*No se pudo abrir el fichero*");
        exit(1);
    }

    fread(movie, sizeof(eMovie), largoArray, archBin);

    printf("Peliculas cargadas desde archivo binario con exito");

    system("cls");

    fclose(archBin);
}


/** \brief imprimir lista de peliculas
 * \param estructura tipo movie y largo del array
 * \return lista de las peliculas
 */

void imprimirListaPeliculas(eMovie *peliculas, int length)
{
    if( peliculas != NULL && length > 0  )
    {
        int i;
        system("cls");
        printf("Titulo\tPuntaje\tGenero\tDuracion\tDescripcion\n");
        for( i=0 ; i<length ; i++ )
        {
            if( peliculas[i].estado == 1 )
            {
                printf("%s\t%d\t%s\t%d\t%s\n", peliculas[i].titulo, peliculas[i].puntaje, peliculas[i].genero, peliculas[i].duracion, peliculas[i].descripcion );

            }
        }

        printf("\n");
        system("pause");
    }
}
