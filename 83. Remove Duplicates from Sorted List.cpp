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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode *tmp1 = head;
        ListNode *tmp2;

        while(tmp1 != nullptr && tmp1->next != nullptr)
        {
            if(tmp1->val == tmp1->next->val)
            {
                tmp2 = tmp1->next;
                if(tmp2->next)
                {
                    tmp1->next = tmp2->next;
                    delete tmp2;
                }
                else
                {
                    tmp1->next = nullptr;
                    delete tmp2;
                }
            }
            else tmp1 = tmp1->next;
        }

        return head;
    }
};