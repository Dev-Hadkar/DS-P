#include<stdio.h>
int top=-1,x,c;
int MaxSize=100;
int stack[100];
int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if(top==MaxSize-1)
        return 1;
    else
        return 0;
}
void push()
{
     if(isFull())
        printf("Stack Overflow\n");
     else
     {
         top++;
         stack[top]=x;
     }       
}
void pop()
{
     if(isEmpty())
        printf("Stack Underflow\n");
     else
     {
         x=stack[top];
         top--;
         printf("Element popped is %d\n",x);
     }       
}
void peek()
{
     if(isEmpty())
        printf("Stack Underflow\n");
     else
     {
         x=stack[top];
         printf("Element at top is %d\n",x);
     }         
}
void display()
{
     if(isEmpty())
        printf("Stack Underflow\n");
     else
     {
         for(int i=top;i>=0;i--)
         {
                 printf("| %d |\n",stack[i]);
                 printf("-----\n");
         }
     }     
}
int main()
{
    while(c!=5)
    {
               printf("Enter Choice(1.Push 2.Pop 3.Peek 4.Display 5.Exit): ");
               scanf("%d",&c);
               switch(c)
               {
                        case 1:
                             printf("Enter element to push: ");
                             scanf("%d",&x);
                             push();
                             break;
                        case 2:
                             pop();
                             break;
                        case 3:
                             peek();
                             break;
                        case 4:
                             display();
                             break;
                        case 5:
                             break;
                        default:
                             printf("Invalid choice\n");
                                    
               }  
    }   
}
