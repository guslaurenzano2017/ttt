/*
 ============================================================================
 Name        : baseExamen1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "utn.h"


#define TRA 20
#define SER 10
#define CLI 10


typedef struct
{
    int dia;
    char mes;
    int anio;
} eFecha;


typedef struct
{
    int idTrabajo;
    char marcaBicicleta[26];
     eFecha fechaTrabajo;
    float rodadoBicicleta;
    int idServicio;
    int isEmpty;
} eTrabajo;

typedef struct
{
    int idServicio;
    char descripcionServicio[26];
    float precioServicio;
    int isEmpty;
} eServicio;

typedef struct
{
    int idCliente;
    char nombre[26];
     float peso;
    int isEmpty;
} eCliente;

int menu();

int inicializarTrabajos( eTrabajo trabajos[], int tamTrab);
void harcodearTrabajos( eTrabajo trabajos[]);
int buscarLibreTrabajo( eTrabajo trabajos[], int tamTrab);
int buscarTrabajo( eTrabajo trabajos[], int tamTrab, int idTrabajo);
int agregarTrabajo( eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamSer);
int modificarTrabajo( eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamSer);
int eliminarTrabajo( eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamSer);
void mostrarTrabajo( eTrabajo trabajos, eServicio servicios[], int tamSer);
int mostrarTrabajos( eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamSer);
int elegirServicio(eServicio servicios[], int tamSer);
int eProducto_ObtenerIDTrabajo(void);


/********************************************************************************************/
int inicializarServicios( eServicio servicios[], int tamSer);
void harcodearServicios(eServicio servicios[]);
int buscarLibreServicio( eServicio servicios[], int tamSer);
int buscarServicio(eServicio servicios[], int tamSer, int idServicio);
int agregarServicio(eServicio servicios[], int tamSer);
int modificarServicio(eServicio servicios[], int tamSer);
int eliminarServicio(eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamSer);
int mostrarServicios(eServicio servicios[], int tamSer);
int cargarDescripcionServicio(eServicio servicios[], int tamSer, int idServicio, char cadena[]);
int cargarPrecioServicio(eServicio servicios[], int tamSer, int idServicio, float* precioSer);
int eProducto_ObtenerIDServicio(void);
/********************************************************************************************/
int listarTrabajosXServicio(eTrabajo trabajos[],int tamTrab, eServicio servicios[], int tamSer);
int listarTrabajosOrdenadoxRodados(eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamSer);
int listarTrabajosOrdenadoxDescripcion(eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamSer);
void ordenarxServicioYTrabajo(eTrabajo trabajos[],int tamTrab, eServicio servicios[], int tamSer);
void ordenarxAnioYMarca(eTrabajo trabajos[],int tamTrab, eServicio servicios[], int tamSer);
void listarImporteTotaldeServiciosPrestados(eTrabajo trabajos[],int tamTrab, eServicio servicios[], int tamSer);

/*******************************************************************************************/
int inicializarClientes( eCliente clientes[], int tamCli);
void harcodearClientes(eCliente clientes[]);
int buscarLibreCliente( eCliente clientes[], int tamCli);
int buscarCliente(eCliente clientes[], int tamCli, int idCliente);
int agregarCliente(eCliente clientes[], int tamCli);
int modificarCliente(eCliente clientes[], int tamCli);
int eliminarCliente(eTrabajo trabajos[], int tamTrab, eCliente clientes[], int tamCli);
int mostrarClientes(eCliente clientes[], int tamCli);
int cargarDescripcionCliente(eCliente clientes[], int tamCli, int idCliente, char cadena[]);
int cargarPesoCliente(eCliente clientes[], int tamCli, int idCliente, float* pesoCli);
int eProducto_ObtenerIDCliente();
/********************************************************************************************/




int main()
{
    setbuf(stdout,NULL);
    char seguir = 's';

    eTrabajo trabajos[TRA];
    eServicio servicios[SER];
    eCliente clientes[CLI];

    inicializarTrabajos(trabajos, TRA);
    inicializarServicios(servicios, SER);
    inicializarClientes(clientes, CLI);

    harcodearTrabajos(trabajos);
    harcodearServicios(servicios);
    harcodearClientes(clientes);

    do
    {
        switch(menu())
        {

        case 1:
            agregarTrabajo(trabajos, TRA , servicios,SER);
            break;
        case 2:
             modificarTrabajo(trabajos, TRA, servicios,SER);

			break;
        case 3:
            eliminarTrabajo(trabajos, TRA, servicios,SER);
            break;
        case 4:
			agregarCliente(clientes,CLI);
            break;
        case 5:
            modificarCliente(clientes, CLI);
     		break;
        case 6:
        	eliminarCliente(trabajos, TRA ,clientes,CLI);
			break;
		case 7:
			agregarServicio(servicios, SER);
			break;
		case 8:
			modificarServicio(servicios, SER);

			break;
		case 9:
			eliminarServicio(trabajos, TRA,servicios,SER);
			break;
        case 10:
            mostrarTrabajos(trabajos, TRA, servicios,SER);
            system("pause");
            break;
        case 11:
        	listarTrabajosOrdenadoxRodados(trabajos,TRA, servicios, SER);
            system("pause");
            break;
        case 12:
        	listarTrabajosOrdenadoxDescripcion(trabajos,TRA, servicios, SER);
            system("pause");
            break;
        case 13:
        	listarTrabajosXServicio(trabajos, TRA, servicios,SER);
        	system("pause");
            break;
        case 14:
        	ordenarxServicioYTrabajo(trabajos,TRA, servicios, SER);
        	mostrarTrabajos(trabajos, TRA,servicios,SER);
        	system("pause");
            break;
        case 15:
        	mostrarServicios(servicios,SER);
			system("pause");
			break;
        case 16:
        	ordenarxAnioYMarca(trabajos, TRA, servicios,SER);
        	mostrarTrabajos(trabajos, TRA,servicios,SER);
			system("pause");
			break;
        case 17:
        	listarImporteTotaldeServiciosPrestados(trabajos,TRA,servicios,SER);
			system("pause");
			break;
        case 18:
            mostrarClientes(clientes,CLI);
			system("pause");
			break;
        case 19:

			system("pause");
			break;
       case 30:
            seguir = 'n';
            break;
        }
    }
    while(seguir == 's');
    return 0;
}
int menu()
{
    int opcion;
    system("cls");
    printf("***Menu de Opciones***\n\n");
    printf("1-  Alta trabajo\n");
    printf("2-  Modificar trabajo\n");
    printf("3-  Baja trabajo\n");
    printf("4-  Alta cliente\n");
    printf("5-  Modificar cliente\n");
    printf("6-  Baja cliente   \n");
    printf("7-  Alta servicio  \n");
    printf("8-  Modificar servicio \n");
    printf("9-  Baja servicio \n");

    printf("10-  Listar de trabajos ordenado x rodados\n");
	printf("11-  Listado de trabajos ordenado x descripcion\n");
	printf("12-  Mostrar datos de  los trabajos mas caros\n");
	printf("13-  Listar  trabajos x un servicio seleccionado  \n");
	printf("14-  Listar ordenado por servicio y trabajo \n");
    printf("15-  Listar servicios  \n");
    printf("16-  Ordenar x anio y marca \n");
	printf("17-  Total en pesos x todos los servicios prestados \n");
	printf("18-    \n");
	printf("19-    \n");

    printf("30- Salir\n");

    opcion=getValidInt("Ingrese una opcion: ", "Error, ingrese nuevamente.", 1, 30);
    return opcion;
}

int inicializarTrabajos( eTrabajo trabajos[], int tamTrab)
{
	int retorno=-1;
	int i;
	{
		    for(i=0; i < tamTrab; i++)
		    {
		    	trabajos[i].isEmpty = -1;
		    }
		    retorno=0;
	}
    return retorno;
}

void harcodearTrabajos( eTrabajo trabajos[])
{
    int i;
    eTrabajo y[]=
    {
        {1, "yeti", {1,2,2021},20 ,20001, 0},
		{2, "kona",{1,5,2021},24, 20002, 0},
        {3, "ibis", {8,5,2021},20, 20003, 0},
        {4, "ripley",{7,2,2021},12, 20004, 0},
        {5, "yeti",{1,8,2019}, 14, 20001, 0},
        {6, "kona",{3,9,2020}, 12, 20002, 0},
        {7, "ibis",{9,11,2020},20, 20003, 0}
    };

    for(i=0; i<7; i++)
    {
    	trabajos[i] = y[i];
    }

}
int buscarLibreTrabajo( eTrabajo trabajos[], int tamTrab)
{
    int indice = -1;
    int i;

    for(i=0; i< tamTrab; i++)
    {
        if( trabajos[i].isEmpty == -1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarTrabajo( eTrabajo trabajos[], int tamTrab, int idTrabajo)
{
    int indice = -1;
    int i;
    for(i=0; i < tamTrab; i++)
    {
        if( trabajos[i].idTrabajo == idTrabajo && trabajos[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int agregarTrabajo( eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamSer)
{
	eTrabajo nuevoTrabajo;
    int indice;
    int esta;
    int idTrabajo;
    char nuevaDesc[21];
    int retorno=-1;

    system("cls");
    printf("  *** Alta Trabajo ***\n\n");
    indice = buscarLibreTrabajo(trabajos, tamTrab);
    if(indice == -1)
		{
			printf("No hay lugar\n\n");
		}
    else
    {
        //idTrabajo=getValidInt("Ingrese id del 1 al 10000: ", "Error, ingrese nuevamente.", 1, 10000);
        idTrabajo= eProducto_ObtenerIDTrabajo();


        esta = buscarTrabajo(trabajos, tamTrab, idTrabajo);

        if(esta != -1)
        {
            printf("Existe un trabajo con el id:  %d\n", idTrabajo);
            mostrarTrabajo( trabajos[esta], servicios, tamSer);

        }
        else
        {
        	nuevoTrabajo.idTrabajo = idTrabajo;
        	getValidString("Ingrese marca bicicleta:  ", "Error, ingrese nuevamente.",nuevaDesc);
        	strcpy(nuevoTrabajo.marcaBicicleta, nuevaDesc);

        	nuevoTrabajo.fechaTrabajo.dia=getValidInt("Ingrese dia: ", "Error, ingrese nuevamente.", 1, 31);
        	nuevoTrabajo.fechaTrabajo.mes=getValidInt("Ingrese mes: ", "Error, ingrese nuevamente.", 1, 12);
			nuevoTrabajo.fechaTrabajo.anio=getValidInt("Ingrese anio: ", "Error, ingrese nuevamente.", 1978, 2021);

            nuevoTrabajo.rodadoBicicleta=getValidFloat("Ingrese rodado: ", "Error, ingrese nuevamente.", 1, 1000000);
            nuevoTrabajo.idServicio = elegirServicio(servicios, tamSer);
            nuevoTrabajo.isEmpty = 0;
            trabajos[indice] = nuevoTrabajo;
            retorno = 0;
          }
    }
    return retorno;
}

int modificarTrabajo( eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamSer)
{
	//eTrabajo nuevoTrabajo;
    int idTrabajo;
    int indice;
   // char modificar;
    int retorno=-1;
	 int cambiar;
	 char continuar;
	 char nuevaDesc[21];

    if(mostrarTrabajos(trabajos, tamTrab, servicios,tamSer)==-1)

    	        {
				printf("no hay trabajos cargados para modificar");
				}
      else{





				idTrabajo=getValidInt("Ingrese el id del 1 al 10000: ", "Error, ingrese nuevamente.", 1, 10000);
				indice = buscarTrabajo(trabajos, tamTrab, idTrabajo);
				if( indice == -1)
						{
							printf("No hay ningun producto con ese id %d\n", idTrabajo);
						}
						else
							{
								do
								{
									printf("\n\nSeleccione la opcion que desea modificar:");
									printf("\n1. marca de bicicleta\n");
									printf("2. fecha\n");
									printf("3. rodado\n");
									printf("4. tipo\n");

									//scanf("%d", &cambiar);
									cambiar=getValidInt("Ingrese opcion del  1 al 5: ", "Error, ingrese nuevamente.", 1, 5);
									switch(cambiar)
											{
											case 1:
												//nuevoTrabajo.idTrabajo = idTrabajo;
												getValidString("Ingrese marca de bicicleta:  ", "Error, ingrese nuevamente.",nuevaDesc);
												strcpy(trabajos[indice].marcaBicicleta, nuevaDesc);
												printf("Se ha modificado la marca con exito\n\n");
												break;

											case 2:
												printf("Ingrese la nueva fecha: ");

												trabajos[indice].fechaTrabajo.dia=getValidInt("Ingrese dia: ", "Error, ingrese nuevamente.", 1, 31);
												trabajos[indice].fechaTrabajo.mes=getValidInt("Ingrese mes: ", "Error, ingrese nuevamente.", 1, 12);
												trabajos[indice].fechaTrabajo.anio=getValidInt("Ingrese anio: ", "Error, ingrese nuevamente.", 1978, 2021);

												printf("Se ha modificado la fecha con exito\n\n");
												break;
											case 3:
												trabajos[indice].rodadoBicicleta=getValidFloat("Ingrese el precio nuevo  1 al 1000000: ", "Error, ingrese nuevamente.", 1, 1000000);
												break;
											case 4:
												trabajos[indice].idServicio = elegirServicio(servicios, tamSer);
												break;

											default :
												printf("Dato no valido\n");
											}

									printf("Desea continuar? s/n \n :");
									fflush(stdin);
									scanf("%c",&continuar);
									system("pause");
									system("cls");
								}
								while(continuar=='s' || continuar=='S');

								trabajos[indice].isEmpty=0;

									 printf("Se ha modificado el precio con exito\n\n");
									 retorno = 0;
									 system("pause");
				            }

    		}

			    return retorno;
}

int eliminarTrabajo( eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamSer)
{
    int idTrabajo;
    int indice;
    char borrar;
    int retorno = -1;
    mostrarTrabajos(trabajos, tamTrab, servicios,tamSer);
    printf("Ingrese id del trabajo a eliminar: ");
    scanf("%d", &idTrabajo);

    indice = buscarTrabajo(trabajos, tamTrab, idTrabajo);

    if( indice == -1)
    {
        printf("No hay ningun trabajo con ese id %d\n", idTrabajo);
    }
    else
    {
        mostrarTrabajo( trabajos[indice], servicios, tamSer);

        printf("\nConfirma borrado?: ");
        fflush(stdin);
        scanf("%c", &borrar);
        if(borrar != 's')
        {
            printf("Borrado cancelado\n\n");
        }
        else
        {
        	trabajos[indice].isEmpty = -1;
            printf("Se ha eliminado el trabajo\n\n");
            retorno = 0;
        }
        system("pause");

    }
    return retorno;
}

void mostrarTrabajo( eTrabajo trabajos, eServicio servicios[], int tamSer)
{

		char descripcionServicio[20];

		float precioSer;
	  cargarDescripcionServicio(servicios, tamSer, trabajos.idServicio, descripcionServicio);
	  cargarPrecioServicio(servicios, tamSer, trabajos.idServicio, &precioSer);
		printf("%d %20s  %15d   %20s  %15.2f  \n\n", trabajos.idTrabajo, trabajos.marcaBicicleta,trabajos.fechaTrabajo.anio, descripcionServicio, precioSer );
}

int mostrarTrabajos( eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamSer)
{
    int i;
     int retorno = -1;
    system("cls");
    printf(("idTrabajo          Marca         fecha       descripcion servicio     Precio servicio    \n\n"));
    	for(i=0; i< tamTrab; i++)
    	    {
    	        if( trabajos[i].isEmpty == 0)
    	        {
    	            mostrarTrabajo(trabajos[i], servicios, tamSer);
    	            retorno = 0;
    	        }
    	    }
    return retorno;
}


int elegirServicio(eServicio servicios[], int tamSer)
{
    int idSer;
    int i;
    printf("\nServicios\n\n");
    for(i=0; i < tamSer; i++)
    {
    	if(servicios[i].isEmpty == 0)
    	{
    		printf("%d %s %f\n", servicios[i].idServicio, servicios[i].descripcionServicio, servicios[i].precioServicio);
    	}
    }
    printf("\nSeleccione servicio: ");
    scanf("%d", &idSer);

    return idSer;
}

int Producto_idIncrementalTrabajo = 8;

int eProducto_ObtenerIDTrabajo() {
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	return Producto_idIncrementalTrabajo += 1;
}


/*****************************************************************************************************************/

int inicializarServicios( eServicio servicios[], int tamSer)
{
	int retorno=-1;
	int i;
	{
		    for(i=0; i < tamSer; i++)
		    {
		    	servicios[i].isEmpty = -1;
		    	 retorno=0;
		    }

	}

    return retorno;
}

void harcodearServicios(eServicio servicios[])
{
    int i;
    eServicio y[]=
    {
		{20001, "limpieza",250,0},
		{20002, "parche",300,0},
		{20003, "centrado",400,0},
		{20004, "cadena",350,0}
    };

    for(i=0; i<4; i++)
    {
    	servicios[i] = y[i];
    }
}

int buscarLibreServicio( eServicio servicios[], int tamSer)
{
    int indice = -1;
    int i;
    for(i=0; i< tamSer; i++)
    {
        if( servicios[i].isEmpty == -1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarServicio(eServicio servicios[], int tamSer, int idServicio)
{
    int indice = -1;
    int i;
    for(i=0; i < tamSer; i++)
    {
        if( servicios[i].idServicio == idServicio && servicios[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int agregarServicio(eServicio servicios[], int tamSer)
{
	eServicio nuevoServicio;
    int indice;
    int esta;
    int idServicio;
    char auxDescServicio[21];
    int retorno=-1;

    system("cls");
    printf("  *** Alta Servicio ***\n\n");
    indice = buscarLibreServicio(servicios, tamSer);

    if(indice == -1)
		{
			printf("No hay lugar\n\n");

		}
    else
    {

    	//idServicio=getValidInt("Ingrese id de servicio del : ", "Error, ingrese nuevamente.", 1, 100);
    	idServicio=eProducto_ObtenerIDServicio();

        esta = buscarServicio(servicios, tamSer, idServicio);

        if(esta != -1)
        {
            printf("Existe un servicio con el id:  %d\n", idServicio);
        }
        else
        {
        	nuevoServicio.idServicio = idServicio;

            getValidString("Ingrese servicio:  ", "Error, ingrese nuevamente.",auxDescServicio);
            strcpy(nuevoServicio.descripcionServicio, auxDescServicio);
            nuevoServicio.precioServicio=getValidFloat("Ingrese el precio nuevo  1 al 1000000: ", "Error, ingrese nuevamente.", 1, 1000000);
            nuevoServicio.isEmpty = 0;
            servicios[indice] = nuevoServicio;
            printf("Se ha cargado el servicio   con exito\n\n");
            retorno = 0;
          }
    }
    return retorno;
}

int modificarServicio(eServicio servicios[], int tamSer)
{
	//eServicio auxServicio;
    int idServicio;
    int indice;
    char modificar;
    char continuar;
    int retorno=-1;
    char nuevaDescServicio[21];
    int cambiar;

    mostrarServicios(servicios, tamSer);
    printf("Ingrese id de servicio a modificar: ");
    scanf("%d", &idServicio);
    indice = buscarServicio(servicios, tamSer, idServicio);
    if( indice == -1)
    {
        printf("No hay ningun servicio con ese id %d\n", idServicio);
    }
    else
    {
        printf("\nModifica servicio?: ");
        fflush(stdin);
        scanf("%c", &modificar);
        if(modificar != 's')
        {
            printf("Modificacion cancelada\n\n");
        }
        else
        {
						do
						{
							printf("\n\nSeleccione la opcion que desea modificar:");
							printf("\n1.descripcion\n");
							printf("2. precio\n");



							cambiar=getValidInt("Ingrese opcion del  1 al 2: ", "Error, ingrese nuevamente.", 1, 2);
							switch(cambiar)
									{
									case 1:
										//nuevoTrabajo.idTrabajo = idTrabajo;
										getValidString("Ingrese descripcion de servicio:  ", "Error, ingrese nuevamente.",nuevaDescServicio);
										strcpy(servicios[indice].descripcionServicio, nuevaDescServicio);
										printf("Se ha modificado la descripcion con exito\n\n");
										break;

									case 2:
										servicios[indice].precioServicio=getValidFloat("Ingrese el precio nuevo  1 al 1000000: ", "Error, ingrese nuevamente.", 1, 1000000);
										break;

									default :
										printf("Dato no valido\n");
									}
							servicios[indice].idServicio = idServicio;
							servicios[indice].isEmpty=0;
							printf("Desea continuar? s/n \n :");
							fflush(stdin);
							scanf("%c",&continuar);
							system("pause");
							system("cls");
						}
						while(continuar=='s' || continuar=='S');

							 retorno = 0;
							 system("pause");
					}

    }
    return retorno;
}


int eliminarServicio(eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamSer)
{

    int idServicio;
    int indice;
    char borrar;
    int retorno = -1;
    int i;
    char cadena[20];
    mostrarServicios(servicios, tamSer);
    system("pause");
    printf("Ingrese id de Servicio a eliminar: ");
    scanf("%d", &idServicio);
    indice = buscarServicio(servicios, tamSer, idServicio);
    if( indice == -1)
    {
        printf("No hay ninguna servicio con ese id %d\n", idServicio);
    }
    else
    {
    	cargarDescripcionServicio(servicios, tamSer, idServicio, cadena);
        printf("Servicio a borrar %s",cadena);
        printf("\nSi borra esta nacionalidad se borraran los trabajos asociados a ella.Confirma borrado?: ");
        fflush(stdin);
        scanf("%c", &borrar);
        if(borrar != 's')
        {
            printf("Borrado cancelado\n\n");
        }
        else

        {
        	for(i=0; i < tamTrab; i++)
        	  {
        	        if( trabajos[i].idServicio == idServicio && trabajos[i].isEmpty == 0)
        	        {
        	            trabajos[i].isEmpty =-1;
        	        }
        	 }
        	{
        	        	servicios[indice].isEmpty = -1;
        	            printf("Se ha eliminado la servicio\n\n");
        	            retorno = 0;
        	 }
          }
              system("pause");
    }
    return retorno;
}



int mostrarServicios(eServicio servicios[], int tamSer)

{
	int retorno=-1;
    int i;
    printf("\nServicios\n\n");
    printf("\nId            descripcion            precio \n\n");
    for(i=0; i < tamSer; i++)
    {
    	if(servicios[i].isEmpty == 0)
    	{
    		 printf("%d %20s %15.2f\n", servicios[i].idServicio, servicios[i].descripcionServicio, servicios[i].precioServicio);
    		 retorno=0;
    	}
    }
    return retorno;
}






int cargarDescripcionServicio(eServicio servicios[], int tamSer, int idServicio, char cadena[])
{
    int i;
    int retorno = -1;
    	for(i=0; i < tamSer; i++)
    	    {
    	        if( servicios[i].idServicio == idServicio)
    	        {
    	            strcpy(cadena, servicios[i].descripcionServicio);

    	            retorno = 0;
    	            break;
    	        }
    	    }
    return retorno;
}

int cargarPrecioServicio(eServicio servicios[], int tamSer, int idServicio, float* precioSer)
{
    int i;
    int retorno = -1;

    	for(i=0; i < tamSer; i++)
    	    {
    	        if( servicios[i].idServicio == idServicio)
    	        {

    	            *precioSer=servicios[i].precioServicio;
    	            retorno = 0;
    	            break;
    	        }
    	    }
    return retorno;
}

int Producto_idIncrementalServicio = 20005;

int eProducto_ObtenerIDServicio() {
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	return Producto_idIncrementalServicio += 1;
}


/*****************************************************************************************************/
/*****************************************************************************************************/
/*****************************************************************************************************/
int listarTrabajosXServicio(eTrabajo trabajos[],int tamTrab, eServicio servicios[], int tamSer)
{
    int idServicio;
    char descripcionServicio[20];

    int flag = 0;
    int i;
    int retorno = -1;

    idServicio = elegirServicio(servicios, tamSer);

    cargarDescripcionServicio(servicios, tamSer, idServicio, descripcionServicio);

    system("cls");
    printf("Productos del servicio  %s\n\n", descripcionServicio);
    for(i=0; i< tamTrab; i++)
    {
        if(trabajos[i].isEmpty == 0 && trabajos[i].idServicio == idServicio)
        {
            mostrarTrabajo(trabajos[i], servicios, tamSer);
            flag = 1;
            retorno=0;
        }
    }
    if(flag == 0)
    {
        printf("No hay trabajos que mostrar\n\n");
    }
    return retorno;
}
int listarTrabajosOrdenadoxRodados(eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamSer)
{
    int i;
    int j;
    int retorno = -1;
    eTrabajo auxiliar;
    {
    	  for(i=0; i<tamTrab-1; i++)
    	    {
    	        for(j=i+1; j<tamTrab; j++)
    	        {
    	            if(trabajos[i].rodadoBicicleta>trabajos[j].rodadoBicicleta)
    	            {
    	               auxiliar = trabajos[i];
    	               trabajos[i] = trabajos[j];
    	               trabajos[j] = auxiliar;
    	            }
    	        }
    	    }
    	    mostrarTrabajos(trabajos, tamTrab,servicios,tamSer);
    	    retorno = 0;
    }
    return retorno;
}

int listarTrabajosOrdenadoxDescripcion(eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamSer)
{
    int i;
    int j;
    eTrabajo auxiliar;
    int retorno=-1;
    {
    	  for(i=0; i<tamTrab-1; i++)
    	    {
    	        for(j=i+1; j<tamTrab; j++)
    	        {
    	            if(strcmp(trabajos[i].marcaBicicleta,trabajos[j].marcaBicicleta)>0)
    	            {
    	               auxiliar = trabajos[i];
    	               trabajos[i] = trabajos[j];
    	               trabajos[j] = auxiliar;
    	            }
    	        }
    	    }
    	    mostrarTrabajos(trabajos, tamTrab, servicios,tamSer);
    	    retorno = 0;
    }
    return retorno;
}

void ordenarxServicioYTrabajo(eTrabajo trabajos[],int tamTrab, eServicio servicios[], int tamSer)
{
    int i, j;
    char descripcionI[20];
    char descripcionJ[20];
    eTrabajo auxProducto;

    for(i=0; i<tamTrab-1; i++)
    {
        for(j = i+1; j<tamTrab; j++)
        {
        	cargarDescripcionServicio(servicios, tamSer, trabajos[i].idServicio, descripcionI);
        	cargarDescripcionServicio(servicios, tamSer, trabajos[j].idServicio, descripcionJ);
            if( strcmp(descripcionI, descripcionJ) > 0)
            {
            	auxProducto = trabajos[i];
            	trabajos[i] = trabajos[j];
            	trabajos[j] = auxProducto;
            }
            else if( strcmp(descripcionI, descripcionJ) == 0 && strcmp(trabajos[i].marcaBicicleta, trabajos[j].marcaBicicleta) > 0)
            {
            	auxProducto = trabajos[i];
            	trabajos[i] = trabajos[j];
            	trabajos[j] = auxProducto;
            }
        }
    }

}

void ordenarxAnioYMarca(eTrabajo trabajos[],int tamTrab, eServicio servicios[], int tamSer)
{
    int i, j;


    eTrabajo auxProducto;

    for(i=0; i<tamTrab-1; i++)
    {
        for(j = i+1; j<tamTrab; j++)
        {

            if(trabajos[i].fechaTrabajo.anio>trabajos[j].fechaTrabajo.anio )
            {
            	auxProducto = trabajos[i];
            	trabajos[i] = trabajos[j];
            	trabajos[j] = auxProducto;
            }
            else if((trabajos[i].fechaTrabajo.anio == trabajos[j].fechaTrabajo.anio ) && strcmp(trabajos[i].marcaBicicleta, trabajos[j].marcaBicicleta) > 0)
            {
            	auxProducto = trabajos[i];
            	trabajos[i] = trabajos[j];
            	trabajos[j] = auxProducto;
            }
        }
    }

}


void listarImporteTotaldeServiciosPrestados(eTrabajo trabajos[],int tamTrab, eServicio servicios[], int tamSer)
{
    int i, j;
    //char descripcionI[20];
   // char descripcionJ[20];
    //eTrabajo auxProducto;
    float acumulador=0;

    for(i=0; i<tamTrab; i++)
    {
        for(j=0 ; j<tamSer; j++)
        {
        	//cargarDescripcionServicio(servicios, tamSer, trabajos[i].idServicio, descripcionI);
        	//cargarDescripcionServicio(servicios, tamSer, trabajos[j].idServicio, descripcionJ);
            if(trabajos[i].isEmpty==0 && trabajos[i].idServicio==servicios[j].idServicio)
            {

            	acumulador=acumulador + servicios[j].precioServicio;
            }


        }
    }
   printf("El total en pesos por los servicios es: $  %.2f",acumulador);
}

/*****************************************************************************************************************/
/*****************************************************************************************************************/
/*****************************************************************************************************************/
/**********************************************************************************************************/

int inicializarClientes( eCliente clientes[], int tamCli)
{
	int retorno=-1;
	int i;
	{
		    for(i=0; i < tamCli; i++)
		    {
		    	clientes[i].isEmpty = -1;
		    	 retorno=0;
		    }

	}

    return retorno;
}

void harcodearClientes(eCliente clientes[])
{
    int i;
    eCliente y[]=
    {
		{1, "juan",50,0},
		{2, "pedro",80,0},
		{3, "hector",90,0},
		{4, "luis",89,0}
    };

    for(i=0; i<4; i++)
    {
    	clientes[i] = y[i];
    }
}

int buscarLibreCliente( eCliente clientes[], int tamCli)
{
    int indice = -1;
    int i;
    for(i=0; i< tamCli; i++)
    {
        if( clientes[i].isEmpty == -1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarCliente(eCliente clientes[], int tamCli, int idCliente)
{
    int indice = -1;
    int i;
    for(i=0; i < tamCli; i++)
    {
        if( clientes[i].idCliente == idCliente && clientes[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int agregarCliente(eCliente clientes[], int tamCli)
{
	eCliente nuevoCliente;
    int indice;
    int esta;
    int idCliente;
    char auxDescServicio[21];
    int retorno=-1;

    system("cls");
    printf("  *** Alta Cliente ***\n\n");
    indice = buscarLibreCliente(clientes, tamCli);

    if(indice == -1)
		{
			printf("No hay lugar\n\n");

		}
    else
    {

    	idCliente=eProducto_ObtenerIDCliente();
        esta = buscarCliente(clientes, tamCli, idCliente);

        if(esta != -1)
        {
            printf("Existe un cliente con el id:  %d\n", idCliente);
        }
        else
        {
        	nuevoCliente.idCliente = idCliente;

            getValidString("Ingrese nombre del cliente:  ", "Error, ingrese nuevamente.",auxDescServicio);
            strcpy(nuevoCliente.nombre, auxDescServicio);
            nuevoCliente.peso=getValidFloat("Ingrese el peso nuevo  1 al 100: ", "Error, ingrese nuevamente.", 1, 1000000);
            nuevoCliente.isEmpty = 0;
            clientes[indice] = nuevoCliente;
            printf("Se ha cargado el cliente   con exito\n\n");
            retorno = 0;
          }
    }
    return retorno;
}

int modificarCliente(eCliente clientes[], int tamCli)
{
	//eCliente auxServicio;
    int idCliente;
    int indice;
    char modificar;
    char continuar;
    int retorno=-1;
    char nuevaDescServicio[21];
    int cambiar;

    mostrarClientes(clientes, tamCli);
    printf("Ingrese id de cliente a modificar: ");
    scanf("%d", &idCliente);
    indice = buscarCliente(clientes, tamCli, idCliente);
    if( indice == -1)
    {
        printf("No hay ningun cliente con ese id %d\n", idCliente);
    }
    else
    {
        printf("\nModifica cliente?: ");
        fflush(stdin);
        scanf("%c", &modificar);
        if(modificar != 's')
        {
            printf("Modificacion cancelada\n\n");
        }
        else
        {
						do
						{
							printf("\n\nSeleccione la opcion que desea modificar:");
							printf("\n1.nombre\n");
							printf("2. peso\n");

							cambiar=getValidInt("Ingrese opcion del  1 al 2: ", "Error, ingrese nuevamente.", 1, 2);
							switch(cambiar)
									{
									case 1:
										//nuevoTrabajo.idTrabajo = idTrabajo;
										getValidString("Ingrese nombre:  ", "Error, ingrese nuevamente.",nuevaDescServicio);
										strcpy(clientes[indice].nombre,nuevaDescServicio);
										printf("Se ha modificado la descripcion con exito\n\n");
										break;
									case 2:
										clientes[indice].peso=getValidFloat("Ingrese el precio nuevo  1 al 100: ", "Error, ingrese nuevamente.", 1, 1000000);
										break;

									default :
										printf("Dato no valido\n");
									}
							clientes[indice].idCliente = idCliente;
							clientes[indice].isEmpty=0;
							printf("Desea continuar? s/n \n :");
							fflush(stdin);
							scanf("%c",&continuar);
							system("pause");
							system("cls");
						}
						while(continuar=='s' || continuar=='S');

							 retorno = 0;
							 system("pause");
					}

    }
    return retorno;
}


int eliminarCliente(eTrabajo trabajos[], int tamTrab, eCliente clientes[], int tamCli)
{

    int idServicio;
    int indice;
    char borrar;
    int retorno = -1;
    int i;
    char cadena[20];
    mostrarClientes(clientes, tamCli);
    system("pause");
    printf("Ingrese id de cliente a eliminar: ");
    scanf("%d", &idServicio);
    indice = buscarCliente(clientes, tamCli, idServicio);
    if( indice == -1)
    {
        printf("No hay ninguna servicio con ese id %d\n", idServicio);
    }
    else
    {
    	cargarDescripcionCliente(clientes, tamCli, idServicio, cadena);
        printf("Servicio a borrar %s",cadena);
        printf("\nSi borra esta nacionalidad se borraran los trabajos asociados a ella.Confirma borrado?: ");
        fflush(stdin);
        scanf("%c", &borrar);
        if(borrar != 's')
        {
            printf("Borrado cancelado\n\n");
        }
        else

        {
        	for(i=0; i < tamTrab; i++)
        	  {
        	        if( trabajos[i].idServicio == idServicio && trabajos[i].isEmpty == 0)
        	        {
        	            trabajos[i].isEmpty =-1;
        	        }
        	 }
        	{
        	        	clientes[indice].isEmpty = -1;
        	            printf("Se ha eliminado la servicio\n\n");
        	            retorno = 0;
        	 }
          }
              system("pause");
    }
    return retorno;
}



int mostrarClientes(eCliente clientes[], int tamCli)

{
	int retorno=-1;
    int i;
    printf("\nClientes\n\n");
    printf("\nId            nombre            peso \n\n");
    for(i=0; i < tamCli; i++)
    {
    	if(clientes[i].isEmpty == 0)
    	{
    		 printf("%d %20s %15.2f\n", clientes[i].idCliente, clientes[i].nombre, clientes[i].peso);
    		 retorno=0;
    	}
    }
    return retorno;
}



int cargarDescripcionCliente(eCliente clientes[], int tamCli, int idCliente, char cadena[])
{
    int i;
    int retorno = -1;
    	for(i=0; i < tamCli; i++)
    	    {
    	        if( clientes[i].idCliente == idCliente)
    	        {
    	            strcpy(cadena, clientes[i].nombre);

    	            retorno = 0;
    	            break;
    	        }
    	    }
    return retorno;
}

int cargarPesoCliente(eCliente clientes[], int tamCli, int idCliente, float* pesoCli)
{
    int i;
    int retorno = -1;

    	for(i=0; i < tamCli; i++)
    	    {
    	        if( clientes[i].idCliente == idCliente)
    	        {

    	            *pesoCli=clientes[i].peso;
    	            retorno = 0;
    	            break;
    	        }
    	    }
    return retorno;
}

int Producto_idIncrementalCliente = 0;

int eProducto_ObtenerIDCliente() {
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	return Producto_idIncrementalServicio += 1;
}
