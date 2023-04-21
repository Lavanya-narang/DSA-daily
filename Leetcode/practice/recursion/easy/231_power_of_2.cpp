// class Solution {
// public:
//     bool isPowerOfTwo(int x) 
//     {
//         if(x==0)
//         {
//             return 0;
//         }   
//             while(x%2==0)
//             {
//                 x/=2;
//             }
//         return x==1;
//     }
// };

class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        if(!n)
        {
            return false;
        }
        if(n==1)
        {
            return true;
        }
        return n%2==0 && isPowerOfTwo(n/2);
    }
};
