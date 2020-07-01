#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "burgos.h"
#include "paises.h"


/** \brief muestra el menu principal del programa
 *
 * \return devuelve la opcion ingresada por el usuario
 *
 */

int mainMenu()
{
    int respuesta = -1;

    system("cls");

    printf("Menu:\n");
    printf(" 1. Cargar los datos de los paises desde el archivo.\n");
    printf(" 2. Imprimir lista.\n");
    printf(" 3. Asignar datos simulados\n");
    printf(" 4. Filtrar paises exitosos\n");
    printf(" 5. Filtrar paises en el horno\n");
    printf(" 6. Ordenar por nivel de infeccion\n");
    printf(" 7. Mostrar mas castigado\n");
    printf(" 8. Salir\n");
    printf("Ingresar opcion: ");

    scanf("%d", &respuesta);
    fflush(stdin);
    return respuesta;
}
