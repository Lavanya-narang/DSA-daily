class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int left=0,right=height.size()-1,area,marea=0;
        while(left<right)
        {
            area=min(height[left],height[right])*(right-left);
            if(area>marea)
            {
                marea=area;
            }
            if(min(height[right],height[left])==height[left])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return marea;
    }
};
