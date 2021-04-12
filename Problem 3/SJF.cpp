#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int i , j , arr[20] , bt[20] , wt[20] , tat[20] , n , temp , ct[20] , ft[20] , sum = 0 ;
	char p[20][20] , t[20];
	float avwt=0.0 , avtat=0.0 , thrput ;
	printf("Enter Total Number Of Processes(Maximum is 20) : ");
	scanf("%d" ,&n);
	
	/*PROCESS ID*/
	printf("\nEnter Process ID :\n");
	for(i=0 ;i<n ;i++)
	{
		scanf("%s" , p[i]);
	}
	
	/*ARRIVAL TIME OF PROCESS*/
	printf("\nEnter Process Arrival Time :\n");
	for(i=0 ; i<n ; i++)
	{
		scanf("%d" , &arr[i]) ;
	}
	
	/*BURST TIME OF PROCESS*/
	printf("\nEnter Process Burst Time :\n");
	for(i=0 ; i<n ; i++)
    {
        scanf("%d",&bt[i]);
    }
    
    for(i=0; i<n; i++)
    {
		for(j=0; j<n; j++)
        {
            if(bt[i]<bt[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
                strcpy(t,p[i]);
                strcpy(p[i],p[j]);
                strcpy(p[j],t);
            }
        }
	}
	
	for(i=0; i<n; i++)
    {
        if(i==0)
        {
		    ct[i]=arr[i];
        }
		else
        {
		    ct[i]=ft[i-1];
        }
		wt[i]=ct[i]-arr[i];
        ft[i]=ct[i]+bt[i];
        tat[i]=ft[i]-arr[i];
        
        avwt+=wt[i];
        avtat+=tat[i];
    }
    /*SCHEDULING LENGTH*/
    for(i=0 ;i<n ;i++)
    {
    	sum = sum +bt[i];
	}

    printf("\nProcess_ID  Arrival_Time  Burst_Time  Completion_Time  Turnaround_Time  Waiting_Time ");
    for(i=0;i<n;i++)
    {
        printf("\n%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d ",p[i],arr[i],bt[i],ct[i],tat[i],wt[i]);
    }
    thrput = n/float(sum);
	avwt = avwt/i;
    avtat = avtat/i;
    printf("\nAverage Waiting Time : %f", avwt);
    printf("\nAverage Turnaround Time : %f", avtat);
    printf("\nThrough Put : %f" , thrput) ;
 
    return 0;
}
