class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) 
    {
        int m=points.size();
        int n=queries.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<m;j++)
            {
                if(pow(points[j][0]-queries[i][0],2)+pow(points[j][1]-queries[i][1],2)<=pow(queries[i][2],2))
                {
                    cnt++;
                }  
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
