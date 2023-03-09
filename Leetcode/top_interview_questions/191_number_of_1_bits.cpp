class Solution {
public:
    int hammingWeight(uint32_t n) {
//         int total=0;
//         for(int i=0;i<32;i++)
//         {
//             if((1<<i)&n)
//             {
//                 total++;
//             }
//         }
//         return total;
       int result =0;
        while(n!=0)
        {
            n=n&(n-1);
            result++;
        }
        return result;
    }
};
