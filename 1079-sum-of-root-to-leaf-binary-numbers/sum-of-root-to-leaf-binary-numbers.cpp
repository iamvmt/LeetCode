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
    int solve(TreeNode* root, int sum) {
        if (root == nullptr)
        return 0;

        if (!root->left && !root->right)
        return (sum << 1) | (root->val);

        return solve(root->left, (sum << 1) | (root->val)) +
               solve(root->right, (sum << 1)| (root->val));
    }

    int sumRootToLeaf(TreeNode* root){
        if (root == nullptr)
        return 0;
        return solve(root, 0);
    }
};