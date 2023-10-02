// class Solution {
// public:
//     bool winnerOfGame(string colors) {
//         map<char, int> c;
//         for (auto it = colors.begin(); it != colors.end(); ) {
//             char x = *it;
//             auto t = it;
//             while (t != colors.end() && *t == x) {
//                 t++;
//             }
//             c[x] += max(int(distance(it, t) - 2), 0);
//             it = t;
//         }

//         if (c['A'] > c['B']) {
//             return true;
//         }
//         return false;
//     }
// };



class Solution {
public:
    bool winnerOfGame(string col) {
        int n=col.size();
        int ca=0,cb=0;
        for(int i=1;i<n-1;i++){
            if(col[i]==col[i-1] && col[i]==col[i+1] && col[i]=='A')
            ca++;
            else if(col[i]==col[i-1] && col[i]==col[i+1] && col[i]=='B')
            cb++;
        }
        if(ca>cb)
        return true;

        return false;
    }
};
