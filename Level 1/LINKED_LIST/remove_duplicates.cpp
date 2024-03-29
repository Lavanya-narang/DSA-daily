#include<iostream>
#include <sstream> 
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};
class LinkedList{
    public:
    Node* head;
    Node* tail;
    int sizee;
    
    LinkedList(){
        head=NULL;
        tail = NULL;
        sizee = 0;
    }

    void addLast(int val) {
        Node* temp = new Node();
        temp->data = val;
        temp->next = NULL;
        
        if(sizee==0){
            head = temp;
            tail = temp;
        }else{
            tail->next = temp;
            tail=temp;
        }
        sizee++;
    }
    int size(){
        return sizee;
    }
    void display(){
      for (Node* temp = head; temp != NULL; temp = temp->next) {
            cout<<temp->data<<" ";
        }  
        cout<<endl;
    }
    void removeFirst() {
        if(head==NULL){
            cout<< "List is empty"<<" ";
        }else if(sizee==1){
            head=NULL;
            tail=NULL;
            sizee--;
        }else{
            Node* ptr = head;
            head= ptr->next;
            ptr->next=NULL;
            ptr = NULL;
            sizee--;
        }
    }
    
    int getFirst() {
        if(head==NULL){
            cout<<"List is empty"<<" ";
            return -1;
        }else{
           Node* ptr;
           ptr = head;
           return ptr->data;
        }
    }

    int getLast() {
           if(tail==NULL){
            cout<<"List is empty"<<" ";
            return -1;
        }else{
           Node* ptr;
           ptr = tail;
           return ptr->data;
        } 
    }

    int getAt(int idx) {
        if(sizee==0){
            cout<<"List is empty"<<" ";
            return -1;
        }else if(idx<0 || idx>=sizee){
            cout<<"Invalid arguments"<<" ";
            return -1;
        }else{
            Node* ptr;
           ptr = head;
           int i =0;
           while(ptr!=NULL){
               if(i==idx){
                   return ptr->data;
               }
               ptr=ptr->next;
               i++;
           }
            
        }
    }
    
    
    void addFirst(int val) {
        Node* temp = new Node();
        temp->data = val;
        temp->next = NULL;
        
        if(sizee==0){
            head = temp;
            tail = temp;
        }else{
            temp->next = head;
            head= temp;
        }
        sizee++;
    }
    
    void addAt(int idx, int val) {
        if(idx<0 || idx>sizee){
            cout<<"Invalid arguments"<<" ";
        }else if(idx==0){
            addFirst(val);
        }else if(idx==sizee){
            addLast(val);
        }else{
           Node* node = new Node();
           node->data = val;
           node->next = NULL;
           
           Node* temp = head;
           for(int i=0;i<idx-1;i++){
               temp = temp->next;
           }
           node->next = temp->next;
           temp->next = node;
           
           sizee++;
        }
    }
    void removeLast() {
            if(sizee==0){
                cout<<"List is empty"<<" ";
            }else if(sizee==1){
                head=NULL;
                tail=NULL;
                sizee--;
            }else{
                Node*pre = NULL;
                Node*post;
                post=head;
                while(post->next!=NULL){
                    pre=post;
                    post=post->next;
                }
                tail=pre;
                tail->next=NULL;
                pre=NULL;
                post=NULL;
                sizee--;
            }
    }
    void removeAt(int idx) {
        if(idx<0 || idx>=sizee){
            cout<<"Invalid arguments"<<" ";
        }else if(idx==0){
            removeFirst();
        }else if(idx==sizee-1){
            removeLast();
        }else{
            Node* temp = head;
            for(int i=0;i<idx-1;i++){
                    temp=temp->next;
                }
            
            temp->next = temp->next->next;
            sizee--;
        }
    }
    
    int kthFromEnd(int k){
            Node* slow = head;
            Node* fast = head;
            for (int i = 0; i < k; i++) {
                fast = fast->next;
            }

            while (fast != tail) {
                slow = slow->next;
                fast = fast->next;
            }

            return slow->data;
    }
    int mid(){
        // without use of size
            Node* slow = head;
            Node* fast = head; 
            while (fast->next != NULL && fast->next->next != NULL) {
                slow = slow->next;
                fast = fast->next->next;
            }
        
        return slow->data;
       
    }
    
    LinkedList mergeTwoSortedLists(LinkedList l1, LinkedList l2) {
        Node* one = l1.head;
        Node* two = l2.head;
        
        LinkedList res;
        
        while(one!=NULL && two!=NULL){
            if(one->data < two->data){
                res.addLast(one->data);
                one=one->next;
            }else{
                res.addLast(two->data);
                two=two->next;
            }
        }
        while(one!=NULL){
                res.addLast(one->data);
                one=one->next;
        }
        
        while(two!=NULL){
                res.addLast(two->data);
                two=two->next;
        }
        return res;
    }
    
    
    Node* midNode(Node* headd, Node* taill){
        Node* s = headd;
        Node* f = headd;
        
        while(f!=taill && f->next!=taill){
            f= f->next->next;
            s= s->next;
        }
        return s;
    }
    
    LinkedList mergeSort(Node* head, Node* tail) {
        if(head==tail){
            LinkedList br;
            br.addLast(head->data);
            return br;
        }
        Node* mid = midNode(head,tail);
        LinkedList fsh = mergeSort(head,mid);
        LinkedList ssh = mergeSort(mid->next,tail);
        LinkedList c1 = mergeTwoSortedLists(fsh,ssh);
        return c1;
        
    }
    
    ///////////////////////////////////////
    void removeDuplicates() {
        LinkedList result;
        while(this->size()>0)
        {
            int val=this->getFirst();
            this->removeFirst();
            if(result.size()==0 || result.tail->data!=val)
            {
                result.addLast(val);
            }
        }
        this->head=result.head;
        this->tail=result.tail;
        this->sizee=result.sizee;
    }
    
};

int main(){
    LinkedList l;
    int n,val;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>val;
        l.addLast(val);
    }
    
        
        
        l.display();
        l.removeDuplicates();
        l.display();
    
    
    return 0;
}
