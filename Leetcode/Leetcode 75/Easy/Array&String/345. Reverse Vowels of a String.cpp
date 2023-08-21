// class Solution {
// public:
// bool vowel(char i)
// {
//     return (i=='a' || i=='e'|| i=='i' || i=='o' || i=='u' || i=='A' || i=='E' || i=='I' || i=='O' || i=='U');
// }
//     string reverseVowels(string s) 
//     {
//         int n=s.length();
//         int i=0,j=n;

//         while(i<j)
//         {
//             if((s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')&&(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u'))
//             {
//                 swap(s[i],s[j]);
//             }
//             while(i<j and !vowel(s[i])) i++;
//             while(i<j and !vowel(s[j])) j--;
//             if(i<j)
//             {
//                 swap(s[i++],s[j--]);
//             }
//         }
//         return s;
//     }
// };

class Solution {
public:
      bool find(vector<char>&v, char c){
          for(int i=0; i<10; i++){
              if(v[i]==c){
                  return true;
              }
          }
          return false;
      }
    string reverseVowels(string s) {
        vector<char>v{'a','e','i','o','u','A','E','I','O','U'};
        int i=0;
        int j=s.size()-1;
        while(i<j){
           if(find(v,s[i])==false){
               i++;
           }
           if(find(v,s[j]) ==false){
               j--;
           }
           if(find(v,s[i]) && find(v,s[j])){
               swap(s[i], s[j]);
               i++;
               j--;
           }
        }
        return s;
    }
};
