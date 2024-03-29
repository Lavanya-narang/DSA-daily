#include<iostream>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include <algorithm>

using namespace std;

class Node
{
public:
    int data;
    vector<Node *> children;
    Node()
    {
    }
    Node(int data)
    {
        this->data = data;
    }
};

void display(Node *node)
{
    string str = to_string(node->data) + " -> ";

    for (Node *child : node->children)
    {
        str += to_string(child->data) + ", ";
    }
    str += ".";
    cout << str << "\n";

    for (Node *child : node->children)
    {
        display(child);
    }
}


bool areSimilar(Node* n1, Node* n2){
    if(n1->children.size() != n2->children.size()){
        return false;
    }
    
    for(int i = 0; i < n1->children.size(); i++){
        Node* c1 = n1->children[i];
        Node* c2 = n2->children[i];
        if(areSimilar(c1, c2) == false){
            return false;
        }
    }
    return true;
}


int main()
{
    int n1,n2;
    // for n1
    cin>>n1;
    int* arr = new int(n1);
    for(int i=0;i<n1;i++){
        cin>>arr[i];
    }
    Node* root1 = NULL;
    stack<Node*> st ;
    
    for(int i=0;i<n1;i++)
    {
        if(arr[i]==-1)
        {
            st.pop();
        }
        else
        {
            Node* t= new Node();
            t->data = arr[i];
            
            if(st.size()>0)
            {
                st.top()->children.push_back(t);
            }
            else{
                root1 = t;
            }
            st.push(t);
        }
    }
// for n2
    cin>>n2;
    // int arr1[n2];
    int* arr1 = new int(n2);
    for(int i=0;i<n2;i++)
    {
        cin>>arr1[i];
    }
    Node* root2 = NULL;
    stack<Node*> st1 ;
    
    for(int i=0;i<n2;i++)
    {
        if(arr1[i]==-1){
            st1.pop();
        }else{
            Node* t= new Node();
            t->data = arr1[i];
            
            if(st1.size()>0)
            {
                st1.top()->children.push_back(t);
            }
            else{
                root2 = t;
            }
            
            st1.push(t);
        }
        
    }
    
   if(areSimilar(root1,root2)==false){
       cout<<"false";
   } else{
       cout<<"true";
   }
    
    return 0;
}
