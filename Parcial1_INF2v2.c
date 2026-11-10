#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//calles 1 y 2
//intensidad del trafico 0 = vacio, 100 = mucho trafico
typedef struct {
    char Calle1[50];
    char Calle2[50];
    int trafico;
} Calles; // typedef para escribir solo calles

//mostrar datos de un semaforo calle 1 ycalle 2, trafico
void mostrar_datos(Calles c) {
    printf("Calle 1: %s\n", c.Calle1);
    printf("Calle 2: %s\n", c.Calle2);
    printf("Trafico: %d\n", c.trafico);
}
//pide al usuario los datos de un semaforo y los guarda en la estructura
void ingresar_semaforo(Calles *s) {
    printf("Ingrese nombre de la Calle 1: ");
    scanf("%s", s->Calle1);
    printf("Ingrese nombre de la Calle 2: ");
    scanf("%s", s->Calle2);
    //do while para validar que el trafico este entre 1 y 100, sino muestra un error
    do {
        printf("Ingrese intensidad de trafico (entre 1 y 100): ");
        scanf("%d", &s->trafico);
        if (s->trafico < 1 || s->trafico > 100) {
            printf("Error\n");
        }
      //entre 1 y 100
    } while (s->trafico < 1 || s->trafico > 100);
}
//pide al usuario que ingrese la cantidad de semaforos a registrar
int menu(Calles *semaforo, int cantidad_actual) {
    int cantidad;
    printf("Ingrese cantidad de semaforos a registrar: ");
    scanf("%d", &cantidad);
    for (int i = 0; i < cantidad; i++) {
        printf("Registro de semaforo %d:\n", cantidad_actual + i + 1);
        ingresar_semaforo(&semaforo[cantidad_actual + i]);  //direccion de semaforo
    }
    return cantidad_actual + cantidad; //devuelve la cantidad de semaforos registrados 
}
//recorre el arreglo con un for y muestra cada semaforo 
void mostrar_todos(Calles semaforo[], int cantidad) {

    printf("Datos de los semáforos:\n");
    //recorre el arreglo con un for y muestra cada semaforo usando la funncion mostrar datos
    for (int i = 0; i < cantidad; i++) {
        printf("Semaforo %d:\n", i + 1);
        mostrar_datos(semaforo[i]); 
    }
}

//operacion con cadenas de caracter
void buscar_por_calle(Calles semaforo[], int cantidad) {
    char calle[50];
    int encontrado = 0;
    printf("Ingrese el nombre de la calle a buscar: ");
    scanf("%s", calle);
    printf("Intersecciones para la calle %s:\n", calle);
    for (int i = 0; i < cantidad; i++) {
        if (strstr(semaforo[i].Calle1, calle) != NULL || strstr(semaforo[i].Calle2, calle) != NULL) {
            printf("Semaforo %d:\n", i + 1);
            mostrar_datos(semaforo[i]);
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("No se encontraron intersecciones para la calle %s\n", calle);
    }
}


int main() {
    // malloc reserva memoria para 100 estructuras 
    Calles *semaforo = malloc(100 * sizeof(Calles));
    int cantidad = 0, opcion;
    //menu
    do {
        printf("Gestion de Semaforos\n");
        printf("1. Ingresar datos de semaforos\n");
        printf("2. Mostrar todos los semaforos\n");
        printf("3. Buscar intersecciones por calle\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                cantidad = menu(semaforo, cantidad);
                break;
            case 2:
                mostrar_todos(semaforo, cantidad);
                break;
            case 3:
                buscar_por_calle(semaforo, cantidad);
                break;
            case 4:
                printf("Saliendo del programa\n");
                break;
            default:
                printf("Error: Opcion invalida.\n");
        }
    } while (opcion != 4);
    free(semaforo);
    return 0;
}