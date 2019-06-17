#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void reverseKGroup(ListNode* head, int k);



int main(){
    int k=3;
    ListNode* head = new ListNode(1); // Notice
    ListNode* tmp ; // Notice
    tmp = head;
    for(int i=2;i<=6;i++){
        ListNode* n = new ListNode(i);
        tmp->next = n;
        tmp = tmp->next;
    }
    
    reverseKGroup(head, k);
}

void reverseKGroup(ListNode* head, int k) {
    ListNode* prevNode = NULL;
    ListNode* nextNode = NULL;
    ListNode* curNode = head;
    while(curNode != NULL){
        nextNode = curNode->next;
        curNode->next = prevNode;
        prevNode = curNode;
        curNode = nextNode;
    }
    ListNode* tmp = prevNode; // Notice
    while(tmp!=NULL){
        cout<<tmp->val;
        tmp = tmp->next;
    }
        
}
