class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> stk;
        
        for(int i = 0; i < n; i++){
            if(stk.empty() || asteroids[i] > 0){
                stk.push(asteroids[i]);
            }else{
                while(!stk.empty() && stk.top() > 0 && stk.top() < abs(asteroids[i])){
                    stk.pop();
                }

                if(!stk.empty() && stk.top() == abs(asteroids[i])){
                    stk.pop();
                }else{
                    if(stk.empty() || stk.top() < 0){
                        stk.push(asteroids[i]);
                    }
                } 
            }
        }
        vector<int> ans(stk.size(), 0);
        int size = stk.size();
        while(!stk.empty()){
            ans[--size] = stk.top();
            stk.pop();
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> asteroidCollision(vector<int>& asteroids) 
//     {
//         vector<int> ans;
//         for(int i = 0; i < asteroids.size(); ++i)
//         {
//             while(ans.size() > 0 && i < asteroids.size() && ans.back() > 0 && asteroids[i] < 0)
//             { 
//                 if(abs(ans.back()) > abs(asteroids[i]))
//                     ++i;
//                 else if(abs(ans.back()) < abs(asteroids[i]))
//                     ans.pop_back();
//                 else
//                 {
//                     ans.pop_back();
//                     ++i;
//                 }
//             }
//         if(i < asteroids.size())
//         ans.push_back(asteroids[i]);
//         }
//         return ans;
//     }
// };
