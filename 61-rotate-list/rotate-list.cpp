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
    ListNode* rotateRight(ListNode* head, int k) {

        if(!head || !head->next)
        return head;

        if(k == 0 )
        return head;
        
        ListNode *temp = head;
        int n = 0;

        while(temp){ // calculate total number of nodes
            n++;
            temp = temp->next;
        }
        temp = head;
        while(temp->next){ // make given linked list circular (connect last node to head of the linked list)
            temp = temp->next;
        }
        temp->next = head;

        int k1 = k % n; // k may be greater than n

        temp = head;
        int count = 0;
        while(temp){ // go to the n-k1 th position
            count++;
            if(count == n - k1) // rotate left by n-k1 places mean rotate right by k places
            break;

            temp = temp->next;
        }
        ListNode *ans = temp->next; // temp->next will become head of the rotated linked list
        temp->next = nullptr; // n-k1 th node ke next ko null kr do

        return ans;
    }
};