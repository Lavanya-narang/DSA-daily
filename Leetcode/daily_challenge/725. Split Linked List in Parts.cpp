/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
// public:
//     // Finds no. of nodes in list
//     // TC: O(N)
//     int nodeCount(ListNode* head) {
//         int c = 0;
//         while(head) {
//             ++c;
//             head = head->next;
//         }
//         return c;
//     }
    
//     // TC: O(N)
//     vector<ListNode*> splitListToParts(ListNode* root, int k) {
//         // N/k gives max equal no. of nodes per block. In order to keep the
//         // max diff 1, we add 1 from each of the remaining N % k elements
//         // to the groups from start
//         const int N = nodeCount(root);
        
//         int elements_per_group = N / k;
//         int extra_nodes = N % k;
        
//         vector<ListNode*> result(k);
        
//         ListNode *curr = root;
        
//         for(int i = 0; i < k; i++) {
//             int remaining = elements_per_group;
//             // if any extra nodes needs to added
//             if(extra_nodes > 0) {
//                 remaining += 1;
//                 --extra_nodes;
//             }

//             result[i] = curr;
//             ListNode *prev = nullptr;
//             // traverse the no. of nodes that will be assigned
//             while(remaining--) {
//                 prev = curr;
//                 curr = curr->next;
//             }
//             // end the list
//             if(prev)
//                 prev->next = nullptr;
//         }    
        
//         return result;
//     }
// };



class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        ListNode* temp=head;
        int n=0;
        while(temp!=NULL){
            temp=temp->next;
            n++;
        }
        int size=n/k;
        int rem=n%k;
        temp=head;
        while(temp!=NULL){
            int s=size;
            if(rem>0){
             s=size+1;
             rem--;
            }
            ListNode* c=new ListNode(100);
            ListNode* tempc=c;
            for(int i=0;i<s;i++){
                tempc->next=temp;
                temp=temp->next;
                tempc=tempc->next;
            }
            tempc->next=NULL;
            ans.push_back(c->next);
        }
        if(ans.size()<k){
            int extra=k-ans.size();
            for(int i=0;i<extra;i++){
                ans.push_back(NULL);
            }
        }
        return ans;
    }
};
