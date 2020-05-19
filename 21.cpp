#include <iostream>
#include <string>
#include <vector>
#include <stack> 
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
int main(){
    ListNode* l1 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *l2 = (ListNode *)malloc(sizeof(ListNode));

    ListNode *tmp;
    ListNode *tmp2;
    tmp = l1;
    tmp2 = l2;


    int data1[] = {1, 2, 4};
    int data2[] = {1, 3, 4};
    for (int i = 0; i < sizeof(data1) / sizeof(data1[0]); i++) {
        ListNode *n = new ListNode(data1[i]);
        tmp->next = n;
        tmp = tmp->next;
    }
     for (int i = 0; i < sizeof(data2) / sizeof(data2[0]); i++) {
        ListNode *n = new ListNode(data2[i]);
        tmp2->next = n;
        tmp2 = tmp2->next;
    }
    mergeTwoLists(l1, l2);
}


void printList(ListNode* l1){
    while(l1){
        cout<<l1->val;
        l1 = l1->next;
    }
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(!l1)return l2;
    if(!l2)return l1;

    ListNode *n;

    if(l1 -> val > l2 -> val){
        n = new ListNode(l2 -> val);
        l2 = l2->next;
    }else{
        n = new ListNode(l1 -> val);
        l1 = l1->next;
    }
    ListNode* ans = n, * ans_curr = ans;

    while(l1 && l2){
        ListNode *n;
        if(l1 -> val > l2 -> val){
            n = new ListNode(l2 -> val);
            l2 = l2->next;
        }else{
            n = new ListNode(l1 -> val);
            l1 = l1->next;
        }
        ans_curr->next = n;
        ans_curr = ans_curr->next;
    } 

    if(l1)
        ans_curr->next = l1;
    if(l2)
        ans_curr->next = l2;
    return ans;
}