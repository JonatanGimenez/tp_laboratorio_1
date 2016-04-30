#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "funciones.h"
#include <windows.h>

//desarrollo de las funciones:

/** \brief Mostrar menu con opciones.
 * \return opcion ingresada.
 */
int menu()
{
    int opcion;
    int contadorErrores = 0;

    printf("Elija una opcion:\n1- Agregar una persona\n2- Borrar una persona\n3- Imprimir lista ordenada por nombre\n4- Imprimir grafico de edades\n5- Salir\n");
    scanf("%d", &opcion);

    //se valida la opcion.
    while(opcion<1 || opcion>5)
    {
        printf("Error, reingrese opcion: \n");
        scanf("%d", &opcion);
        contadorErrores++;
        //si se intenta demasiadas veces (3) si cierra el programa.
        if(contadorErrores>=3)
        {
            printf("Demasidos intentos, el programa se cerrara.");
            opcion = 5;
        }
    }

    return opcion;
}

/** \brief Inicializa el array en 0
 * \param recibe el largo del array
 * \return los campos "persona.estado" con valor '0'.
 */
void iniciarArrays(estructuraPersona personal[], int largoArray)
{
    int i;
    for(i=0; i<largoArray; i++)
    {
        personal[i].estado=0;
    }
}

/** \brief Agregar personas.
 * \param un array de persona y el largo del array.
 * \return el array cargado.
 */
void agregarPersona(estructuraPersona personal[], int largoArray)
{
    int i;
    for(i=0;i<largoArray;i++)
    {
        if(personal[i].estado == 0)
        {
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(personal[i].nombre);

            printf("Ingrese edad: ");
            fflush(stdin);
            scanf("%d", &personal[i].edad);

            printf("Ingrese DNI:");
            fflush(stdin);
            scanf("%ld", &personal[i].dni);

            personal[i].estado=1;
            system("pause");
            system("cls");
            break;
        }
    }
        //Aviso que el array esta completo.
        if(i==largoArray)
        {
            printf("\nNo hay espacio disponible para agregar personas\n\n");
            system("pause");
            system("cls");
        }

}

/** \brief se solicita el dni de la persona a ser eliminada.
 * \param el dni a elimiar
 * \return el campo "estado" del array en 0.
 */
void borrarPersona(estructuraPersona personal[], int largoArray)
{
    long int dni;
    int i;

    printf("Ingrese DNI de la persona que desea eliminar: ");
    scanf("%ld", &dni);

    for(i=0;i<largoArray;i++)
    {
        if(personal[i].estado == 1 && dni == personal[i].dni)
        {
            personal[i].estado = 0;

            printf("Eliminacion exitosa!\n");
            system("pause");
            system("cls");

            break;
        }
    }
    //aviso de que el dni ingresado no existe.
    if(i==largoArray)
    {
        printf("No existe el dni buscado.\n");
        system("pause");
        system("cls");
    }
}

/** \brief Imprime en pantalla una lista de las personas ordenadas por nombre.
 * \param array de personas y largo del array.
 * \return array ordenado por el campo "nombre".
 */

void imprimirPersonas(estructuraPersona personal[],int largoArray)
{
    int i;
    int j;
    estructuraPersona auxPersonal;

    for(i=0; i<largoArray-1;i++)
    {
        for(j=i+1;j<largoArray;j++)
        {
            if(personal[j].estado!=0)
            {
                if(strcmp(personal[i].nombre,personal[j].nombre)>0)
                {
                    auxPersonal=personal[i];
                    personal[i]=personal[j];
                    personal[j]=auxPersonal;
                }
            }
        }
    }
    for(i=0;i<largoArray;i++)
    {
        if(personal[i].estado==1)
        {
           printf("\n%s\t\t%d\t%ld\n", personal[i].nombre, personal[i].edad, personal[i].dni);
        }
    }
    system("pause");
    system("cls");
}

/** \brief Grafico de barras del rango de edades (menores de 18, entre 19 y 35, mayores de 35)
 * \param array de personas y largo del array.
 * \return grafico de estadistica de las edades.
 *
 */

int graficar(estructuraPersona personal[],int largoArray)
{
    int i;
    int menoresde18 = 0;
    int entre19y35 = 0;
    int mayoresDe35 = 0;

    for(i=0;i<largoArray;i++ )
    {
        if(personal[i].estado==1)
        {

            if(personal[i].edad<=18)
            {
                menoresde18++;
            }
            if(personal[i].edad>18 && personal[i].edad<=35)
            {
                entre19y35++;
            }
            if(personal[i].edad>35)
            {
                mayoresDe35++;
            }
        }
    }
    int hasta18 = menoresde18;
    int de19a35  = entre19y35;
    int mayorDe35= mayoresDe35;
    int flag=0;
    int mayor;

     if(hasta18 >= de19a35 && hasta18 >= mayorDe35){
        mayor = hasta18;
    }else{
        if(de19a35 >= hasta18 && de19a35 >= mayorDe35)
        {
            mayor = de19a35;
        }
        else{
        mayor = mayorDe35;
        }
    }
    for(i=mayor; i>0; i--){
        if(i<10){
            printf("%02d|",i);
        }
        else
            printf("%02d|",i);

        if(i<= hasta18){
            printf("*");
        }
        if(i<= de19a35){
            flag=1;
            printf("\t*");
        }
        if(i<= mayorDe35){
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");
        }
        printf("\n");
    }
    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35");
    printf("\n   %d\t%d\t%d\n", menoresde18, entre19y35, mayoresDe35);

    system("pause");
    system("cls");


}

/** \brief Se carga el array para probar funciones
 */
void cargaDePrueba(estructuraPersona personal[], int largoArray)
{
    char nombres[][50] = {"Jack", "Sawyer", "Kate", "Sayid", "Charlie", "Hugo", "Walt"};
    int edades[] = {35, 37, 33, 36, 26, 27, 15};
    long int dnis[] = {21324773, 51324774, 91324776, 98324777, 26324778, 96324771, 66322774};

    int i;

    for(i=0;i<7;i++)
    {
        strcpy(personal[i].nombre, nombres[i]);
        personal[i].edad = edades[i];
        personal[i].dni = dnis[i];
        personal[i].estado = 1;
    }
}
