#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

int main(){
  struct stat *info = malloc(sizeof(struct stat));
  char * fd = "test.txt";
  stat(fd,info);
  int size = info->st_size;
  printf("Size of file: %d\n",size);
  
  int perm = info->st_mode;
  printf("File permissions: %o",perm);

  time_t last_acc = info->st_atime;
  printf("Last accessed: %s\n", ctime(&last_acc));
  
  return 0;
}
