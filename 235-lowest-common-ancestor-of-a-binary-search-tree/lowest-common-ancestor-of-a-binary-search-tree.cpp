/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution { // copy paste the solution of leetcode 236 (no change)
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) // base case
        return NULL;

        if(root == p || root == q)  
        return root;
        //recursive call to find leftNode or p 
        TreeNode* leftNode = lowestCommonAncestor(root->left, p, q); 
        //recursive call to find rightNode or q 
        TreeNode* rightNode = lowestCommonAncestor(root->right, p, q);
        //if we get p from left side and q from right side then return root
        if(leftNode != NULL && rightNode != NULL)
        return root;

        //if leftNode is NULL i.e., we don't get p from left them q will be lca
        if(leftNode == NULL)
        return rightNode;
        //else p will be lca
        return leftNode;
    }
};