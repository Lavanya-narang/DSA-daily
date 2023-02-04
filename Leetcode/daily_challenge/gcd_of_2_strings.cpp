class Solution {
public:
    int gcd(int n1,int n2)
    {
        if(n2==0)
        {
            return n1;
        }
        return gcd(n2,n1%n2);
    }
    string gcdOfStrings(string str1, string str2) {
        if((str1+str2)!=(str2+str1))
        {
            return "";
        }
        int gcd1=gcd(str1.length(),str2.length());
        return str2.substr(0,gcd1);
    }
};
