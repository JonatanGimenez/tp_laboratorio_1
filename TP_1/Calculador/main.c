#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "funciones.h"

int main()
{
    char seguir=1;
    int opcion=0;
    float A=0.0;
    float B=0.0;
    float resultado=0.0;
    int auxFacA;
    int intentos = 0;
  /*Muestra el menu al inciar el programa y pide ingresar una opcion*/
    while(seguir==1)
    {
        printf("Ingrese una opcion\n\n");
        printf("1- Ingresar 1er operando (A = %.2f)\n", A);
        printf("2- Ingresar 2do operando (B = %.2f)\n", B);
        printf("3- Calcular la suma (%.2f + %.2f)\n", A, B);
        printf("4- Calcular la resta (%.2f - %.2f)\n", A, B);
        printf("5- Calcular la division (%.2f / %.2f)\n", A, B);
        printf("6- Calcular la multiplicacion (%.2f * %.2f)\n", A, B);
        printf("7- Calcular el factorial (%.2f)\n", A);
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n\n");
        printf("Opcion: ");
        scanf("%d",&opcion);

      /*Segun la opcion ingresada se llamara a la funcion dentro del case correspondiente.
       (de no ser valida la opcion, se pedira el reingreso de la misma)*/
        switch(opcion)
        {
            case 1:
                A = pedirNumero();
                intentos--;
                break;
            case 2:
                B = pedirNumero();
                intentos--;
                break;
            case 3:
                resultado = sumar(A, B);
                printf("La suma de %.2f + %.2f es: %.2f\n", A, B, resultado);
                intentos--;
                break;
            case 4:
                resultado = restar(A, B);
                printf("La resta de %.2f - %.2f es: %.2f\n", A, B, resultado);
                intentos--;
                break;
            case 5:
                resultado = division(A, B);
                if(B != 0)
                {
                    printf("La division de %.2f / %.2f es: %.2f\n", A, B, resultado);
                }
                intentos--;
                break;
            case 6:
                resultado = multiplicar(A, B);
                printf("El producto de %.2f * %.2f es: %.2f\n", A, B, resultado);
                intentos--;
                break;
            case 7:
                if(A!=0)
                {
                    auxFacA = (int)A;
                    resultado = factorial(auxFacA);
                    printf("El factor de %d es: %.0f\n", auxFacA, resultado);
                    intentos--;
                }
                else
                {
                    printf("Error\n");
                }
                intentos--;
                break;
            case 8:
                resultado = sumar(A, B);
                printf("La suma de %.2f + %.2f es: %.2f\n", A, B, resultado);
                resultado = restar(A, B);
                printf("La resta de %.2f - %.2f es: %.2f\n", A, B, resultado);
                resultado = division(A, B);
                printf("La division de %.2f / %.2f es: %.2f\n", A, B, resultado);
                resultado = multiplicar(A, B);
                printf("El producto de %.2f * %.2f es: %.2f\n", A, B, resultado);
                if(A!=0)
                {
                resultado = factorial(auxFacA);
                printf("El factor de %d es: %.0f\n", auxFacA, resultado);
                }
                else
                {
                    printf("Error\n");
                }
                intentos--;
                break;
            case 9:
                seguir = 0;
                break;
            default:
                printf("Error, opcion no valida\n\n");
                intentos++;
                if(intentos >= 3)
                {
                    printf("Demasiados intentos, el programa se cerrara\n\n");
                    seguir = 0;
                }
        }

      /*Si se elige la opcion 9 o se ingresan mas de 3 opciones no validas consecutivas
        el programa se cerrara automaticamente.
        De lo contrario, se pauseara el programa (para mostrar resultado)
        y luego se limpiara la pantalla*/
        if(opcion !=9)
        {
            system("pause");
            system("cls");

        }
    }
   return 0;
}





