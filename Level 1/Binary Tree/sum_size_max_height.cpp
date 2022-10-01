#include<iostream>
#include<climits>
#include<string.h>
#include<vector>

using namespace std;

// structure of node
class Node
{
public:
  int data;
  Node* left = nullptr;
  Node* right = nullptr;
  Node(int data)
  {
    this->data = data;
  }
};

class Pair {
public:
  Node* node = nullptr;
  int state = 0;

  Pair(Node* node, int state) {
    this->node = node;
    this->state = state;
  }
};

int idx = 0;
Node* constructTree(vector<int>& arr)
{

  if (idx == arr.size() || arr[idx] == -1)
  {
    idx++;
    return nullptr;
  }
  Node* node = new Node(arr[idx++]);
  node->left = constructTree(arr);
  node->right = constructTree(arr);
  return node;
}

void display(Node* node)
{
  if (node == nullptr)
    return;
  string str = "";
  str += node->left != nullptr ? to_string(node->left->data) : ".";
  str += " <- " + to_string(node->data) + " -> ";
  str += node->right != nullptr ? to_string(node->right->data) : ".";
  cout << str << endl;

  display(node->left);
  display(node->right);
}


int size(Node* node)
{
  //write your code here
  if(node==nullptr)
  {
      return 0;
  }
  int lsize=size(node->left);
  int rsize=size(node->right);
  int tsize=lsize+rsize+1;
  return tsize;
}

int height(Node* node)
{
  //write your code here
  if(node==nullptr)
  {
      return -1;
  }
  int lheight=height(node->left);
  int rheight=height(node->right);
  int theight=lheight+rheight+1;
  return theight;
}

int maximum(Node* node)
{
  //write your code here
  if(node==nullptr)
  {
      return INT_MIN;
  }
  int lmax=maximum(node->left);
  int rmax=maximum(node->right);
  int tmax=max(node->data,max(lmax,rmax));
  return tmax;
}

int sum(Node* root)
{

  //write your code here
  if(root==nullptr)
  {
      return 0;
  }
  int lsum=sum(root->left);
  int rsum=sum(root->right);
  int tsum=lsum+rsum+root->data;
  return tsum;
}

int main()
{

  int n;
  cin >> n;

  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;

    if (temp == "n")
    {
      arr[i] = -1;
    }
    else
    {
      arr[i] = stoi(temp);
    }
  }

  Node* root = constructTree(arr);

  int sz = size(root);
  int sm = sum(root);
  int max = maximum(root);
  int ht = height(root);
  cout << sz << endl;
  cout << sm << endl;
  cout << max << endl;
  cout << ht << endl;
}
