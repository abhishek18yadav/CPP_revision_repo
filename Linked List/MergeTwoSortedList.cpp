#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int val;
        node *next;
        node(int val){
            this->val = val;
            this->next = NULL;
        }
};
class LinkedList{
    public:
         node *head;
         LinkedList(){
             head = NULL;
        }
        void addToTail(int val){
            node* newNode = new node(val);
            if(head == NULL){
                head = newNode;
                return;
            }
            else{
                node *temp = head;
                while(temp->next){
                    temp = temp->next;
                }
                temp->next = new node(val);
            }
            return;
        }
};
node *mergeTwoLists(node *list1, node *list2)
{
    node *head = NULL;
    node *temp1 = list1;
    node *temp2 = list2;
    while(temp1 and temp2){
        if(temp1->val < temp2->val){
            node* dummy = new node(temp1->val);
            if(head == NULL){
                head = dummy;
                
            }else{
                node *temp3 = head;
                while(temp3->next){
                    temp3 = temp3->next;
                }
                temp3->next = dummy;
            }
            temp1 = temp1->next;
        }else{
            node *dummy = new node(temp2->val);
            if(head == NULL){
                head = dummy;

            }
            else{
                node *temp3 = head;
                while(temp3->next){
                    temp3 = temp3->next;
                }
                temp3->next = dummy;
            }
            temp2 = temp2->next;
        }
    }
    node *temp3 = head;
    while (temp3->next)
    {
        temp3 = temp3->next;
    }
    while(temp1){
        temp3->next = new node(temp1->val);
        temp3 = temp3->next;
        temp1=temp1->next;
    }
    while(temp2){
        temp3->next = new node(temp2->val);
        temp3 = temp3->next;
        temp2=temp2->next;
    }
    return head;
}
int main(){
    LinkedList l1;
    l1.addToTail(1);
    l1.addToTail(2);
    l1.addToTail(4);
    l1.addToTail(6);
    l1.addToTail(8);
    LinkedList l2;
    l2.addToTail(1);
    l2.addToTail(3);
    l2.addToTail(4);
    node *temp = l1.head;
    node *temp2 = l2.head;
    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
    while(temp2){
        cout<<temp2->val<<" ";
        temp2 = temp2->next;
    }
    cout<<endl;
    node *mergedHead = mergeTwoLists(l1.head, l2.head);
    node *temp3 = mergedHead;
    while(temp3){
        cout<<temp3->val<<" ";
        temp3 = temp3->next;
    }
    return 0;
}