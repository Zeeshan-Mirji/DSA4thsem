#include <stdio.h>
#define SIZE 5
int stack[SIZE];
int top=-1;
int i,ch;
void push();
void pop();
void display();
int main ()
{

 printf("***Stack operations using array***");

 printf("\n----------------------------------------------\n");
 while(1)
 {
 printf("Chose one from the below options...\n");
 printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");
 printf("\n Enter your choice \n");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:push();
 break;
 case 2:pop();
 break;
 case 3:display();
 break;

 default:printf("Exiting...");

 }

 }
}

void push ()
{
 int val;
 if (top == SIZE-1 )
 printf("\n Overflow");
 else
 {
 printf("Enter the value?\n");
 scanf("%d",&val);
 top = top +1;
 stack[top] = val;
 }
}
void pop ()
{
 if(top == -1)
 printf("Underflow");
 else
 printf("DELETED ITEM =%d\n",stack[top--]);
}
void display()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
    }
    for(i=top;i>=0;i--)
    {
        printf("%d\t",stack[i]);
    }
}
