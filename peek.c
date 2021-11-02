#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int ele)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow \n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = ele;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow \n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack *ptr, int i)
{

    int indarr = ptr->top - i + 1;
    if (indarr < 0)
    {
        printf("ERROR!");
        return -1;
    }
    else
    {
        return ptr->arr[indarr];
    }
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    // if(isEmpty(s))
    //   {
    //     printf("Stack is Empty \n");
    //   }
    // else
    //   {
    //     printf("Stack is not Empty \n");
    //   }

    // if(isFull(s))
    //   {
    //     printf("Stack is Full\n");
    //   }
    // else
    //   {
    //     printf("Stack is not Full \n");
    //   }

    printf("Before Push, Empty - %d \n", isEmpty(s));
    printf("Before Push, Full - %d \n", isFull(s));

    // printf("The %d number is pushed \n", push(s,5));
    // printf("The %d number is pushed \n", push(s,15));
    // printf("The %d number is pushed \n", push(s,25));
    // printf("The %d number is pushed \n", push(s,35));
    // printf("The %d number is pushed \n", push(s,45));
    // printf("The %d number is pushed \n", push(s,45));

    push(s, 5);
    push(s, 15);
    push(s, 25);
    push(s, 35);
    push(s, 45);

    printf("After Push, Empty - %d \n", isEmpty(s));
    printf("After Push, Full - %d \n", isFull(s));

    pop(s);
    pop(s);


    printf("After Pop, Empty - %d \n", isEmpty(s));
    printf("After Pop, Full - %d \n", isFull(s));

    //peek(s,2);

    for (int j = 1; j <= s->top + 1; j++)
    {
        printf("The value at position %d is %d \n", j, peek(s, j));
    }

    return 0;
}