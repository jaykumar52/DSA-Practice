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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy=new ListNode(0,head);
        ListNode* temp=head->next;
        ListNode* pretemp=head;
        while(temp!=nullptr){
            ListNode* nextTemp=temp->next;
            ListNode* start=dummy->next;
            ListNode* pre=dummy;
            while(start!=temp && start->val<temp->val){
                pre=start;
                start=start->next;
            }
            if (start!=temp){
                pre->next=temp;
                temp->next=start;
                pretemp->next=nextTemp;
                temp=nextTemp;
            }
            else {
                pretemp=temp;
                temp=nextTemp;
            }
        }
        ListNode* ans=dummy->next;
        delete dummy;
        return ans;
    }
};