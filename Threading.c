/*
Name: Chirantan Joshi.
Div: G
Batch: G1
Roll No.: PG13
ADDITION BY THREADING
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct num
{
	int num1;
	int num2;
}num;
void *add(void *arg);
void *sub(void *argp);
void *mul(void *argc);
void *division(void *argd);
int main()
{
	pthread_t tid1,tid2,tid3,tid4;
	int n1,n2;
	num n;
	printf("Enter the first number: ");
	scanf("%d",&n1);
	printf("Enter the second number: ");
	scanf("%d",&n2);
	n.num1=n1;
	n.num2=n2;
	pthread_create(&tid1,NULL,add,(void*)&n);
	pthread_create(&tid2,NULL,sub,(void*)&n);
	pthread_create(&tid3,NULL,mul,(void*)&n);
	pthread_create(&tid4,NULL,division,(void*)&n);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	pthread_join(tid3,NULL);
	pthread_join(tid4,NULL);
	return 0;
}
void *add(void *arg)
{
	num *add=(num*)arg;
	int sum=0;
	sum=add->num1 + add->num2;
	printf("\nThe sum is: %d\n",sum);
	return NULL;
}
void *sub(void *argp)
{
	num *sub=(num*)argp;
	int subt=0;
	subt=sub->num1 - sub->num2;
	printf("\nThe subtraction is: %d\n",subt);
	return NULL;
}
void *mul(void *argc)
{
	num *mul=(num*)argc;
	int mult=0;
	mult=mul->num1 * mul->num2;
	printf("\nThe multiplication is: %d\n",mult);
	return NULL;
}
void *division(void *argd)
{
	num *div=(num*)argd;
	int divi=0;
	divi=div->num1 / div->num2;
	printf("\nThe division is: %d\n",divi);
	return NULL;
}

/*
OUTPUT:
Enter the first number: 9
Enter the second number: 3

The sum is: 12

The subtraction is: 6

The division is: 3

The multiplication is: 27
*/
