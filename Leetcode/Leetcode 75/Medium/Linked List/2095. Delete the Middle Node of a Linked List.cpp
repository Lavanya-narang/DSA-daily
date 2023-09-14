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
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        ListNode *dummyHead = new ListNode(-1, head);
        
        ListNode *prevOfMiddle = dummyHead, *slow = head, *fast = head;
        
        // Use tortoise and hare algorithm to locate the middle node
        while( fast != nullptr && fast->next != nullptr ){
            
            // locate the node before middle node
            prevOfMiddle = slow;
            
            // tortoise moves one step on each round
            slow = slow->next;
            
            // hare moves two steps on each round
            fast = fast->next->next;
        }
        
        // locate the node after middle node
        ListNode *junction = slow->next;
        
        // update linkage between previous one and next node
        prevOfMiddle->next = junction;
        
        // release middle node
        delete slow;
        
        return dummyHead->next;
    }
};
