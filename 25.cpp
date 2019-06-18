#include <iostream>
using namespace std;

/**
 * Q: Using the advanced REVERSEING algorithm to get the new linklist
 * 
 * 1. Concern the detail that connecting 2 sub-reverse linklist
 * 2. Remember to connect the remain which isn't reversed.
 */ 

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *reverseKGroup(ListNode *head, int k);
void printList(ListNode *head);

int main() {
    int k = 3; // The amount of nodes should be reversed.
    ListNode *head; 
    ListNode *tmp;  
    tmp = head;
    for (int i = 2; i <= 5; i++) {
        ListNode *n = new ListNode(i);
        tmp->next = n;
        tmp = tmp->next;
    }
    head->val = 1; // Head is a pointer points to a list from 1 to 5
    head = reverseKGroup(head, k);
    printList(head);
}

void printList(ListNode *head) {
    while (head != NULL) {
        cout << head->val;
        head = head->next;
    }
}

ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *ctrNode = head;
    int ctr = 0, set;
    bool firstRun = true;
    while (ctrNode != NULL) {
        ctr++;
        ctrNode = ctrNode->next;
    }

    set = ctr / k;
    ListNode *prevNode = NULL;
    ListNode *nextNode = NULL;
    ListNode *curNode = head;
    ListNode *LeftNode = (ListNode *)malloc(sizeof(ListNode)); // Tail of the previous reverse sub-list
    for (int u = 0; u < set; u++) {
        for (int i = 0; i < k; i++) { // Reverse the sub linklist
            nextNode = curNode->next;
            curNode->next = prevNode;
            prevNode = curNode;
            curNode = nextNode;
        }
        LeftNode->next = prevNode; // Connect the tail of the previous reverse sub-list and the head of the current reverse sub-list.

        if (firstRun) // Record the head of the original list
            head = prevNode;
        firstRun = false;

        while (LeftNode->next != NULL) {
            LeftNode = LeftNode->next;
        }
        prevNode = NULL;
    }
    LeftNode->next = curNode;
    return head;
    // printList(head);
}
