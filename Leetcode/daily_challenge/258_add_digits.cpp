class Solution {
public:
   int addDigits(int n) 
    {
        int ans=0;
    while(n>9)
    {
        while(n>0)
        {
            ans+=n%10;
            n/=10;
        }
        n=ans;
        ans=0;
    }
    return n;
    }
};

class Solution {
public:
   int addDigits(int n) 
    {
        if(n==0)
        {
            return 0;
        }
        return (n%9)==0?9:n%9;
    }
};
