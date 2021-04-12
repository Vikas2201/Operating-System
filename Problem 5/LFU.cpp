#include<stdio.h>
int main()
{
    int i, j, k , m, n, rs[50], frame[10], temp[10] , fault = 0, min;
	float hit_ratio , miss_ratio ;
    printf("\nEnter the no. of frames:");
    scanf("%d",&n);
    printf("\nEnter the length of the Reference string:");
    scanf("%d",&m);
    printf("\nEnter the reference string :");
    for(i=0;i<m;i++)
    {
    	scanf("%d",&rs[i]);
	}
    for(i=0;i<n;i++)
    {
	    frame[i] = -1;
	    temp[i] = 0;
	}
	printf("\nFrame Page :");
	for(i=0 ; i<m ; i++)
	{
		for(j=0 ; j<n ;j++)
		{
			if(frame[j] == rs[i])
			{
				temp[j]++ ;
				break;
			}
		}
		if(j==n)
        {     
	        min = 0;    
            for(k=1;k<n;k++)
            if(temp[k] < temp[min])
            {
			    min=k;
			}
            frame[min] = rs[i]; 
			temp[min] = 1;
            fault++;
        }
        printf("\n\n");
        for(j = 0; j < n; j++)
	    {
    	    printf("%d\t\t", frame[j]);
        }
    }
    miss_ratio = fault/(float)m ;
    hit_ratio = 1 - miss_ratio ;
    printf("\nTotal Number of Miss : %d",fault);
    printf("\nTotal Number Of Hit : %d",(m - fault));
    printf("\nHit Ratio : %.2f",hit_ratio);
    printf("\nMiss Ratio : %.2f",miss_ratio);
    return 0 ;
}
