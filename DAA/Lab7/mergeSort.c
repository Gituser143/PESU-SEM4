#include<stdlib.h>
#include"mergeSort.h"
void mergeSortedHalfs(int *a, int start, int mid, int end)
{
  int i = 0, j = 0, k = 0;
  int m = mid - start;
  while(i <= m && j <= m)
  {
    if(a[i] < a[m+j])
      a[k++] = a[i++];
    else
      a[k++] = a[m+(j++)];
  }

  while(i <= m)
  {
    a[k++] = a[i++];
  }

  while(j <= m)
  {
    a[k++] = a[m+(j++)];
  }
}

void mergeSort(int *a, int start, int end)
{
  if(start < end)
  {
    int mid = (start + end)/2;
    mergeSort(a, start, mid);
    mergeSort(a, mid+1, end);
    mergeSortedHalfs(a, start, mid, end);
  }
  return;
}

void insertionSort(int *a, int start, int end)
{
  int i, key, j;
  int n = end - start + 1;
  for (i = 1; i < n; i++)
  {
    key = a[i];
    j = i - 1;
    while (j >= 0 && a[j] > key)
    {
      a[j + 1] = a[j];
      j = j - 1;
    }
    a[j + 1] = key;
  }
}

void selectiveMergeSort(int *a, int start, int end, int parameter)
{
  int n = end - start + 1;
  if(parameter > n)
  {
    insertionSort(a, start, end);
  }
  else
  {
    mergeSort(a, start, end);
  }
}
