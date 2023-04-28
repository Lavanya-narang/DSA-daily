class Solution {
public:
void nextpermutation(vector<int>& v)
{
    int k=v.size()-1;
    while(v[k-1]>v[k])
    {
        k--;
    }
    sort(v.begin()+k,v.end());
    for(int i=k;i<v.size();i++)
    {
        if(v[i]>v[k-1])
        {
            swap(v[i],v[k-1]);
            return;
        }
    }
}
    string smallestNumber(string pattern) 
    {
        int n=pattern.size()+1;
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            v.push_back(i+1);
        }
        while(1)
        {
            bool flag=false;
            for(int i=1;i<n;i++)
            {
                if((pattern[i-1]=='I' && v[i]>v[i-1]) || (pattern[i-1]=='D' && v[i]<v[i-1]))
                {
                    continue;
                }
                flag=true;
                break;
            }
            if(!flag)
            {
                string s;
                for(int i=0;i<v.size();i++)
                {
                    s+=(v[i]+'0');
                }
                return s;
            }
            nextpermutation(v);
        }
        return "";
    }
};
