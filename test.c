#include <stdlib.h>
#include <stdio.h>

int main()
{
  FILE *fptr;
  int c;
  printf("begin\n");
  fptr = fopen("file.txt", "rw");
  printf("opened\n");
  if (fptr == NULL) {
    printf("fptr is null");
    return 0;
  }
  while ((c = fgetc(fptr)) != EOF) {
    printf("%c", c);
  }
  fclose(fptr);
  printf("done\n");
  return 0;
}
