class Solution {
public:
    string decodeMessage(string key, string message) 
    {
        string s="";
        vector<bool>vis(26,false);
        map<char,char>mp;
        char ch='a';
       for(auto x:key)
       {
           if(x>='a' && x<='z' && vis[x-'a']==false && ch<='z')
           {
               vis[x-'a']=true;
               mp[x]=ch;
               ch++;
           }
       }
       for(auto x:message)
       {
           if(x>='a' && x<='z')
           {
               s+=mp[x];
           }
           else
           {
               s+=x;
           }
       }
        return s;
    }
};
