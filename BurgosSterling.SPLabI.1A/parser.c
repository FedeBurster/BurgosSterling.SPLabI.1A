#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "paises.h"

/** \brief Parsea los datos los datos de los paises desde el archivo pandemia.csv (modo texto).
 *
 * \param pointerFile File* puntero a la direccion de memoria de un archivo abierto
 * \param pArrayList LinkedList*
 * \return int devuelve 1 si se completa con exito, 0 de lo contrario
 *
 */
int parser_paisFromText(FILE* pointerFile , LinkedList* pLinkedList)
{
    int okay=0;
    int quantity;
    char stringFile[5][128];

    ePaises* auxPais = (ePaises*) pais_new();
    if (pointerFile == NULL || pLinkedList == NULL)
    {
        return okay;
    }
    fscanf(pointerFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]",stringFile[0], stringFile[1], stringFile[2], stringFile[3], stringFile[4]);
    while(!feof(pointerFile))
    {
        quantity = fscanf(pointerFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]",stringFile[0], stringFile[1], stringFile[2], stringFile[3], stringFile[4]);
        if(quantity == 5)
        {
            auxPais = pais_newParam(stringFile[0], stringFile[1], stringFile[2], stringFile[3], stringFile[4]);
            if (auxPais != NULL)
            {
                ll_add(pLinkedList, auxPais);
            }
        }
    }
    okay = 1;
    return okay;
}
