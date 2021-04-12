#include<stdio.h>
int main()
{
    int i, j, m, n, rs[50], frame[10], k, avail, count=0 ;
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
    for(j=0;j<n;j++)
    {
	    frame[j] = -1;
	}
	j = 0;
	printf("Reference String\n");
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
	printf("\nTotal Number of Miss : %d",count);
    printf("\nTotal Number Of Hit : %d",(m - count));
    printf("\nHit Ratio : %.2f",hit_ratio);
    printf("\nMiss Ratio : %.2f",miss_ratio);
	return 0;
}
