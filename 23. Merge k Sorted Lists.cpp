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

// https://leetcode.com/problems/merge-k-sorted-lists/submissions/1195169209

void push_front(ListNode *&head,const int &x)
{
    if(head==nullptr)
    {
        head=new ListNode(x);
        head->next=nullptr;
        return;
    }
    auto temp=new ListNode(x);
    temp->next=head;
    head=temp;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*> &lists) 
    {
        int size=lists.size();
        if(size==0) return nullptr;
        ListNode *head=nullptr;
        vector<int> v;
        for(int i=0;i<size;++i)
        {
            ListNode *crt=lists[i];
            if(crt!=nullptr)
            {
                while(crt->next)
                {
                    v.push_back(crt->val);
                    crt=crt->next;
                }
                v.push_back(crt->val);
            }
        }
        std::sort(v.begin(), v.end());
        for(long long int i=v.size()-1;i>=0;--i) 
            push_front(head,v[i]);
        return head;
    }
};

///// SLOW VERSION WITH NO STL
// void insert(ListNode*&head,const int &x)
// {
//     ListNode *temp=new ListNode(x);
//     temp->next=nullptr;
//     if(!head)
//     {
//         head=temp;
//         head->next=nullptr;
//         return;
//     }

//     ListNode *crt=head;

//     if( crt->val > x )
//     {
//         temp->next=crt;
//         head=temp;
//         return;
//     }

//     while(crt->val <= x)
//     {
//         if(crt->next && crt->next->val <= x)
//             crt=crt->next;
//         else break;
//     }

//     if(crt->next==nullptr)
//     {
//         crt->next=temp;
//         return;
//     }

//     temp->next=crt->next;
//     crt->next=temp;
// }

// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*> &lists) 
//     {
//         int size=lists.size();
//         if(size==0) return nullptr;
//         ListNode *head=lists[0];
//         for(int i=1;i<size;++i)
//         {
//             ListNode *crt=lists[i];
//             if(crt!=nullptr)
//             {
//                 while(crt->next)
//                 {
//                     insert(head,crt->val);
//                     crt=crt->next;
//                 }
//                 insert(head,crt->val);
//             }
//         }
//         return head;
//     }
// };