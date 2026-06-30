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
private:
    void helper(TreeNode* root, vector<int> &ans){
        if (root==nullptr) return;

        if (root->left!=nullptr){
            helper(root->left, ans);
            ans.push_back(root->left->val);
        } 
        
        if (root->right!=nullptr){
            helper(root->right, ans);
            ans.push_back(root->right->val);
        } 
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root==nullptr) return ans;
        helper(root, ans);
        ans.push_back(root->val);
        return ans;
    }
};