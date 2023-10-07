// class Solution {
// public:
//     long long totalCost(vector<int>& costs, int k, int candidates) {
//         priority_queue<int,vector<int>,greater<int>> pq1,pq2;
//         long long ans=0;
//         int cnt = 0,i=0,j=costs.size()-1;
//         while(cnt<k){
//             while(pq1.size()<candidates && i<=j) pq1.push(costs[i++]);
//             while(pq2.size()<candidates && j>=i) pq2.push(costs[j--]);
//             int a=pq1.size()>0?pq1.top():INT_MAX;
//             int b=pq2.size()>0?pq2.top():INT_MAX;
//             // cout<<a<<" "<<b<<"\n";
//             if(a<=b){
//                 ans+=a;
//                 pq1.pop();
//             }else{
//                 ans+=b;
//                 pq2.pop();
//             }
//             cnt++;
//         }
//         return ans;
//     }
// };


class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        const int n = costs.size();
        long long totalCost = 0;
        if (2*candidates + k > n) {
            nth_element(costs.begin(), costs.begin()+k, costs.end());
            return accumulate(costs.begin(), costs.begin()+k, totalCost);
        }
        int leftIdx = 0;
        int rightIdx = costs.size()-1;
        priority_queue<int,vector<int>, greater<int>> leftpq;
        priority_queue<int,vector<int>, greater<int>> rightpq;
        while (k--) {
            while (leftpq.size() <candidates && leftIdx <= rightIdx) {
                leftpq.push(costs[leftIdx++]);
            }
            while (rightpq.size() <candidates && leftIdx <= rightIdx) {
                rightpq.push(costs[rightIdx--]);
            }
            int leftMin = leftpq.size() ? leftpq.top() : INT_MAX;
            int rightMin = rightpq.size() ? rightpq.top() : INT_MAX;
            if (leftMin <= rightMin) {
                totalCost += leftMin;
                leftpq.pop();
            } else {
                totalCost += rightMin;
                rightpq.pop();
            }
        }
        return totalCost;
    }
};
