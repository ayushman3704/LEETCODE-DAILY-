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
class Solution { // using recurssion
public:
    string tree2str(TreeNode* root) {
        if(!root)
        return "";

        string str = to_string(root->val);

        string LEFT = tree2str(root->left);
        string RIGHT = tree2str(root->right);

        if(!root->left && !root->right) // case-1 when only root is present
        return str;

        if(!root->left){ // case-2 when root and root->right are present
           return str + "(" + ")" + "(" + RIGHT + ")";
        }

        if(!root->right){ // case-3 when root and root->left is present
           return str + "(" + LEFT + ")";
        }

        return str + "(" + LEFT + ")" + "(" + RIGHT + ")";
    }
};