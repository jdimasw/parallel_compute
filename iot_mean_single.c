#include <stdio.h>
#include <string.h>
#include <json/json.h>

#define bufSize 1024

int main(int argc, char *argv[])
{
  FILE* fp;
  char buf[bufSize];
  if (argc != 2)
  {
    fprintf(stderr,
            "Usage: %s <soure-file>\n", argv[0]);
    return 1;
  }
  if ((fp = fopen(argv[1], "r")) == NULL)
  { /* Open source file. */
    perror("fopen source-file");
    return 1;
  }

  int count = 0;

  while (fgets(buf, sizeof(buf), fp) != NULL)
  {
    buf[strlen(buf) - 1] = '\0'; // eat the newline fgets() stores
    //printf("%s\n", buf);
    count = count + 1;
  }

  printf("%d \n", count);

  fclose(fp);
  return 0;
}
