class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) 
    {
        int steps=0;
        int cap=capacity;
        for(int i=0;i<plants.size();i++)
        {
            if(plants[i]<=capacity)
            {
                steps++;
                capacity-=plants[i];
            }
            else
            {
                capacity=cap;
                capacity-=plants[i];
                steps+=(2*i)+1;
            }
        }
        return steps;
    }
};
