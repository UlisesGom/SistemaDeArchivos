#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include "structs.h" 

struct SECBOOTPART secboot;
char Nodosi_bitmap[512];
char Nodosi_rootDir[512*3];
char AreaDatos_bitmap[512*6];

int main(){
       

        memset(secboot, 0x00, 512);

        secboot.sec_inicpart = 1;
        secboot.sec_res = 1;
        secboot.sec_mapa_bits_area_nodos_i = 1;
        secboot.sec_mapa_bits_bloques = 6;
        secboot.sec_tabla_nodos_i = 3;
        secboot.sec_log_particion = 43199;
        secboot.sec_x_bloque = 2;
        secboot.heads = 8;
        secboot.cyls = 200;
        secboot.secfis = 27;
        
        if(vdwriteseclog(1,secboot)) {
                printf("Error en formato de SBR");
        }


        memset(Nodosi_bitmap, 0x00, 512);
        
        if( vdwriteseclog(2,Nodosi_bitmap) ) {
                printf("Error en formato mapa de bits nodos i ");
        }

        memset(AreaDatos_bitmap, 0x00, 512*6);
        
        if( vdwriteseclog(3, AreaDatos_bitmap )) {
                printf("Error en formato mapa de bits area de datos");
        }

        memset(Nodosi_rootDir, 0x00, 512*3);
    
        if( vdwriteseclog(9,Nodosi_rootDir) ) {
                printf("Error en formato Nodosi Directorio Raiz");
        }
}
