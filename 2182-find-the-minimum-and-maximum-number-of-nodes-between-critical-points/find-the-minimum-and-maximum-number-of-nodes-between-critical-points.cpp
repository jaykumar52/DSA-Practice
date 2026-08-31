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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> critical;
        int pre=head->val;
        int curr=head->next->val;
        ListNode* temp=head->next;
        int dist=1;
        while (temp->next!=nullptr){
            int next=temp->next->val;
            if ((curr>pre && curr>next) || (curr<pre && curr<next)) critical.push_back(dist);
            dist++;
            pre=curr;
            curr=next;
            temp=temp->next;
        }
        if (critical.size()<2) return {-1,-1};
        int maxDist=critical[critical.size()-1]-critical[0];
        int minDist=maxDist;
        for (int i=1; i<critical.size(); i++){
            minDist=min(minDist, critical[i]-critical[i-1]);
        }
        return {minDist, maxDist};
    }
};