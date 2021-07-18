/*
Name: Chirantan Joshi.
Div: G
Batch: G1
Roll No.: PG13
SORTING WITH FORK CALL
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	pid_t num_pid;
	int arr[20],n,i,j,temp,status;
	printf("Enter the number of elements in array: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter element in array: ");
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[j] < arr[i])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	num_pid=fork();
	if(num_pid==0)
	{
		printf("\nIn Child process!!\n\nSorted array is:\n");
		for(i=n-1;i>=0;i--)
		{
			printf("%d\n",arr[i]);
		}
		_exit(0);
	}
	else
	{
		waitpid(num_pid,&status,0);
		int exit_status=WEXITSTATUS(status);
		printf("\nThe exit status of child is: %d\n",exit_status);
		printf("\nIn Parent process!!\n\nSorted array is:\n");
		for(i=0;i<n;i++)
		{
			printf("%d\n",arr[i]);
		}
	}
	return 0;
}
/*
OUTPUT:
Enter the number of elements in array: 5
Enter element in array: 10
Enter element in array: 3
Enter element in array: 5
Enter element in array: 20
Enter element in array: 15

In Child process!!

Sorted array is:
20
15
10
5
3

The exit status of child is: 0

In Parent process!!

Sorted array is:
3
5
10
15
20
*/
