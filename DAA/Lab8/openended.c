#include <stdbool.h>
#include <stdio.h>
int graph[][6]={{0,1,1,1,0,0},
                {0,0,0,0,0,0},
                {0,0,0,0,1,1},
                {0,0,0,0,0,0},
                {0,0,0,0,0,0},
                {0,0,0,0,0,0}};
/*
int graph[][6] = {{0,1,1},
                  {0,0,1},
                  {0,0,0}
                };
*/
void DFS(int v, bool visited[]);


void dfs(int v)
{
  bool visited[6];
  for(int i = 0; i < v; i++)
  {
    visited[i] = false;
  }
  DFS(v,visited);
}

void DFS(int v, bool visited[])
{
  visited[v] = true;

  for(int i = 0; i < 6; i++)
  {
    if(!visited[i] && graph[v][i])
      DFS(i,visited);

  }
  printf("%d\n",v);
}

int main()
{
  dfs(0);
}
