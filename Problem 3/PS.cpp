#include<stdio.h>
#include<string.h>

int main()
{
	int i , j , pri[20] , bt[20] , wt[20] , tat[20] , n , temp , sum = 0 ;
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
	
	/*BURST TIME OF PROCESS*/
	printf("\nEnter Process Burst Time :\n");
	for(i=0 ; i<n ; i++)
    {
        scanf("%d",&bt[i]);
    }
    	
	/*PRIORITY  OF PROCESS*/
	printf("\nEnter priority of process :\n");
	for(i=0 ; i<n ; i++)
	{
		scanf("%d" , &pri[i]) ;
	}
	   
	/*SCHEDULING LENGTH*/
    for(i=0 ;i<n ;i++)
    {
    	sum = sum +bt[i];
	}
	
    for(i=0; i<n; i++)
    {
		for(j=0; j<n; j++)
        {
            if(pri[i]>pri[j])
            {
                temp=pri[i];
                pri[i]=pri[j];
                pri[j]=temp;
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
                strcpy(t,p[i]);
                strcpy(p[i],p[j]);
                strcpy(p[j],t);
            }
        }
	}
	/*WAITING TIME*/
	wt[0]= 0;
	for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
        {
            wt[i]=wt[i]+bt[j];
        }
        avwt+=wt[i];
    }
    /*TURN AROUND TIME*/
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     
        avtat+=tat[i];
    }

    printf("\nProcess_ID  Arrival_Time  Burst_Time  Priority  Waiting_Time  Turnaround_Time ");
    for(i=0;i<n;i++)
    {
        printf("\nP[%s]\t\t%d\t\t%d\t%d\t\t%d\t\t%d ",p[i],0,bt[i],pri[i],wt[i],tat[i]);
    }
    thrput = n/float(sum);
	avwt = avwt/n;
    avtat = avtat/n;
    printf("\nAverage Waiting Time : %f", avwt);
    printf("\nAverage Turnaround Time : %f", avtat);
    printf("\nThrough Put : %f" , thrput) ;
 
    return 0;
}
