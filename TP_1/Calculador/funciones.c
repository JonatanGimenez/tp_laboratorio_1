#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/** \brief Funcion para ingresar valores.
 * \param  void, no recibe nada.
 * \return retorna el valor ingresado.
 */
float pedirNumero()
{
    float A;
    printf("Ingrese un numero: ");
    scanf("%f", &A);
    return A;
}



/** \brief Funcion para calcular la suma entre dos valores.
 * \param  A, B. Recibe dos valores.
 * \return retorna el resultado de la suma de los valores recibidos.
 */
float sumar(float A, float B)
{
    float resultado;
    resultado = A + B;
    return resultado;
}



/** \brief Funcion para calcular la resta entre dos valores.
 * \param  A, B. Recibe dos valores.
 * \return retorna el resultado de la resta entre los dos valores recibidos.
 */
float restar(float A, float B)
{
   float resultado;
   resultado = A - B;
   return resultado;
}



/** \brief Funcion para calcular el producto entre dos valores.
 * \param A, B. Recibe dos valores.
 * \return Retorna el producto entre los dos valores recibidos.
 */
float multiplicar(float A, float B)
{
    float resultado;
    resultado = A * B;
    return resultado;
}



/** \brief Funcion para calcular la division entre dos valores.
 * \param A, B. Recibe dos numeros.
 * \return Retorna el resultado de la division entre los valores.
 */
float division(float A, float B)
{
    float resultado;
    if(B!=0)
    {
        resultado =  A / B;
        return resultado;
    }
    else
    {
        printf("Error\n");
        return 0;
    }
}



/** \brief Calcula el factorial del valor ingresado.
 * \param auxFacA, recibe la parte entera del valor ingresado.
 * \return retorna el factor del valor ingresado.
 */
int factorial(int auxFacA)
{
   int resultado;
   if(auxFacA==1)
    {
        return 1;
    }
   resultado = auxFacA * factorial(auxFacA-1);
   return resultado;
}


