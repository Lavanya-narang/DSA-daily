// class Solution {
// public:
//     bool buddyStrings(string A, string B) 
//     {
//        if (A.size() != B.size())
// 		return false; 
//         if (A == B && set<char>(A.begin(), A.end()).size() < A.size())
// 		return true;

// 	vector<int> diff {};
// 	for (int i = 0; i < A.size(); i++)
// 		if (A[i] != B[i])
// 			diff.push_back(i);

// 	return (diff.size() == 2 && A[diff[0]] == B[diff[1]] && A[diff[1]] == B[diff[0]]);
// }
  
// };

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.length();
        if(s.length()!=goal.length()) return false;
        if(s==goal){
            map<char,int>mp;
            for(auto i : s){
                mp[i]++;
                if(mp[i]==2) return true;
            }
            return false;
        }
        map<char,char>m;
        for(int i=0;i<s.length();i++){
            if(s[i]!=goal[i]){
            if(m.find(goal[i])!=m.end()){
                if(m[goal[i]]==s[i]){
                    for(int j=i+1;j<n;j++){
                        if(s[j]!=goal[j]) return false;
                    }
                    return true;
                }
            }
            if(m.find(s[i])!=m.end()) return false;
            m[s[i]]=goal[i];
            }
        }
        return false;
    }
};
