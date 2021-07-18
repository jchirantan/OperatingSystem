/*
Name: Chirantan Joshi.
Div: G
Batch: G1
Roll No.: PG13
DEMAND PAGING
*/

#include <stdio.h>
#include <stdlib.h>

int queue[5];
int front=-1;
int rear=-1;
void enq(int page)
{
	front++;
	queue[front]=page;
}
int deq()
{
	int x;
	rear++;
	x=queue[rear];
	return x;
}

void fifo()
{
	char choice;
	int a[20],cnt=0,cnt1,fr,fault=0,i,j,x,k;
	printf("Enter the total no. of frames: ");
	front=-1;
	rear=-1;
	scanf("%d",&fr);
	do
	{
		printf("Enter the reference string element %d: ",cnt+1);
		scanf("%d",&a[cnt]);
		cnt++;
		printf("Do you want to enter more(y/n)? ");
		scanf(" %c",&choice);
	}while(choice=='y');
	i=0;
	while(front < fr-1)
	{
		cnt1=0;
		if(front==-1)
		{
			enq(a[i]);
			fault++;
			i++;
		}
		for(j=0;j<=front;j++)
		{
			if(queue[j]==a[i])
				break;
			else
				cnt1++;
		}
		if(cnt1==front+1)
		{
			enq(a[i]);
			fault++;
		}	
		i++;
		printf("\nContents of queue are: ");
		for(j=rear+1;j<=front;j++)
		{
			printf("%d\t",queue[j]);
		}
	}
	if(i>=cnt)
		printf("\n\nTotal number of faults are: %d\n",fault);
	while(i<cnt)
	{
		cnt1=0;
		for(j=0;j<fr;j++)
		{
			if(queue[j]==a[i])
				break;
			else
				cnt1++;
		}
		if(cnt1==fr)
		{
			front=-1;
			rear=-1;
			x=deq();
			for(k=0;k<fr-1;k++)
			{
				x=deq();
				enq(x);
			}
			enq(a[i]);
			fault++;
		}
		printf("\nContents of queue are: ");
		for(j=0;j<fr;j++)
		{
			printf("%d\t",queue[j]);
		}
		i++;
	}
	printf("\n\nTotal number of faults are: %d\n",fault);
}
void lru()
{
	char choice;
	int a[20],cnt=0,cnt1,fr,fault=0,i,j,x,y,k;
	printf("Enter the total no. of frames: ");
	front=-1;
	rear=-1;
	scanf("%d",&fr);
	do
	{
		printf("Enter the reference string element %d: ",cnt+1);
		scanf("%d",&a[cnt]);
		cnt++;
		printf("Do you want to enter more(y/n)? ");
		scanf(" %c",&choice);
	}while(choice=='y');
	i=0;
	while(front < fr-1)
	{
		cnt1=0;
		if(front==-1)
		{
			enq(a[i]);
			fault++;
			i++;
		}
		for(j=0;j<=front;j++)
		{
			if(queue[j]==a[i]) 
			{
				y=front;
				front=-1;
				rear=-1;
				for(k=0;k<y;k++)
				{
					if(rear==j-1)
						rear++;
					x=deq();
					enq(x);
				}
				enq(a[i]);
				break;
			}
			else
				cnt1++;
		}
		if(cnt1==front+1)
		{
			enq(a[i]);
			fault++;
		}	
		i++;
		printf("\nContents of queue are: ");
		for(j=0;j<=front;j++)
		{
			printf("%d\t",queue[j]);
		}
	}
	if(i>=cnt)
		printf("\n\nTotal number of faults are: %d\n",fault);
	while(i<cnt)
	{
		cnt1=0;
		for(j=0;j<fr;j++)
		{
			if(queue[j]==a[i])
			{
				front=-1;
				rear=-1;
				for(k=0;k<fr-1;k++)
				{
					if(rear==j-1)
						rear++;
					x=deq();
					enq(x);
				}
				enq(a[i]);
				break;
			}
			else
				cnt1++;
		}
		if(cnt1==fr)
		{
			front=-1;
			rear=-1;
			x=deq();
			for(k=0;k<fr-1;k++)
			{
				x=deq();
				enq(x);
			}
			enq(a[i]);
			fault++;
		}
		printf("\nContents of queue are: ");
		for(j=0;j<fr;j++)
		{
			printf("%d\t",queue[j]);
		}
		i++;
	}
	printf("\n\nTotal number of faults are: %d\n",fault);
}
int main()
{
	int choice;
	while(1)
	{
		printf("\n----------MENU----------\n1.First In First Out.\n2.Last Rcently Used.\n3.Exit.\n\nEnter the choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	fifo();
			break;
			case 2:	lru();
			break;
			case 3:	exit(0);
			break;
			default:printf("Wrong choice!!");
		}
	}
	return 0;
}

/*
OUTPUT:

----------MENU----------
1.First In First Out.
2.Last Rcently Used.
3.Exit.

Enter the choice: 1
Enter the total no. of frames: 3
Enter the reference string element 1: 1
Do you want to enter more(y/n)? y
Enter the reference string element 2: 2
Do you want to enter more(y/n)? y
Enter the reference string element 3: 3
Do you want to enter more(y/n)? y
Enter the reference string element 4: 4
Do you want to enter more(y/n)? y
Enter the reference string element 5: 1
Do you want to enter more(y/n)? y
Enter the reference string element 6: 2
Do you want to enter more(y/n)? y
Enter the reference string element 7: 5
Do you want to enter more(y/n)? y
Enter the reference string element 8: 1
Do you want to enter more(y/n)? y
Enter the reference string element 9: 2
Do you want to enter more(y/n)? y
Enter the reference string element 10: 3
Do you want to enter more(y/n)? y
Enter the reference string element 11: 4
Do you want to enter more(y/n)? y
Enter the reference string element 12: 5
Do you want to enter more(y/n)? n

Contents of queue are: 1	2	
Contents of queue are: 1	2	3	
Contents of queue are: 2	3	4	
Contents of queue are: 3	4	1	
Contents of queue are: 4	1	2	
Contents of queue are: 1	2	5	
Contents of queue are: 1	2	5	
Contents of queue are: 1	2	5	
Contents of queue are: 2	5	3	
Contents of queue are: 5	3	4	
Contents of queue are: 5	3	4	

Total number of faults are: 9

----------MENU----------
1.First In First Out.
2.Last Rcently Used.
3.Exit.

Enter the choice: 1
Enter the total no. of frames: 4
Enter the reference string element 1: 1
Do you want to enter more(y/n)? y
Enter the reference string element 2: 2
Do you want to enter more(y/n)? y
Enter the reference string element 3: 3
Do you want to enter more(y/n)? y
Enter the reference string element 4: 4
Do you want to enter more(y/n)? y
Enter the reference string element 5: 1
Do you want to enter more(y/n)? y
Enter the reference string element 6: 2
Do you want to enter more(y/n)? y
Enter the reference string element 7: 5
Do you want to enter more(y/n)? y
Enter the reference string element 8: 1
Do you want to enter more(y/n)? y
Enter the reference string element 9: 2
Do you want to enter more(y/n)? y
Enter the reference string element 10: 3
Do you want to enter more(y/n)? y
Enter the reference string element 11: 4
Do you want to enter more(y/n)? y
Enter the reference string element 12: 5
Do you want to enter more(y/n)? n

Contents of queue are: 1	2	
Contents of queue are: 1	2	3	
Contents of queue are: 1	2	3	4	
Contents of queue are: 1	2	3	4	
Contents of queue are: 1	2	3	4	
Contents of queue are: 2	3	4	5	
Contents of queue are: 3	4	5	1	
Contents of queue are: 4	5	1	2	
Contents of queue are: 5	1	2	3	
Contents of queue are: 1	2	3	4	
Contents of queue are: 2	3	4	5	

Total number of faults are: 10

----------MENU----------
1.First In First Out.
2.Last Rcently Used.
3.Exit.

Enter the choice: 1
Enter the total no. of frames: 3
Enter the reference string element 1: 2
Do you want to enter more(y/n)? y
Enter the reference string element 2: 3
Do you want to enter more(y/n)? y
Enter the reference string element 3: 2
Do you want to enter more(y/n)? y
Enter the reference string element 4: 1
Do you want to enter more(y/n)? y
Enter the reference string element 5: 5
Do you want to enter more(y/n)? y
Enter the reference string element 6: 2
Do you want to enter more(y/n)? y
Enter the reference string element 7: 4
Do you want to enter more(y/n)? y
Enter the reference string element 8: 5
Do you want to enter more(y/n)? y
Enter the reference string element 9: 3
Do you want to enter more(y/n)? y
Enter the reference string element 10: 2
Do you want to enter more(y/n)? y
Enter the reference string element 11: 5
Do you want to enter more(y/n)? y
Enter the reference string element 12: 2
Do you want to enter more(y/n)? n

Contents of queue are: 2	3	
Contents of queue are: 2	3	
Contents of queue are: 2	3	1	
Contents of queue are: 3	1	5	
Contents of queue are: 1	5	2	
Contents of queue are: 5	2	4	
Contents of queue are: 5	2	4	
Contents of queue are: 2	4	3	
Contents of queue are: 2	4	3	
Contents of queue are: 4	3	5	
Contents of queue are: 3	5	2	

Total number of faults are: 9

----------MENU----------
1.First In First Out.
2.Last Rcently Used.
3.Exit.

Enter the choice: 2
Enter the total no. of frames: 3
Enter the reference string element 1: 2
Do you want to enter more(y/n)? y
Enter the reference string element 2: 3
Do you want to enter more(y/n)? y
Enter the reference string element 3: 2
Do you want to enter more(y/n)? y
Enter the reference string element 4: 1
Do you want to enter more(y/n)? y
Enter the reference string element 5: 5
Do you want to enter more(y/n)? y
Enter the reference string element 6: 2
Do you want to enter more(y/n)? y
Enter the reference string element 7: 4
Do you want to enter more(y/n)? y
Enter the reference string element 8: 5
Do you want to enter more(y/n)? y
Enter the reference string element 9: 3
Do you want to enter more(y/n)? y
Enter the reference string element 10: 2
Do you want to enter more(y/n)? y
Enter the reference string element 11: 5
Do you want to enter more(y/n)? y
Enter the reference string element 12: 2
Do you want to enter more(y/n)? n

Contents of queue are: 2	3	
Contents of queue are: 3	2	
Contents of queue are: 3	2	1	
Contents of queue are: 2	1	5	
Contents of queue are: 1	5	2	
Contents of queue are: 5	2	4	
Contents of queue are: 2	4	5	
Contents of queue are: 4	5	3	
Contents of queue are: 5	3	2	
Contents of queue are: 3	2	5	
Contents of queue are: 3	5	2	

Total number of faults are: 7

----------MENU----------
1.First In First Out.
2.Last Rcently Used.
3.Exit.

Enter the choice: 3
*/
