#include<bits/stdc++.h>
using namespace std;

void longestConsecutive(vector<int>& num) 
{

//write your code here
unordered_map<int,bool> mp;
for(int i=0;i<num.size();i++)
{
    mp[num[i]]=true;
}
for(int i=0;i<num.size();i++)
{
    if(mp.find(num[i]-1)!=mp.end())
    {
        mp[num[i]]=false;
    }
}
int mstartpt=0;
int mlen=0;
for(int val:num)
{
    if(mp[val]==true)
    {
        int tempstartpt=val;
        int templen=1;
        while(mp.find(tempstartpt+templen)!=mp.end())
        {
            templen++;
        }
        if(templen>mlen)
        {
            mlen=templen;
            mstartpt=tempstartpt;
        }
    }
}
for(int i=0;i<mlen;i++)
{
    cout<<mstartpt+i<<endl;
}
}

int main()
{
  vector<int>arr;
  int n;
  cin >> n;
  for (int i = 0 ; i < n; i++) {
    int data;
    cin >> data;
    arr.push_back(data);
  }
  longestConsecutive(arr);

  return 0;
}
