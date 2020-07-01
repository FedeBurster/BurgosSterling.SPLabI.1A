#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "paises.h"
#include "LinkedList.h"
#include "burgos.h"


/** \brief Inicializa las variables de la estructura pais
 *
 * \return Devuelve la estructura inicializada
 *
 */
ePaises* pais_new()
{
    ePaises* newPais = (ePaises*) malloc(sizeof(ePaises));
    if (newPais != NULL)
    {
        newPais->id = 0;
        strcpy(newPais->nombre," ");
        newPais->recuperados = 0;
        newPais->infectados = 0;
        newPais->muertos = 0;
    }
    return newPais;
}

/** \brief Carga los parametros ingresados a la estructura pais
 *
 * \param cadena de caracteres que contiene el id
 * \param cadena de caracteres que contiene el nombre
 * \param cadena de caracteres que contiene el numero de recuperados
 * \param cadena de caracteres que contiene el numero de infectados
 * \param cadena de caracteres que contiene el numero de muertos
 * \return Devuelve la direccion de memoria a la estructura con los datos cargados
 *
 */
ePaises* pais_newParam(char* idString,char* nombreString,char* recuperadosString, char* infectadosString,char*muertosString)
{
    ePaises* newPais = pais_new();
    if (newPais != NULL)
    {
        auto_setId(newPais, atoi(idString));
        auto_setNombre(newPais, nombreString);
        auto_setRecuperados(newPais, atoi(recuperadosString));
        auto_setInfectados(newPais, atoi(infectadosString));
        auto_setMuertos(newPais, atoi(muertosString));
    }
    return newPais;
}

/** \brief Coloca el id ingresado en el campo id de una estructura pais
 *
 * \param direccion de memoria de una estructura pais
 * \param valor del id a cargar
 * \return Devuelve 1 si se completa con exito, 0 si no se completa
 *
 */
int auto_setId(ePaises* this,int id)
{
    int okay = 0;
    if (this != NULL)
    {
        this->id = id;
        okay = 1;
    }
    return okay;
}

/** \brief Coloca el nombre ingresado en el campo nombre de una estructura pais
 *
 * \param direccion de memoria de una estructura pais
 * \param cadena de caracteres que contiene el nombre
 * \return Devuelve 1 si se completa con exito, 0 si no se completa
 *
 */
int auto_setNombre(ePaises* this,char* nombre)
{
    int okay = 0;
    if (this != NULL)
    {
        strcpy(this->nombre, nombre);
        okay=1;
    }
    return okay;
}

/** \brief Coloca la cantidad de recuperados en una estructura pais
 *
 * \param direccion de memoria de una estructura pais
 * \param cantidad de recuperados
 * \return Devuelve 1 si se completa con exito, 0 si no se completa
 *
 */
int auto_setRecuperados(ePaises* this,int recuperados)
{
    int okay = 0;
    if (this != NULL)
    {
        this->recuperados = recuperados;
        okay = 1;
    }
    return okay;
}

/** \brief Coloca la cantidad de infectados en una estructura pais
 *
 * \param direccion de memoria de una estructura pais
 * \param cantidad de infectados
 * \return Devuelve 1 si se completa con exito, 0 si no se completa
 *
 */
int auto_setInfectados(ePaises* this,int infectados)
{
    int okay = 0;
    if (this != NULL)
    {
        this->infectados = infectados;
        okay = 1;
    }
    return okay;
}

/** \brief Coloca la cantidad de muertos en una estructura pais
 *
 * \param direccion de memoria de una estructura pais
 * \param cantidad de muertos
 * \return Devuelve 1 si se completa con exito, 0 si no se completa
 *
 */
int auto_setMuertos(ePaises* this,int muertos)
{
    int okay = 0;
    if (this != NULL)
    {
        this->muertos = muertos;
        okay = 1;
    }
    return okay;
}

/** \brief Recorre la lista LinkedList mostrando todos los elementos
 *
 * \param direccion de memoria del primer elemento de una lista linkedList
 *
 */
void listPaises(LinkedList* lista)
{
    int i;
    printf("  ID             Nombre    Recuperados  Infectados    Muertos\n");
    for (i=0; i<ll_len(lista); i++)
    {
        listPais(lista, i);
    }
}


/** \brief Muestra en pantalla los datos contenidos en una estructura pais
 *
 * \param direccion de memoria del primer elemento de una lista linkedList
 * \param indice donde se encuentra los datos a mostrar
 *
 */
void listPais(LinkedList* lista, int index)
{
    ePaises* auxPais = (ePaises*) pais_new();
    auxPais = ll_get(lista, index);
    printf("%4d  %18s  %9d    %9d %9d\n", auxPais->id, auxPais->nombre, auxPais->recuperados, auxPais->infectados,auxPais->muertos);
}


/** \brief Carga datos aleatorios en una estructura pais
 *
 * \param direccion de memoria de una estructura pais
 * \return Estructura pais con los datos cargados
 *
 */
void* funcCargarPaises(void* this)
{
    ePaises*auxPais=this;
    int auxRecu,auxInf,auxMuer;


    auxInf= rand() % 40000 + 1960001;
    auxMuer=rand() % 1000 + 49001;
    auxRecu=rand() % 50000 + 950001;

    auto_setRecuperados(auxPais, auxRecu);
    auto_setInfectados(auxPais, auxInf);
    auto_setMuertos(auxPais, auxMuer);

    return auxPais;
}

/** \brief Analiza si la estructura cumple con el criterio
 *
 * \param Estructura pais
 * \return Devuelve 1 si cumple con el criterio, de lo contrario devuelve 0
 *
 */
int filtrarPaisesExitosos(void* pais)
{
    ePaises* auxPais;
    int auxReturn = 0 ;

    if(pais!=NULL)
    {
        auxPais=(ePaises*)pais;
        if(auxPais->muertos<5000)
        {
            auxReturn=1;
        }
    }
    return auxReturn;
}

/** \brief Analiza si la estructura cumple con el criterio
 *
 * \param Estructura pais
 * \return Devuelve 1 si cumple con el criterio, de lo contrario devuelve 0
 *
 */
int filtrarPaisesHorno(void* pais)
{
    ePaises* auxPais;
    int auxReturn = 0 ;

    if(pais!=NULL)
    {
        auxPais=(ePaises*)pais;
        if(auxPais->recuperados>(auxPais->infectados/3))
        {
            auxReturn=1;
        }
    }
    return auxReturn;
}


/** \brief Compara dos estructuras pais
 *
 * \param primer estructura
 * \param segunda estructura
 * \return Devuelve 1 si el primero es mayor que el segundo, -1 si el segundo es mayor que el primero, 0 si son iguales
 *
 */
int sortByInfectados(void* pais1, void* pais2)
{
    int answer,infectados1,infectados2;

    pais_getInfectados(pais1, &infectados1);
    pais_getInfectados(pais2, &infectados2);
    if(infectados1 > infectados2)
    {
        answer = 1;
    }
    else if(infectados1 < infectados2)
    {
        answer = -1;
    }
    else
    {
        answer = 0;
    }
    return answer;
}

/** \brief Consigue la cantidad de infectados de una estructura pais
 *
 * \param estructura pais
 * \param direccion de memoria donde se guarda la cantidad de infectados
 * \return devuelve 1 si consigue la cantidad de infectados, 0 si no puede
 *
 */
int pais_getInfectados(ePaises* this,int* infectados)
{
    int okay = 0;
    if (this != NULL && infectados !=NULL)
    {
        *infectados = this->infectados;
        okay = 1;
    }
    return okay;
}

/** \brief Consigue el id de una estructura pais
 *
 * \param estructura pais
 * \param direccion de memoria donde se guarda el id
 * \return devuelve 1 si consigue el id, 0 si no puede
 *
 */
int pais_getId(ePaises* this,int* id)
{
    int okay = 0;
    if (this != NULL && id !=NULL)
    {
        *id = this->id;
        okay = 1;
    }
    return okay;
}

/** \brief Compara dos estructuras pais
 *
 * \param primer estructura
 * \param segunda estructura
 * \return Devuelve 1 si el primero es mayor que el segundo, -1 si el segundo es mayor que el primero, 0 si son iguales
 *
 */
int sortByMuertos(void* pais1, void* pais2)
{
    int answer,infectados1,infectados2;

    pais_getMuertos(pais1, &infectados1);
    pais_getMuertos(pais2, &infectados2);
    if(infectados1 > infectados2)
    {
        answer = 1;
    }
    else if(infectados1 < infectados2)
    {
        answer = -1;
    }
    else
    {
        answer = 0;
    }
    return answer;
}

/** \brief Consigue los muertos de una estructura pais
 *
 * \param estructura pais
 * \param direccion de memoria donde se guarda la cantidad de muertos
 * \return devuelve 1 si consigue la cantidad de muertos, 0 si no puede
 *
 */
int pais_getMuertos(ePaises* this,int* muertos)
{
    int okay = 0;
    if (this != NULL && muertos !=NULL)
    {
        *muertos = this->muertos;
        okay = 1;
    }
    return okay;
}
