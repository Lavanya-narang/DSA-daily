class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) 
    {
    int x0=c[0][0],y0=c[0][1];
    int x1=c[1][0],y1=c[1][1];
    int dx=x1-x0,dy=y1-y0;
    for(int i=0;i<c.size();i++)
    {
        int x=c[i][0],y=c[i][1];
        if(dx*(y-y1)!=dy*(x-x1))
        {
            return false;
        }
    }
    return true;
    
//     if(c.size() <= 2) return true;
//         int x1 =c[0][0];
//         int y1 =c[0][1];
//         int x2 =c[1][0];
//         int y2 =c[1][1];
//         for(int i=2;i<c.size();i++){
//             int x =c[i][0];
//             int y =c[i][1];
//             if((y2-y1)*(x1-x) != (y1-y)*(x2-x1)) return false;
//         }
//         return true;
     }
 };


// class Solution {
// public:
//     bool checkStraightLine(vector<vector<int>>& cord) {
//         int s = cord.size();
//         int x = (cord[1][1] - cord[0][1]);
//         int y = (cord[1][0] - cord [0][0]);
//         if(!x) {
//             for(int i = 2; i < s; i++) {
//                 if(cord[i][1] != cord[i-1][1]) return false;
//             }
//         } else if (!y) {
//             for(int i = 2; i < s; i++) {
//                 if(cord[i][0] != cord[i-1][0]) return false;
//             }
//         } else {
//             double slope = (double)x/y;
//             for(int i = 2; i < s; i++) {
//                 double sl = (double)(cord[i][1] - cord[i-1][1])/(cord[i][0] - cord [i-1][0]);
//                 if(sl != slope) return false;
//             }
//         }
//         return true;
//     }
// };
