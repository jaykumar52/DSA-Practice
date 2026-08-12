/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root==nullptr) return {};
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()){
            vector<int> curr;
            int size=q.size();
            while(size--){
                Node* currNode=q.front();
                curr.push_back(currNode->val);
                for (Node* it : currNode->children){
                    q.push(it);
                }
                q.pop();
            }
            ans.push_back(curr);
        }
        return ans;
    }
};