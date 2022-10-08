#include "LCListNode.h"

// 方法一：将链表转化为数组，然后用双指针遍历一次
class Solution1 {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        while(head != nullptr) {
            arr.push_back(head->val);
            head = head->next;
        }
        for(int i = 0; i < arr.size() / 2; ++i) {
            if(arr[i] != arr[arr.size() - 1 - i]) return false;
        }
        return true;
    }
};

// 方法二：快慢指针
// 1.找到前半部分链表的尾节点。
// 2.反转后半部分链表。
// 3.判断是否回文。
// 4.恢复链表。
// 5.返回结果。
class Solution2 {
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr) return true;
        // 快慢指针遍历一次找到链表中点
        auto fast = head, slow = head;
        while(fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        auto p1 = head, p2 = reverseList(slow->next), secondStartHalf = p2;
        bool ans = true;
        while(ans && p2 != nullptr) {
            if(p1->val != p2->val) ans = false;
            p1 = p1->next;
            p2 = p2->next;
        }
        // 恢复链表
        slow->next = reverseList(secondStartHalf);
        return ans;
    }

    // 反转链表函数
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }
};

int main() {
    auto head = new ListNode(1,new ListNode(2,new ListNode(2,new ListNode(1))));
    Solution1 s1;
    Solution2 s2;
    cout << boolalpha << s2.isPalindrome(head);
}