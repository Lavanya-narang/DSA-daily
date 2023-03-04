/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//Length of List A
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

    // Initally, both A & B points to HeadA & HeadB respectively

    ListNode *a = headA ;
    ListNode *b = headB ;

    while(a != b)
    {
        // If A has become NULL, we assign it to HeadB

        if(a == NULL)
            a = headB ;

        // Else we move A to it's Next Node

        else
            a = a -> next ;

        // Similarly, if B has become NULL , we assign it to HeadA

        if(b == NULL)
            b = headA ;

        // Else we move B to it's Next Node

        else
            b = b -> next ;
    }

    // At the end, A will point to NULL, if the LinkedList's don't have an Intersection Point
    // Otherwise, it will point to the Intersecting Node of the LinkedList

    return a ;

}
};
