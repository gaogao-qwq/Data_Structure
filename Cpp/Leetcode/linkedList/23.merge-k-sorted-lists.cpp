/* https://leetcode.cn/problems/merge-k-sorted-lists/ */
#include "LCListNode.h"

class Solution {
public:
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

    ListNode *mergeKLists(vector<ListNode*> &lists) {
        // 空数组直接返回 nullptr
        if(lists.empty()) return nullptr;
        // 找到数组中第一个有效链表的头结点
        int i = 0;
        auto head = lists[i];
        while(head == nullptr && i + 1 < lists.size()) {
            head = lists[++i];
        }
        // 若未找到（head == nullptr）则直接返回
        if(head == nullptr) return head;
        // 定义一个临时指针p，用于连接有效链表尾结点和后继有效链表头结点
        auto p = head;
        while(p->next != nullptr) p = p->next;
        for(++i; i < lists.size(); ++i) {
            if(lists[i] == nullptr) {
                continue;
            }
            p->next = lists[i];
            // 记得每次连接两个有效链表后，要将p遍历至连接后的链表的尾结点
            while(p->next != nullptr) p = p->next;
        }
        return sortList(head);
    }
};

int main() {
    Solution s;
    vector<ListNode*>lists{nullptr,new ListNode(2),nullptr,new ListNode(3)};
    auto ans = s.mergeKLists(lists);
    return 0;
}