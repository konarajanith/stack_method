#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Define the maximum size of the stack

typedef struct Stack {
    int items[MAX];
    int top;
} Stack;

// Function to create a stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to push an element to the stack
void push(Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->items[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->items[stack->top--];
}

// Function to peek the top element of the stack
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->items[stack->top];
}

// Function to display the stack
void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
   
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->top[i]);
    }
    printf("\n");
}

// Function to return the size of the stack
int size(Stack* stack) {
    return stack->top + 1;
}

int main() {
    // Main code for stack operations
    Stack* stack = createStack();

    push(stack, 100);
    push(stack, 120);
    push(stack, 350);

    printf("Top element is %d\n", peek(stack));

    printf("Stack elements are:\n");
    display(stack);

    printf("Current stack size is %d\n", size(stack));

    printf("%d popped from stack\n", pop(stack));

    printf("Stack elements after pop:\n");
    display(stack);

    printf("Current stack size after pop is %d\n", size(stack));

    // Free the allocated memory
    free(stack);

    return 0;
}

