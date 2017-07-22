#include <unistd.h>
#include <stdio.h>
#include <sys/io.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
  long io_port =  strtol(argv[1], NULL, 0);
  long temp = io_port;
  long io_leng =  strtol(argv[2], NULL, 0);
  /* gain access to i/o ports */
  iopl(2);
  if (ioperm(io_port, io_leng , 1) < 0) {
    perror("io_port");
    return 1;
  }
  while (temp <= io_port + io_leng)
  {
    printf("The output of io port %x is %x \n", temp, inb(temp));
    temp++;
  }

  return 0;

}
