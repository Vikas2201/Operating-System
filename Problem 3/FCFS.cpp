#include<stdio.h>
int main()
{
	int i , j , arr[20] , bt[20] , wt[20] , tat[20] , ct[20] ;
	int n ;
	float avwt=0 , avtat=0 , thrput ;
	printf("Enter Total Number Of Processes(Maximum is 20) : ");
	scanf("%d" ,&n);
	
	/*ARRIVAL TIME OF PROCESS*/
	printf("\nEnter Process Arrival Time in incresing order :\n");
	for(i=0 ; i<n ; i++)
	{
		printf("P[%d] :",i+1);
		scanf("%d" , &arr[i]) ;
	}
	
	/*BURST TIME OF PROCESS*/
	printf("\nEnter Process Burst Time :\n");
	for(i=0 ; i<n ; i++)
    {
        printf("P[%d] :",i+1);
        scanf("%d",&bt[i]);
    }
     
    /*COMPLETION TIME OF PROCESS*/
	ct[0] = bt[0];
	for(i=1 ; i<n ; i++) 
	{
		ct[i] = ct[i-1] + bt[i];
	}
	
	/*TRUN AROUND TIME*/
	for(i=0 ; i<n ; i++)
	{
		tat[i] = ct[i] - arr[i];
		avtat+=tat[i];
	}
	
	/*WAITING TIME*/
	for(i=0 ; i<n ;i++)
	{
		wt[i] = tat[i] - bt[i];
		avwt+=wt[i];
	}
    
    printf("\nProcess_ID  Arrival_Time  Burst_Time  Completion_Time  Turnaround_Time  Waiting_Time ");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d ",i+1,arr[i],bt[i],ct[i],tat[i],wt[i]);
    }
	avwt = avwt/i;
    avtat = avtat/i;
    thrput = n/float(ct[3]);
    printf("\nnAverage Waiting Time : %f", avwt);
    printf("\nAverage Turnaround Time : %f", avtat);
    printf("\nThrough Put : %f" , thrput) ;
 
    return 0;
}
