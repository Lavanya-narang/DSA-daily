#include <iostream>
#include <vector>

using namespace std;

void transactions(vector<int> arr) {

// write your code here
int bd=0,sd=0,profit=0;
for(int i=1;i<arr.size();i++)
{
    if(arr[i]>arr[i-1])
    {
        sd++;
    }
    else
    {
        profit+=arr[sd]-arr[bd];
        bd=sd=i;
    }
}
profit+=arr[sd]-arr[bd];
cout<<profit<<endl;
}

int main() {
  int n ;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < arr.size(); i++) {
    cin >> arr[i];
  }

  transactions(arr);
  return 0;
}
