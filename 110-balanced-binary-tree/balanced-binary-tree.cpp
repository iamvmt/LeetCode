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
    struct DfsInfo {
        int height;
        bool ok;
    };

    DfsInfo dfs(TreeNode* node) {
        if (!node) return {0, true};

        auto L = dfs(node->left);
        if (!L.ok) return {-1, false};

        auto R = dfs(node->right);
        if (!R.ok) return {-1, false};

        if (abs(L.height - R.height) > 1) return {-1, false};

        return {1 + max(L.height, R.height), true};
    }

public:
    bool isBalanced(TreeNode* root) {
        return dfs(root).ok;
    }
};