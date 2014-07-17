#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void push(int *stack, int data, int *pointer) {
  stack[(*pointer)++] = data;
}

int pop(int *stack, int *pointer) {
  int data = stack[--(*pointer)];
  stack[*pointer] = 0;
  return data;
}

void p(int *stack, int size) {
  printf("%c", '[');
  for(int i=0; i<size; i++) {
    printf("%0d", stack[i]);
    if (i != size - 1) {
      printf("%c ", ',');
    }
  }
  printf("%c\n", ']');
}

int main(int argc, char *argv[]) {
  
  int stack_size;
  stack_size = 10;
  for (int i = 1; i < argc; ++i) {
    if ( i == 1 ) {
      stack_size = atoi(argv[i]);
    }
  }
  int pointer = 0;
  printf("stack size: %i\n", stack_size);

  int *stack;

  stack = calloc(sizeof(int), stack_size);
  if(NULL == stack) {
    printf("ERROR: malloc failed.\n");
    exit(-1);
  }
  srand((unsigned)time(NULL));
  p(stack, stack_size);
  for(int i=0; i<stack_size; i++) {
    int data = rand();
    push(stack, data, &pointer);
    printf("push: %i\n", data);
    p(stack, stack_size);
  }

  for(int i=0; i<stack_size; i++) {
    int data = pop(stack, &pointer);
    printf("pop:  %i\n", data);
    p(stack, stack_size);
  }

  free(stack);

  return 0;
}