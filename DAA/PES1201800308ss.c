int searchFirstOccurrence(int arr[], int n, int key)
{
  for(int i=0;i<n;i++)
  {
    if(key==arr[i])
    {
      return i;
    }
  }
  return -1;
}

int searchLastOccurrence(int arr[], int n, int key)
{
  for(int i=n-1;i>=0;i--)
  {
    if(arr[i]==key)
    {
      return i;
    }
  }
  return -1;
}

int numOccurrences(int arr[], int n, int key)
{
  int count=0;
  for(int i=0;i<n;i++)
  {
    if(key==arr[i])
    {
      count++;
    }
  }
  return count;
}
