#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void enqueue(int *queue, int data, int *front_pointer, int queue_size) {
  queue[((*front_pointer)++) % queue_size] = data;
}

int dequeue(int *queue, int *rear_pointer, int queue_size) {
  return queue[((*rear_pointer)++) % queue_size];
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

  queue = malloc(sizeof(int) * queue_size);
  if(NULL == queue) {
    printf("ERROR: malloc failed.\n");
    exit(-1);
  }
  srand((unsigned)time(NULL));
  for(int i=0; i<queue_size; i++) {
    int data = rand();
    enqueue(queue, data, &front_pointer, queue_size);
    printf("enqueue: %i\n", data);
  }

  for(int i=0; i<queue_size; i++) {
    int data = dequeue(queue, &rear_pointer, queue_size);
    printf("dequeue: %i\n", data);
  }

  for(int i=0; i<queue_size; i++) {
    int data = rand();
    enqueue(queue, data, &front_pointer, queue_size);
    printf("enqueue: %i\n", data);
  }

  for(int i=0; i<queue_size; i++) {
    int data = dequeue(queue, &rear_pointer, queue_size);
    printf("dequeue: %i\n", data);
  }

  free(queue);

  return 0;
}