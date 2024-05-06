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
    ListNode* removeNodes(ListNode* head) {
        ListNode *temp=head;
        stack<ListNode*> s;
        while(temp!=NULL)
        {
            while(!s.empty() && s.top()->val<temp->val)
                s.pop();
            s.push(temp);
            temp=temp->next;
        }
        ListNode *curr=NULL;
        while(!s.empty())
        {
            temp=s.top();
            s.pop();
            temp->next=curr;
            curr=temp;
        }
        return temp;
    }
};