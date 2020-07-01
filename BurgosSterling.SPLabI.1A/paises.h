#include "LinkedList.h"

#ifndef PAISES
#define PAISES
typedef struct{
    int id;
    char nombre[20];
    int recuperados;
    int infectados;
    int muertos;
}ePaises;

ePaises* pais_new();

ePaises* pais_newParam(char* idString,char* nombreString,char* recuperadosString, char* infectadosString,char*muertosString);

int auto_setId(ePaises* this,int id);
int auto_setNombre(ePaises* this,char* nombre);
int auto_setRecuperados(ePaises* this,int recuperados);
int auto_setMuertos(ePaises* this,int muertos);
int auto_setInfectados(ePaises* this,int infectados);

void listPais(LinkedList* lista, int index);
void listPaises(LinkedList* lista);

void* funcCargarPaises(void* this);

int filtrarPaisesExitosos(void* pais);
int filtrarPaisesHorno(void* pais);
int sortByInfectados(void* pais1, void* pais2);

int pais_getInfectados(ePaises* this,int* infectados);

int pais_getId(ePaises* this,int* id);
int pais_getMuertos(ePaises* this,int* muertos);

int sortByMuertos(void* pais1, void* pais2);
#endif
