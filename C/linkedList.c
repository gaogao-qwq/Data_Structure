#include <stdio.h>
#include <stdlib.h>

#define LEN 10

typedef struct linkedList
{
    int num;
    struct linkedList *next;
}LNode;

int main(int argc, char **argv) {
    LNode *head = (LNode *)malloc(sizeof(LNode));
    LNode *p1 = (LNode *)malloc(sizeof(LNode)), *p2 = NULL;
    head->next = p1;
    // 创建一个长度为10的单链表，并将其中每个结点的num数值都初始化
    for (int i = 1; i <= LEN; i++)
    {
        p2 = (LNode *)malloc(sizeof(LNode));
        p1->num = i;
        if (i == LEN) {
            p1->next = NULL;
        }
        else {
            p1->next = p2;
        }
        p1 = p2;
    }
    // 释放 p1 和 p2（因为最后一次循环结束后 p1 与 p2 应指向同一地址，所以只需要 free 任一即可）
    free(p1);
    p1 = p2 = NULL;

    /* 对链表某一结点数据域的编辑实现 */

    // 将p1指向链表首部
    p1 = head->next;
    // 遍历至链表某一结点，此处为链表的第五个结点
    for (int i = 1; i < 5; i++)
    {
        p1 = p1->next;
    }
    // 对该结点的数据域进行更改
    p1->num = 114514;

/* 对链表内结点的删除实现 */

    // 将p1指向链表首部
    p1 = head->next;
    // 遍历至链表某一结点的前驱，此处为链表的第六个结点的前驱，即第五个结点
    for (int i = 1; i < 5; i++)
    {
        p1 = p1->next;
    }
    // 将 p2 指向该结点的后驱结点来方便后续释放该结点
    p2 = p1->next;
    // 将该结点的指针域直接指向其后驱结点的后驱
    p1->next = p1->next->next;
    //释放p2
    free(p2);
    p2 = NULL;

    /* 向链表增添结点实现 */

    // 将p1指向链表首部
    p1 = head->next;
    // 遍历至链表某一结点，此处为链表的第五个结点
    for (int i = 1; i < 5; i++)
    {
        p1 = p1->next;
    }
    // 内存分配
    p2 = (LNode *)malloc(sizeof(LNode));
    p2->num = 1919810;
    // p2 的指针域指向 p1 的后驱
    p2->next = p1->next;
    // p1 的指针域指向 p2
    p1->next = p2;

    return 0;
}