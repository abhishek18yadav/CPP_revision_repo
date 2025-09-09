#include<bits/stdc++.h> 
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void  generateList(vector<int>&nodes , ListNode* head ){
    ListNode* temp = head;
    for(int i=1;i<nodes.size();i++){
        ListNode* newNode = new ListNode(nodes[i]);
        temp->next = newNode;
        temp = temp->next;
    }
    
}
int getIndex(ListNode *head)
{
    ListNode *temp = head;
    int ptr = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        ptr++;
    }
    return ptr;
}
ListNode *deleteMiddle(ListNode *head)
{
    int targetNodeNo = getIndex(head) / 2;
    if (targetNodeNo == 0)
    {
        if (head->next)
            return head->next;
        else
            return NULL;
    }
    ListNode *temp = head;
    while (targetNodeNo > 1 and temp != NULL)
    {
        temp = temp->next;
        targetNodeNo--;
    }
    ListNode *target = temp->next;
    temp->next = temp->next->next;
    return head;
}

int main(){
    vector<int>nodes = {1,3,4,7,1,2,6};
    ListNode* head = new ListNode(nodes[0]);
    generateList(nodes, head);
    ListNode* newHead = deleteMiddle(head);
    while(newHead){
        cout<<newHead->val<<" ";
        newHead = newHead->next;
    }
    return 0;
}