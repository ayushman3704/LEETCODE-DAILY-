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
class Solution {
public:
    typedef long long ll;
    int M = 1e9 + 7;
    ll totalSum = 0;
    ll maxProd = 0;

    ll calTotal(TreeNode* root){
        if(!root) return 0;

        return root->val + calTotal(root->left) + calTotal(root->right);
    }

    ll dfs(TreeNode* root){
        if(!root) return 0;

        ll left = dfs(root->left);
        ll right = dfs(root->right);

        ll subSum = root->val + left + right;

        ll product = subSum * (totalSum - subSum);

        maxProd = max(maxProd, product);

        return subSum;
    }
    int maxProduct(TreeNode* root) {
        // if(!root) return 0;

        totalSum = calTotal(root);
        dfs(root);

        return maxProd % M;
    }
};