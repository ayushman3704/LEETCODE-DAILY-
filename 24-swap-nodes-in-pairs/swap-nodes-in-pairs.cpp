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
class Solution { // recursive approach. Pattern- "Reversal & Segments | Hint: Dummy + iterative pair swapping"
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
        return head;

        ListNode *curr = head;
        swap(curr->val, curr->next->val);

        swapPairs(curr->next->next);

        return curr;
    }
};