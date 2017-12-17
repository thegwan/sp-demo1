#include <stdlib.h>
#include <stdio.h>

int main()
{
  FILE *fptr;
  int c;
  printf("begin\n");
  fptr = fopen("file.txt", "r");
  printf("opened\n");
  while ((c = fgetc(fptr)) != EOF) {
    printf("%c", c);
  }
  fclose(fptr);
  printf("done\n");
}
