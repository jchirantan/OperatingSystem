/*
Name: Chirantan Joshi.
Div: G
Batch: G1
Roll No.: PG13
BANKER'S ALGORITHM
*/
#include <stdio.h>
int main()
{
	char choice;
	int i,j,proc,res,alloc[10][10],max[10][10],need[10][10],avail[10],pid;
	int work[10],cnt=0,cnt1=0,finish[10]={0};
	printf("Enter the number of processes in system: ");
	scanf("%d",&proc);
	printf("Enter the number of resources: ");
	scanf("%d",&res);
	for(i=0;i<res;i++)
	{
		printf("Enter the number of resources of type %d: ",i);
		scanf("%d",&avail[i]);
	}
	for(i=0;i<proc;i++)
	{
		for(j=0;j<res;j++)
		{
			printf("Enter the maximum instances required of resource type %d for process %d: ",j,i);
			scanf("%d",&max[i][j]);
		}
	}
	for(i=0;i<proc;i++)
	{
		for(j=0;j<res;j++)
		{
			printf("Enter the number of instances allocated of resource type %d for process %d: ",j,i);
			scanf("%d",&alloc[i][j]);
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
	for(i=0;i<res;i++)
	{
		int x=0;
		for(j=0;j<proc;j++)
		{
			x+=alloc[j][i];
		}
		avail[i]=avail[i]-x;
		work[i]=avail[i];
	}
	while(cnt<proc)
	{
		for(j=0;j<proc;j++)
		{
			cnt1=0;
			for(i=0;i<res;i++)
			{
				if(need[j][i]<=work[i])
					cnt1++;
				else
					break;
			}
			if(cnt1==res && finish[j]==0)
			{
				printf("Process in execution is P%d\n",j);
				finish[j]=1;
				cnt++;
				for(i=0;i<res;i++)
				{
					work[i]+=alloc[j][i];
				}
			}
		}
	}
	cnt=0;
	for(i=0;i<proc;i++)
	{
		if(finish[i]==1)
			cnt++;
	}
	if(cnt==proc)	
		printf("\nThe system is in safe state.\n");
	else
		printf("\nSystem is not in safe state.\n\n");
	do
	{
		printf("Do you want to request additional resources(y/n)? ");
		scanf(" %c",&choice);
		if(choice == 'y')
		{
			printf("Enter the process ID: ");
			scanf("%d",&pid);
			printf("\n");
			for(i=0;i<res;i++)
			{
				printf("Enter the number of instances for resource type %d: ",i);
				scanf("%d",&work[i]);
			}
			cnt1=0;
			for(i=0;i<res;i++)
			{
				if(work[i] <= avail[i])
					cnt1++;
				else
					break;
			}
			if(cnt1 == res)
			{
				for(i=0;i<res;i++)
				{
					avail[i]=avail[i]-work[i];
				}
				printf("\nThe system is in safe state...REQUEST GRANTED.\n\n");
			}
			else
				printf("\nThe system is not in safe state...REQUEST CAN'T BE GRANTED.\n\n");
		}	
	}while(choice=='y');
	printf("\nProcess\tAllocation\tMax\t\tNeed\t\tAvailable\n\n\t");
	cnt=0;
	while(cnt<4)
	{
		for(i=0;i<res;i++)
		{
			printf("R%d  ",i);
		}
		cnt++;
		printf("\t");
	}
	printf("\n");
	cnt=0;
	for(i=0;i<proc;i++)
	{
		printf("P%d\t",i);
		for(j=0;j<res;j++)
		{
			printf("%d   ",alloc[i][j]);
		}
		printf("\t");
		for(j=0;j<res;j++)
		{
			printf("%d   ",max[i][j]);
		}
		printf("\t");
		for(j=0;j<res;j++)
		{
			printf("%d   ",need[i][j]);
		}
		printf("\t");
		if(cnt==0)
		{
			for(j=0;j<res;j++)
			{printf("%d   ",avail[j]);cnt++;}
		}
		printf("\n");
	}
	return 0;
}
/*
OUTPUT:
Enter the number of processes in system: 5
Enter the number of resources: 3
Enter the number of resources of type 0: 10
Enter the number of resources of type 1: 5
Enter the number of resources of type 2: 7
Enter the maximum instances required of resource type 0 for process 0: 7
Enter the maximum instances required of resource type 1 for process 0: 5
Enter the maximum instances required of resource type 2 for process 0: 3
Enter the maximum instances required of resource type 0 for process 1: 3
Enter the maximum instances required of resource type 1 for process 1: 2
Enter the maximum instances required of resource type 2 for process 1: 2
Enter the maximum instances required of resource type 0 for process 2: 9
Enter the maximum instances required of resource type 1 for process 2: 0
Enter the maximum instances required of resource type 2 for process 2: 2
Enter the maximum instances required of resource type 0 for process 3: 2
Enter the maximum instances required of resource type 1 for process 3: 2
Enter the maximum instances required of resource type 2 for process 3: 2
Enter the maximum instances required of resource type 0 for process 4: 4
Enter the maximum instances required of resource type 1 for process 4: 3
Enter the maximum instances required of resource type 2 for process 4: 3
Enter the number of instances allocated of resource type 0 for process 0: 0
Enter the number of instances allocated of resource type 1 for process 0: 1
Enter the number of instances allocated of resource type 2 for process 0: 0
Enter the number of instances allocated of resource type 0 for process 1: 2
Enter the number of instances allocated of resource type 1 for process 1: 0
Enter the number of instances allocated of resource type 2 for process 1: 0
Enter the number of instances allocated of resource type 0 for process 2: 3
Enter the number of instances allocated of resource type 1 for process 2: 0
Enter the number of instances allocated of resource type 2 for process 2: 2
Enter the number of instances allocated of resource type 0 for process 3: 2
Enter the number of instances allocated of resource type 1 for process 3: 1
Enter the number of instances allocated of resource type 2 for process 3: 1
Enter the number of instances allocated of resource type 0 for process 4: 0
Enter the number of instances allocated of resource type 1 for process 4: 0
Enter the number of instances allocated of resource type 2 for process 4: 2
Process in execution is P1
Process in execution is P3
Process in execution is P4
Process in execution is P0
Process in execution is P2

The system is in safe state.

Do you want to request additional resources(y/n)? y
Enter the process ID: 0

Enter the number of instances for resource type 0: 1
Enter the number of instances for resource type 1: 0
Enter the number of instances for resource type 2: 2

The system is in safe state...REQUEST GRANTED.

Do you want to request additional resources(y/n)? y
Enter the process ID: 4

Enter the number of instances for resource type 0: 3
Enter the number of instances for resource type 1: 3
Enter the number of instances for resource type 2: 0

The system is not in safe state...REQUEST CAN'T BE GRANTED.

Do you want to request additional resources(y/n)? n

Process	Allocation	Max		Need		Available

	R0  R1  R2  	R0  R1  R2  	R0  R1  R2  	R0  R1  R2  	
P0	0   1   0   	7   5   3   	7   4   3   	2   3   0   
P1	2   0   0   	3   2   2   	1   2   2   	
P2	3   0   2   	9   0   2   	6   0   0   	
P3	2   1   1   	2   2   2   	0   1   1   	
P4	0   0   2   	4   3   3   	4   3   1   	
*/
