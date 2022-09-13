#include<stdio.h>//ascending priority queue
#include<stdlib.h>
typedef struct node
{
   int data;
   int prio;
   struct node*link;
}NODE;
NODE*get_node(int ele,int prio)
{
    NODE*temp=(NODE*)malloc(sizeof(NODE));
    temp->data=ele;
    temp->prio=prio;
    temp->link=NULL;
    return temp;
}
void insert_ascending_priority(NODE**f,NODE**r,int info,int priority)
{
    NODE*temp=get_node(info,priority);
    if(*f==NULL||temp->prio<(*f)->prio)
    {
        temp->link=*f;
        *f=temp;
        //*r=temp->link;
        if((*f)->link==NULL)
        {
            *r=*f;
        }
  
    }
    else{
        NODE*c;
        NODE*p=NULL;
        c=*f;
        while(c!=NULL&&c->prio<temp->prio)
        {
            p=c;
            c=c->link;
        }
        if(c==NULL)
        {
           (*r)->link=temp;
           *r=temp;
        }
        else{
            
            p->link=temp;
            temp->link=c;

        }
    }
}
NODE * delete_highest_PQ(NODE**f,NODE**r)
{
     //NODE temp;
     NODE*q;
     q=*f;
    if(*f==NULL)
    {
        printf("NOTHING TO DELETE!!!!");
    }
    else{
    while(q->link!=*r)
    {
        q=q->link;
    }
    //return (*r);
    NODE*temp;
    temp=*r;
    free(*r);
    *r=q;
    q->link=NULL;
     return (*r);
    }
}
void display_PQ(NODE**f)
{
   NODE*q;
   q=*f;
   if(*f==NULL)
   {
    printf("\nNO ELEMENTS IN THE QUEUE!!!");
   }
   else
   {
     while (q!=NULL)
     {
        printf("DAtA:%d\t",q->data);
        printf("Prio:%d\n",q->prio);
        q=q->link;
     }
     
   }
}
void main()
{
    NODE*front=NULL;
    NODE*rear=NULL;
    insert_ascending_priority(&front,&rear,1,2);
    insert_ascending_priority(&front,&rear,2,4);
    insert_ascending_priority(&front,&rear,2,3);
    display_PQ(&front);   
    NODE*delete_node=delete_highest_PQ(&front,&rear);
    printf("the delete with highest priority is:\n");
    printf("DATA:%d\t",delete_node->data);
    printf("prio:%d\n",delete_node->prio);
    display_PQ(&front);
   
    

}
