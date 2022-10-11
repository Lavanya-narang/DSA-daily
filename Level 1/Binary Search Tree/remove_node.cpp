#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
  Node(int val) {
    data = val;
    left = nullptr;
    right = nullptr;
  }
};

Node* construct(vector<int>& arr) {
  Node* root = new Node(arr[0]);
  pair<Node*, int> p = {root, 1};

  stack<pair<Node*, int>> st;
  st.push(p);

  int idx = 1;
  while (!st.empty()) {

    if (st.top().second == 1) {
      st.top().second++;
      if (arr[idx] != -1) {
        st.top().first->left = new Node(arr[idx]);
        pair<Node*, int> lp = {st.top().first->left, 1};
        st.push(lp);
      }
      else {
        st.top().first->left = nullptr;
      }
      idx++;
    }
    else if (st.top().second == 2) {
      st.top().second++;
      if (arr[idx] != -1) {
        st.top().first->right = new Node(arr[idx]);
        pair<Node*, int> rp = {st.top().first->right, 1};
        st.push(rp);
      } else {
        st.top().first->right = nullptr;
      }
      idx++;
    }
    else {
      st.pop();
    }

  }
  return root;
}
void display(Node* node) {
  if (node == nullptr) {
    return;
  }

  string str = " <- " + to_string(node->data) + " -> ";

  string left = (node->left == nullptr) ? "." :  "" + to_string(node->left->data);
  string right = (node->right == nullptr) ? "." : "" + to_string(node->right->data);

  str = left + str + right;
  cout << str << endl;

  display(node->left);
  display(node->right);
}

int max(Node* root) {
  if (root->right == nullptr) {
    return root->data;
  }
  return max(root->right);
}


Node* remove(Node* root, int data) {
//     Write your code here
    if(root==nullptr)
    {
        return nullptr;
    }
    if(data<root->data)
    {
        root->left=remove(root->left,data);
    }
    else if(data>root->data)
    {
        root->right=remove(root->right,data);
    }
    else
    {
        if(root->left!=nullptr && root->right!=nullptr)
        {
            int lm=max(root->left);
            root->data=lm;
            root->left=remove(root->left,lm);
        }
        else if(root->left!=nullptr)
        {
            return root->left;
        }
        else if(root->right!=nullptr)
        {
            return root->right;
        }
        else
        {
            return nullptr;
        }
    }
    return root;
}
int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    string x;
    cin >> x;
    if (x == "n") {
      arr[i] = -1;

    }
    else {
      arr[i] = stoi(x);
    }
  }
  int data;
  cin >> data;
  Node* root = construct(arr);

  root = remove(root, data);

  display(root);
}
