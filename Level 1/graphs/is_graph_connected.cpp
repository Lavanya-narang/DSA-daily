#include<bits/stdc++.h>
using namespace std;
class Edge {
public:
  int src;
  int nbr;
  int wt;

  Edge(int src, int nbr, int wt) {
    this->src = src;
    this->nbr = nbr;
    this->wt = wt;
  }
};
void dfs(vector<Edge>graph[],int src,vector<bool>& visited)
{
        visited[src]=true;
        for(Edge edge: graph[src])
        {
            if(visited[edge.nbr]==true)
            {
                continue;
            }
            dfs(graph,edge.nbr,visited);
        }
}
int main() {
  int vtces;
  cin >> vtces;
  vector<Edge>graph[vtces];

  int edges;
  cin >> edges;
  for (int i = 0; i < edges; i++) {
    int v1 ;
    int v2 ;
    int wt ;
    cin >> v1 >> v2 >> wt;
    graph[v1].push_back( Edge(v1, v2, wt));
    graph[v2].push_back( Edge(v2, v1, wt));
  }

  int src;
  cin >> src;
  int dest;
  cin >> dest;
  // write your code here
  vector<bool>visited(vtces,false);
  dfs(graph,0,visited);
  for(int v=0;v<vtces;v++)
  {
      if(visited[v]==false)
      {
        vector<int>comp;
        cout<<"false";
        return 0;
      }
  }
    cout<<"true";
}
