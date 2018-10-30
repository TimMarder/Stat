#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

size_t filesize(char *filename){
  struct stat info;
  stat(filename,&info);
  return info.st_size;
}
