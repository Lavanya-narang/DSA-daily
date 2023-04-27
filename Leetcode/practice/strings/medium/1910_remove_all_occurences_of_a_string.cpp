class Solution {
public:
    string removeOccurrences(string s, string part) 
    {
        //tc:o(m*n)
        //o(n) for insertion and then checking top m elements
       string ans;
       for(auto x:s)
       {
           ans.push_back(x);
           if(ans.size()>=part.size() && ans.substr(ans.size()-part.size())==part)
           {
               int a=part.size();
               while(a--)
               {
                   ans.pop_back();
               }
           }
       }
       return ans;
    }
};
