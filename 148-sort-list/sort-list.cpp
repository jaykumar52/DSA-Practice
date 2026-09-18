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
private:
    ListNode* getMid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode* dummy=new ListNode(0);
        ListNode* tail=dummy;
        while (list1 && list2){
            if (list1->val>list2->val){
                tail->next=list2;
                list2=list2->next;
                tail=tail->next;
            } else{
                tail->next=list1;
                list1=list1->next;
                tail=tail->next;
            }
        }
        if (list1) tail->next=list1;
        else if(list2) tail->next=list2;
        ListNode* merged=dummy->next;
        delete dummy;
        return merged;
    }
public:
    ListNode* sortList(ListNode* head) {
        if (head==nullptr || head->next==nullptr) return head;
        ListNode* mid = getMid(head);
        ListNode* rightHead=mid->next;
        mid->next=nullptr;

        ListNode* left=sortList(head);
        ListNode* right=sortList(rightHead);

        return merge(left, right);
    }
};