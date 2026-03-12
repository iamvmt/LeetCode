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

void dfs(string curr,TreeNode *root,long long&ans){
    
    if(root->left!=nullptr){
        dfs(curr+to_string(root->val),root->left,ans);    
    }

    if(root->right!=nullptr){
        dfs(curr+to_string(root->val),root->right,ans);
    }




    if(root->left ==NULL && root->right == NULL){
        curr+=to_string(root->val);
        
        ans+=stoi(curr);
        return ;
    }
}

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        long long ans = 0;
        
        dfs("",root,ans);
        return ans;
    }
};