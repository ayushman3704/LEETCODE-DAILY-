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
class Solution { // using dfs
public:
    map<int, int> mp; // stores [level, sum]

    void dfs(TreeNode* root, int level){
        if(!root)
        return;

        mp[level] += root->val; // same level ke saare node ka sum map me store kr lenge

        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int resLevel = 0;

        dfs(root, 1); // root ka level 1 h. isliye yahan level me 1 bheja h

        for(auto &it: mp){ // traverse in the map and get minimal level with maximum sum
            int level = it.first;
            int sum = it.second;

            if(sum > maxSum){
                maxSum = sum;
                resLevel = level;
            }
        }

        return resLevel;
    }
};