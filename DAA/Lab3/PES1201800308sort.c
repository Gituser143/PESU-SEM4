#include<stdio.h>
int isSorted(int *a, int n)
{
  for(int i = 0; i < n-1 ; i++)
  {
    if(a[i] > a[i+1])
      return 0;
  }
  return 1;
}

void bubblePass(int *a, int n)
{
  for(int j = 0; j < n-1; j++)
  {
    if(a[j]>a[j+1])
    {
      int temp = a[j+1];
      a[j+1] = a[j];
      a[j] = temp;
    }
  }
}

void bubbleSort(int *a, int n)
{
  for(int i = 0; i < n; i++)
  {
    bubblePass(a,n-i);
  }
}

int numBubblePasses(int *a, int n)
{
  int count = 0;
  for(int i = 0; i < n && !isSorted(a,n); i++)
  {
    bubblePass(a,n-i);
    count++;
  }
  return count;
}

int maxIndex(int *a, int n)
{
  int max = a[0];
  int index = 0;
  for(int i = 0; i < n; i++)
  {
    if(max<=a[i])
    {
      index = i;
      max = a[i];
    }
  }
  return index;
}

void swapWithMax(int *a, int n)
{
  int i = maxIndex(a,n);
  if(i<n-1)
  {
    int temp = a[i];
    a[i] = a[n-1];
    a[n-1] = temp;
  }
}

void selectionSort(int *a, int n)
{
  for(int i = 0; i < n; i++)
  {
    swapWithMax(a,n-i);
  }
}

int numSwaps(int *a, int n)
{
  int count = 0;
  for(int i = 0; i < n && !isSorted(a,n-i); i++)
  {
      if(maxIndex(a,n-i) != n-i-1)
      {
        swapWithMax(a,n-i);
        count++;
      }
  }
  return count;
}
