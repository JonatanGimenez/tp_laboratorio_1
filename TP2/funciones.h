//declaracion de estructura;
typedef struct
{
    char nombre[50];
    int edad;
    long int dni;
    int estado;
}estructuraPersona;

//declaracion de prototipos de funciones:
int menu();
void iniciarArrays(estructuraPersona personal[], int largoArray);
void agregarPersona(estructuraPersona Personal[], int largoArray);
void borrarPersona(estructuraPersona personal[], int largoArray);
void imprimirPersonas(estructuraPersona personal[],int largoArray);
int graficar(estructuraPersona personal[],int largoArray);
void cargaDePrueba(estructuraPersona personal[], int largoArray);
