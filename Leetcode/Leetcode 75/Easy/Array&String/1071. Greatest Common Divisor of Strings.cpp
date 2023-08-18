// class Solution {
// public:
//     int gcd(int n1,int n2)
//     {
//         if(n2==0)
//         {
//             return n1;
//         }
//         return gcd(n2,n1%n2);
//     }
//     string gcdOfStrings(string str1, string str2) {
//         if((str1+str2)!=(str2+str1))
//         {
//             return "";
//         }
//         int gcd1=gcd(str1.length(),str2.length());
//         return str2.substr(0,gcd1);
//     }
// };


// class Solution {
// public:
//     string gcdOfStrings(string str1, string str2) {
//         string ans="";
//         if(str1+str2==str2+str1){
//             int k=__gcd(str1.size(),str2.size());
//             ans+=str1.substr(0,k);
//         }
//         return ans;
//     }
// };


class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2!=str2+str1)
        {
            return "";
        }
        return str1.substr(0,gcd(str1.length(),str2.length()));
    }
};
