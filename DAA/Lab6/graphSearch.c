#include<stdbool.h>
#include <math.h>
#include "graphSearch.h"

int max = 0;
int count = 0;

bool isCyclic(int u, bool visited[], int parent, int n, const int graph[][n])
{
  visited[u] = true;
  for(int v = 0; v<n; v++)
  {
    if(graph[u][v])
    {
      if(!visited[v])
      {
        if(isCyclic(v, visited, u, n, graph))
        {
               return true;
        }
      }
      else if(v != parent)
      {    //when adjacent vertex is visited but not parent
        return true;    //there is a cycle
      }
    }
  }
   return false;
}

bool isTree(int n, const int graph[][n])
{
  bool visited[n];
  for (int i = 0; i < n; i++)
    visited[i] = false;
  if (isCyclic(0, visited, -1, n, graph))
    return false;
  for (int i = 0; i < n; i++)
    if (!visited[i])
      return false;

return true;
}

void DFS(int v, bool visited[], int n, const int graph[][n])
{
  count++;
  visited[v] = true;
  for(int i = 0; i<n; i++)
  {
    if(graph[v][i] && !visited[i])
    {
      DFS(i, visited, n, graph);
    }
  }
}

void DFSWithK(int v, bool visited[], int n, const int graph[][n], int k)
{
  count++;
  visited[v] = true;
  for(int i = 0; i<n; i++)
  {
    if(graph[v][i] && !visited[i] && fabs(v-i) <= k)
    {
      DFS(i, visited, n, graph);
    }
  }
}

Result pepesAnswers(int n, const int safeSeq[][n])
{
  bool visited[n];
  int comp = 0;
  for(int v = 0; v < n; v++)
  {
    visited[v] = false;
  }
  for(int v = 0; v < n; v++)
  {
    if(visited[v] == false)
    {
      count = 0;
      DFS(v, visited, n, safeSeq);
      comp += 1;
      if(count > max)
        max = count;
    }
  }

  Result res;
  res.numDeliveryFrogs = comp;
  res.maxHouses = max;
  return res;

}



Result pepesAnswersWithK(int n, const int safeSeq[][n], int k)
{
  bool visited[n];
  int comp = 0;
  for(int v = 0; v < n; v++)
  {
    visited[v] = false;
  }
  for(int v = 0; v < n; v++)
  {
    if(visited[v] == false)
    {
      count = 0;
      DFSWithK(v, visited, n, safeSeq,k);
      comp += 1;
      if(count > max)
        max = count;
    }
  }

  Result res;
  res.numDeliveryFrogs = comp;
  res.maxHouses = max;
  return res;

}
