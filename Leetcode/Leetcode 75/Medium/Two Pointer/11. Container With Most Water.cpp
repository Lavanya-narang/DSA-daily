// class Solution {
// public:
//     int maxArea(vector<int>& height) 
//     {
//         int left=0,right=height.size()-1,area,marea=0;
//         while(left<right)
//         {
//             area=min(height[left],height[right])*(right-left);
//             if(area>marea)
//             {
//                 marea=area;
//             }
//             if(min(height[right],height[left])==height[left])
//             {
//                 left++;
//             }
//             else
//             {
//                 right--;
//             }
//         }
//         return marea;
//     }
// };

class Solution {
public:
    int maxArea(vector<int>& height) {

		int n = height.size();
        int left =0, right = n-1;
		int best = 0;

		while(left < right){
			int A = height[left], B = height[right];
			best = max(best, min(A, B)*(right-left));

			if(A < B){
				left++;
			}else{
				right--;
			}
		}

		return best;
    }
};
