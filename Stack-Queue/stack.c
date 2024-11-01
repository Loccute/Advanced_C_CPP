#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct 
{
    int* item;
    int top;
    int size;
}Stack;

void initialize(Stack* stack,int size)
{
    stack->item = (int*)malloc(size*sizeof(int));
    stack->top = -1;
    stack->size = size;
}

bool isfull(Stack *stack){
    return stack->top == stack->size - 1;
}

void push(Stack* stack, int value){
    if (!isfull(stack)){
        stack->item[++stack->top] = value;
        printf("Push %d successfully at address: %p\n", value, &stack->item[stack->top]);
    }
    else{
        printf("Stack overflow!\n");
        return;
    }
}

int pop(Stack* stack){
    if (stack->top == -1){
        printf("Stack underflow!\n");
        return -1;
    }
    int value = stack->item[stack->top--];
    return value;
}

int top( Stack stack) {
    if (stack.top != -1) {
        return stack.item[stack.top];
    } else {
        printf("Stack is empty\n");
        return -1;
    }
}


void display(Stack stack){
    printf("The value of the stack: \n");
    for (int i = 0; i <= stack.top; i++){
        printf("Value stack[%d] = %d, at address: %p\n", i, stack.item[i], &stack.item[i]);
    }
}

int main()
{
    Stack stack1;
    initialize(&stack1, 5);


    push(&stack1, 10);
    push(&stack1, 20);
    push(&stack1, 30);
    push(&stack1, 40);
    push(&stack1, 50);
    push(&stack1, 60);

    display(stack1);
    

    printf("Top element: %d\n", top(stack1));

    printf("Pop element: %d\n", pop(&stack1));
    printf("Pop element: %d\n", pop(&stack1));

    printf("Top element: %d\n", top(stack1));

    free(stack1.item);
    return 0;
}
