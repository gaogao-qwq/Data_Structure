/* https://leetcode.cn/problems/swap-nodes-in-pairs/ */
#include "LCListNode.h"

void nSwap(ListNode *a, ListNode *b) {
    ListNode *tmp = b->next;
    b->next = a;
    a->next = tmp;
}

ListNode* swapPairs(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return head;
    
    ListNode *p = head->next;
    head->next = p->next;
    p->next = head;
    head = p;
    
    p = head->next->next;
    ListNode *prev = head->next;
    while(p != nullptr && p->next != nullptr) {
        prev->next = p->next;
        nSwap(p, p->next);
        p = p->next;
        prev = prev->next->next;
    }
    return head;
}

int main() {
    auto head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    head = swapPairs(head);
    return 0;
}