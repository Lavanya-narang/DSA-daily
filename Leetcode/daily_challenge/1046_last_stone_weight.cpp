class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        priority_queue<int>mxp;
        int n=stones.size();
        for(int i=0;i<n;i++)
        {
            mxp.push(stones[i]);
        }
        int f,s;
        while(n>1)
        {
            f=mxp.top();
            mxp.pop();
            s=mxp.top();
            mxp.pop();
            n-=2;
            if(f-s>0)
            {
                mxp.push(f-s);
                n+=1;
            }
        }
        if(!mxp.empty())
        {
            return mxp.top();
        }
        return 0;
    }
};
