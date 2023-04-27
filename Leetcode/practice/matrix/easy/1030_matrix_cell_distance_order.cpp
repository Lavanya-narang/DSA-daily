// class Solution {
// public:
//     vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) 
//     {
//         vector<vector<int>>ans;
//         for (int i = 0; i < R; i++)
//             for (int j = 0; j < C; j++)
//                 ans.push_back({i, j, abs(i - r0) + abs(j - c0)});

//         sort(ans.begin(), ans.end(), [](vector<int>& c1, vector<int>& c2) {
//             return c1[2] < c2[2];
//         });

//         for (vector<int>& d: ans) 
//             d.pop_back();
//         return ans;
//     }
// };
class Solution {
public:
	vector<vector<int>> allCellsDistOrder(int r, int c, int rCen, int cCen) {
		vector<vector<int>>ans;
		map<int,vector<vector<int>>>mp;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				int dis=abs(i-rCen)+abs(j-cCen);
				mp[dis].push_back({i,j});
			}
		}
		for(auto i:mp){
			for(auto j:i.second) ans.push_back(j);
		}
		return ans;
	}
};
