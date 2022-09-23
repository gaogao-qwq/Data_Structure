/* https://leetcode.cn/problems/insertion-sort-list/ */
// 链表 排序
// 技巧：设置虚拟头指针
#include "LCListNode.h"

ListNode* insertionSortList(ListNode* head) {
    auto _dummyHead = new ListNode(0, head);
    auto curr = head;
    auto prev = new ListNode();
    auto tmp = new ListNode();
    while(curr != nullptr && curr->next != nullptr) {
        if(curr->val <= curr->next->val) {
            curr = curr->next;
            continue;
        }
        tmp = curr->next;
        curr->next = curr->next->next;

        prev = _dummyHead;
        while(prev->next->val <= tmp->val) {
            prev = prev->next;
        }
        tmp->next = prev->next;
        prev->next = tmp;
    }
    return _dummyHead->next;
}

int main() {
    auto head = new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3))));
    head = insertionSortList(head);
    return 0;
}