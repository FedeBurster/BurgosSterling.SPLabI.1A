#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "paises.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* directorio del archivo
 * \param pArrayListEmployee LinkedList*
 * \return int devuelve 1 si se carga con exito, 0 de lo contrario
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int okay = 0;
    FILE* pointerFile = fopen(path, "r");
    if (pointerFile != NULL)
    {
        if(parser_paisFromText(pointerFile, pArrayListEmployee))
        {
            okay = 1;
        }
    }
    fclose(pointerFile);
    return okay;
}

/** \brief Guarda los datos contenidos en la lista LinkedList en un archivo
 *
 * \param destino donde se encuentra el archivo
 * \param lista LinkedList
 * \return Devuelve 1 si se guarda con exito, 0 si no se guarda
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int okay = 0,i;

    FILE* pointerFile = fopen(path, "w");
    ePaises* auxPais = (ePaises*) pais_new();
    if(path != NULL && pArrayListEmployee != NULL && pointerFile != NULL )
    {
        fprintf(pointerFile, "id,nombre,infectados,recuperados,muertos\n");
        for (i=0; i<ll_len(pArrayListEmployee); i++)
        {
            auxPais = ll_get(pArrayListEmployee, i);
            fprintf(pointerFile, "%d,%s,%d,%d,%d\n", auxPais->id, auxPais->nombre, auxPais->infectados, auxPais->recuperados, auxPais->muertos );
        }
        printf("Se completo el guardado con exito\n");
        okay = 1;
    }else
    {
        printf("Ha ocurrido un error, los datos no fueron guardados\n");
    }
    return okay;
}


/** \brief Muestra en pantalla los paises con mas muertos
 *
 * \param lista LinkedList
 *
 */
void controllerMasMuertos(LinkedList* lista)
{
    ePaises* max;
    ePaises* aux;
    int i;

    ll_sort(lista,sortByMuertos,0);
    max=(ePaises*)ll_get(lista,0);
    for(i=0;i<ll_len(lista);i++)
    {
        aux=ll_get(lista,i);

        if(max->muertos==aux->muertos)
        {
            listPais(lista,i);
        }
    }
    system("pause");
}
