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
        if (root==nullptr || (root->right==nullptr && root->left==nullptr)) return root;

        queue<Node*> q;
        q.push(root->right);
        q.push(root->left);
        while(!q.empty()){
            Node* tempNext=q.front();
            
            q.pop();
            int n=q.size();
            if (tempNext->left!=nullptr){
                q.push(tempNext->right);
                q.push(tempNext->left);
            }
            for (int i=0; i<n; i++){
                Node* currNode=q.front();
                if (tempNext->left!=nullptr){
                    q.push(currNode->right);
                    q.push(currNode->left);
                }
                q.pop();
                currNode->next=tempNext;
                tempNext=currNode;
            }
        }
        return root;
    }
};