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
  int level=0,src=0;
  string psf="";
  Pair(int src,int level,string psf)
  {
      this->src=src;
      this->level=level;
      this->psf=psf;
  }
};
bool checkcompbip(vector<vector<Edge>>graph,int src,vector<int>&vis)
{
    queue<Pair>q;
    q.push(Pair(src,0,to_string(src)+""));
    while(q.size()!=0)
    {
        Pair rem=q.front();
        q.pop();
        if(vis[rem.src]!=-1)
        {
            if(rem.level!=vis[rem.src])
            {
              return false;  
            }
        }
        else
        {
            vis[rem.src]=rem.level;
        }
        for(Edge e: graph[rem.src])
        {
            if(vis[e.nbr]==-1)
            {
                q.push(Pair(e.nbr,rem.level+1,rem.psf+to_string(e.nbr)));
            }
        }
    }
    return true;
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
  vector<int>vis(vtces,-1);
  for(int i=0;i<vtces;i++)
  {
      if(vis[i]==-1)
      {
        bool ans=checkcompbip(graph,i,vis);
        if(ans==false)
        {
        cout<<"false";
        return 0;
        }

      }
  }
  cout<<"true";
  return 0;
}
