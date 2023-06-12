// class Solution {
// public:
//     vector<string> summaryRanges(vector<int>& nums) {
//         vector<string>ret;
//         int n=nums.size();
//         for (int i=0; i<nums.size(); i++) 
//         {
//             int pre = nums[i];
//             while (i+1<nums.size() && nums[i+1]==nums[i]+1)  
//              i++;
//             if (pre == nums[i])
//                 ret.push_back(to_string(pre));
//             else
//                 ret.push_back(to_string(pre)+"->"+to_string(nums[i]));
//         }
//         return ret;
//     }
// };


 class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;
        string temp="";
        int n=nums.size();

        for(int i=0;i<nums.size();i++)
        {
            int j=i;

            while(j+1<n && nums[j+1]==nums[j]+1)
            {
                j++;
            }

            if(j>i)
            {
                temp+=to_string(nums[i]);
                temp+="->";
                temp+=to_string(nums[j]);
            }
            else{
                temp+=to_string(nums[i]);
            }

            ranges.push_back(temp);
            temp="";
            i=j;
        }
        return ranges;


    }
};
