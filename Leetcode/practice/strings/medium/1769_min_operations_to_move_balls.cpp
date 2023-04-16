// class Solution {
// public:
//     vector<int> minOperations(string boxes) 
//     {
//         //tc:o(n^2) sc:o(n)
//         int n=boxes.length();
//         vector<int>ans(n);
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                  if(i!=j && boxes[j]=='1')
//                  {
//                     ans[i]+=(abs(i-j));
//                  }
                
//             }
//         }   
//         return ans; 
//     }
// };
class Solution {
public:
    vector<int> minOperations(string boxes) 
    {
        //tc:o(n) sc:o(n)
        int n=boxes.length();
        vector<int>ans(n);
        int travel=0,one=0;
        for(int i=0;i<n;i++)
        {
           travel+=one;
           ans[i]+=travel;
           if(boxes[i]=='1')
           {
               one++;
           }
        } 
        travel=0;
        one=0;
         for(int i=n-1;i>=0;i--)
        {
           travel+=one;
           ans[i]+=travel;
           if(boxes[i]=='1')
           {
               one++;
           }
        }   
        return ans; 
    }
};
