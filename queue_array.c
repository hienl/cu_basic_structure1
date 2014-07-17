#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void enqueue(int *queue, int data, int *pointer) {
  for (int i = (*pointer)++; i > 0; --i) {
    queue[i] = queue[i-1];
  }
  queue[0] = data;
}

int dequeue(int *queue, int *pointer) {
  --(*pointer);
  int data = queue[*pointer];
  queue[*pointer] = 0;
  return data;
}

void p(int *queue, int size) {
  printf("%c", '[');
  for(int i=0; i<size; i++) {
    printf("%0d", queue[i]);
    if (i != size - 1) {
      printf("%c ", ',');
    }
  }
  printf("%c\n", ']');
}

int main(int argc, char *argv[]) {
  
  int queue_size;
  queue_size = 10;
  if (argc > 1) {
    queue_size = atoi(argv[1]);
  }
  int pointer = 0;
  printf("queue size: %i\n", queue_size);

  int *queue;

  queue = calloc(sizeof(int), queue_size);
  if(NULL == queue) {
    printf("ERROR: malloc failed.\n");
    exit(-1);
  }
  srand((unsigned)time(NULL));
  p(queue, queue_size);
  for(int i=0; i<queue_size; i++) {
    int data = rand();
    enqueue(queue, data, &pointer);
    printf("enqueue: %i\n", data);
    p(queue, queue_size);
  }

  for(int i=0; i<queue_size; i++) {
    int data = dequeue(queue, &pointer);
    printf("dequeue: %i\n", data);
    p(queue, queue_size);
  }

  free(queue);

  return 0;
}
