#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

char* get_size( char* buff , double size ) {
    if (size < 1000.0) {
        sprintf( buff, "%f B", size );
        return buff;
    }
    size = size / 1000.0;
    if (size < 1000.0){
		sprintf( buff, "%f KB", size );
		return buff;
	}
	size = size / 1000.0;
	if (size < 1000.0){
		sprintf( buff, "%f MB", size );
		return buff;
	}
	size = size / 1000.0;
	sprintf( buff, "%f GB", size );
	return buff;
}

int main(){
    char * info;
  struct stat buff;
  char * fd = "findstat.c";
  stat(fd,&buff);
  printf("Size of file: %ld\n", buff.st_size);
  printf("Convinient size: %s\n", get_size(info, buff.st_size));
  printf("Last accessed: %s\n", ctime(&buff.st_atime));
  printf("Last modified: %s\n", ctime(&buff.st_mtime));
  printf("File permissions: %d\n", buff.st_mode);
  return 0;
}
