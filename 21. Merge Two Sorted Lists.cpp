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


void push_front(ListNode *head, const int &x)
{
    auto crt=head;
    while(crt->next)    crt=crt->next;
    crt->next=new ListNode(x);
    crt->next->next=nullptr;
}

void sorted_push(ListNode *&head, ListNode *&crt)
{
    push_front(head,crt->val);
    if(crt->next)  crt=crt->next;
    else crt=nullptr;
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if(list1==nullptr && list2==nullptr)    return nullptr;
        if(list1==nullptr && list2)    return list2;
        if(list1 && list2==nullptr)    return list1;
        ListNode *crt1=list1,*crt2=list2;
        ListNode *head;
        if( crt1->val <= crt2->val)
        {
            head=new ListNode(list1->val);
            if(crt1->next)  crt1=crt1->next;
            else crt1=nullptr;
        }
        else
        {
            head=new ListNode(list2->val);
            if(crt2->next)  crt2=crt2->next;
            else crt2=nullptr;
        }
        head->next=nullptr;

        while(crt1 && crt2)
            if( crt1->val <= crt2->val)
                sorted_push(head,crt1);
            else
                sorted_push(head,crt2);
        while(crt1 && crt2==nullptr)
            sorted_push(head,crt1);
        while(crt1==nullptr && crt2)
            sorted_push(head,crt2);

        return head;
    }
};