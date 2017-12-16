#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define LIMITE_ARREGLOS 50

int cantidadProcesos,temporal,i,j,k,quantum,eleccionProceso,opcionRepetir;
int procesos [LIMITE_ARREGLOS] ;// rafaga
int prioridades [LIMITE_ARREGLOS];
int posiciones[LIMITE_ARREGLOS]; //

void FIFO ()
{

    printf("Ingresa la cantidad de procesos \n");
    scanf("%d",&cantidadProcesos);
    if(cantidadProcesos>LIMITE_ARREGLOS)
    {
        printf("La cantidad de procesos debe ser menor a 50 \n");
    }

    while(cantidadProcesos>LIMITE_ARREGLOS);


    for(i=0; i<cantidadProcesos; i++)
    {
        posiciones[i]=i+1;
        printf("Ingrese la rafaga del Proceso %d\n", posiciones[i]);
        scanf("%d", &procesos[i]);
        getchar();

    }

    printf("-----FIFO-----\n");
    for(i=0; i<cantidadProcesos; i++)
    {
        printf("Proceso %d = %d\n", i+1, procesos[i]);
    }
    for(i=0; i<cantidadProcesos; i++)
    {
        printf("\n\nProceso %d: %d\t", posiciones[i], procesos[i]);
        for(j=procesos[i]; j>=0; j--)
        {
            printf("%d\t", procesos[i]);
            procesos[i]=procesos[i]-1;

        }
        printf("\n");
    }
    printf("procesos finalizados\n");
    system("pause");
    system("cls");

}

void SJF()
{
    do
    {
        printf("Ingresa la cantidad de procesos \n");
        scanf("%d",&cantidadProcesos);
        if(cantidadProcesos>LIMITE_ARREGLOS)
        {
            printf("La cantidad de procesos debe ser menor a 50 \n");
        }
    }
    while(cantidadProcesos>LIMITE_ARREGLOS);


    for( i =0; i<cantidadProcesos; i++)
    {
        printf("Determina la rafaga de del proceso[%d]\n",i+1);
        scanf("%d", &procesos[i]);
    }
    for ( i=0; i<cantidadProcesos; i++)
    {


        for( j =0; j<cantidadProcesos-1; j++)
        {
            if (procesos [j]>=procesos[j+1])
            {

                temporal = procesos[j];
                procesos[j] = procesos[j+1];
                procesos[j+1] = temporal;

                temporal = posiciones[j];
                posiciones[j] = posiciones [j+1];
                posiciones [j+1]= temporal;

            }

        }

    }


    printf("Proceso\t \t \t Rafaga del proceso \n");
    for( i =0; i<cantidadProcesos; i++)
    {
        printf("%d \t\t\t %d \n", posiciones[i], procesos[i]);
        Sleep(1000);
    }
    printf("NP=Numero de proceso\n");
    printf("R=Rafaga\n");
    for(i=0; i<cantidadProcesos; i++)
    {

        printf("Proceso \t\t\t Rafaga \n");

        printf(" NP:%d \t\t\t R:%d \t ",posiciones[i], procesos[i]);
        for(j=procesos[i]; j>=0; j--)
        {

            printf("%d\t", procesos[i]);
            procesos[i]=procesos[i]-1;
            Sleep(1000);
        }
        printf("\n");
    }
}
void ROUND_ROBIN ()
{
    printf("Ingresa la cantidad de procesos \n");
    scanf("%d",&cantidadProcesos);

    if(cantidadProcesos>LIMITE_ARREGLOS)
    {
        printf("La cantidad de procesos debe ser menor a 50 \n");
    }

    while(cantidadProcesos>LIMITE_ARREGLOS);


    for(i = 0; i<cantidadProcesos; i++)
    {
        posiciones [i]=i+1;
        printf("Determina la rafaga de del proceso[%d]\n", posiciones[i]);
        //arreglos procesos en la posicion (i)
        scanf("%d", &procesos[i]);
    }

    printf("Ingresa el quantum\n");
    scanf("%d", &quantum);

    printf("cola de listos\n");
    for(i=0; i<cantidadProcesos; i++)
    {
        printf("Proceso[%d]: %d\n\n", posiciones[i], procesos[i]);
    }
    for(i=0; i<cantidadProcesos; i++)
    {
        if(procesos[i]>0)
        {
            for(j=0; j<cantidadProcesos; j++)
            {
                if(procesos[j]>0)
                {
                    printf("Proceso[%d]: %d \t", posiciones[j], procesos[j]);


                    for(k=0; k<quantum; k++)
                    {
                        if(procesos[j]>0)
                        {
                            procesos[j]=procesos[j]-1;
                            printf("%d\t", procesos[j]);
                            Sleep(1000);
                        }
                    }
                    printf("\n");
                }
            }
        }

    }
    system("pause");
    system("cls");
}

void PRIORIDAD ()
{
    do
    {
        printf("Ingresa la cantidad de procesos \n");
        scanf("%d",&cantidadProcesos);
        if(cantidadProcesos>LIMITE_ARREGLOS)
        {
            printf("La cantidad de procesos debe ser menor a 50 \n");
        }
    }
    while(cantidadProcesos>LIMITE_ARREGLOS);


    for( i =0; i<cantidadProcesos; i++)
    {
        posiciones[i] = i+1;
        printf("Determina la rafaga de del proceso[%d]\n",posiciones[i]);
        scanf("%d", &procesos[i]);


        printf("Determina la prioridad del proceso [%d]\n",posiciones[i]);
        scanf("%d", &prioridades[i]);


    }
    for ( i=0; i<cantidadProcesos; i++)
    {
        for( j =0; j<cantidadProcesos-1; j++)
        {
            if (prioridades[j]>=prioridades[j+1])
            {

                temporal = procesos[j];
                procesos[j] = procesos[j+1];
                procesos[j+1] = temporal;

                temporal = posiciones[j];
                posiciones[j] = posiciones[j+1];
                posiciones[j+1]= temporal;


                temporal=prioridades[j];
                prioridades[j]=prioridades[j+1];
                prioridades[j+1]=temporal;

            }

        }

    }


    printf("Prioridad\t \t \t Proceso \t\t\t Rafaga \n");
    for( i =0; i<cantidadProcesos; i++)
    {
        printf("P%d \t\t\t\t %d\t\t\t\t %d \n",prioridades[i], posiciones[i],procesos[i]);
        Sleep(1000);
    }
    //Momento deonde se ejecuta el proceso
    printf("P=Prioridad\n");
    printf("NP=Numero de proceso\n");
    printf("R=Rafaga\n");

    for(i=0; i<cantidadProcesos; i++)
    {
        printf("Prioridad %d Proceso %d:", prioridades[i], posiciones[i]);
        for(j=procesos[i]; j>=0; j--)

        {
            printf("%d\t", procesos[i]);
            procesos[i]=procesos[i]-1;
            Sleep(1000);
        }
        printf("\n");
    }
    printf("procesos finalizados\n");
    system("pause");
    system("cls");

}

int main()
{
    system("color F0");
    int eleccionProceso;
    int opcionRepetir;
    printf("PROGRAMA DE SISTEMAS OPERATIVOS\n");

    do
    {
        printf("Elige el algo que deseas utilizar\n");
        printf("1.-Algoritmo FIFO\n");
        printf("2.-Algoritmo SJF\n");
        printf("3.-Algoritmo ROUN ROBIN\n");
        printf("4.-Algoritmo PRIORIDAD\n");
        scanf("%d",&eleccionProceso);


        switch (eleccionProceso)
        {
        case 1:
            FIFO();
            break;
        case 2:
            SJF();
            break;
        case 3:
            ROUND_ROBIN();
            break;
        case 4:
            PRIORIDAD();
            break;
        default:
            printf("Ingresa una opcion valida \n");
            break;
        }

        printf("Deseas Volver a elejir otro algoritmo  \n");
        printf("1 seguir 0 salir\n");
        scanf("%d",&opcionRepetir);
        system("cls");
    }
    while(opcionRepetir == 1  );

    return 0;
}

