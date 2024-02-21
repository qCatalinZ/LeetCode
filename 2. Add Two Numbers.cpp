#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode
 {
 *     int val;
 *     ListNode *next;

 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


class Solution
{
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode *l=new ListNode();
        ListNode *inc=l;
        short int cf=0;
        short int sum;

        while(l1->next || l2->next)
        {

            if(l1->next && l2->next)
            {
            }
            else if(l1->next || l2->next)
            {
                if(l1->next)
                {
                    l2->next=new ListNode(0);
                }
                else if(l2->next)
                {
                    l1->next=new ListNode(0);
                }
            }
            sum=l1->val+l2->val+cf;
            if(sum<10)
            {
                cf=0;
                l->val=sum;
            }
            else if(sum>=10)
            {
                cf=1;
                l->val=sum%10;
            }
            l->next=new ListNode();
            l=l->next;
            l1=l1->next;
            l2=l2->next;
        }


        sum=l1->val+l2->val+cf;
        if(sum<10)
        {
            cf=0;
            l->val=sum;
        }
        else if(sum>=10)
        {
            cf=1;
            l->val=sum%10;
        }
        if(cf)
            l->next=new ListNode(1);

        return inc;
    }
};

int main(){}
