#include<stdio.h>
#include<stdlib.h>
#define max 5
struct priority_queue
{
    int data;
    int pty;
    
};
typedef struct priority_queue PRIQ ;
//PRIQ array[100];
void insert_descending_priority(PRIQ *array,int ele,int pty,int *count)
{
    int i=*count-1;
    PRIQ * p;
    PRIQ key;
    p=&key;
    p->data=ele;
    p->pty=pty;
    while( i>=0&&p->pty> array[i].pty)
    {
        array[i+1]=array[i];
        i--;
    }
    array[i+1]=*p;
    (*count)++;
}
PRIQ dequeue_front(PRIQ*array,int *count)
{
   PRIQ p=array[0];
   for(int i=1;i<(*count);i++)
   {
     array[i-1]=array[i];
   }
   (*count)--;
   return p;
}
void display(PRIQ*array,int*count)
{
    if(*count==0)
    {
        printf("NO ELEMENTS TO BE DISPLAY>>>>\n");
    }
    else{
    for(int i=0;i<*count;i++)
    {
     //  printf("\t");
      printf("\n");
       printf("DATA:%d",array[i].data);
       printf("\tpri:%d",array[i].pty);
    }
    }
}
int main()
{
    PRIQ array[max];
    int count=0;
    int d;
    int p;
    // insert_descending_priority(array,12,3,&count);
    // insert_descending_priority(array,15,5,&count);
    // insert_descending_priority(array,13,4,&count);
    // insert_descending_priority(array,18,1,&count);
    // display(array,&count);
    // printf("DELETING THE ITEMS!!!");
    // dequeue_front(array,&count);
    // printf("AFTER");
    //   display(array,&count);
    int re=0;
    do
    {
          int ch;)
         printf("\nPRESS \t1.insert in descending order priority()\n\t2.dequeue()\n\t3.display()\n");
         scanf("%d",&ch);
         switch (ch)
         {
         case 1:
                if(count!=max)
                {
                    printf("ENTER THE DATA AND PRIORITY");
                    scanf("%d\t%d",&d,&p);
                    insert_descending_priority(array,d,p,&count);
                }
                else{
                    printf("QUEUE IS FULL");
                }
            break;
             case 2:if(count)
				{
                    PRIQ temp;
					temp=dequeue_front(array,&count);
                    printf("THE DELETED ITEM IS:\n");
					printf("Data:%d Pri:%d",temp.data,temp.pty);
				}
				else
					printf("Queue is already empty\n");
				break;
		    case 3:
               display(array,&count);
				break;
         }

    } while (re!=4);
    


}