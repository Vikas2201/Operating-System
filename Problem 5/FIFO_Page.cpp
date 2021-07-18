#include<stdio.h>
void fifo(int n , int *rs , int m)
{
	int i , j , k , avail , count = 0 , frame[n];
	float hit_ratio , miss_ratio ;
	for(j=0;j<n;j++)
    {
	    frame[j] = -1;
	}
	
	j = 0;
	printf("\nGiven reference string on using FIFO page replacement\n");
	for(i=0 ; i<m ; i++)
	{
        printf("%d\t\t",rs[i]);
        avail=0;
        for(k=0;k<n;k++)
            if(frame[k]==rs[i])
                avail=1;
        if (avail==0)
        {
            frame[j]=rs[i];
            j=(j+1)%n;
            count++;
            for(k=0;k<n;k++)
                printf("%d\t\t",frame[k]);
        }
        printf("\n");
    }
    
    miss_ratio = count/(float)m ;
    hit_ratio = 1 - miss_ratio ;
    
    printf("\nWhen the number of frames are : %d",n);
	printf("\nTotal Number of Miss : %d",count);
    printf("\nTotal Number Of Hit : %d",(m - count));
    printf("\nThe number of page faults is : %d\n",count);
    return ;
}
int main()
{
    int m , i;
	printf("\nEnter the length of the Reference string : ");
    scanf("%d",&m);
    
    int rs[m];
    printf("\nEnter the reference string : ");
    for(i=0;i<m;i++)
    {
    	scanf("%d",&rs[i]);
	}
	
	int n = 3;
 
    fifo(n, rs, m);
 
    // Increase value of frame size
    n = 4;
 
    // The page fault increases even after increasing then the number of frames. This is Belady's Anomaly
    fifo(n , rs , m);
	return 0;
}
