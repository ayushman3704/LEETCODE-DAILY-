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
class Solution { // Pattern- Two Pointers / Cycle | Hint: Split odd/even lists, then join
public:
    ListNode* oddEvenList(ListNode* head) {

        if(!head || !head->next)
        return head;
        ListNode *oddHead = head;
        ListNode *evenHead = head->next;

        ListNode* evenStart = head->next;

        while(evenHead != NULL && evenHead->next != NULL){
            oddHead->next = evenHead->next;
            evenHead->next = evenHead->next->next;

            oddHead = oddHead->next;
            evenHead = evenHead->next;
        }

        oddHead->next = evenStart;
        return head;
    }
};