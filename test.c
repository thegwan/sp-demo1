#include <stdlib.h>
#include <stdio.h>

int main()
{
  FILE *fptr;
  int c;
  char filename[100];
  printf("begin\n");
  printf("enter filename: ");
  scanf("%s", filename);

  fptr = fopen(filename, "rw");
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
