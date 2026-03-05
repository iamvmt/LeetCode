/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string serialize(TreeNode* root) {

       if(!root) return "#" + string(" ");

       queue<TreeNode*> Q;
       Q.push(root);

       string ans = "";
       ans.append(nodeToString(root));

       while(!Q.empty()){

            TreeNode* currNode = Q.front();
            Q.pop();

            ans.append(" ");
            ans.append(nodeToString(currNode->left));
            ans.append(" ");
            ans.append(nodeToString(currNode->right));

            if(currNode->left){
                Q.push(currNode->left);
            }

            if(currNode->right){
                Q.push(currNode->right);
            }
       }


       ans.append(" ");
       return ans;        
    }

    TreeNode* deserialize(string data) {

       vector<TreeNode*> levelOrderTraversal;
       string nodeVal = "";

       for( auto ch: data){
         if(ch == ' '){

            TreeNode* node = strToNode(nodeVal);
            levelOrderTraversal.push_back(node);
            nodeVal = "";      

         }else{
            nodeVal += ch;
         }
       } 

       if(levelOrderTraversal[0] == nullptr) return levelOrderTraversal[0]; // the tree is empty

       queue<TreeNode*> Q;
       Q.push(levelOrderTraversal[0]);

       TreeNode* root = levelOrderTraversal[0];
       int start = 1;

       while(!Q.empty()){

            TreeNode* currNode = Q.front();
            Q.pop();

            currNode->left = levelOrderTraversal[start++];
            currNode->right = levelOrderTraversal[start++];

            if(currNode->left) Q.push(currNode->left);
            if(currNode->right) Q.push(currNode->right);

       }

       return root;        
    }

    string nodeToString(TreeNode* node){

        if(!node) return "#";
        else if(node->val == 0) return "0";

        int val = node->val;
        string ans = "";

        if(val < 0){
            val = -1*val;
        }

        while(val){
            int digit = val%10;
            ans =  (char)( digit + '0' ) + ans;
            val = val/10;
        }

        if(node->val < 0) return "-" + ans;
        return ans;
    }

    TreeNode* strToNode(string str){

        if(str == "#") return nullptr;

        int sign = (str[0] == '-')? -1: 1;
        int num = 0;

        for( auto ch: str){
           
            if(ch != '-'){
                num = num*10 + (int)(ch - '0');
            }
        }

        TreeNode* node = new TreeNode(sign*num);

        return node;
    }
};
