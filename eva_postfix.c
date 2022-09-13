// pop out 3 and4 and for that apply the coressponding  operator
// then again if you encounter the operator pop out the stack again ...and apply operator
// as you encounter operator
// 4
// 3
// 2
#include<stdio.h>
#include<stdlib.h>
#define size 5
char stk[10];
int top=-1;
float is_num(int num )
{
    if(num>0&&num<9)
       return 1;
    else
       return 0;

}
float get_result(char op,float op1,float op2)
{
    switch(op)
    {
        case '+':return(op1+op2);
        case '-':return(op1-op2);
        case '*':return(op1*op2);
        case '/':return(op1/op2);

    }
}
float evaluate(char postfix[])
{
   int i=0;
   char symb;
   while(postfix[i]!='\0')
   {
    symb=postfix[i];
    if( is_num(symb-'0'))
    {
        stk[++top]=symb-'0';
    }
    else{
       float op2=stk[top--];
       float  op1=stk[top--];
        float res=get_result(symb,op1,op2);
        stk[++top]=res;
       // printf("%d",res);
     
    }
    i++;
   }
   return(stk[top]);
}
int main()
{
    
    char postfix[20];
    int i ;
    printf("enter the postfix expression");
    scanf("%s",&postfix);
    float res=evaluate(postfix);
    printf("THE VALUE OF POSTFIX EXPRESSION IS %f",res);
}
