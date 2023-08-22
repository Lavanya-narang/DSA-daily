// class Solution {
// public:
//     string reverseWords(string s) {
//         if(s.size() == 0) return s;
//         stack<string> stack;
//         string result;
//         for(int i=0; i<s.size(); i++) {
//             string word;
//             if(s[i]==' ') continue; //skip spaces
//             while(i<s.size() && s[i]!=' ' ) { //store continuous letters into word
//                 word += s[i]; i++;
//             }
//             stack.push(word); //push word to the stack
//         }
//         while(!stack.empty()) {
//             result += stack.top(); stack.pop();
//             if(!stack.empty()) result += " ";
//         }
//         return result;
//     }
// };

class Solution {
public:
    string reverseWords(string s) {
        string word = "";
        string temp = "";
        int end = s.length() - 1;
        int start = 0;
        while (end >= start) { // Use >= instead of !=
            if (s[end] != ' ') { // Use single quotes for characters, not double quotes
                while (end >= start && s[end] != ' ') { // Add a condition to check for start <= end
                    temp = s[end] + temp;

                    end--;
                }
                word += temp;
                word += " ";
                temp = "";
            }
            end--;
        }
        word.pop_back();
        return word;
    }
};
