class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) 
    {
       vector<int>ans(obstacles.size(),1),lis;
       for(int i=0;i<obstacles.size();i++)
       {
          int ind=upper_bound(lis.begin(),lis.end(),obstacles[i])-lis.begin();
          if(ind==lis.size())
          {
              lis.push_back(obstacles[i]);
          }
          else
          {
              lis[ind]=obstacles[i];
          }
          ans[i]=ind+1;
       }
       return ans; 
    }
};
