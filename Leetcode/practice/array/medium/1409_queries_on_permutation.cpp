class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) 
    {
       vector<int>per;
       vector<int>ans;
       for(int i=1;i<=m;i++)
       {
           per.push_back(i);
       } 
       for(int i=0;i<queries.size();i++)
       {
           for(int j=0;j<per.size();j++)
           {
                if(queries[i]==per[j])
                {
                    ans.push_back(j);
                   per.erase(per.begin()+j);
                    per.insert(per.begin()+0, queries[i]);
                    break;
                }
           }
       }
       return ans;
    }
};
