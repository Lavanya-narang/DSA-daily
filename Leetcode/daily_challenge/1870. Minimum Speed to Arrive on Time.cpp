// class Solution {
// public:
//     bool satisfy(int mid, vector<int>& dist, double hour)
//     {
//         double time = 0;
//         for(int i=0;i<dist.size()-1;i++)
//         {
//             time += ceil((double)dist[i]/mid);
//         }
//         time+=((double)dist.back())/mid;
//         if(time<=hour)
//         {
//             return true;
//         }
//         return false;
//     }
//     int minSpeedOnTime(vector<int>& dist, double hour) {
//         int n = dist.size();
//         // base condition
//         if(n>ceil(hour))
//         {
//             return -1;
//         }
        
//         int i = 1; // as the lowest answer can be one
//         int j = 1e7; // as maximum is given in the question
//         int res = -1;
//         while(i<=j)
//         {
//             int mid = (i+j)/2;
//             if(satisfy(mid,dist,hour)==true)
//             {
//                 res = mid;
//                 j = mid-1;
                
//             }
//             else
//             {
//                 i = mid+1;
//             }
//         }
//         return res;
//     }
// };


class Solution {
public:
    double limit = 0;
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if (dist.size() > ceil(hour)) {
            return -1;
        }

        this->limit = hour;
        int left = 1;
        int right = pow(10, 7);
     
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(mid, dist)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;     
    }

    bool check(int speed, vector<int>& dist) {
        double time = 0;
        for (double d : dist) {
            time = ceil(time);
            time += d / speed;
        }

        return time <= limit;
    }
};
