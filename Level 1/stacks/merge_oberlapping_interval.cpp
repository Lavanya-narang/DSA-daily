#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;
bool compare(const vector<int> v1, const vector<int> v2) {
  return v1[0] < v2[0];
}

void mergeOverlappingIntervals(vector<vector<int>>& arr) {

  // write your code here
      sort( arr.begin(), arr.end(), compare);

  stack<vector<int>> st;

  for (int i = 0; i < arr.size() ; i++) {
    vector<int> meeting = arr[i];
    int sp = meeting[0];
    int ep = meeting[1];

    if (st.size() == 0) {
      st.push(meeting);
    }
    else {
      vector<int> lastmeeting = st.top();
      st.pop();
      if (lastmeeting[1] >= sp ) {
        vector<int> mergedmeeting{
          lastmeeting[0], max(lastmeeting[1], ep)
        };

        st.push(mergedmeeting);
      }
      else {
        st.push(lastmeeting);
        st.push(meeting);
      }
    }
  }


  // reverse stack
  stack<vector<int>> tempst;
  while (! st.empty()) {
    tempst.push(st.top());
    st.pop();

  }


  // print stack
  while (! tempst.empty()) {
    vector<int> a = tempst.top();
    tempst.pop();

    cout << a[0] << " ";
    cout << a[1] << endl;

  }

}



int main() {
  int n;
  cin >> n ;

  vector<vector<int>> arr( n, vector<int>(2) );



  // input
  for (int i = 0; i < n ; i++ ) {
    cin >> arr[i][0];
    cin >> arr[i][1];
  }


  mergeOverlappingIntervals(arr);

}
