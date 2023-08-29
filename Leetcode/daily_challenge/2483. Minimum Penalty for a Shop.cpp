// class Solution {
// public:
//     int bestClosingTime(string customers) {
//         int max_score = 0, score = 0, best_hour = -1;
//         for(int i = 0; i < customers.size(); ++i) {
//             score += (customers[i] == 'Y') ? 1 : -1;
//             if(score > max_score) {
//                 max_score = score;
//                 best_hour = i;
//             }
//         }
//         return best_hour + 1;
//     }
// };


class Solution {
public:
    int bestClosingTime(string customers) {
        int count = 0;       
        int min = count,index = 0;
        for(int i=1;i<=customers.length();i++){
            if(customers[i-1]=='Y') count--;
            else count++;
            if(count<min){
                min = count;
                index = i;
            }
        }
        return index;
    }
};
