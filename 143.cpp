#include <iostream>
#include <vector>
using namespace std;

/**
 * Get the reorder linklist
 * 
 * - EX: 1-2-3-4-5 => 1-5-2-4-3
 * - Reverse the original list
 * - A connection set:
 *      - Given 2 list ABCDE EDCBA 
 *      - A->E, E->B
 * 
 * - Repeat the above set operation, and clear the remain list if the size meet the original size.
 * - TODO: too slow and the mem usage is a little bit more.
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* reorderList(ListNode* head);
void printList(ListNode* reverseHead);

int main() {
    int k = 5;  // The amount of nodes should be reversed.
    ListNode* head;
    ListNode* tmp;
    tmp = head;
    for (int i = 2; i <= k; i++) {
        ListNode* n = new ListNode(i);
        tmp->next = n;
        tmp = tmp->next;
    }
    head = new ListNode(1);
    reorderList(head);
}

void printList(ListNode* reverseHead) {
    while (reverseHead) {
        cout << reverseHead->val;
        reverseHead = reverseHead->next;
    }
}

ListNode* reorderList(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
    ListNode* reverseHead = NULL;
    ListNode* prevNode = NULL;
    ListNode* forwardNext = NULL;
    ListNode* forwardCurr = NULL;
    ListNode* reverseNext = NULL;
    ListNode* reverseCurr = NULL;
    ListNode* reorderHead = NULL;
    reorderHead = head;
    int size = 0, run;
    while (head) {
        ListNode* n = new ListNode(head->val);
        reverseHead = n;
        n->next = prevNode;
        prevNode = n;
        size++;
        head = head->next;
    }
    forwardCurr = reorderHead;
    reverseCurr = reverseHead;
    run = (size - 1) / 2;
    for (int i = 0; i < run; i++) {
        forwardNext = forwardCurr->next;
        reverseNext = reverseCurr->next;
        forwardCurr->next = reverseCurr;
        reverseCurr->next = forwardNext;
        forwardCurr = forwardNext;
        reverseCurr = reverseNext;
    }
    if ((size % 2) == 0) {
        reverseCurr->next = NULL;
        forwardCurr->next = reverseCurr;
    } else {
        forwardCurr->next = NULL;
    }
    return reorderHead;
}