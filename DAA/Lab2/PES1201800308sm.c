#include<string.h>
#include <stdio.h>
int searchFirstOccurrence(char *pattern, char *text)
{
  int m = strlen(pattern);
  int n = strlen(text);
  for(int i = 0; i <= n - m;i++)
  {
    int j;
    for(j = 0; j < m; j++)
    {
      if(text[i+j] != pattern[j])
      {
        break;
      }
    }
    if(j==m)
    {
      return i;
    }
  }
  return -1;
}

int searchLastOccurrence(char *pattern, char *text)
{

  int m = strlen(pattern);
  int n = strlen(text);
  for(int i = n - m ; i >= 0;i--)
  {
    int j;
    for( j = 0; j < m; j++)
    {
      if(text[i+j] != pattern[j])
      {
        break;
      }
    }
    if(j==m)
    {
      return i;
    }
  }
  return -1;
}

int numOccurrences(char *pattern, char *text)
{
  int count = 0;
  int m = strlen(pattern);
  char *temp = text;
  while(strlen(temp) > 1)
  {
    int i = searchFirstOccurrence(pattern, temp);
    if(i == -1)
    {
      break;
    }
    i+=m;
    temp+=i;
    count++;
  }
  return count;

}


int longestPrefix(char *pattern, char *text)
{
    int n = strlen(text);
    int m = strlen(pattern);
    int max = 0;
    for(int i = 0; i < n - m; i++)
    {
        int count = 0;
        for(int j = 0; j < m; j++)
        {
            if(text[i+j] != pattern[j])
            {
                break;
            }
            count++;
        }
        if(count > max)
        {
            max = count;
        }
    }
    return max;
}

int charactersCompared(char *pattern, char *text)
{
    int n = strlen(text);
    int m = strlen(pattern);
    int count = 0;
    for(int i = 0; i <= n - m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            count++;
            if(text[i+j] != pattern[j])
            {
                break;
            }
        }
    }
    return count;
}
