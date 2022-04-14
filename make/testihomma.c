#include "fcntl.h"
#include "types.h"
#include "user.h"
#include "syscall.h"
#include "param.h"
#include "mmu.h"
#include "proc.h"
#include "x86.h"

int main(int argc, char *argv[]) {
  // argument to integer value from char
  int i = atoi(argv[1]);
  // get count from syscall
  int count = getreadcount(i);
  if(i == 1)
  {
    printf(1,"\nCounter has been reset!\n\n");
  }
  // print before and after calling read
  printf(1, "Readcount before calling read(): %d\n", count);
  int fd = open("README", O_RDONLY);
  char buf[100];
  read(fd, buf, 99);
  count = getreadcount(0);
  printf(1, "Readcount after calling read(): %d\n", count);

  

  close(fd);
  exit();
}
