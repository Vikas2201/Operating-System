#include<stdio.h>
int findLRU(int temp[] , int n)
{
	int i, minimum = temp[0], pos = 0;
	for(i = 1; i < n; i++)
	{
		if(temp[i] < minimum)
		{
			minimum = temp[i];
			pos = i;
		}
	}
	return pos;
}
int main()
{
    int i, j, m, n, rs[50], frame[10], k , l, counter=0 , temp[10] , fault = 0, pos;
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
	}
	printf("\nFrame Page :");
	for(i=0 ; i<m ; i++)
	{
		l = 0 , k =0 ;
		for(j=0 ; j<n ;j++)
		{
			if(frame[j] == rs[i])
			{
				counter++ ;
				temp[j] = counter ;
				l = 1 , k = 1;
				break;
			}
		}
		if (l==0)
		{
			for(j=0 ;j<n ;j++)
			{
				if(frame[j] == -1)
				{
					counter++;
	    			fault++;
	    			frame[j] = rs[i];
	    			temp[j] = counter;
					k=1;
					break;
				}
			}
		}
		if(k == 0)
		{
    		pos = findLRU(temp, n);
    		counter++;
    		fault++;
    		frame[pos] = rs[i];
    		temp[pos] = counter;
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
