
//Gestion de bloques
int writeblock(int num_block,char *buffer); 
int readblock(int num_block,char *buffer); 

//Gestion de apuntador
unsigned short *postoptr(int fd,int pos); 
unsigned short *currpostoptr(int fd); 

//Gestion de directorios
VDDIR *vdopendir(char *path); 
struct vddirent *vdreaddir(VDDIR *dirdesc); 
int vdclosedir(VDDIR *dirdesc); 