#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"
#include "sector.h"

void inicializarEmpleados(employee* empleado,int tam)
{

    for(int i=0; i < tam; i++)
    {
        empleado[i].isEmpty = 1;
    }
}

int buscarLibre(employee* empleado, int tam){
    int i;
    int index=-1;

        for(i=0; i<tam; i++){
            if(empleado[i].isEmpty==1){
            index=i;
            break;
        }
    }

    return index;
}
void altaEmpleado(employee* empleado, int tam){
    int i;
    i= buscarLibre(empleado,tam);
    if(i!=-1){
        printf("ingrese el nombre: ");
        fflush(stdin);
        gets(empleado[i].name);
        printf("ingrese el apellido: ");
        fflush(stdin);
        gets(empleado[i].lastName);
        printf("ingrese el salario: ");
        fflush(stdin);
        scanf("%f",&empleado[i].salary);
        printf("ingrese el sector:\n\n 1-Administracion\n 2-Comunicaciones\n 3-Comercio\n\n ");
        fflush(stdin);
        scanf("%d",&empleado[i].idSector);
        empleado[i].id=i+1;

        empleado[i].isEmpty=0;

    }
    else
    {
        printf("No hay espacio");
    }

}
int estudiante_buscarID(employee empleado[], int tam, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(empleado!= NULL && tam>=0)
    {
        for(i=0;i<tam;i++)
        {
            if(empleado[i].isEmpty==1)
                continue;
            else if(empleado[i].id==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
int estudiante_baja(employee empleado[], int tam)
{
    int retorno=-1;
    int posicion;
    int idEst;
    if(empleado!=NULL && tam>0)
    {
        printf("ingrese la id que se busca");
        scanf("%d",&idEst);
        if(estudiante_buscarID(empleado,tam,idEst,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            empleado[posicion].isEmpty=1;
            empleado[posicion].id=0;
            empleado[posicion].idSector=0;
            empleado[posicion].salary=0;
            strcpy(empleado[posicion].name,"");
            strcpy(empleado[posicion].lastName,"");
            retorno=0;
            printf("se elimino correctamente");
        }
    }
    return retorno;
}



int estudiante_modificar(employee empleado[], int tam)
{
    int retorno=-1;
    int posicion;
    int idEst;
    char opcion;
    if(empleado!=NULL && tam>0)
    {
        printf("ingrese la id del estudiante a modificar");
        scanf("%d",&idEst);
        if(estudiante_buscarID(empleado,tam,idEst,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
                printf("ingrese una opcion de la A a la D y S para salir");
                fflush(stdin);
                scanf("%c",&opcion);
                switch(opcion)
                {
                    case 'A':
                        printf("ingrese el nuevo nombre: ");
                        fflush(stdin);
                        gets(empleado[posicion].name);
                        break;
                    case 'B':
                        printf("ingrese el nuevo apellido: ");
                        fflush(stdin);
                        gets(empleado[posicion].lastName);
                        break;
                    case 'C':
                        printf("ingrese el salario: ");

                        scanf("%f",&empleado[posicion].salary);
                        break;
                    case 'D':
                        printf("ingrese el nuevo sector:\n\n 1-Administracion\n 2-Comunicaciones\n 3-Comercio\n\n ");
                        fflush(stdin);
                        scanf("%d",&empleado[posicion].idSector);
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}
int getDescripcionSector(eSector arraySector[], int ts, int buscar, char* descripcion)
{
    int i;
    for(i=0;i<ts;i++)
    {
        if(arraySector[i].idSector==buscar)
        {
            strcpy(descripcion,arraySector[i].descripcionSector);
        }
    }
    return 0;
}
int estudiante_listar(employee empleado[], int tam, eSector arraySector[], int ts)                      //cambiar estudiante
{
    int retorno=-1;
    int i;
    char descSector[20];
    if(empleado!=NULL && tam>=0)
    {

         printf("ID |Nombre  |Apellido   |Sueldo |ID Sector |Descripcion de sector\n");
        for(i=0;i<tam;i++)
        {


            if(empleado[i].isEmpty!=1)
            {
                getDescripcionSector(arraySector,ts,empleado[i].idSector, descSector);
                printf("\n %2d|  %5s| %5s| %.2f| %2d| %5s\n",empleado[i].id, empleado[i].name, empleado[i].lastName,empleado[i].salary , empleado[i].idSector, descSector);

            }

        }
        retorno=0;
    }
    return retorno;
}





