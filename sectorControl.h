#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define SEC_X_PISTA 27
#define SEC_FIC_INC 2
#define SEC_INC_PART 0

//Gestion de sectores lógicos 
int vdwriteseclog(int seclog,char *buffer); //Escribir un sector fisico a partir del sector lógico 
int vdreadseclog(int seclog,char *buffer); // Escribir un sector fisico a partir del sector lógico 

// Funciones para la lectura y escritura de bloques, a partir 
// de un número de bloques
int writeblock(int nblock,char *buffer); 
int readblock(int nblock,char *buffer); 


