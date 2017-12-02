

//Gestion Nodos i
int isinodefree(int inode); 
int nextfreeinode(); 
int assigninode(int inode); 
int unassigninode(int inode); 
int isblockfree(int block); 

//Gestion Bloques
int nextfreeblock(); 
int assignblock(int block);
int unassignblock(int block); 
int writeblock(int block,char *buffer); 
int readblock(int block,char *buffer); 

//Gestion de fecha

unsigned int datetoint(struct DATE date);
int inttodate(struct DATE *date,unsigned int val);; 
unsigned int currdatetimetoint(); 
