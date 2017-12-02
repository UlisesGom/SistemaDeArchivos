#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <structs.h>

int vdwriteseclog(int seclog,char *buffer)
{ 
	int superficie, cilindro, sector_fisico; 
	
	// Calcular superficie, cilindro, sector_fisico a partir de sector lógico
	superficie = ((seclog + SEC_FIC_INC - 1) + SEC_INC_PART) / SEC_X_PISTA % SUPERFICIES; 
	cilindro = ((seclog + SEC_FIC_INC - 1) + SEC_INC_PART) / (SEC_X_PISTA * SUPERFICIES);
	sector_fisico =  (seclog + SEC_FIC_INC - 1) % SEC_X_PISTA + 1; 

	vdwritesector(0,superficie,cilindro,sector_fisico,1,*buffer);
}

int vdreadseclog(int seclog,char *buffer)
{
	int superficie, cilindro, sector_fisico; 

	// Calcular superficie, cilindro, sector_fisico a partir de sector lógico 
	superficie = ((seclog + SEC_FIC_INC - 1) + SEC_INC_PART) / SEC_X_PISTA % SUPERFICIES; 
	cilindro = ((seclog + SEC_FIC_INC - 1) + SEC_INC_PART) / (SEC_X_PISTA * SUPERFICIES);
	sector_fisico =  (seclog + SEC_FIC_INC - 1) % SEC_X_PISTA + 1; 

	vdreadsector(0,superficie,cilindro,sector_fisico,1,*buffer);
}

// Funciones para la lectura y escritura de bloques, a partir 
// de un número de bloques

int writeblock(int nblock,char *buffer)
{
	int slad; // Sector lógico del área de datos
	int secs_x_bloque;
	int i;
	
	// Obtener los datos del sector de boot de la partición
	// para:
	// 	1.- Determinar en que sector lógico inicia el área
	// 	de bloques de datos, y guardarlo en la variable slad
	//
	//	2.- Obtener el número de sectores por bloque y guardarlo
	// 	en la variable secs_x_bloque
	slad = secboot.sec_inicpart+secboot.sec_res +secboot.sec_mapa_bits_area_nodos_i +secboot.sec_mapa_bits_bloques+secboot.sec_tabla_nodos_i; 
	secs_x_bloque = secboot.sec_x_bloque; 

	// Calcular en que sector lógico inicia el bloque
	seclog = slad+(nblock-1)*secs_x_bloque;

	// Escribir en todos los sectores lógicos del bloque
	for(i=0;i<secs_x_bloque;i++)
	{	
		vdwriteseclog(seclog,buffer);
		seclog++;
		buffer+=512;
	}
}

int readblock(int nblock,char *buffer)
{
	int slad; // Sector lógico del área de datos
	int secs_x_bloque;
	int i;

	// Obtener los datos del sector de boot de la partición
	// para:
	// 	1.- Determinar en que sector lógico inicia el área
	// 	de bloques de datos, y guardarlo en la variable slad
	//
	//	2.- Obtener el número de sectores por bloque y guardarlo
	// 	en la variable secs_x_bloque

	slad = secboot.sec_inicpart+secboot.sec_res +secboot.sec_mapa_bits_area_nodos_i +secboot.sec_mapa_bits_bloques+secboot.sec_tabla_nodos_i; 
	secs_x_bloque = secboot.sec_x_bloque; 
	
	// Calcular en que sector lógico inicia el bloque
	seclog=slad+(nblock-1)*secs_x_bloque;

	// Escribir en todos los sectores lógicos del bloque
	for(i=0;i<secs_x_bloque;i++)
	{	
		vdreadseclog(seclog,buffer);
		seclog++;
		buffer+=512;
	}
}