// class Solution {
// public:
//     vector<string> fullJustify(vector<string>& words, int maxWidth) {
//         vector<string> res;
//         const int n = words.size();
//         int begin = 0, len = 0;
//         for (int i = 0; i < n; ++i) {
//             if (len + words[i].size() + (i - begin) > maxWidth) {
//                 res.emplace_back(connect(words, maxWidth, begin, i, len, false));
//                 begin = i;
//                 len = 0;
//             }
//             len += words[i].size();
//         }
//         res.emplace_back(connect(words, maxWidth, begin, n, len, true));
//         return res;
//     }
// private:
//     string connect(const vector<string>& words, int maxWidth,
//                    int begin, int end, int len,
//                    bool is_last) {
//         string s;
//         int n = end - begin;
//         for (int i = 0; i < n; ++i) {
//             s += words[begin + i];
//             addSpaces(i, n - 1, maxWidth - len, is_last, &s);
//         }
//         if (s.size() < maxWidth) {
//             s.append(maxWidth - s.size(), ' ');
//         }
//         return s;
//     }
//     void addSpaces(int i, int spaceCnt, int maxWidth, bool is_last, string *s) {
//         if (i < spaceCnt) {
//             int spaces = is_last ? 1 : maxWidth / spaceCnt + (i < maxWidth % spaceCnt);
//             s->append(spaces, ' ');
//         }
//     }
// };







class Solution {
public:
    string make_line(vector<string>&words, int s, int e, int maxWidth, int len){
        int num_words = e-s;
        string res="";
        if(num_words==1){
            return make_last_line(words,s,e,maxWidth,len);
        }
        int spaces_even = (maxWidth-len)/(num_words-1);
        int spaces_extra = (maxWidth-len)%(num_words-1);
        for(int i=s;i<e;i++){
            res = res+words[i];
            if(i==e-1){
                continue;
            }
            string space(spaces_even,' ');
            if(spaces_extra){
                space.push_back(' ');
                spaces_extra--;
            }
            res = res + space;
        }
        return res;

    }
    string make_last_line(vector<string>&words, int s, int e, int maxWidth, int len){
        int num_words = e-s;
        string res="";
        for(int i=s;i<e;i++){
            res=res+words[i];
            if(i==e-1){
                continue;
            }
            res.push_back(' ');
        }
        string space(maxWidth-res.size(),' ');
        res=res+space;
        return res;

    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>res;
        string curr="";
        int s=0;
        int l=words[s].size();
        for(int i=1;i<words.size();i++){
            if(l+(i-s)+words[i].size()>maxWidth){
                curr = make_line(words,s,i,maxWidth,l);
                res.push_back(curr);
                l=words[i].size();
                s=i;
            }
            else{
                l=l+words[i].size();
            }
        }
        curr = make_last_line(words,s,words.size(),maxWidth,l);
        res.push_back(curr);
        return res;
    }
};
