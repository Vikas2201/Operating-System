#include<stdio.h>
#include<math.h>
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
void bubblesort(int arr[], int n) 
{ 
    int i, j; 
    for (i = 0; i < n-1; i++)     
    {
	    for (j = 0; j < n-i-1; j++) 
        {
		    if (arr[j] > arr[j+1]) 
            {
			    swap(&arr[j], &arr[j+1]); 
			}
		}
	}
} 
int main()
{
    int queue[50],n,head,i,j,k,seek=0,temp,queue1[30],queue2[30],temp1=0,temp2=0;
    float avg;
    printf("Enter the size of disk Queue : ");
    scanf("%d",&n);
    printf("Enter position of Read/Write head : ");
    scanf("%d",&head);
    printf("\nEnter elements of disk queue : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&temp);
        if(temp > head)
        {
        	queue1[temp1] = temp; 
            temp1++;
		}
		else    
        {   
            queue2[temp2] = temp; 
            temp2++;
        }
    }
    bubblesort(queue1,temp1);
    bubblesort(queue2,temp2);
    queue[0] = head;
    for(i=1,j=0;j<temp1;i++,j++)
    {
        queue[i] = queue1[j]; 
    }
    for(i=temp1+1,j=temp2-1;j>=0;i++,j--)
    {
        queue[i] = queue2[j];
    }
    for(i=0;i<n;i++)
    {
        seek=seek+abs(queue[i+1]-queue[i]);
    }
    printf("\nTotal Seek Time : %d",seek);
    avg=seek/(float)n;
    printf("\nAverage Seek Time : %f",avg);   
}
