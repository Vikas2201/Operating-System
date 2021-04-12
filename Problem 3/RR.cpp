#include<stdio.h>

int main()
{
	int i , j , arr[20] , bt[20] , wt[20] , tat[20] , n , temp[20] , sum = 0 , tq , N , count = 0;
	float avwt=0.0 , avtat=0.0 , thrput ;
	printf("Enter Total Number Of Processes(Maximum is 20) : ");
	scanf("%d" ,&n);
	N = n ;
	
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
        temp[i] = bt[i];
    }
    
	printf("\nEnter the Time Quantum for the process: ");  
    scanf("%d", &tq); 
    for(i = 0; !N == 0; )  
    {  
        if(temp[i] <= tq && temp[i] > 0)   
        {  
            sum = sum + temp[i];  
            temp[i] = 0;  
            count=1;  
        }     
        else if(temp[i] > 0)  
        {  
            temp[i] = temp[i] - tq;  
            sum = sum + tq;    
        }  
        if(temp[i]==0 && count==1)  
        {  
            N--;    
            wt[i] = sum-arr[i]-bt[i]; 
			avwt+=wt[i]; 
            tat[i] = sum-arr[i];  
            avtat+=tat[i];
            count =0;     
        }  
        if(i==n-1)  
        {  
            i=0;  
        }  
        else if(arr[i+1]<=sum)  
        {  
            i++;  
        }  
        else  
        {    
            i=0;  
        }  
    }
    printf("\nProcess_ID  Arrival_Time  Burst_Time  Waiting_Time  Turnaround_Time ");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d ",i+1,arr[i],bt[i],wt[i],tat[i]);
    }
    /*SCHEDULING LENGTH*/
    sum =0 ;
    for(i=0 ;i<n ;i++)
    {
    	sum = sum + bt[i];
	}
    thrput = n/float(sum);
	avwt = avwt/n;
    avtat = avtat/n;
    printf("\nAverage Waiting Time : %f", avwt);
    printf("\nAverage Turnaround Time : %f", avtat);
    printf("\nThrough Put : %f" , thrput) ;
 
    return 0;
}

