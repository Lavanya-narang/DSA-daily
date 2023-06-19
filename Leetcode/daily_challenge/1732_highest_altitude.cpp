// class Solution {
// public:
//     int largestAltitude(vector<int>& gain) 
//     {
//         int mx=0,curr=0;
//        for(int i=0;i<gain.size();i++)
//        {
//            curr+=gain[i];
//            mx=max(curr,mx);
//        }
//        return mx;
//     }
// };


// class Solution {
// public:
//     int largestAltitude(vector<int>& gain) 
//     {
//         vector<int> altitudes;
//         int sum=0;
//         for(int i=0; i<gain.size(); i++)
//         {
//           altitudes.push_back(sum);
//           sum=sum+gain[i];
//         }
//         altitudes.push_back(sum);
//         return *max_element(altitudes.begin(),altitudes.end());
//     }
// };


class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans =0, tmp=0;

        for (int i = 0; i < gain.size(); i++)
        {
          if(i!=0){
            gain[i] += gain[i-1];
          }
          ans = max(ans, gain[i]);
        }
        return ans;
    }
};
