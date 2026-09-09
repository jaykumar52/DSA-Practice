/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> map;
        Node* temp=head;
        Node* dummy=new Node(0);
        Node* pre=dummy;
        while (temp!=nullptr){
            Node* newNode=new Node(temp->val);
            pre->next=newNode;
            pre=pre->next;
            map[temp]=newNode;
            temp=temp->next;
        }
        for (const auto& [old, copy] : map){
            if (old->random==nullptr) copy->random=nullptr;
            else {
                copy-> random=map[old->random];
            }
        }
        Node* ans=dummy->next;
        delete dummy;
        return ans;

    }
};