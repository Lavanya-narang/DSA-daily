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
    mainQ.push(data);
  }

  int top() {
    // write your code here
    if(mainQ.size()==0)
    {
        cout<<"Stack underflow"<<endl;
        return -1;
    }
        while(mainQ.size()>1)
        {
            int val=mainQ.front();
            mainQ.pop();
            helperQ.push(val);
        }
        int valtop=mainQ.front();
        mainQ.pop();
        helperQ.push(valtop);
        while(helperQ.size()>0)
        {
            int val=helperQ.front();
            helperQ.pop();
            mainQ.push(val);
        }
        return valtop;
  }

  int pop() 
  {
    // write your code here
    if(mainQ.size()==0)
    {
        cout<<"Stack underflow"<<endl;
        return -1;
    }
    while(mainQ.size()>1)
    {
        int val=mainQ.front();
        mainQ.pop();
        helperQ.push(val);
    }
    int v2=mainQ.front();
    mainQ.pop();
    while(helperQ.size()>0)
    {
     int v1=helperQ.front();
     helperQ.pop();
        mainQ.push(v1);
    }
    return v2;
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
