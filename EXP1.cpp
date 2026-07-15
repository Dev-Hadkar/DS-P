#include<stdio.h>
#include<conio.h>
void main()
{
    clrscr();
    int n,i,x,count=0,f=-1;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[100];
    printf("Enter %d elements :\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter number to find:");
    scanf("%d",&x);
    for(i=0;i<n;i++)
    {
	if(arr[i]==x)
	{
	    count++;
	    f=i;
	}

    }
    printf("The number of occurences of %d:%d \n",x,count);
    if(f!=-1)
    {
	printf("First occurence is at index: %d \n",f);

    }
    else
    {
	printf("%d not found in the array \n",x);

    }
    getch();
}
