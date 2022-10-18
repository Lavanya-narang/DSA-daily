#include <iostream>
#include <queue>
using namespace std;

class MedianPriorityQueue {
public:
  priority_queue <int> left;
  priority_queue <int, vector<int>, greater<int>> right;

  void push(int val) {
    //write your code here
    if(right.size()>0 && val>right.top())
    {
        right.push(val);
    }
    else
    {
        left.push(val);
    }
    if(right.size()+2==left.size())
    {
        right.push(left.top());
        left.pop();
    }
    else if(left.size()+2==right.size())
    {
        left.push(right.top());
        right.pop();
    }
  }

  int pop() {
    //write your code here
        if(size()==0)
    {
        cout<<"Underflow"<<endl;
        return -1;
    }
    if(left.size()>=right.size())
    {
        int top=left.top();
        left.pop();
        return top;
    }
    else 
    {
        int top=right.top();
        right.pop();
        return top;
    }
  }

  int top() {
    //write your code here
    if(size()==0)
    {
        cout<<"Underflow"<<endl;
        return -1;
    }
    if(left.size()>=right.size())
    {
        return left.top();
    }
    else 
    {
        return right.top();
    }
  }

  int size() {
    //write your code here
    return left.size()+right.size();
  }
};

int main() {
  MedianPriorityQueue pq;

  string str;
  cin >> str;
  while (str != "quit") {
    if (str == "add") {
      int val;
      cin >> val;
      pq.push(val);
    }
    else if (str == "remove") {
      int val = pq.pop();
      if (val != -1) {
        cout << val << endl;
      }
    }
    else if (str == "peek") {
      int val = pq.top();
      if (val != -1) {
        cout << val << endl;
      }
    }
    else if (str == "size") {
      cout << pq.size() << endl;
    }
    cin >> str;
  }

  return 0;
}
