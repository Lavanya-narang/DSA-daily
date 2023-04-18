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
ListNode* findmid(ListNode* head)
{
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast->next!=nullptr && fast->next->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next;
        if(fast)
        {
            fast=fast->next;
        }
    }
    return slow;
}
ListNode* reverse(ListNode* head)
{
    ListNode* prev=nullptr;
    ListNode* curr=head;
    ListNode* temp=nullptr;
    while(curr!=nullptr)
    {
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}
bool comparenode(ListNode* head1,ListNode* head2)
{
    while(head1!=nullptr && head2!=nullptr)
    {
        if(head1->val!=head2->val)
        {
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }
    return true;
}
    bool isPalindrome(ListNode* head) 
    {
        if(head==nullptr || head->next==nullptr)
        {
            return true;
        }   
        ListNode* h=head;
        ListNode* mid=findmid(h);
        ListNode* h2=reverse(mid);
        return comparenode(h,h2);
    }
};
