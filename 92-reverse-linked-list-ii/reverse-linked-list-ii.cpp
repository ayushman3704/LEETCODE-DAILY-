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
class Solution { // Using stack. Pattern- "Reversal & Segments | Hint: Reverse sublist with connectors"

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(!head || !head->next)
        return head;

        stack<ListNode*> st;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        for(int i = 0; i < left - 1; i++){ // traverse to reach the left node
            prev = prev->next;
        }

        ListNode *curr = prev->next;
        for(int i = left; i <= right; i++){ // push all node from left to right into the stack, which to be reversed.
            st.push(curr);
            curr = curr->next;
        }

        ListNode *rightNext = st.top()->next; // store just next node of the right node

        while(!st.empty()){ // reverse all left to right nodes
            prev->next = st.top();
            st.pop();
            prev = prev->next;
        }
        prev->next = rightNext; // connect tail of reverse linked list to the right->next node of the original linked list.

        return dummy->next; // return the head of the reversed list.
    }
};