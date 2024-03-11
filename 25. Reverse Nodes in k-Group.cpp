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

void push_back(ListNode *&head,const int &x)
{
    if(!head)
    {
        head=new ListNode(x);
        head->next=nullptr;
        return;
    }
    ListNode*crt=head;
    while(crt->next)
        crt=crt->next;
    ListNode*temp=new ListNode(x);
    crt->next=temp;
    temp->next=nullptr;
}

void push_front(ListNode*&head, const int &x)
{
    if(!head)
    {
        head=new ListNode(x);
        head->next=nullptr;
        return;
    }
    ListNode*crt=new ListNode(x);
    crt->next=head;
    head=crt;
}

void reverseList(ListNode*&head)
{
    ListNode*crt=head;
    head=nullptr;
    while(1)
    {
        if(crt)
        {
            push_front(head,crt->val);
        }
        if(crt->next)
            crt=crt->next;
        else break;
    }
}

int size(ListNode*head)
{
    int l=1;
    ListNode*crt=head;
    while(crt->next)
    {
        l++;
        crt=crt->next;
    }
    return l;
}

void pop_back(ListNode*&head, int &x)
{
    auto slow=head;
    ListNode *fast;
    if(head->next)
        fast=head->next;
    while(fast->next)
    {
        slow=slow->next;
        fast=fast->next;
    }
    if(fast)
    {
        x=fast->val;
        slow->next=nullptr;
        delete fast;
        fast=nullptr;
        return;
    }
    x=slow->val;
    delete slow;
    slow=nullptr;
}

void deleteList(ListNode*&head)
{
    if(head)
    {   
        auto crt=head;
        while(crt->next)
        {
            crt=crt->next;
            head->next=nullptr;
            delete head;
            head=crt;
        }
        delete head;
        head=nullptr;
    }
}

class Solution 
{
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode*output=nullptr;
        int index=0;
        ListNode *lists[5000];

        ListNode*crt=head;
        int nodes=1;
        push_front(lists[index],crt->val);
        while(1)
        {
            if(nodes==k)
            {
                index++;
                nodes=0;
            }
            if(crt->next)
            {
                crt=crt->next;
                push_front(lists[index],crt->val);
                nodes++;
            }
            if(crt->next==nullptr)  break;
        }

        for(int i=0;i<=index;++i)
        {
            auto current=lists[i];
            while(current)
            {
                push_back(output,current->val);
                if(current->next)
                    current=current->next;
                else break;
            }
        }
        
        int pops=size(output)%k;
        ListNode *list=nullptr;
        while(pops)
        {
            int val;
            pop_back(output,val);
            push_back(list,val);
            pops--;
        }
        if(list)
        {
            auto temp=list;
            push_back(output,temp->val);
            while(temp->next)
            {
                temp=temp->next;
                push_back(output,temp->val);
            }
        }
        for(int z=0;z<=index;++z)
        {
            deleteList(lists[z]);
        }
        head=output;
        return head;    
    }
};