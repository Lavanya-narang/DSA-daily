// class Solution {
// public:
//     vector<int> countBits(int num) {
//           vector<int> ret(num+1, 0);
//         for (int i = 1; i <= num; ++i)
//             ret[i] = ret[i&(i-1)] + 1;
//         return ret;
//     }
// };


// class Solution {
// public:
//     //this function i have used to count set bits in an number
//     //using Barin Kerningam's Algorithm
//     int countbits(int num)
//     {
//         int count = 0;
//         while(num>0)
//         {
//             num = num&(num-1);
//             count++;
//         }
//         return count;
//     }
//     vector<int> countBits(int n)
//     {
//         vector<int> v;
//         for(int i=0;i<=n;i++)
//         {
//             v.push_back(countbits(i));
//         }
//         return v;
//     }
// };



class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i<=n; i++){
            int sum = 0,num=i;
            while(num != 0){
                sum += num%2;
                num /=2;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};
