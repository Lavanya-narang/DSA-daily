class Solution {
public:
    bool isPalindrome(string s) 
    {
       if(s.length()<=1)
       {
           return true;
       }
       int left=0,right=s.length();
       while(left<right)
       {
           while(left<right && !isalnum(s[left]))
           {
               left++;
           }
           while(left<right && !isalnum(s[right]))
           {
               right--;
           }
           if(left<right && tolower(s[left])!=tolower(s[right]))
           {
               return false;
           }
           left++;
           right--;
       }
        return true;
    }
   
};
