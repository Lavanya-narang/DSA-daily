
class Solution {
 public:
//     vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
//         //tc:o(nlogn)+o(mlogn) m=no of queries
//         sort(nums.begin(),nums.end());
//         vector<int>ans;
//         vector<int>pre(nums.size(),0);
//         pre[0]=nums[0];
//         for(int i=1;i<nums.size();i++)
//         {
//             pre[i]=nums[i]+pre[i-1];
//         }
//         for(int i=0;i<queries.size();i++)
//         {
//             int query=queries[i];
//             ans.push_back(upper_bound(pre.begin(),pre.end(),query)-pre.begin());//where the element u are seraching would be
//         }
//         return ans;
//     }
// };


int binary(vector<int> &n, int target)
{
    int s = 0, e = n.size() - 1, m;
	
    while (s <= e)
    {
        m = s + (e-s)/2;
        if (n[m] > target)
            e = m - 1;  //it'll point to the required element eventually in case target
							  // is not present in nums.
        else if (n[m] < target)
			s = m + 1;   //s will pass the required element if(target <   n[m]);
				
        else             // if (target == n[m])
            return m + 1;
    }
    return 
       e+1;
}
vector<int> answerQueries(vector<int>& n, vector<int>& q) 
{
    int a = n.size(), b = q.size();
    sort(n.begin(), n.end());
    
    //prefix sum -> 
    for (int i = 1; i < a; i++)
        n[i] += n[i-1];
    
   //binary search 
    for (int i = 0; i < b; i++)
    {
        q[i] = binary(n, q[i]);
    }
    return q;
}
 };
