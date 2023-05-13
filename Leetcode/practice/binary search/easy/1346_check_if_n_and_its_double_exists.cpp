// Brute Force Two Pointer Soln
// Time O(n.n)
// Space O(1)

// class Solution {
// public:
//     bool checkIfExist(vector<int>& arr) 
//     {
//         int pointer_one = -1;
//         int pointer_two = -1;
        
//         for (pointer_one = 0; pointer_one < arr.size(); pointer_one++) {
//             int n = arr[pointer_one];
//             for (pointer_two = pointer_one + 1; pointer_two < arr.size(); pointer_two++) {
//                 int m = arr[pointer_two];
//                 if ( n == (2 * m) || m == (2 * n)) {
//                     return true;
//                 }
//             }
//         }
        
//         return false;
//     }
// };




//set appproach
// class Solution {
// public:
//     bool checkIfExist(vector<int>& arr) 
//     {
//        unordered_set<int>s;
//        for(int i=0;i<arr.size();i++)
//        {
//            s.insert(arr[i]);
//        }
//        for(auto val:s)
//        {
//            if(val!=0 and s.find(2*val)!=s.end())
//            {
//                return true;
//            }
//        }
//        return count(arr.begin(),arr.end(),0)>1;
//     }
// };

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        for (int i=0; i<arr.size(); i++){
            int low=i+1; int high= arr.size()-1;
            if (arr[i]<0){
                while (low<= high){
                int mid= low+ (high-low)/2;
                if (arr[i] == arr[mid]*2)return true;
                else if (arr[i] < arr[mid]*2){
                    high= mid-1;
                }
                else low= mid+1;
                }
            }
            else{
                while (low<= high){
                    int mid= low+ (high-low)/2;
                    if (arr[i]*2 == arr[mid]) {return true;}
                    else if (arr[i]*2 < arr[mid]){
                        high= mid-1;
                    }
                    else low= mid+1;
                }
            }
        }
        return false;
    }
};
