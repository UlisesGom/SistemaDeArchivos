#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "structs.h" 
#include "vdisk.h"

int main(){

	struct MBR mbr;

	memset(&mbr, 0x0,512); //Se limipia buffer para el MBR

	int secf_beg = 2;
	int cil_beg = 0;
	int head_beg = 0;

	int secf_end = 27;
	int cil_end = 199;
	int head_end = 7;

	mbr.partition[0].drive_status = 0x80; //Bit 7 activo para indicar que es una partición de arranque

	mbr.partition[0].chs_begin[0] = head_beg; //Se alberga la superficie incial en el primer byte 
	mbr.partition[0].chs_begin[1] = (cil_beg<<6) & 0xC0 | secf_beg & 0x3F; //Se albergan 6 bits de sector inicial y 2 de cilindro en byte 2 
	mbr.partition[0].chs_begin[2] = (cil_beg>>2) & 0xFF; //Se alberga el resto del cilindro inicial en el byte 3
	mbr.partition[0].partition_type = 0x83; //Tipo de partición de Linux
	mbr.partition[0].chs_end[0] = head_end; //Se alberga la superficie final en el primer byte 
	mbr.partition[0].chs_end[1] = (cil_beg<<6) & 0xC0 | secf_end & 0x3F; //Se albergan 6 bits de sector final y 2 de cilindro en byte 2 
	mbr.partition[0].chs_end[2] = (cil_end>>2) & 0xFF; //Se alberga el resto del cilindro final en el byte 3

	vdwritesector(0,0,0,1,1, (char*) &mbr); //Se escribe el MBR superficie = 0, cilindro = 0, sector =1 
}
