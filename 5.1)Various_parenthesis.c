
#include <stdio.h>
#include <stdlib.h>

struct stack{
    int top;
    int size;
    char* arr;
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
        printf("Stack Overflow \n");
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
        printf("Stack Underflow\n");
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int same(char a, char b)
{
    if(a=='(' && b==')')
    {return 1;}
    if(a=='[' && b==']')
    {return 1;}
    if(a=='{' && b=='}')
    {return 1;}
   return 0; 
}

int parenthesis(char* exp)
{
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->top=-1;
    s->size=10;
    s->arr=(char*)malloc(s->size * sizeof(char));

    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
        {
            push(s, exp[i]);
        }
        else if(exp[i]==')' || exp[i]==']' || exp[i]=='}')
        {
            if(isEmpty(s))
            {return 0;}
            
            char popped_ch=pop(s);
            if(!same(popped_ch, exp[i]))
            {
                return 0;
            }

        }
    }
   if(isEmpty(s))
   {return 1;}
   else
   {return 0;} 
}

int main()
{
    char* exp = "as(A)s{safs[]sd}";
    if(parenthesis(exp))
    {
        printf("The Parenthesis are balanced ");
    }
    else
    {
        printf("The Parenthesis are not balanced ");
    }
   return 0; 
}
