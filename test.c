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
  char val = 0;

  while (fgets(buf, sizeof(buf), fp) != NULL)
  {
    buf[strlen(buf) - 1] = '\0'; // eat the newline fgets() stores
    //printf("%s\n", buf);
    count = count + 1;
    
    json_object *jobj = json_tokener_parse(buf);
    json_object *obj_hum = json_object_object_get(jobj,"humidity");

    const char *hum_val = json_object_get_string(obj_hum);
    val = hum_val;
  }

  printf("%d \n%s\n", count, val);

  fclose(fp);
  return 0;
}
