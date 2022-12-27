#include<bits/stdc++.h>

using namespace std;

class Edge {
public:
  int src = 0;
  int nbr = 0;
  int wt = 0;

  Edge(int src, int nbr, int wt) {
    this->src = src;
    this->nbr = nbr;
    this->wt  = wt;
  }
};
int searchvertex(vector<vector<Edge>> graph,int u,int v)
{
    int index=-1;
    for(int i=0;i<graph[u].size();i++)
    {
        Edge e=graph[u][i];
        if(e.nbr==v)
        {
            index=i;
            break;
        }
    }
    return index;
}
void hamiltonianpath(vector<vector<Edge>> graph,int src,int osrc,int noedge,vector<bool>&vis,string path)
{
    if(noedge==graph.size()-1)
    {
        int index=searchvertex(graph,src,osrc);
        path+=to_string(src);
        if(index!=-1)
        {
            cout<<path<<"* "<<endl;
        }
        else
        {
            cout<<path<<". "<<endl;
        }
    }
    vis[src]=true;
    for(Edge edge:graph[src])
    {
        if(vis[edge.nbr]==false)
        {
           hamiltonianpath(graph,edge.nbr,osrc,noedge+1,vis,path+to_string(src)); 
        }
    }
    vis[src]=false;
}

int main() {
  int vtces;
  cin >> vtces;
  vector<vector<Edge>> graph(vtces, vector<Edge>());


  int edges;
  cin >> edges;

  for (int i = 0; i < edges; i++ ) {
    int u, v, w;
    cin >> u >> v >> w;

    graph[u].push_back(Edge(u, v, w));
    graph[v].push_back(Edge(v, u, w));

  }
  int src;
  cin >> src;

  // write your codes here
  vector<bool>vis(vtces,false);
  hamiltonianpath(graph,src,src,0,vis,"");
  return 0;
}
