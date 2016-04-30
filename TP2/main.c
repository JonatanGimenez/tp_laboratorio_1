#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "funciones.h"
#define CANTIDAD 1000


int main()
{
    //Declaracion de estructura.
    estructuraPersona persona[CANTIDAD];
    //Se inicializa el array en 0.
    iniciarArrays(persona, CANTIDAD);

    //Se carga la estructura para probar las funciones.
    cargaDePrueba(persona, CANTIDAD);
    //contador.

    int i;
    //variable para funcionamiento del menu.
    int opcion;

    do
    {
        //llamada a la funcion del menu para mostrarlo.
        opcion = menu();
        //se entra en el case de la opcion ingresada
        switch(opcion)
        {
        case 1:
            agregarPersona(persona, CANTIDAD);//Se ingresa una persona.
            break;
        case 2:
            borrarPersona(persona, CANTIDAD);//Ingresar dni de una persona para eliminarlo.
            break;
        case 3:
            imprimirPersonas(persona, CANTIDAD);//imprimir lista de personas ordenadas por Nombre.
            break;
        case 4:
            graficar(persona, CANTIDAD);//grafico de rangos de edades.
            break;
        }
    }while(opcion!=5);

return 0;
}

