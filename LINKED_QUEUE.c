//linked implementation
#include<stdio.h>
#include<stdlib.h>
typedef struct LINKED_QUEUE
{
    int data;
    struct LINKED_QUEUE *link;
}NODE;
// typedef struct  rear_front{
//     NODE*rear;
//     NODE*front;
// }HEAD;
NODE*get_node(int ele)
{
    NODE*temp=(NODE*)malloc(sizeof(NODE));
    temp->link=NULL;
    temp->data=ele;
    return temp;
}
// void init(HEAD*p)
// {
//     p->front=NULL;
//     p->rear=NULL;
// }
// void insert(HEAD *p,int ele)
// {
//     NODE*temp=get_node(ele);
//     if(p->rear==NULL)
//     {
//       printf("\n Queue is Empty!!");
//     }
//     else
//       p->rear->link=temp;
//     p->rear=temp;
// }
// void display(HEAD*p)
// {
    
// }

void Enqueue(NODE**f,NODE**r,int ele)
{
    NODE*temp;
    temp=get_node(ele);
    if(*f==NULL)
     *f=*r=temp;
    else{
    (*r)->link=temp;
    *r=temp;    
     }
}
int Dequeue(NODE**f,NODE**r)
{
    NODE*q;
    int x;
    q=*f;
    if(q==NULL)
    {
        printf("\nThe queue is empty\n");
        return -1;
    }
    else{
        x=q->data;
        if(*f==*r)
        {
            *f=*r=NULL;
        }
        else{
            *f=q->link;
            return x;
        }
        free(q);
    }
}
void display(NODE**f,NODE**r)
{
    if(*f==NULL)
    {
        printf("NO elements !!!");
    }
    else{
        NODE*q;
        q=*f;
        while (q!=*r)
        {
            printf("%d\n",q->data);
            q=q->link;
        }
        printf("%d\n",q->data);
        
}
}
void main()
{
   NODE n1;
   NODE*front=NULL;
   NODE*rear=NULL;
   Enqueue(&front,&rear,20);
   Enqueue(&front,&rear,30);
   Enqueue(&front,&rear,40);
   Enqueue(&front,&rear,50);
   Enqueue(&front,&rear,60);
 
  Enqueue(&front,&rear,70);   
  Dequeue(&front,&rear);
  Enqueue(&front,&rear,80);
   display(&front,&rear);
}
