#include<stdio.h>
  
int main() 
{
    int arr[10], bt[10], temp[10];
    int i, min , count = 0, j , n , sum=0;
    double wt = 0, tat = 0, end ;
    float avwt, avtat , thrput;
    printf("\nEnter the Total Number of Processes : ");
    scanf("%d", &n); 
    
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
    /*SCHEDULING LENGTH*/
    for(i=0 ;i<n ;i++)
    {
    	sum = sum + bt[i];
	}
    bt[9] = 9999;  
    for(i = 0; count != n; i++)
    {
        min = 9;
        for(j = 0; j < n ; j++)
        {
            if(arr[j] <= i && bt[j] < bt[min] && bt[j] > 0)
            {
                min = j;
            }
        }
        bt[min]--;
        if(bt[min] == 0)
        {
            count++;
            end = i + 1;
            wt = wt + end - arr[min] - temp[min];
            tat = tat + end - arr[min];
        }
    }

	thrput = n / float(sum);
    avwt = wt / n ; 
    avtat = tat / n;
    printf("\nAverage Waiting Time : %f", avwt);
    printf("\nAverage Turnaround Time : %f", avtat);
    printf("\nThrough Put : %f" , thrput) ;
    return 0;
}
