#include <stdio.h>
#include <string.h>
#include <json/json.h>
#include <mpi.h>

#define bufSize 1024

int main(int argc, char *argv[])
{

int rank, size;
MPI_Init(NULL, NULL);
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &size);

if(rank == 0){

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
  const char *val;
double hasil = 0;

  while (fgets(buf, sizeof(buf), fp) != NULL)
  {
    buf[strlen(buf) - 1] = '\0'; // eat the newline fgets() stores
    //printf("%s\n", buf);
    count = count + 1;

    json_object *jobj = json_tokener_parse(buf);
    json_object *obj_hum = json_object_object_get(jobj,"humidity");

    const char *hum_val = json_object_get_string(obj_hum);
    val = hum_val;
hasil = hasil + atoi(val);
  }

  printf("Total Data: %d\nNilai Terakhir: %s\nPenjumlahan Humidity: %f\n", count, val, hasil);

hasil = hasil / (count*1.0);

printf("Rata-rata Humidity : %.2f\n", hasil);

//int hasil = 0;
//hasil = atoi(val) - 10;

//printf("%d\n", hasil);

  fclose(fp);

}

MPI_Finalize();
  return 0;
}
