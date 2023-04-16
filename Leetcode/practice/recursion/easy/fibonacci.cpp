class Solution {
public:
    int fib(int n) 
    {
        if(n<=1)
        {
            return n;
        }
        return fib(n-1)+fib(n-2);
        // int a=0,b=1,c,count=2;
        // while(count<=n)
        // {
        //     c=a+b;
        //     a=b;
        //     b=c;
        //     count++;
        // }
        // return c;
    }
};
