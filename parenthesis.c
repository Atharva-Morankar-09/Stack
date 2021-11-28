
#include<stdio.h>
#include<stdlib.h>

struct stack{
       int top;
       int size;
       char *arr;
};

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
    if(ptr->top == ptr->size-1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack* ptr, char val)
{
    if(isFull(ptr))
    {
        printf("Stack Overflow \n");
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
       printf("Stack Underflow\n");
   }
   else
   {
       char val=ptr->arr[ptr->top];
       ptr->top--;
       return val;
   }
}

int Parenthesischeck(char* exp)
{
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->size=10;
    s->top=-1;
    s->arr= (char*)malloc(s->size*sizeof(char));

    for(int i=0;exp[i]!='\0';i++)
    {
          if(exp[i]=='(')
          {
              push(s,'(');
          }
          else if(exp[i]==')')
          {
              if(isEmpty(s))
              {
                  return 0;
              }
              else
              {
                  pop(s);
              }
          }
    }

   if(isEmpty(s))
   {
     return 1;
   }
   else
   {
     return 0;
   }
}

int main()
{
    char *exp = "(abjkds)asldkn((askdil)())";
    // char* exp;
    // printf("Enter the Expression - ");
    // scanf("%c", &exp);
    if(Parenthesischeck(exp))
    {
        printf("Parenthesis are in right order\n");
    }
    else
    {
        printf("Parenthesis are not in right order\n");
    }
   return 0; 
}