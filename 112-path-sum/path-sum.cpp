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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root==nullptr) return false;

        queue<TreeNode*> q;
        root->val=targetSum-root->val;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0; i<size; i++){
                TreeNode* node=q.front();
                q.pop();
                targetSum=node->val;
                if (targetSum==0 && node->left==nullptr && node->right==nullptr) return true;
                if (node->left!=nullptr){
                    node->left->val=targetSum-node->left->val;
                    q.push(node->left);
                }
                if (node->right!=nullptr){
                    node->right->val=targetSum-node->right->val;
                    q.push(node->right);
                }
            }
        }
        return false;
    }
};