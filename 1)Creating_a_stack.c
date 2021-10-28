# Stack using Array


 #include<stdio.h>
 #include<stdlib.h>

 struct stack{
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

  int isFull(struct stack* s)
  {
      if(s->top==s->size-1)
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
     struct stack* s=(struct stack*)malloc(sizeof(struct stack));
     s->size=5;
     s->top=-1;
     s->arr=(int*)malloc(s->size * sizeof(int));

     s->arr[0]=9;
     s->top++;
      if(isEmpty(s))
        {
            printf("Stack is Empty\n");
        }
      else
        { 
            printf("Stack is not Empty\n");
        }

       if(isFull(s))
         {
             printf("Stack is Full\n");
         }  
      else
         {
             printf("Stack is not Full\n");
         }
    return 0;
 }

