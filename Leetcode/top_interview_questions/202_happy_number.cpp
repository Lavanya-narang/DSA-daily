class Solution {
public:
    bool isHappy(int n) 
    {
        set<int>st;
        int val,index;
        while(1)
        {
            val=0;
            while(n)
            {
                index=n%10;
                val+=index*index;
                n=n/10;
            }
            if(val==1)
            {
                return true;
            }
            else if(st.find(val)!=st.end())
            {
                return false;
            }
            st.insert(val);
            n=val;
        }
        return false;
    }
};
