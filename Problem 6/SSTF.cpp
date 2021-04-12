#include<stdio.h>
#include<math.h>
int main()
{
    int queue[100],t[100],head,seek=0,n,i,j,temp;
    float avg;
    printf("Enter the size of disk Queue : ");
    scanf("%d",&n);
    printf("Enter position of Read/Write head : ");
    scanf("%d",&head);
    printf("\nEnter elements of disk queue : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&queue[i]);
    }
    for(i=1;i<n;i++)
    {
        t[i]=abs(head-queue[i]);	
	}
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(t[j]>t[j+1])
            {
                temp=t[j];
                t[j]=t[j+1];
                t[j+1]=temp;
                temp=queue[j];
                queue[j]=queue[j+1];
                queue[j+1]=temp;	
            }
        }
    }
    for(i=1;i<n-1;i++)
    {
        seek=seek+abs(head-queue[i]);
        head=queue[i];
    }
    printf("\nTotal Seek Time : %d",seek);
    avg=seek/(float)n;
    printf("\nAverage Seek Time : %f",avg);
}
