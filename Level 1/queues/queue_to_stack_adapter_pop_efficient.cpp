#include <iostream>
#include <exception>
#include <queue>
using namespace std;

class QueueToStackAdapter {
public:
  queue<int> mainQ;
  queue<int> helperQ;

  int size() {
    // write your code here
    return mainQ.size();
  }

  void push(int data) {
    // write your code here
    while(mainQ.size()>0)
    {
        int v1=mainQ.front();
        mainQ.pop();
        helperQ.push(v1);
    }
    mainQ.push(data);
    while(helperQ.size()>0)
    {
        int v2=helperQ.front();
        helperQ.pop();
        mainQ.push(v2);
    }
  }

  int top() {
    // write your code here
    if(mainQ.size()==0)
    {
        cout<<"Stack underflow"<<endl;
        return -1;
    }
    return mainQ.front();
  }

  int pop() {
    // write your code here
    if(mainQ.size()==0)
    {
        cout<<"Stack underflow"<<endl;
        return -1;
    }
    int val1=mainQ.front();
    mainQ.pop();
    return val1;
  }
};

int main() {
  QueueToStackAdapter st;
  string str;
  cin >> str;

  while (str != "quit") {
    if (str == "push") {
      int val;
      cin >> val;
      st.push(val);
    }
    else if (str == "pop") {
      int val = st.pop();
      if (val != -1) {
        cout << val << endl;
      }
    }
    else if (str == "top") {
      int val = st.top();
      if (val != -1) {
        cout << val << endl;
      }
    }
    else if (str == "size") {
      cout << st.size() << endl;
    }
    cin >> str;
  }
  return 0;
}
