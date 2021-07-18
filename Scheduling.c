/*
Name: Chirantan Joshi.
Div: G
Batch: G1
Roll No.: PG13
CPU SCHEDULING
*/
#include <stdio.h>
#include <stdlib.h>
struct process
{
	int at,bt,wt,tat,rt;
};
void fcfs(struct process p[10])
{
	struct process k;
	float wt=0,tat=0,avg_wt,avg_tat;
	int i,j,n,curr_time;
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter arrival time for process %d: ",i);
		scanf("%d",&p[i].at);
		printf("Enter burst time for process %d: ",i);
		scanf("%d",&p[i].bt);
		for(j=0;j<i;j++)
		{
			if(p[i].at < p[j].at)
			{
				k=p[i];
				p[i]=p[j];
				p[j]=k;
			}
		}
	}
	curr_time=p[0].at;
	for(i=0;i<n;i++)
	{
		curr_time+=p[i].bt;
		p[i].tat=curr_time-p[i].at;
		p[i].wt=p[i].tat-p[i].bt;
		wt+=p[i].wt;
		tat+=p[i].tat;
		if(i < n-1 && curr_time < p[i+1].at)
			curr_time=p[i+1].at;
	}
	printf("\nProcess\tAT\tBT\tWT\tTAT\n");
	for(i=0;i<n;i++)
	{
		printf("\nP%d\t%d\t%d\t%d\t%d",i,p[i].at,p[i].bt,p[i].wt,p[i].tat);
	}
	avg_tat=tat/n;
	avg_wt=wt/n;
	printf("\nAverage waiting time = %.2f\n",avg_wt);
	printf("Average turn around time = %.2f\n",avg_tat);
}
void sjf(struct process p[10])
{
	struct process k;
	float avg_wt,avg_tat,wt=0,tat=0;
	int i,j,n,curr_time,cnt=0,m=0,flag=0,cnt1=0,cnt2=0,min;
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter arrival time for process %d: ",i);
		scanf("%d",&p[i].at);
		printf("Enter burst time for process %d: ",i);
		scanf("%d",&p[i].bt);
		p[i].rt=p[i].bt;
		for(j=0;j<i;j++)
		{
			if(p[i].at < p[j].at)
			{
				k=p[i];
				p[i]=p[j];
				p[j]=k;
			}
		}
	}
	curr_time=p[0].at;
	while(cnt1 < n)
	{
		if(flag==1)
			printf("Processor is idle.\n");
		else
			printf("Process in execution is P%d\n",cnt);
		curr_time++;
		p[cnt].rt--;
		if(p[cnt].rt==0)
		{
			p[cnt].tat=curr_time-p[cnt].at;
			p[cnt].wt=p[cnt].tat-p[cnt].bt;
			wt+=p[cnt].wt;
			tat+=p[cnt].tat;
		}
		flag=0;
		cnt2=0;
		min=10;
		if(curr_time==p[m+1].at)
			m++;
		for(j=0;j<=m;j++)
		{
			if(p[j].rt < min && p[j].rt > 0)
			{
				min=p[j].rt;
				cnt=j;
			}
			else if(p[j].rt <= 0)
				cnt2++;
			
		}
		if(cnt2 == (m+1))
			flag=1;
		cnt1=0;
		for(i=0;i<n;i++)
		{
			if(p[i].rt<=0)
				cnt1++;
			else
				break;
		}
	}
	printf("\nProcess\tAT\tBT\tWT\tTAT\n");
	for(i=0;i<n;i++)
	{
		printf("\nP%d\t%d\t%d\t%d\t%d",i,p[i].at,p[i].bt,p[i].wt,p[i].tat);
	}
	avg_tat=tat/n;
	avg_wt=wt/n;
	printf("\nAverage waiting time = %.2f\n",avg_wt);
	printf("Average turn around time = %.2f\n",avg_tat);
}
int main()
{
	struct process p[10];
	int choice;
	while(1)
	{
		printf("\n----------MENU----------\n1.First Come First Serve.\n2.Shortest Job First.\n3.Exit.\n\nEnter the choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	fcfs(p);
			break;
			case 2:	sjf(p);
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
1.First Come First Serve.
2.Shortest Job First.
3.Exit.

Enter the choice: 1
Enter the number of processes: 5
Enter arrival time for process 0: 0
Enter burst time for process 0: 3
Enter arrival time for process 1: 1
Enter burst time for process 1: 1
Enter arrival time for process 2: 2
Enter burst time for process 2: 2
Enter arrival time for process 3: 7
Enter burst time for process 3: 4
Enter arrival time for process 4: 8
Enter burst time for process 4: 2

Process	AT	BT	WT	TAT

P0	0	3	0	3
P1	1	1	2	3
P2	2	2	2	4
P3	7	4	0	4
P4	8	2	3	5
Average waiting time = 1.40
Average turn around time = 3.80

----------MENU----------
1.First Come First Serve.
2.Shortest Job First.
3.Exit.

Enter the choice: 2
Enter the number of processes: 5
Enter arrival time for process 0: 0
Enter burst time for process 0: 3
Enter arrival time for process 1: 1
Enter burst time for process 1: 1
Enter arrival time for process 2: 2
Enter burst time for process 2: 2
Enter arrival time for process 3: 7
Enter burst time for process 3: 4
Enter arrival time for process 4: 8
Enter burst time for process 4: 2
Process in execution is P0
Process in execution is P1
Process in execution is P0
Process in execution is P0
Process in execution is P2
Process in execution is P2
Processor is idle.
Process in execution is P3
Process in execution is P4
Process in execution is P4
Process in execution is P3
Process in execution is P3
Process in execution is P3

Process	AT	BT	WT	TAT

P0	0	3	1	4
P1	1	1	0	1
P2	2	2	2	4
P3	7	4	2	6
P4	8	2	0	2
Average waiting time = 1.00
Average turn around time = 3.40

----------MENU----------
1.First Come First Serve.
2.Shortest Job First.
3.Exit.

Enter the choice: 3
*/
