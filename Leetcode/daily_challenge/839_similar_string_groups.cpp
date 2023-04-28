class DSU
{
public:
vector<int>rank;
vector<int>parent;
DSU(int n)
{
    rank.resize(n);
    parent.resize(n);
    for(int i=0;i<n;i++)
    {
        rank[i]=0;
        parent[i]=i;
    }
}
int findparent(int x)
{
    if(x==parent[x])
    {
        return x;
    }
    return parent[x]=findparent(parent[x]);
}
void makeunion(int x,int y)
{
    int p1=findparent(x),p2=findparent(y);
    if(p1!=p2)
    {
        if(rank[p1]>rank[p2])
        {
            parent[p2]=p1;
            rank[p1]+=rank[p2];
        }
        else
        {
            parent[p1]=p2;
            rank[p2]+=rank[p1];
        }
    }
}
};
class Solution {
public:
    int numSimilarGroups(vector<string>& strs) 
    {
        int n=strs.size();
        DSU dsu(n);
        int count=n;
        for(int i=0;i<strs.size();i++)
        {
            for(int j=i+1;j<strs.size();j++)
            {
                int posmatch=0;
                for(int k=0;k<strs[i].size();k++)
                {
                    if(strs[j][k]!=strs[i][k])
                    {
                        posmatch++;
                    }
                }
                if(posmatch==0 || posmatch==2)
                {
                    if(dsu.findparent(i)!=dsu.findparent(j))
                    {
                        count--;
                        dsu.makeunion(i,j);
                    }
                }
            }
        }
        return count;
    }
};
