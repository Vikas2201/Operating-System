#include<stdio.h>

int main()
{
    int i,j,sum=0,n,dq[20],seek_time[20],head;
	float avg;
    printf("Enter number of location : ");
    scanf("%d",&n);
    printf("\nEnter position of Read/Write head : ");
    scanf("%d",&head);
    printf("\nEnter elements of disk queue :");
    for(i=0;i<n;i++)
    {
        scanf("%d",&dq[i]);
        seek_time[i] = head - dq[i];
        if(seek_time[i] < 0)
        {
            seek_time[i] = dq[i] - head;
        }
        head = dq[i];
        sum = sum + seek_time[i];
	}
    printf("\nMovement of total cylinders : %d",sum);
    avg=sum/(float)n;
    printf("\nAverage Seek Time : %f",avg);
    return 0;
}
