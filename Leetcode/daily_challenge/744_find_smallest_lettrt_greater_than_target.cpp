class Solution {
 public:
     char nextGreatestLetter(vector<char>& letters, char target) 
     {
         int t=target-'0';
         int low=0,high=letters.size()-1;
         string ans="";
         while(low<=high)
         {
             int mid=(high+low)/2;
             int y=letters[mid]-'0';
             if(y>t)
             {
                 ans=letters[mid];
                 high=mid-1;
             }
             else
             {
                 low=mid+1;
             }
         }
         if(ans.length()>0)
         {
             return ans[0];
         }
         
             return letters[0];
         
     }
 };

// class Solution {
// public:
//     char nextGreatestLetter(vector<char>& letters, char target) 
//     {
//        int t=target-'0';
//        for(auto it:letters)
//        {
//            int a=it-'0';
//            if(a>t)
//            {
//                return it;
//            }
//        }
//        return letters[0];
//     }
// };
