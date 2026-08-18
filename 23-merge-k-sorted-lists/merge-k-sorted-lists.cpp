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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> values;
        for (const auto &node : lists){
            if (node==nullptr) continue;
            ListNode *temp=node;
            while (temp!=nullptr){
                values.push_back(temp->val);
                temp=temp->next;
            }
        }
        sort(values.begin(), values.end());
        if (values.size()==0) return nullptr;
        ListNode *head=new ListNode(values[0]);
        ListNode* temp=head;
        for (int i=1; i<values.size(); i++){
            ListNode* first=new ListNode(values[i]);
            temp->next=first;
            temp=first;
        }
        return head;
    }
};