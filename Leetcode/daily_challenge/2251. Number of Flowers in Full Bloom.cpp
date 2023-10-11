// class Solution {
// public:
//     vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
//         vector<int> start, end;
//         for (auto& t : flowers)
//             start.push_back(t[0]), end.push_back(t[1]);
//         sort(start.begin(), start.end());
//         sort(end.begin(), end.end());
//         vector<int> res;
//         for (int t : persons) {
//             int started = upper_bound(start.begin(), start.end(), t) - start.begin();
//             int ended = lower_bound(end.begin(), end.end(), t) - end.begin();
//             res.push_back(started - ended);
//         }
//         return res;
//     }
// };


class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = flowers.size();
        int start[n],finish[n];
        for(int i=0;i<n;i++)
        {
            start[i]=flowers[i][0];
            finish[i]=flowers[i][1];
        }
        int cur=0;
        sort(start,start+n);
        sort(finish,finish+n);
        int i1,i2;
        i1=i2=0;
        int m = people.size();
        vector<int>ans(m);
        pair<int,int>vec[m];
        for(int i=0;i<m;i++)vec[i]={people[i],i};
        sort(vec,vec+m);
        for(int i=0;i<m;i++)
        {
            while(i1<n && vec[i].first>=start[i1])
            {
                cur++;
                i1++;
            }
            while(i2<n && vec[i].first>finish[i2])
            {
                cur--;
                i2++;
            }
            ans[vec[i].second]=cur;
        }
        return ans;
    }
};
