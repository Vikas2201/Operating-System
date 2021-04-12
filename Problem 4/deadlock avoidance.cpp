#include<stdio.h>
#include<conio.h>

int max[100][100];
int alloc[100][100];
int need[100][100];
int avail[100];
int n,r;

void input()
{
    int i,j;
    printf("ENTER THE NUMBER OF PROCESSES : ");
    scanf("%d",&n);
    printf("ENTER THE NUMBER OF RESOURCES INSTANCES : ");
    scanf("%d",&r);
    printf("ENTER THE MAX MATRIX : \n");
    for(i=0; i<n; i++) 
	{
        for(j=0; j<r; j++) 
		{
            scanf("%d",&max[i][j]);
        }
	}
    printf("ENTER THE ALLOCATION MATRIX : \n");
    for(i=0; i<n; i++) 
	{
        for(j=0; j<r; j++) 
		{
            scanf("%d",&alloc[i][j]);
        }
	}
    printf("ENTER THE AVAILABLE RESOURCES :\n");
    for(i=0 ; i<r; i++) 
	{
        scanf("%d",&avail[i]);
    }
}
void show() 
{
    int i,j ;
    printf("PROCESS_ID\t ALLOCATION_MATRIX\t MAX_MATRIX\t AVAILABLE_MATRIX\t");
    for(i=0; i<n; i++) 
	{
        printf("\nP%d\t\t\t",i+1);
        for(j=0; j<r; j++) 
		{
            printf("%d ",alloc[i][j]); 
		}
        printf("\t\t\t");
        for(j=0; j<r; j++) 
		{
            printf("%d ",max[i][j]); 
		}
        printf("\t\t");
        if(i == 0) 
		{
        for(j=0; j<r; j++)
        printf("%d ",avail[j]);
        }
	}
}
void cal()
{
    int finish[100], temp, need[100][100], flag=1, k, c1=0;
    int safe[100];
    int i,j;
    for(i=0; i<n; i++) 
	{
        finish[i] = 0; 
	}
    //find need matrix
    for(i=0; i<n; i++) 
	{
        for(j=0; j<r; j++) 
		{
            need[i][j] = max[i][j] - alloc[i][j];
		}
	}
    printf("\n");
    while(flag) 
	{
        flag=0;
        for(i=0; i<n; i++) 
		{
            int c=0;
            for(j=0; j<r; j++) 
			{
                if((finish[i] == 0)&&(need[i][j] <= avail[j])) 
				{
                    c++;
                    if(c==r) 
					{
                        for(k=0; k<r; k++) 
						{
                            avail[k] = avail[k] + alloc[i][j];
                            finish[i] = 1;
                            flag = 1; 
						}
                        printf("P%d ->",(i+1));
                        if(finish[i] == 1) 
						{
                            i=n;
                        }
					}
				}
			}
		}
	}
    for(i=0; i<n; i++) 
	{
        if(finish[i] == 1) 
		{
            c1++;
        }
        else
        {
		    printf("P%d ->",i);
        }
    }
    if(c1 == n)
    {
	    printf("\nTHE SYSTEM IS IN SAFE STATE");
    }
    else
    {
        printf("\n PROCESS ARE IN DEAD LOCK");
        printf("\nTHE SYSTEM IS IN UNSAFE STATE");
	}
}
int main()
{
    printf("\t\tBANKERS ALGORITHM FOR DEADLOCK AVOIDANCE\n");
    input();
    show();
    cal();
    getch();
    return 0;
}	
