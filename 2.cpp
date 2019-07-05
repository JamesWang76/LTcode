#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * Add the two link list
 * 
 * - Be cautious of the cin from from the previous digit summation.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);

int main() {
    int k = 3;  // The amount of nodes should be reversed.
    ListNode *l1 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *l2 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *tmp;
    ListNode *tmp2;
    tmp = l1;
    tmp2 = l2;
    int data1[] = {9, 9};
    int data2[] = {1};

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
    addTwoNumbers(l1, l2);
}

void printArr(ListNode *tmp) {
    while (tmp) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << "\n";
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int sumValue = l1->val + l2->val, cinValue;
    cinValue = sumValue / 10;
    ListNode *sum = new ListNode(sumValue % 10);
    ListNode *tmp;
    tmp = sum;
    // printArr(l1);
    // printArr(l2);
    l1 = l1->next;
    l2 = l2->next;
    while (l1 && l2) {
        sumValue = (l1->val + l2->val + cinValue) % 10;
        cinValue = (l1->val + l2->val + cinValue) / 10;
        ListNode *n = new ListNode(sumValue);
        tmp->next = n;
        tmp = tmp->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    if (l1 == NULL && l2 == NULL && cinValue) {
        ListNode *n = new ListNode(1);
        tmp->next = n;
    }

    while (l1) {
        sumValue = (l1->val + 0 + cinValue) % 10;
        cinValue = (l1->val + 0 + cinValue) / 10;
        ListNode *n = new ListNode(sumValue);
        tmp->next = n;
        tmp = tmp->next;
        l1 = l1->next;
    }
    while (l2) {
        sumValue = (l2->val + 0 + cinValue) % 10;
        cinValue = (l2->val + 0 + cinValue) / 10;
        ListNode *n = new ListNode(sumValue);
        tmp->next = n;
        tmp = tmp->next;
        l2 = l2->next;
    }
    if (cinValue) {
        ListNode *n = new ListNode(1);
        tmp->next = n;
    }
    // printArr(sum);
    return sum;
}