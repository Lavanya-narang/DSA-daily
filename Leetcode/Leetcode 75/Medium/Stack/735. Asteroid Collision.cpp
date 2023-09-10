// class Solution {
// public:
//     vector<int> asteroidCollision(vector<int>& asteroids) {
//         int n = asteroids.size();
//         stack<int> stk;
        
//         for(int i = 0; i < n; i++){
//             if(stk.empty() || asteroids[i] > 0){
//                 stk.push(asteroids[i]);
//             }else{
//                 while(!stk.empty() && stk.top() > 0 && stk.top() < abs(asteroids[i])){
//                     stk.pop();
//                 }

//                 if(!stk.empty() && stk.top() == abs(asteroids[i])){
//                     stk.pop();
//                 }else{
//                     if(stk.empty() || stk.top() < 0){
//                         stk.push(asteroids[i]);
//                     }
//                 } 
//             }
//         }
//         vector<int> ans(stk.size(), 0);
//         int size = stk.size();
//         while(!stk.empty()){
//             ans[--size] = stk.top();
//             stk.pop();
//         }
//         return ans;
//     }
// };

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






class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
       stack<int> st;
        st.push(asteroids[0]);
        for (int i=1; i<asteroids.size(); i++) {
            int val = asteroids[i];
            if (st.empty()) st.push(val); //base case
            else if (st.top() < 0) st.push(val); //top asteroid moves left, => can't affect next incoming/outgoing asteroid
            else {
                if (val > 0) st.push(val); //both asteroid forward => simply push it
                else {
            // now simulate collision behaviour
                    int canPush = 1;
                    while (!st.empty() && st.top() > 0) {
                        if (st.top() + val < 0) {
                            st.pop();
                        }
                        else if (st.top() + val > 0) {
                            canPush = 0;
                            break;
                        }
                        else {
                            st.pop();
                            canPush = 0;
                            break;
                        }
                    }
                    if (canPush) st.push(val);
                }
            }
        }
    // now reverse stack elements so that we can push them into our answer vector
        stack<int> temp;
        while (!st.empty()) {
            temp.push(st.top());
            st.pop();
        }
        vector<int> ans;
        while (!temp.empty()) {
            ans.push_back(temp.top());
            temp.pop();
        }
        return ans;
    }
};
