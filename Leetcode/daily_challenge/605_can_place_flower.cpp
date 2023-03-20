class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
         int s = flowerbed.size();
        int ans = 0;
        for(int i = 0; i <= s-1; i++){
            if((flowerbed[i] == 0) && (i == 0 || flowerbed[i-1] == 0) && (i == s-1 || flowerbed[i+1] == 0)){
                flowerbed[i] = 1;
                ans++;
            }
        }
        return (ans >= n);
    }
};
