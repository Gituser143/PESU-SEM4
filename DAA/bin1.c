#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

double time_elapsed(struct timespec start, struct timespec end)
{
    double t;
    t = (end.tv_sec - start.tv_sec);                  //diff of tv_sec
    t += (end.tv_nsec - start.tv_nsec) * 0.000000001; //add diff of tv_nsec too
    return t;
}
int bin(int i,int n)
{
	for (int j=n-1;j>=0;j--) {
		if (i & 1<<j)
			putchar('1');
		else
			putchar('0');
	}
	putchar('\n');
}
int * add(int* a,int n)
{
	int i=1;
	int x=1;
	while(i<=n && a[n-i]==0)
	{
		if(a[n-i]==1)
			a[n-i]=0;
		i++;
	}
	a[n-i]=1;
	return a;
}
void bitstrings(int n)
{
	int p=1<<(n);
	//int *a=(int*)calloc(n,sizeof(int));
	for(int i=0;i<p;i++)
	{
		bin(i,n);
		//for(int k=0;k<n;k++)
			//printf("%d ",a[i]);
		//printf("\n");
		//a=add(a,n);
	}
}
void main()
{
	int n;
	struct timespec start, end; //timestamps
	printf("Enter the length of bit string:");
	scanf("%d",&n);
    clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
    bitstrings(n);
    clock_gettime(CLOCK_REALTIME, &end); //End timestamp
    printf("Time for calculating bit strings : %lf\n",time_elapsed(start, end));
}
