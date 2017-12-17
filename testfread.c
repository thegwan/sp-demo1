#include <stdlib.h>
#include <stdio.h>

int main()
{
  FILE *fptr;
  int c;
  int numRead;
  char buffer[1];
  printf("begin\n");
  fptr = fopen("file.txt", "r");
  printf("opened\n");
  while ((numRead = fread(buffer, 1, 1, fptr) > 0)) {
      printf("%s", buffer);
  }
  fclose(fptr);
  printf("done\n");
}
