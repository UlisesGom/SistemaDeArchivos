

//Gestion de iNodos 
int setninode(int num, char *filename,unsigned short atribs, int uid, int gid);
int searchinode(char *filename); 
int removeinode(int numinode);

//Gestion de archivos 
int vdopen(char *filename,unsigned short mode); 
int vdcreat(char *filename,unsigned short perms); 
int vdunlink(char *filename); 
int vdseek(int fd, int offset, int whence); 
int vdwrite(int fd, char *buffer, int bytes); 
int vdread(int fd, char *buffer, int bytes); 
int vdclose(int fd);
