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

  int src;
  cin >> src;
  // write your code here
vector<bool>vis(vtces,false);
queue<Pair>q;
q.push(Pair(src,to_string(src)+""));
while(q.size()!=0)
{
    Pair rem=q.front();
    q.pop();
    if(vis[rem.src]==true)
    {
        continue;
    }
    vis[rem.src]=true;
    cout<<rem.src<<"@"<<rem.psf<<endl;
    for(Edge edge:graph[rem.src])
    {
        if(vis[edge.nbr]==false)
        {
            q.push(Pair(edge.nbr,rem.psf+to_string(edge.nbr)));
        }
    }
}
  return 0;
}
