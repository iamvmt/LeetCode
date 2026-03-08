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
    void solve(TreeNode* root, int targetSum, vector<int> &path, vector<vector<int>> &ans, int &pathSum){

        if(!root) return;

        pathSum += root->val;
        path.push_back(root->val);

        if(!root->left && !root->right && pathSum == targetSum) ans.push_back(path);
        
        solve(root->left, targetSum, path, ans, pathSum);
        solve(root->right, targetSum, path, ans, pathSum);

        pathSum -= root->val;
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        int pathSum = 0;
        solve(root, targetSum, path, ans, pathSum);

        return ans;
    }
};