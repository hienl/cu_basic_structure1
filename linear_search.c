#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int i_compare(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

int main(int argc, char *argv[]) {
  
  int array_size, search_frequency;
  array_size = pow(2, 10);
  search_frequency = 10;
  for (int i = 1; i < argc; ++i) {
    if ( i == 1 ) {
      array_size = atoi(argv[i]);
    } else if ( i == 2 ) {
      search_frequency = atoi(argv[2]);
    }
  }
  printf("array size: %i\n", array_size);
  printf("search frequency: %i\n", search_frequency);

  int *array;

  array = malloc(sizeof(int) * array_size);
  if(NULL == array) {
    printf("ERROR: malloc failed.\n");
    exit(-1);
  }
  srand((unsigned)time(NULL));
  for(int i=0; i<array_size; i++) {
    array[i] = rand();
  }
  qsort(array, array_size, sizeof(int), i_compare);

  int wanted;
  int max, min;
  long sum;
  sum = 0;
  max = min = -1;
  srand((unsigned)time(NULL));
  for(int i=0; i<search_frequency; i++) {
    wanted = array[rand() % array_size];
    for(int j=0; j<array_size; j++) {
      if (array[j] == wanted) {
        max = (max == -1 || max < j) ? j : max;
        min = (min == -1 || min > j) ? j : min;
        sum += j;
        printf("[WANTED:%i] %iを%i回目で発見\n", i, wanted, j);
        break;
      }
    }
  }
  
  printf("検索回数 最小： %i回、最大: %i回、平均: %f回", min, max, (float)sum/search_frequency);

  free(array);

  return 0;
}