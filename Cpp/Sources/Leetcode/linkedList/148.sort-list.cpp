#include "LCListNode.h"

// 递归 快慢指针 归并排序
    ListNode* sortList(ListNode* head) {
        // 分割递归终止条件
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        // 定义并初始化快慢指针
        auto fast = head->next, slow = head;
        while(fast != nullptr && fast->next != nullptr) {
            // 慢指针一次移动一个结点
            slow = slow->next;
            // 快指针一次移动两个结点
            fast = fast->next->next;
        }
        // 循环结束后快指针指向链表尾部 nullptr，慢指针指向链表中间结点的前驱结点。
        // 用 tmp 缓存中间结点，然后从中间分割链表。
        auto tmp = slow->next;
        slow->next = nullptr;
        auto left = sortList(head);
        auto right = sortList(tmp);
        
        // 合并递归
        auto h = new ListNode();
        auto res = h;
        while(left != nullptr && right != nullptr) {
            if(left->val < right->val) {
                h->next = left;
                left = left->next;
            } else {
                h->next = right;
                right = right->next;
            }
            h = h->next;
        }
        h->next = (left != nullptr) ? left : right;
        return res->next;
    }

int main() {
    auto head = new ListNode(-1, new ListNode(5, new ListNode(3, new ListNode(4, new ListNode(0)))));
    head = sortList(head);
    return 0;
}