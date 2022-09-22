/* https://leetcode.cn/problems/remove-nth-node-from-end-of-list/ */
#include "LCListNode.h"

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head->next == nullptr) {
        return {};
    }
    ListNode *left = head, *right = head;
    int size = 0;
    for(int i = 0; i <= n && right != nullptr; ++i) {
        ++size;
        right = right->next;
    }
    while(right != nullptr) {
        ++size;
        left = left->next;
        right = right->next;
    }
    if(n == 1) {
        ListNode *del = left->next;
        left->next = left->next->next;
        delete(del);
        return head;
    }
    if(n == size) {
        ListNode *del = left;
        head = head->next;
        delete(left);
    } else {
        ListNode *del = left->next;
        left->next = left->next->next;
        delete(del);
    }
    return head;
}

int main() {
    auto head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    head = removeNthFromEnd(head, 2);
    return 0;
}