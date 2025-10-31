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
    void findPath(TreeNode* root, string path, vector<string> &res){
        if(!root->left && !root->right){
            res.push_back(path);
            return;
        }

        if(root->left){
            findPath(root->left, path+"->"+ to_string(root->left->val), res);
        }
        if(root->right){
            findPath(root->right, path+"->"+ to_string(root->right->val), res);
        }

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;

        string path = to_string(root->val);

        findPath(root, path, ans);

        return ans;
    }
};