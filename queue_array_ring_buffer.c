#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void enqueue(int *queue, int data, int *front_pointer, int queue_size) {
  queue[((*front_pointer)++) % queue_size] = data;
}

int dequeue(int *queue, int *rear_pointer, int queue_size) {
  int p = ((*rear_pointer)++) % queue_size;
  int data = queue[p];
  queue[p] = 0;
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
  for (int i = 1; i < argc; ++i) {
    if ( i == 1 ) {
      queue_size = atoi(argv[i]);
    }
  }
  int front_pointer, rear_pointer;
  front_pointer = rear_pointer = 0;
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
    enqueue(queue, data, &front_pointer, queue_size);
    printf("enqueue: %i\n", data);
    p(queue, queue_size);
  }

  for(int i=0; i<queue_size; i++) {
    int data = dequeue(queue, &rear_pointer, queue_size);
    printf("dequeue: %i\n", data);
    p(queue, queue_size);
  }

  for(int i=0; i<queue_size; i++) {
    int data = rand();
    enqueue(queue, data, &front_pointer, queue_size);
    printf("enqueue: %i\n", data);
    p(queue, queue_size);
  }

  for(int i=0; i<queue_size; i++) {
    int data = dequeue(queue, &rear_pointer, queue_size);
    printf("dequeue: %i\n", data);
    p(queue, queue_size);
  }

  free(queue);

  return 0;
}