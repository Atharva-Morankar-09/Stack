
#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack* ptr)
{
    if(ptr->top==-1)
     {
         return 1;
     }
    else
     {
         return 0;
     } 
}

int isFull(struct stack* ptr)
{
    if(ptr->top==ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack* ptr, int val)
{
    if(isFull(ptr))
    {
        printf("Stack Overflow ! \n\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

int pop(struct stack* ptr)
{
    if(isEmpty(ptr))
     {
         printf("Stack Underflow !\n\n");
     }
     else
     {
         int val=ptr->arr[ptr->top];
         ptr->top--;
         return val;
     }
}

int main()
{
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->size=5;
    s->top=-1;
    s->arr=(int*)malloc(s->size * sizeof(int));
    
    printf("\nStack is formed\n\n");

    printf("Before Pushing, Empty : %d \n", isEmpty(s));
    printf("Before Pushing, Full : %d \n\n", isFull(s));

    push(s,10);
    push(s,20);
    push(s,30);
    push(s,40);
    push(s,50);
    push(s,60); // Overflow

    printf("After Pushing, Empty : %d \n", isEmpty(s));
    printf("After Pushing, Full : %d \n\n", isFull(s));

    printf("Popped %d from the stack \n", pop(s));
    printf("Popped %d from the stack \n", pop(s));
    printf("Popped %d from the stack \n", pop(s));
    printf("Popped %d from the stack \n", pop(s));
    printf("Popped %d from the stack \n\n", pop(s));

    printf("After Popping, Empty : %d \n", isEmpty(s));
    printf("After Popping, Full : %d \n", isFull(s));

}
