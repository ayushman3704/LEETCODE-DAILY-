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
        
        if(!head || !head->next || k == 0)
            return head;

        int len = 1;

        ListNode* temp = head;
        while(temp->next){
            temp = temp->next;

            len++;
        }

        k = k % len;
        if(k == 0)
        return head;

        int cnt = len - k;

        temp = head;
        for(int i = 1; i < cnt; i++){
            temp = temp->next;
        }

        ListNode* newHead = temp->next;

        temp->next = NULL;

        ListNode* tail = newHead;
        while(tail->next){

            tail = tail->next;
        }

        tail->next = head;

        return newHead;
    }
};


// Approach - 

// Find length 
// Find (len - k % len) node → breaking point
// Split list into two parts 
// Attach second part to front 