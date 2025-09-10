#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void createList(vector<int>&arr, ListNode* head){
    ListNode* temp=head;
    for(int i=0;i<arr.size();i++){
        ListNode* newNode=new ListNode(arr[i]);
        temp->next=newNode;
        temp=temp->next;
    }
    
}
ListNode *oddEvenList(ListNode *head)
{
    if (head == NULL)
        return NULL;
    ListNode *even = head->next;
    ListNode *ptr1 = head;
    ListNode *ptr2 = even;
    while (ptr1->next and ptr2->next)
    {
        ptr1->next = ptr1->next->next;
        ptr1 = ptr1->next;
        ptr2->next = ptr2->next->next;
        ptr2 = ptr2->next;
    }

    ptr1->next = even;
    return head;
}

