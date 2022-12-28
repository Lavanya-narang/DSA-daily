#include <iostream>
#include <vector>
#include <queue>
#include<string>
using namespace std;

class Edge
{
public:
  int src = 0;
  int nbr = 0;

  Edge(int src, int nbr)
  {
    this->src = src;
    this->nbr = nbr;
  }
};
class Pair
{
    public:
        int src=0;
        string psf="";
        Pair(int src,string psf)
        {
            this->src=src;
            this->psf=psf;
        }
};
bool iscycle(vector<vector<Edge>>graph,int src,vector<bool>&vis)
{
    queue<Pair>q;
    q.push(Pair(src,to_string(src)+""));
    while(q.size()!=0)
    {
        Pair rem=q.front();
        q.pop();
        if(vis[rem.src]==true)
        {
            return true;
        }
        vis[rem.src]=true;
        for(Edge e:graph[rem.src])
        {
            if(vis[e.nbr]==false)
            {
                q.push(Pair(e.nbr,rem.psf+to_string(e.nbr)));
            }
        }
    }
    return false;
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

    graph[u].push_back(Edge(u, v));
    graph[v].push_back(Edge(v, u));

  }

// write your code here
vector<bool>vis(vtces,false);
for(int v=0;v<vtces;v++)
{
    if(vis[v]==false)
    {
        bool cycle=iscycle(graph,v,vis);
        if(cycle==true)
        {
            cout<<"true"<<endl;
             return 0;
        }
    }
    
}
cout<<"false"<<endl;
  return 0;
}
