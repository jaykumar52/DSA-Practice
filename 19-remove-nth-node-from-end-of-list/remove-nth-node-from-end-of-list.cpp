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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        ListNode* temp=head;
        while (temp!=nullptr){
            count++;
            temp=temp->next;
        }
        n=count-n;
        ListNode* dummy=new ListNode(0,head);
        temp=dummy;
        while(n-->0) temp=temp->next;
        ListNode* nodeToDelete = temp->next;
        temp->next=temp->next->next;
        delete nodeToDelete;
        ListNode* newHead=dummy->next;
        delete dummy;
        return newHead;
        
    }
};