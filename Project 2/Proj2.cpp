
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
  

int V = 0;
int X_source = 0; int Y_sink = 0;
int soma2 = 0;
vector<vector<int>> edges;
vector<vector<int>> edges2;
vector<int> reachable;
  

int flagged_bfs(vector<int> paths,int flag)
{
    
    reachable = vector<int>(V,0);
    vector<int> queue;
    queue.push_back(X_source);
    reachable[X_source] = 1;
    paths[X_source] = -1;
    
    while (!queue.empty())
    {
        int u = queue[0];
        queue.erase(queue.begin());
  
        for (int i=0; i<V; i++)
        {
            if (reachable[i]==0 &&  edges2[u][i] > 0)
            {
                
                paths[i] = u;                  
                reachable[i] = 1;  
                queue.push_back(i);               
            }
        }
    }
    
    if (flag == 0){
    int path_flow = edges2[paths[Y_sink]][Y_sink];
        
        for (int v=Y_sink; v!=X_source; v=paths[v])
        {
            int u = paths[v];
            path_flow = min(path_flow,  edges2[u][v]);
            
        }
  
       
        for (int v=Y_sink; v != X_source; v=paths[v])
        {
            int u = paths[v];
           
            edges2[v][u] += path_flow;
            edges2[u][v] -= path_flow;
        }
    }
    
    return (reachable[Y_sink] == 1);
}
  

void cost()
{
                 
    vector<int> paths = vector<int>(V,0);  
  
    
    while (flagged_bfs(paths,0) == 1);
  
    
    
    flagged_bfs(paths,1);
    int final = 0;
    
    for (int i = 0; i < V; i++)
      for (int j = 0; j < V; j++) 
         if (reachable[i] && !reachable[j] && edges[i][j] > 0){
              final += edges[i][j];  
         }
    printf("%d\n",final);
}
  

int main()
{
    int p,ent;   

     if (scanf("%d %d", &p, &ent))
        ;
    V = p +2;
    Y_sink = V-1;
    int i = 0;
    edges = vector<vector<int>>(V, vector<int>(V,0));
    edges2 = vector<vector<int>>(V, vector<int>(V,0));
    while (i < p)
    {
        int x, y;
        if (scanf("%d %d", &x, &y))
        {
            i++;
            edges[0][i] = x;
            edges[i][0] = x;
            
            edges[V-1][i] = y;
            edges[i][V-1] = y;
            
            edges2[0][i] = x;
            edges2[i][0] = x;
            
            edges2[V-1][i] = y;
            edges2[i][V-1] = y;
            
        }
    }
    i = 0;
    while (i < ent)
    {
        int a, b,c;
        if (scanf("%d %d %d", &a, &b, &c))
        {
            i++;
            edges[a][b] = c;
            edges[b][a] = c;
            edges2[a][b] = c;
            edges2[b][a] = c;
            
        }
    }
    cost();
    
    
    return 0;
}