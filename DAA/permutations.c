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
int mobile(int *A,int *arr,int n)
{
	int k;
	int pos=-1;
	int max=0;
	for(int i=0;i<n;i++)
	{
		if(!arr[i])
			k=i-1;
		else
			k=i+1;
		if(k==n)
			return pos;
		if(k==-1)
			continue;
		if(A[k]<A[i] && max<A[i])
			{
			pos=i;
			max=A[i];
			}
	}
	return pos;
}
void reverse(int *A,int *arr,int x,int n)
{
	for(int i=0;i<n;i++)
	{
		if(A[i]>x)
		{
			arr[i]=arr[i]^1;
		}
	} 
}
void Permutation(int n)
{
	int k,swap,x;
	int *A=(int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
		A[i]=i+1;
	int *arr=(int*)calloc(n,sizeof(int));
	for(int i=0;i<n;i++)
			printf("%d ",A[i]);
	printf("\n");
	k=mobile(A,arr,n);
	while(k!=-1)
	{
		if(arr[k]==0)
			x=k-1;
		else
			x=k+1;
		swap=A[k];
		A[k]=A[x];
		A[x]=swap;
		swap=arr[k];
		arr[k]=arr[x];
		arr[x]=swap;
		reverse(A,arr,A[x],n);
		for(int i=0;i<n;i++)
			printf("%d ",A[i]);
		printf("\n");
		k=mobile(A,arr,n);
	}
}
void main()
{
	struct timespec start, end; //timestamps
	int n;
	printf("Enter the length of permutation:");
	scanf("%d",&n);

    clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
    Permutation(n);
    clock_gettime(CLOCK_REALTIME, &end); //End timestamp
    printf("Time for calculating permutations : %lf\n",time_elapsed(start, end));
}
