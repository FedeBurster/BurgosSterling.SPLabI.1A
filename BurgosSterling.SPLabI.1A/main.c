#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "burgos.h"
#include <time.h>
#include "Controller.h"
#include "paises.h"

int main()
{
    int option = 0, flag=0;
    LinkedList* auxList = ll_newLinkedList();
    LinkedList* subList = ll_newLinkedList();
    LinkedList* paisesExitosos = ll_newLinkedList();
    LinkedList* paisesEnElHorno = ll_newLinkedList();
    srand(time(NULL));
    char auxString[30];

    do{
        option=mainMenu();
        switch(option)
        {
            case 1:
                if(!flag)
                {
                    printf("Ingrese el nombre del archivo: ");
                    scanf("%s",auxString);
                    if(controller_loadFromText(auxString,auxList))
                    {
                        printf("La carga se completo con exito\n");
                        system("pause");
                        flag=1;
                    }
                    else
                    {
                        printf("Ocurrio un error al cargar el archivo\n");
                        system("pause");
                    }
                }
                break;
            case 2:
                if(flag)
                {
                    listPaises(auxList);
                    system("pause");
                }
                else{
                    printf("\nSe debe cargar el archivo\n");
                    system("pause");
                }
                break;
            case 3:
                if(flag)
                {
                    subList=ll_map(auxList,funcCargarPaises);
                    listPaises(subList);
                    printf("\nDatos simulados con exito\n");
                    system("pause");
                }
                else{
                    printf("\nSe debe cargar el archivo\n");
                    system("pause");
                }
                break;
            case 4:
                if(flag)
                {
                    paisesExitosos=ll_filter(auxList,filtrarPaisesExitosos);
                    listPaises(paisesExitosos);
                   controller_saveAsText("paisesExitosos" ,paisesExitosos);
                    printf("\nLista guardada con exito\n");
                    system("pause");
                }
                else{
                    printf("\nSe debe cargar el archivo\n");
                    system("pause");
                }
                break;
            case 5:
                if(flag)
                {
                    paisesEnElHorno=ll_filter(auxList,filtrarPaisesHorno);
                    controller_saveAsText("paisesEnElHorno" ,paisesEnElHorno);
                    listPaises(paisesEnElHorno);
                    printf("\nLista guardada con exito\n");
                    system("pause");
                }
                else{
                    printf("\nSe debe cargar el archivo\n");
                    system("pause");
                }
                break;
            case 6:
                if(flag)
                {
                    ll_sort(auxList,sortByInfectados,0);
                    listPaises(auxList);
                    system("pause");
                }
                else{
                    printf("\nSe debe cargar el archivo\n");
                    system("pause");
                }
                break;
            case 7:
                if(flag)
                {
                    controllerMasMuertos(auxList);
                }
                else{
                    printf("\nSe debe cargar el archivo\n");
                    system("pause");
                }
                break;
            default:
                break;
        }
    }while(option != 8);
    return 0;
}
