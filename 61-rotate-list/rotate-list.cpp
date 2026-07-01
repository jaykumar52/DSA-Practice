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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==nullptr || head->next==nullptr) return head;
        int count =1;
        ListNode* temp=head;
        while(temp->next!=nullptr){
            count++;
            temp=temp->next;
        }
        k=k%count;
        temp->next=head;
        temp=head;
        int n=count-k;
        for (int i=1; i<n; i++){
            temp=temp->next;
        }
        ListNode* newHead=temp->next;
        temp->next=nullptr;
        return newHead;

    }
};