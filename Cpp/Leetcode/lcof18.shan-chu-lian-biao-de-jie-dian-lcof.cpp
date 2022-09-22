#include "LCListNode.h"

ListNode* deleteNode(ListNode* head, int val) {
    if(head == nullptr || head->next == nullptr) return head;
    if(head->val == val) {
        head = head->next;
        return head;
    }
    auto p = head;
    while(p->next != nullptr) {
        if(p->next->val == val) {
            p->next = p->next->next;
            continue;
        }
        p = p->next;
    }
    return head;
}

int main() {
    auto head = new ListNode(4, new ListNode(5, new ListNode(1, new ListNode(9))));
    head = deleteNode(head, 5);
    return 0;
}