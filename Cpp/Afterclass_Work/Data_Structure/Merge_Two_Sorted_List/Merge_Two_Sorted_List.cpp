#include <iostream>
using namespace std;

// 链表结点类型定义
struct ListNode {
    //数据域
    int val;
    // 指针域
    ListNode *next;
    // 构造函数定义
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 递归实现合并有序链表
ListNode* mergeTwoSortedLists(ListNode* list1, ListNode* list2) {
    if(!list1) {
        return list2;
    }
    if(!list2) {
        return list1;
    }
    if(list1->val <= list2->val) {
        list1->next = mergeTwoSortedLists(list1->next, list2);
        return list1;
    }
    list2->next = mergeTwoSortedLists(list2->next, list1);
    return list2;
}

// 归并排序（递归实现）
ListNode* sortLists(ListNode* head) {
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
    auto left = sortLists(head);
    auto right = sortLists(tmp);

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

// 合并链表函数实现
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    auto p = list1;
    // 先遍历至 list1 尾结点
    while(p->next != nullptr) {
        p = p->next;
    }
    // 将 list1 尾结点指向 list2 头结点
    p->next = list2;
    // 返回 list1 头指针
    return list1;
}

int main() {
    // 懒得写用户输入实现了，直接硬编码写死。
    auto list1 = new ListNode(1, new ListNode(1, new ListNode(1, new ListNode(4))));
    auto list2 = new ListNode(1, new ListNode(5, new ListNode(1, new ListNode(4))));
    auto res1 = mergeTwoLists(list1, list2);
    cout << "实现1（仅仅只是把一个链表丢到另一个链表后面去罢了）：";
    while(res1 != nullptr) {
        cout << res1->val << ",";
        res1 = res1->next;
    }

    auto list3 = new ListNode(1, new ListNode(2, new ListNode(4)));
    auto list4 = new ListNode(1, new ListNode(3, new ListNode(4, new ListNode(5))));
    auto res2 = mergeTwoSortedLists(list3, list4);
    cout << "实现2（仅适用于合并有序链表）：";
    while(res2 != nullptr) {
        cout << res2->val << ",";
        res2 = res2->next;
    }

    auto list5 = new ListNode(1, new ListNode(1, new ListNode(4, new ListNode(5, new ListNode(1, new ListNode(4))))));
    auto list6 = new ListNode(1, new ListNode(9, new ListNode(1, new ListNode(9, new ListNode(8, new ListNode(1, new ListNode(0)))))));
    auto res3 = sortLists(mergeTwoLists(list5, list6));
    cout << endl << "实现3（适用于任意链表合并）：";
    while(res3 != nullptr) {
        cout << res3->val << ",";
        res3 = res3->next;
    }
    return 0;
}