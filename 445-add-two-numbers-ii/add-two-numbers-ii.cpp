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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        ListNode *t1=l1, *t2=l2;
        while(t1)
        {
            s1.push(t1->val);
            t1=t1->next;
        }
        while(t2)
        {
            s2.push(t2->val);
            t2=t2->next;
        }
        int sum=0, carry=0, first=0, second=0;
        ListNode *ans=NULL; 
        while(s1.size()>0 || s2.size()>0)
        {
            if(s1.size()>0)
            {
                sum+=s1.top();
                s1.pop();
            }
            if(!s2.empty())
            {
                sum+=s2.top();
                s2.pop();
            }
            sum+=carry;
            carry=sum/10;
            ListNode *node=new ListNode(sum%10);
            node->next=ans;
            ans=node;
            sum=0;
        }
        if(carry!=0)
        {
            ListNode *node=new ListNode(carry);
            node->next=ans;
            ans=node;
        }
        return ans;
    }
};