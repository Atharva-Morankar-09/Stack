
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int size;
    int top;
    char*arr;
};

int top(struct stack* sp)
{
    return sp->arr[sp->top];
}

int isEmpty(struct stack* ptr)
{
    if(ptr->top==-1)
    {
        return 1;
    }
   return 0; 
}

int isFull(struct stack* ptr)
{
    if(ptr->top==ptr->size-1)
    {
        return 1;
    }
   return 0; 
}

void push(struct stack* ptr, char val)
{
    if(isFull(ptr))
    {
        printf("Stack is overflowing\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

char pop(struct stack* ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack is underflowing\n");
    }
    else
    {
        char val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int precedence(char sp)
{
    if(sp=='*' || sp=='/')
    {return 3;}
    else if(sp=='+' || sp=='-')
    {return 2;}
    else    
    {return 0;}
}

int isOperator(char sp)
{
    if(sp=='*' || sp=='/' || sp=='+' || sp=='-')
    {
        return 1;
    }
   return 0; 
}

char* postfix(char* infix)
{
    struct stack* sp = (struct stack*)malloc(sizeof(struct stack));
    sp->top=-1;
    sp->size=100;
    sp->arr=(char*)malloc(sp->size*sizeof(char));
    char* postfix = (char*)malloc((strlen(infix)+1) * sizeof(char));
    int i=0,j=0;
    while(infix[i]!='\0')
    {
        if(!isOperator(infix[i]))
        {
            postfix[j]=infix[i];
            i++;
            j++;
        }
        else
        {
            if(precedence(infix[i])>precedence(top(sp)))
            {
                push(sp, infix[i]);
                i++;   
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
  while(!isEmpty(sp))
  {
      postfix[j]=pop(sp);
      j++;
  } 
  postfix[j]='\0';
  return postfix;
}

int main()
{
    char* infix = "x-y/z-k*d";
    printf("The Postfix of %c is %s", infix, postfix(infix));
  return 0;
}
