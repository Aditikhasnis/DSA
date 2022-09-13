#include<stdio.h>
#include<stdlib.h>
#define max 2
struct queue
{
    int items[max];
    int front,rear;
};
typedef struct queue queue;
void insert(queue*p,int ele)
{
    if((p->rear+1)%max==p->front)
    {
        printf("Queue is full");
        return;
    }
    else{
    p->rear=(p->rear+1)%max;
    p->items[p->rear]=ele;
    if(p->front==-1)
    {
        p->front=0;
    }
    }
}
void display(queue*p)
{
    int i,j;
    i=p->front;
    j=p->rear;
    while (i!=j)
    {
        printf("\n%d",p->items[i]);
        i=(i+1)%max;

    }
    printf("\n%d",p->items[i]);
}
int delete(queue*p)
{
    int x;
 if(p->front==-1)
 {
    return -1;
 }
 else{
 x=p->items[p->front];
//  if(p->front==p->rear)
//  {
//     p->front=p->rear=-1;

 
    p->front=(p->front+1)%max;
    return x;
 }
}
int main()
{
    int ch=0,c;
    int res;
    queue q;
    q.front=-1;
    q.rear=-1;
    do
    {
        printf("\nenter your choice Press:\t\t\n1.insert\t\t\n2.display\t\t\n3.delete \n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to insert:");
            scanf("%d",&c);
            insert(&q,c);
            break;
        case 2:
           printf("displaying the elements......");
           display(&q);
           break;
        case 3:
         res=delete(&q);
         if(res==-1)
           printf("\nQueue is empty");
         else
           printf("\nthe deleted item is:%d",res);
        break;
        default:
        printf("\n enter the valid number");
        break;
        }
    } while (ch!=4);
    
}
