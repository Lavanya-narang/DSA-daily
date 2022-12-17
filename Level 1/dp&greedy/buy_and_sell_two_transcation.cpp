#include <iostream>
#include <vector>
#include <climits>

using namespace std;


void transactions(vector<int> arr) {
  // write your code here
  int misf = arr[0];
  vector<int> ps(arr.size(), 0);
  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] < misf) {
      misf = arr[i];
    }

    if (arr[i] - misf > ps[i - 1]) {
      ps[i] = arr[i] - misf;
    } else {
      ps[i] = ps[i - 1];
    }
  }
   int masf = arr[arr.size() - 1];
  vector<int> pb(arr.size(), 0);
  for (int i = arr.size() - 2; i >= 0; i--) {
    if (arr[i] > masf) {
      masf = arr[i];
    }

    if (masf - arr[i] > pb[i + 1]) {
      pb[i] = masf - arr[i];
    } else {
      pb[i] = pb[i + 1];
    }
  }
   int mp = INT_MIN;
  for (int i = 0; i < arr.size(); i++) {
    if (ps[i] + pb[i] > mp) {
      mp = ps[i] + pb[i];
    }
  }

  cout << mp;
}

int main() {
  int n ;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < arr.size(); i++) {
    cin >> arr[i] ;
  }

  transactions(arr);

  return 0;
}
