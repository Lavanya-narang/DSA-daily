#include <iostream>
#include <exception>
#include <stack>
using namespace std;

class StackToQueueAdapter {
public:
stack<int> mainS;
  stack<int> helperS;

  int size() {
    // write your code here
    return mainS.size();
  }

  void add(int data) {
    // write your code here
    mainS.push(data);
  }

  int peek() 
  {
     if(mainS.size()==0)
     {
         cout<<"Queue underflow"<<endl;
         return -1;
     }
     while(mainS.size()>1)
     {
         int val=mainS.top();
         mainS.pop();
         helperS.push(val);
     }
     int v1=mainS.top();
     mainS.pop();
     helperS.push(v1);
     while(helperS.size()>0)
     {
         int v2=helperS.top();
         helperS.pop();
         mainS.push(v2);
     }
     return v1;
  }
  int remove()
  {
    if(mainS.size()==0)
    {
        cout<<"Queue underflow"<<endl;
        return -1;
    }
         while(mainS.size()>1)
     {
         int val=mainS.top();
         mainS.pop();
         helperS.push(val);
     }
      int v1=mainS.top();
     mainS.pop();
          while(helperS.size()>0)
     {
         int v2=helperS.top();
         helperS.pop();
         mainS.push(v2);
     }
     return v1;
    
  }

};


int main() {
  StackToQueueAdapter q;
  string str;
  cin >> str;

  while (str != "quit") {
    if (str == "add") {
      int val;
      cin >> val;
      q.add(val);
    }
    else if (str == "remove") {
      int val = q.remove();
      if (val != -1) {
        cout << val << endl;
      }
    }
    else if (str == "peek") {
      int val = q.peek();
      if (val != -1) {
        cout << val << endl;
      }
    }
    else if (str == "size") {
      cout << q.size() << endl;
    }
    cin >> str;
  }
  return 0;
}
