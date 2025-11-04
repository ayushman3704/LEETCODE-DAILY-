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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution { // using BST property
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)
        return NULL;

        if(!head->next)
        return new TreeNode(head->val);

        ListNode* slow = head; // this pointer move by one step each time
        ListNode* fast = head; // this pointer move by two steps each time
        ListNode* slow_prev = NULL; // this is slow previous pointer which will stay one step before slow pointer

        while(fast && fast->next){ // run loop to find middle node (root node) of linked list
            slow_prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode* root = new TreeNode(slow->val); // create root

        slow_prev->next = nullptr; // head to slow_prev will generate left sub tree

        root->left = sortedListToBST(head); // recursively create left subtree
        root->right = sortedListToBST(slow->next); // recursively create right subtree

        return root;
    }
};