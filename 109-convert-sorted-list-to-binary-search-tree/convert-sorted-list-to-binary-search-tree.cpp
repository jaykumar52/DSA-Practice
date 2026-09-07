/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    void leftHelper(TreeNode* node, int left, int right, vector<int> & arr){
        if (left>right) return;
        int mid=(right+left)/2;
        TreeNode* temp=new TreeNode(arr[mid]);
        node->left=temp;
        leftHelper(node->left, left, mid-1, arr);
        rightHelper(node->left, mid+1, right, arr);
    }
    void rightHelper(TreeNode* node, int left, int right, vector<int> & arr){
        if (left>right) return;
        int mid=(right+left)/2;
        TreeNode* temp=new TreeNode(arr[mid]);
        node->right=temp;
        rightHelper(node->right, mid+1, right, arr);
        leftHelper(node->right, left, mid-1, arr);
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        vector<int> arr;
        ListNode* temp=head;
        while (temp!=nullptr){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int n=arr.size();
        TreeNode* root=new TreeNode(arr[n/2]);
        leftHelper(root, 0, n/2-1, arr);
        rightHelper(root, n/2+1, n-1, arr);
        return root;
    }
};