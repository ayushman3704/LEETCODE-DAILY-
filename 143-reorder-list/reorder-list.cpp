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
    ListNode *reverseList(ListNode *head){ // function to reverse a list
        ListNode *prev = nullptr, *curr = head, *ahead;

        while(curr){
            ahead = curr->next;
            curr->next = prev;
            prev = curr;
            curr = ahead;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        // if(!head || !head->next)
        // return head;

        ListNode *slow = head;
        ListNode *fast = slow->next;
        while(fast && fast->next){ // loop to find middle node of list
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *head1 = head; // start node of the first half list
        ListNode *head2 = slow->next; // start node of the next half list
        slow->next = nullptr; // end of the first half list

        head2 = reverseList(head2); // reverse the next half list(from midlle to the last node)
        head = new ListNode(0);
        while(head1 || head2){ // loop to re-order the list

            if(head1){
                head->next = head1;
                head = head->next;
                head1 = head1->next;
            }

            if(head2){
                head->next = head2;
                head = head->next;
                head2 = head2->next;
            }
        }
    }
};