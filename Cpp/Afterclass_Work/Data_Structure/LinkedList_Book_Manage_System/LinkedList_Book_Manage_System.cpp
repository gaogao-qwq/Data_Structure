#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

// 书类型定义
typedef struct {
    string ISBN;  // ISBN
    string name;  // 书名
    double price; // 价格
} Book;

// 双链表结点类型定义
typedef struct LinkedList {
    Book book;
    LinkedList *next{};
    LinkedList *prev{};
} LinkedNode;

// 定义一个全局变量 len 用于存储链表长度
int len = 0;

// 表创建函数
LinkedNode *create();
// 菜单函数
void menu();
// 菜单选项函数
void choice(LinkedNode *head);
// 表取值函数
bool getValue(LinkedNode *head);
// 表打印函数
bool print(LinkedNode *head);
// 重载表打印函数用于打印指定行数据
bool print(LinkedNode *head, int row);
// 表搜索函数
bool searchMenu(LinkedNode *head);
bool searchISBN(LinkedNode *head);
bool searchName(LinkedNode *head);
bool searchPrice(LinkedNode *head);
// 表插入函数
LinkedNode *insertNode(LinkedNode *head);
// 表删除函数
LinkedNode *deleteNode(LinkedNode *head);


void menu() {
    cout << "1. 取值\n";
    cout << "2. 查找\n";
    cout << "3. 插入\n";
    cout << "4. 删除\n";
    cout << "5. 打印\n";
    cout << "0. 退出\n";
}

void choice(LinkedNode *head) {
    while(true) {
        menu();

        int choice = -1;
        cout << "请输入选项：";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                if(!getValue(head)) {
                    cout << "取值失败！" << endl << endl;
                } else {
                    cout << "取值成功！" << endl << endl;
                }
                break;
            case 2:
                if(!searchMenu(head)) {
                    cout << "搜索失败！" << endl << endl;
                } else {
                    cout << "搜索成功！" << endl << endl;
                }
                break;
            case 3:
                head = insertNode(head);
                break;
            case 4:
                head = deleteNode(head);
                break;
            case 5:
                if(!print(head)) {
                    cout << "打印失败！" << endl << endl;
                } else {
                    cout << "打印成功！" << endl << endl;
                }
                break;
            case 0:
                return;
            default:
                cout << "无效的输入";
                break;
        }
    }
}

bool getValue(LinkedNode *head) {
    if(!print(head)) {
        return false;
    }

    int row = 0;
    do {
        cout << "请输入想取值的行号：";
        cin >> row;
    } while(row > len);
    cout << endl;

    auto p = head;
    for(int i = 1; i < row; ++i) {
        p = p->next;
    }
    cout << left << setw(3)  << "行标"  << "\t"
         << left << setw(20) << "ISBN" << "\t"
         << left << setw(50) << "书名"  << "\t"
         << left << setw(5)  << "价格"  << endl
         << left << setw(3)  << row << "\t"
         << left << setw(20) << p->book.ISBN  << "\t"
         << left << setw(50) << p->book.name  << "\t"
         << left << setw(5)  << p->book.price << endl;
    return true;
}

bool print(LinkedNode *head) {
    if(head == nullptr) {
        cout << "表为空表，请重启程序并重新创建表。" << endl;
        return false;
    }

    auto p = head;

    cout << left << setw(3)  << "行标"  << "\t"
         << left << setw(20) << "ISBN" << "\t"
         << left << setw(50) << "书名"  << "\t"
         << left << setw(5)  << "价格"  << endl;
    for(int i = 1; i <= len; ++i) {
        cout << left << setw(3)  << i << "\t"
             << left << setw(20) << p->book.ISBN  << "\t"
             << left << setw(50) << p->book.name  << "\t"
             << left << setw(5)  << p->book.price << endl;
        p = p->next;
    }

    return true;
}

bool print(LinkedNode *head, int row) {
    if(head == nullptr) {
        cout << "表为空表，请重启程序并重新创建表。" << endl;
        return false;
    }
    if(row < 1 || row > len) {
        cout << "行号超界" << endl;
        return false;
    }

    auto p = head;

    for(int i = 1; i < row; ++i) {
        p = p->next;
    }

    cout << left << setw(3)  << "行标"  << "\t"
         << left << setw(20) << "ISBN" << "\t"
         << left << setw(50) << "书名"  << "\t"
         << left << setw(5)  << "价格"  << endl
         << left << setw(3)  << row << "\t"
         << left << setw(20) << p->book.ISBN  << "\t"
         << left << setw(50) << p->book.name  << "\t"
         << left << setw(5)  << p->book.price << endl;

    return true;
}

bool searchMenu(LinkedNode *head) {
    int choice = -1;
    cout << "1. 按 ISBN 查找\n";
    cout << "2. 按书名查找\n";
    cout << "3. 按价格查找\n";
    cout << "0. 退出\n";
    cout << "请输入选项：";
    cin >> choice;
    cout << endl;
    switch (choice) {
        case 1:
            if(!searchISBN(head)) {
                return false;
            }
            break;
        case 2:
            if(!searchName(head)) {
                return false;
            }
            break;
        case 3:
            if(!searchPrice(head)) {
                return false;
            }
            break;
        case 0:
            break;
        default:
            cout << "无效的输入" << endl;
    }
    return true;
}

bool searchISBN(LinkedNode *head) {
    bool flag = false;
    auto p = head;
    string ISBN;

    cout << "请输入你想查询的ISBN：";
    cin >> ISBN;

    for(int i = 1; i <= len; ++i) {
        if(p->book.ISBN == ISBN) {
            if(!print(head, i)) {
                return false;
            }
            flag = true;
        }
        p = p->next;
    }

    if(flag) {
        return true;
    }
    cout << "未找到值" << endl;
    return false;
}

bool searchName(LinkedNode *head) {
    bool flag = false;
    auto p = head;
    string name;

    cout << "请输入你想查询的书名：";
    cin >> name;

    for(int i = 1; i <= len; ++i) {
        if(p->book.name == name) {
            if(!print(head, i)) {
                return false;
            }
            flag = true;
        }
        p = p->next;
    }

    if(flag) {
        return true;
    }
    cout << "未找到值" << endl;
    return false;
}

bool searchPrice(LinkedNode *head) {
    bool flag = false;
    auto p = head;
    int price = 0;

    cout << "请输入你想查询的价格：";
    cin >> price;

    for(int i = 1; i <= len; ++i) {
        if(p->book.price == price) {
            if(!print(head, i)) {
                return false;
            }
            flag = true;
        }
        p = p->next;
    }

    if(flag) {
        return true;
    }
    cout << "未找到值" << endl;
    return false;
}

LinkedNode *insertNode(LinkedNode *head) {
    auto p = head;
    int row = 0;
    if(!print(head)) {
        return head;
    }

    do {
        cout << "请输入想插入的行号：";
        cin >> row;
    } while (row < 1 || row > len);

    if(row == 1) {
        cout << "你输入的行号为1，请选择前插或后插（输入1前插，默认后插）：";
        int choice = 0;
        cin >> choice;
        cout << endl;
        if(choice == 1) {
            auto temp = new LinkedNode;

            temp->prev = nullptr;
            temp->next = head;
            head->prev = temp;

            cout << "请输入第" << row << "本书的信息（ISBN 书名 价格，以空格分隔）：";
            cin >> temp->book.ISBN >> temp->book.name >> temp->book.price;
            cout << endl <<endl;

            ++len;
            head = temp;
            return head;
        }
    }

    for(int i = 1; i < row; ++i) {
        p = p->next;
    }

    auto temp = new LinkedNode;

    temp->next = p->next;
    temp->prev = p;
    p->next->prev = temp;
    p->next = temp;

    cout << "请输入第" << row << "本书的信息（ISBN 书名 价格，以空格分隔）：";
    cin >> temp->book.ISBN >> temp->book.name >> temp->book.price;
    cout << endl <<endl;

    ++len;
    return head;
}

LinkedNode *deleteNode(LinkedNode *head) {
    auto p = head;
    int row = 0;
    if(!print(head)) {
        return head;
    }

    do {
        cout << "请输入想删除的行号：";
        cin >> row;
        cout << endl <<endl;
    } while (row < 1 || row > len);

    // 对头结点特殊处理
    if(row == 1) {
        delete(head);
        p = p->next;
        p->prev = nullptr;
        head = p;
        --len;
        return head;
    }

    // 对尾结点特殊处理
    if(row == len) {
        // 遍历至尾结点前驱
        for (int i = 1; i < row - 1; ++i) {
            p = p->next;
        }
        auto temp = p->next;
        delete(temp);
        temp = nullptr;
        p->next = nullptr;
        --len;
        return head;
    }

    // 遍历至要删除节点的前驱
    for(int i = 1; i < row - 1; ++i) {
        p = p->next;
    }
    p->next->next->prev = p;
    auto temp = p->next;
    delete(temp);
    temp = nullptr;
    p->next = p->next->next;
    --len;
    return head;
}

LinkedNode *create() {
    auto head = new LinkedNode;
    auto p = head;

    head->prev = nullptr; // 头结点前向指针置空。

    do {
        cout << "请输入书本数量（1 < len < 2^32）：";
        cin >> len;
        cout << endl;
    }while(len < 1);
    cout << endl;

    for (int i = 0; i < len; ++i) {
        cout << "请输入第" << i + 1 << "本书的信息（ISBN 书名 价格，以空格分隔）：";
        cin >> p->book.ISBN >> p->book.name >> p->book.price;
        cout << endl;
        p->next = new LinkedNode;
        p->next->prev = p;
        p = p->next;
    }
    p->next = nullptr;
    cout << endl;
    return head;
}

int main() {
    LinkedNode *head = create();
    choice(head);
    return 0;
}