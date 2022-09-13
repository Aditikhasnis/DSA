#include<stdio.h>
#include<stdlib.h>
#define max 5
struct queue
{
    int items[max];
    int front,rear;
};
typedef struct queue queue;
int qdelete(queue*p)
{
    int x;
    if(p->rear==-1)
    {
        return -1;
    }
    else{
        
        x=p->items[p->front];
        p->front++;
        if(p->front>p->rear)
        {
            p->front=0;
            p->rear=-1;
        }
        //(p->front)++;

    }
    return x;
}
void init_queue(queue*p)
{
    p->front=0;
    p->rear=-1;
}
int  qinsert(queue*p,int ele)
{
   if(p->rear==max-1)
   {
    printf("Queue is full .......\t\t cannot insert more!!!!!");
    printf("\nSorry could not insert %d ",ele);
    return 1;
   }
   else{
       (p->rear)++;
    p->items[p->rear]=ele;
    return 0;
   }

//    if(p->front==-1)
//    {
//     p->front=0;
//    }
}
void display(queue*p)
{
    // int i,j;
    // i=p->front;
    // j=p->rear;
    if(p->rear==-1)
    {
        printf("\nQueue is empty");
    }
    for(int i=p->front;i<=p->rear;i++)
    {
        printf("\n%d",p->items[i]);
        //i++;
    }
    printf("\n");
     //printf("\n%d",p->items[i]);
}
int main()
{
    int ch=0,c;
    int res;
    queue q;
    q.front=0;
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
            qinsert(&q,c);
            break;
        case 2:
           printf("displaying the elements......");
           display(&q);
           break;
        case 3:
         res=qdelete(&q);
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
