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
class Solution { // TREE DP. Memoization Approach.
public:
    unordered_map<TreeNode*, int> dp;

    int solve(TreeNode* root){

        if(!root)
        return 0;

        if(dp.count(root)) return dp[root];

        int rob = root->val;

        if(root->left){
            
            rob += solve(root->left->left);
            rob += solve(root->left->right);
        }

        if(root->right){

            rob += solve(root->right->left);
            rob += solve(root->right->right);
        }

        int not_rob = solve(root->left) + solve(root->right);

        return dp[root] = max(rob, not_rob);
    }

    int rob(TreeNode* root) {
        
        if(!root)
        return 0;

        return solve(root);
    }
};