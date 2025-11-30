/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution { // Approach- 1(Using two pointer technique). 
                // Pattern- "Two Pointers / Cycle | Hint: Switch heads technique (A+B == B+A)"
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr1 = headA;
        ListNode *ptr2 = headB;

        if(ptr1 == nullptr || ptr2 == nullptr)
        return nullptr;

        while(ptr1 != ptr2){

            ptr1 = ptr1 ? ptr1->next : headB;
            ptr2 = ptr2 ? ptr2->next : headA;
        }
        return ptr1;
    }
};