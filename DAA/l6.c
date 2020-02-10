#include "graphSearch.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void dfs(int a,int *visited,int n,const int graph[][n],int parent,int *houses,int k){
    ++visited[a];
    (*houses)++;
    for(int i=0;i<n;++i)
    {
        if(abs(a - i) <= k)
        {
            if(graph[a][i] && i!=parent)
            {
                if(visited[i])
                    ++visited[i];
                else
                    dfs(i,visited,n,graph,a,houses,k);
            }
        }
    }
}

bool isTree(int n, const int graph[][n]){
    int *visited = (int *)calloc(n,sizeof(int));
    int houses = 0;
    dfs(0,visited,n,graph,-1,&houses,n);
    for(int i = 0; i < n; ++i){
        if(visited[i]!=1){
            free(visited);
            return false;
        }
    }
    free(visited);
    return true;
}

Result pepesAnswers(int n, const int safeSeq[][n]){
    pepesAnswersWithK(n,safeSeq,n);
}

Result pepesAnswersWithK(int n, const int safeSeq[][n], int k){
    Result r;
    r.numDeliveryFrogs = 0;
    r.maxHouses = 0;
    int houses = 0;
    int *visited = (int *)calloc(n,sizeof(int));
    for(int i = 0; i < n; ++i){
        if(!visited[i]){
            houses = 0;
            dfs(i,visited,n,safeSeq,-1,&houses,k);
            r.numDeliveryFrogs++;

            if(houses > r.maxHouses)
                r.maxHouses = houses;
        }
    }
    free(visited);
    return r;
}
