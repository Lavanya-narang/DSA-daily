class Solution {
public:
    ListNode* mergelist(ListNode* p,ListNode* q)
    {
        ListNode* start=new ListNode(-1);
        ListNode* head=new ListNode;
        head=start;
        while(p && q)
        {
            if(p->val>q->val)
            {
                start->next=q;
                q=q->next;
            }
            else
            {
                start->next=p;
                p=p->next;
            }
            start=start->next;
        }
        while(p)
        {
            start->next=p;
            start=start->next;
            p=p->next;
        }
        while(q)
        {
            start->next=q;
            start=start->next;
            q=q->next;
        }
        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.size()==0)
        {
            return nullptr;
        }
        ListNode* head=new ListNode;
        head=lists[0];
        for(int i=1;i<lists.size();i++)
        {
            head=mergelist(lists[i],head);
        }
        return head;
    }
};
