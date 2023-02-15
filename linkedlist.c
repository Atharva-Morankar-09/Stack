
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void traversal(struct Node* ptr)
{
    while(ptr!=NULL)
    {
        printf("Element - %d \n", ptr->data);
        ptr=ptr->next;
    }
}

int isEmpty(struct Node* top)
{
    if(top==NULL)
    {return 1;}
    else
    {return 0;}
}

int isFull(struct Node* top)                                         
{
    struct Node* p=(struct Node*)malloc(sizeof(struct Node));
    if(p==NULL)
    {return 1;}
    else{
        return 0;}
}

struct Node* push(struct Node* top,int x)
{
   
    if(isFull(top))
    {
        printf("StackOverflow\n");
    }
    else
    {
         struct Node* n=(struct Node*)malloc(sizeof(struct Node));
         n->data=x;
         n->next=top;
         top=n;  
        return top;      
    }
}

int pop(struct Node* tp)
{
    if(isEmpty(tp))
    {
        printf("StackUnderflow\n");
    }
    else
    {
        struct Node* p = tp;
        top=(tp)->next;
        int x=p->data;
        free(p); 
        return x; 
    }
}


int main()
{
    top = push(top,20);
    top = push(top,30);
    top = push(top,40);

    traversal(top);

    int ele = pop(top);
    printf("Popped Element - %d\n", ele);

    traversal(top);

    return 0;
}
