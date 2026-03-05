/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<Node*> temp;
            for(int i=0; i<size; i++){
                Node* n = q.front();
                q.pop();
                temp.push_back(n);
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }

            for(int i=0; i<temp.size()-1; i++){
                temp[i]->next = temp[i+1];
            }
            temp.back()->next = NULL;
        }

        return root;

    }
};