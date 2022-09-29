#include "LCListNode.h"

ListNode* middleNode(ListNode* head) {
    int size = 0;
    ListNode *p = head;
    while(p) {
        p = p->next;
        ++size;
    }
    p = head;
    for(int i = 0; i < size / 2; ++i) {
        p = p->next;
    }
    return p;
}

int main() {
    auto head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    auto mid = middleNode(head);
    return 0;
}