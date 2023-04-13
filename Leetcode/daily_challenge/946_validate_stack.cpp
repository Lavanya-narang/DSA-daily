class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        //tc:o(n) sc:o(n)
        stack<int>st;
        int n=pushed.size();
        for(int i=0,j=0;i<n;i++)
        {
            st.push(pushed[i]);
            while(j<n && st.size()>0 && st.top()==popped[j])
            {
                st.pop();
                j++;
            }
        }   
        return st.size()==0?true:false;
    }
};


class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        //tc:o(n) sc:o(1)
        int n=pushed.size(),i=0,j=0;
        for(auto x:pushed)
        {
            pushed[i]=x;
            i++;
            while(j<n && i>0 && pushed[i-1]==popped[j])
            {
                i--;
                j++;
            }
        }
        return i==0?true:false;
    }
};
