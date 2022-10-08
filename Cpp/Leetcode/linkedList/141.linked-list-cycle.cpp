/* https://leetcode.cn/problems/linked-list-cycle/ */
#include "LCListNode.h"

    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) return false;
        auto slow = head, fast = head;
        while(fast->next!=nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) return true;
        }
        return false;
    }

int main() {
    auto head = new ListNode(3, new ListNode(2, new ListNode(0, new ListNode(4))));
    cout << boolalpha << hasCycle(head);
    return 0;
}