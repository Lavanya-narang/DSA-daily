// class Solution {
// public:
//     bool helper(vector<int> &v,int m,int p) {
//         int cnt = 0,mx = 0;
//         for(int i = 1; i < v.size(); i += 1) {
//             if(v[i] - v[i - 1] <= m) {
//                 i += 1;
//                 cnt += 1;
//             }
//         }
//         return cnt >= p;
//     }
    
//     int minimizeMax(vector<int>& v, int p) {
//         sort(v.begin(),v.end());
//         int l = 0,r = v.back(), ans = -1;
//         //0,6 --> m = 3
//         while(r >= l) {
//             int m = (l + r)/2;
//             // cout<<"m : "<<m<<endl;
//             if(helper(v,m,p)) {
//                 ans = m;
//                 r = m - 1;
//             } else l = m + 1;
//         }
//         return ans;
//     }
// };



class Solution {
public:

    bool ispos(vector<int>nums,int diff,int pairs){
        int i = 1;
        int n = nums.size();
        int k = 0;

        for(i;i<n && k<pairs;i++){
            if(nums[i]-nums[i-1]<=diff){
                k++;
                i++;
            }
        }

        if(k>=pairs){
            return true;
        }
        return false;

    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int left = 0;
        int right = nums[n-1]-nums[0];

        while(left<=right){

            int mid = (left+right)/2;

            if(ispos(nums,mid,p)){
                right = mid-1;
            }
            else{
                left = mid+1;
            }

        }

        return left;

    }
};
