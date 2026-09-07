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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count=0;
        ListNode* temp=head;
        while(temp!=nullptr){
            count++;
            temp=temp->next;
        } 
        ListNode* dummy=new ListNode(0, head);
        ListNode* curr=head;
        ListNode* pre=dummy;
        while( count>=k && curr!=nullptr){
            ListNode* nextNode=curr->next;
            int n=k-1;
            while(n-- && nextNode!=nullptr){
                ListNode* temp=nextNode->next;
                nextNode->next=curr;
                curr=nextNode;
                nextNode=temp;
            }
            count-=k;
            ListNode* temp1=pre->next;
            pre->next=curr;
            pre=temp1;
            curr=nextNode;
            pre->next=curr;
        }
        ListNode* ans=dummy->next;
        delete dummy;
        return ans;
    }
};