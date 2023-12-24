#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct stack{
    int maxsize;
    int top;
    int *items;
};

struct stack* newStack(int capacity)
{
    struct stack *pt = (struct stack*)malloc(sizeof(struct stack));

    pt->maxsize = capacity;
    pt->top = -1;
    pt->items = (int*)malloc(sizeof(int) * capacity);

    return pt;
}

int isEmpty(struct stack *pt) {
    return pt->top == -1;
}

int peek(struct stack *pt)
{
    if (!isEmpty(pt)) {
        return pt->items[pt->top];
    }
    else {
        exit(EXIT_FAILURE);
    }
}

int isFull(struct stack *pt) {
    return pt->top == pt->maxsize - 1;
}

int pop(struct stack *pt)
{ 
    return pt->items[pt->top--];
}

void push(struct stack *pt, int x)
{
    if (isFull(pt))
    {
        exit(EXIT_FAILURE);
    }
    pt->items[++pt->top] = x;
}

int main(int argc, char* argv[]){
    char* string = argv[1];
    int len = strlen(string);
    struct stack *pt = newStack(argc);
    for (int i = 0; i < len; i++) {
        if(scanf("%d", string[i]) == 1){
            push(struct stack *pt, string[i]);
        }
    }
    return 0;
}