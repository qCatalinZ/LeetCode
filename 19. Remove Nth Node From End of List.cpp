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
    ListNode* removeNthFromEnd(ListNode* head, const int &n) 
    {
        int size=0;
        if(head)    size=1;
        else return nullptr;
        auto crt=head;
        while(crt->next)
        {
            crt=crt->next;
            size++;
        }
        if(size==1 && n==1) return nullptr;
        if(size==n)
        {
            crt=head;
            head=head->next;
            crt->next=nullptr;
            delete crt;
            return head;
        }
        size=size-n-1;
        crt=head;
        while(size)
        {
            crt=crt->next;
            size--;
        }
        auto tmp=crt->next;
        if(tmp->next)
        {
            crt->next=tmp->next;
        }
        else crt->next=nullptr;
        delete tmp;
        return head;
    }
};