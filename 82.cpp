#include <iostream>
#include <vector>
using namespace std;

/**
 * Delete the duplicate number in the list
 * 
 * - CheckDiff is the node to be checked, add it if it passes the check
 * - Notice the sequence that how the pointer A "follows" the other pointer B.
 *      - B should point to the address firstly, then A points to the B
 *      - If the sequence get reversed, then it would get some wrong answer ( Spend much time to find this bug ...)
 *  
 * - O(n), Faster than 88%
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* deleteDuplicates(ListNode* head);
void printList(ListNode* head);
int main() {
    int k = 4;  // The amount of nodes should be reversed.
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    ListNode* tmp;
    tmp = head;
    int data[] = {1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 4, 5, 6, 7, 7, 7, 7, 7, 7, 7, 8, 8};

    for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
        ListNode* n = new ListNode(data[i]);
        n->next = NULL;
        tmp->next = n;
        tmp = tmp->next;
    }
    head->val = 1;
    // printList(head);
    deleteDuplicates(head);
}
// Basic link list problem
void printList(ListNode* x) {
    while (x) {
        cout << x->val;
        x = x->next;
    }
    cout << "\n";
}

ListNode* deleteDuplicates(ListNode* head) {
    ListNode *ans = NULL, *checkDiff, *checkDiffNext;
    bool AddNode = true, FIRST = true;
    if (!head)
        return head;
    checkDiff = head;
    checkDiffNext = checkDiff;
    while (checkDiffNext) {
        AddNode = true;
        checkDiffNext = checkDiff->next;
        while (checkDiffNext && checkDiff->val == checkDiffNext->val) {
            checkDiffNext = checkDiffNext->next;
            AddNode = false;
        }
        if (AddNode) {
            if (FIRST) {
                head = checkDiff;  // Notice that the order between the line and next line !
                ans = head;
                ans->next = NULL;
                FIRST = false;
            } else {
                head->next = checkDiff;
                head = head->next;
                head->next = NULL;
            }
        }
        if (checkDiffNext)
            checkDiff = checkDiffNext;
    }
    // printList(ans);
    return ans;
}