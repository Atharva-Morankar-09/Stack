#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack* ptr)
{
    if(ptr->top==-1)
    {return 1;}
    else
    {return 0;}
}

int isFull(struct stack* ptr)
{
    if(ptr->top==ptr->size-1)
    {return 1;}
    else
    {return 0;}
}

void push(struct stack* ptr,int ele)
{
    if(isFull(ptr))
    {
        printf("Stack Overflow \n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=ele;
    }
}

int top(struct stack* ptr)
{
    return ptr->arr[ptr->top];
}

int bottom(struct stack* ptr)
{
    return ptr->arr[0];
}

int main()
{
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->size=5;
    s->top=-1;
    s->arr=(int*)malloc(s->size * sizeof(int));

    printf("Stack successfully created \n");

    push(s,10);
    push(s,20);
    push(s,30);
    push(s,40);
    push(s,50);
    push(s,60);

    printf("Top element is - %d \n", top(s));

    printf("Bottom element is -%d ", bottom(s));
}

