#include <iostream>
#include <vector>
using namespace std;

/**
 * Q: Rotate the linklist k times
 * 
 * 1. Traverse from list head to the tail and duplicate the value to another vector
 * 2. Insert the new node behind the tail and move on the head to the next node at the same time.
 * 
 * Faster than 99% but a bit big mem usage.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *rotateRight(ListNode *head, int k);

int main() {
    int k = 4; // The amount of nodes should be reversed.
    ListNode *head;
    ListNode *tmp;
    tmp = head;
    for (int i = 2; i <= 5; i++) {
        ListNode *n = new ListNode(i);
        tmp->next = n;
        tmp = tmp->next;
    }
    head->val = 1;
    rotateRight(head, k);
}

ListNode *rotateRight(ListNode *head, int k) {
    vector<int> listVal;
    ListNode *tmp = head;
    int size = 1, rotateStep;
    if (!head)
        return head;
    while (tmp->next) {
        size++;
        listVal.push_back(tmp->val);
        tmp = tmp->next;
    }
    rotateStep = k % size;
    if (rotateStep == 0) {
        return head;
        // while(head){
        //     cout<<head->val<<" ";
        //     head = head ->next;
        // }
    } else {
        for (int i = 0; i < size - rotateStep; i++) {
            ListNode *n = new ListNode(listVal[i]);
            tmp->next = n;
            tmp = tmp->next;
            head = head->next;
        }
        return head;
        // while(head){
        //     cout<<head->val<<" ";
        //     head = head ->next;
        // }
    }
}
