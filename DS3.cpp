#include<stdio.h>
int front=-1,rear=-1,x,c;
int MaxSize=5;
int cirqueue[5];
int isFull()
{
    if(((rear+1)%MaxSize)==front)
        return 1;
    else
        return 0;
}
int isEmpty()
{
    if(front==-1 && rear==-1)
        return 1;
    else
        return 0;
}
void insert()
{
     if(isFull())
        printf("Queue Overflow\n");
     else if(isEmpty())
     {
         front=0;
         rear=0;
         cirqueue[rear]=x;
     }
     else
     {
         rear=((rear+1)%MaxSize);
         cirqueue[rear]=x;
     }       
}
void delete()
{
     if(isEmpty())
        printf("Queue Empty\n");
     else
     {
         if(front!=rear)
        {
            x=cirqueue[front];
            if(front==MaxSize-1)
                front=0;
             else
                front++;
            printf("Element deleted is %d\n",x);
        }   
        else
        {
            x=cirqueue[front];
            printf("Element deleted is %d\n",x);
            front=-1;
            rear=-1;
        }
    }
}
void display()
{
     if(isEmpty())
        printf("Queue is Empty\n");
     else
     {
        printf("Elements: \n");
        if(front<=rear)
        {
           for(int i=front;i<=rear;i++)
           {
              printf("%d ",cirqueue[i]);
           }
           printf("\n");
        }
        else
        {
           for(int i=front;i<MaxSize;i++)
           {
              printf("%d ",cirqueue[i]);
           }
           for(int i=0;i<=rear;i++)
           {
              printf("%d ",cirqueue[i]);
           }
           printf("\n");

        }
     }         
}
int main()
{
    while(c!=4)
    {
               printf("Enter Choice(1.Insert 2.Delete 3.Display 4.Exit): ");
               scanf("%d",&c);
               switch(c)
               {
                        case 1:
                             printf("Enter element to insert: ");
                             scanf("%d",&x);
                             insert();
                             break;
                        case 2:
                             delete();
                             break;
                        case 3:
                             display();
                             break;
                        case 4:
                             break;
                        default:
                             printf("Invalid choice\n");
                                    
               }  
    }   
}
