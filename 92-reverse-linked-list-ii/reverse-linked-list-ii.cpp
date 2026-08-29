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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left==right) return head;
        ListNode* tempHead=new ListNode(0, head);
        ListNode* leftPtr=tempHead;
        ListNode* rightPtr=head;
        for (int i=1; i<left; i++){
            leftPtr=leftPtr->next;
        }
        for (int i=0; i<right; i++){
            rightPtr=rightPtr->next;
        }
        ListNode* temp1=leftPtr->next;
        ListNode* temp2=temp1->next;
        temp1->next=rightPtr;
        if (temp2==nullptr) return head;
        while(temp2->next!=rightPtr){
            ListNode* temp=temp2->next;
            temp2->next=temp1;
            temp1=temp2;
            temp2=temp;
        }
        temp2->next=temp1;
        leftPtr->next=temp2;
        ListNode* ans=tempHead->next;
        delete tempHead;
        return ans;
    }
};