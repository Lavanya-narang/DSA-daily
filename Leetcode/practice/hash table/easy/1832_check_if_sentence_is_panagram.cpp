// class Solution {
// public:
//     bool checkIfPangram(string sentence) 
//     {
//        unordered_set<char>s;
//        for(auto i:sentence)
//        {
//            s.insert(i);
//        } 
//         if(s.size()==26)
//         {
//             return true;
//         }
//         return false;
//     }
// };


class Solution {
public:
    bool checkIfPangram(string sentence) 
    {
       unordered_map<char,int>mp;
       for(int i=0;i<sentence.size();i++)
       {
           mp[sentence[i]]++;
       }
       return 26==mp.size();
    }
};
