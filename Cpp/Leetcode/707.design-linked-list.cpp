/* https://leetcode.cn/problems/design-linked-list/ */
#include "LCListNode.h"

class MyLinkedList {
public:
    struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    
    MyLinkedList() {
        _dummyHead = new ListNode;
        _size = 0;
    }
    
    int get(int index) {
        if(index > _size - 1 || index < 0) {
            return -1;
        }
        auto p = _dummyHead->next;
        for(int i = 0; i < _size; ++i) {
            if(index == i) {
                return p->val;
            }
            p = p->next;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        if(_size == 0) {
            auto p = new ListNode(val);
            _dummyHead->next = p;
            ++_size;
            return;
        }
        auto p = new ListNode(val, _dummyHead->next);
        _dummyHead->next = p;
        ++_size;
    }
    
    void addAtTail(int val) {
        if(_size == 0) {
            auto p = new ListNode(val);
            _dummyHead->next = p;
            ++_size;
            return;
        }
        auto p = _dummyHead->next;
        while(p->next != nullptr) {
            p = p->next;
        }
        p->next = new ListNode(val);
        ++_size;
    }
    
    void addAtIndex(int index, int val) {
        if(index > _size) return;
        if(index <= 0) {
            auto p = new ListNode(val, _dummyHead->next);
            _dummyHead->next = p;
            ++_size;
            return;
        }
        if(index == _size) {
            auto p = _dummyHead->next;
            while(p->next != nullptr) {
                p = p->next;
            }
            p->next = new ListNode(val);
            ++_size;
            return;
        }
        auto p = _dummyHead->next;
        for(int i = 1; p->next != nullptr; ++i) {
            if(index == i) {
                auto q = new ListNode(val, p->next);
                p->next = q;
                ++_size;
                return;
            }
            p = p->next;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index > _size - 1 || index < 0) {
            return;
        }
        auto p = _dummyHead;
        for(int i = 0; i < _size; ++i) {
            if(index == i) {
                p->next = p->next->next;
                --_size;
                return;
            }
            p = p->next;
        }
    }
private:
    int _size;
    ListNode *_dummyHead;
};


int main() {
    auto LinkedList = new MyLinkedList();
    LinkedList->addAtHead(7);
    LinkedList->addAtHead(2);
    LinkedList->addAtHead(1);
    LinkedList->addAtIndex(3, 0);
    LinkedList->deleteAtIndex(2);
    LinkedList->addAtHead(6);
    LinkedList->addAtTail(4);
    cout << LinkedList->get(4);
    LinkedList->addAtHead(4);
    LinkedList->addAtIndex(5, 0);
    LinkedList->addAtHead(6);
    // ["MyLinkedList","addAtHead","addAtHead","addAtHead","addAtIndex","deleteAtIndex","addAtHead","addAtTail","get","addAtHead","addAtIndex","addAtHead"]
    // [[],[7],[2],[1],[3,0],[2],[6],[4],[4],[4],[5,0],[6]]
    return 0;
}