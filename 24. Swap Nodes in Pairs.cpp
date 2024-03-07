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
    ListNode* swapPairs(ListNode* head) 
    {
        auto crt=head;
        if(crt)
        while(crt->next)
        {
            int aux=crt->next->val;
            crt->next->val=crt->val;
            crt->val=aux;
            crt=crt->next;
            if(crt->next)   crt=crt->next;
            else break;
        }
        
        return head;
    }
};