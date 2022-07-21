#include <bits/stdc++.h>
using namespace std;

void celebPrblm(vector<string> &v, int n)
{
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        st.push(i);
    }
    while(st.size()>1)
    {
        int i=st.top();
        st.pop();
        int j=st.top();
        st.pop();
        if(v[i][j]=='1')
        {
            st.push(j);
        }
        else
        {
            st.push(i);
        }
    }
    int pot=st.top();
    st.pop();

    for(int i=0;i<n;i++)
    {
        if(i!=pot)
        {
            if((v[i][pot]=='0') || (v[pot][i]=='1'))
            {
               cout<<"none";
               return;
            }
        }
    }
        cout<<pot;
 }


int main() {
    int n;
    cin >> n;
    vector<string> s;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        s.push_back(str);
    }
    celebPrblm(s, n);
}
