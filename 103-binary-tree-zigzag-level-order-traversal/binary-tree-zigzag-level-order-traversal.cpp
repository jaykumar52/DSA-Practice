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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root==nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool right=false;
        while(!q.empty()){
            vector<int> currLevel;
            int size=q.size();

            for (int i=0; i<size; i++){
                currLevel.push_back(q.front()->val);
                if (q.front()->left!=nullptr) q.push(q.front()->left);
                if (q.front()->right!=nullptr) q.push(q.front()->right);
                q.pop();
            }
            if (right) reverse(currLevel.begin(), currLevel.end());
            right=!(right);
            ans.push_back(currLevel);
        }
        return ans;
    }
};