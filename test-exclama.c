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
  printf("repeat filename: %s\n", filename);

  fptr = fopen(filename, "rw");
  printf("opened\n");
  if (fptr == NULL) {
    printf("fptr is null\n");
    return 0;
  }
  while ((c = fgetc(fptr)) != '.') {
    printf("%c", c);
  }
  fclose(fptr);
  printf("done\n");
  return 0;
}
