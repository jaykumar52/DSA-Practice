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
    ListNode* sortList(ListNode* head) {
        multiset<int> ms;
        ListNode* temp=head;
        while (temp!=nullptr){
            ms.insert(temp->val);
            temp=temp->next;
        }
        temp=head;
        for (int num : ms){
            temp->val=num;
            temp=temp->next;
        }
        return head;
    }
};