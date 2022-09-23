#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100 // 顺序表可能达到的最大长度

typedef struct {
    int row;
    string no;    // ISBN
    string name;  // 书名
    double price; // 价格
} Book;

typedef struct {
    vector<Book> elem; // 人生苦短，我用STL。
    int length;        // 当前长度
} SqList;

void menu();
SqList InitList_Sq();
int Create_Sq(SqList &L);
int Delete(SqList &L);
int Insert(SqList &L);
int Display(SqList L);
int Display(SqList L, int row);
int getValue(SqList L);
int searchMenu(SqList L);
    int searchISBN(SqList L);
    int searchName(SqList L);
    int searchPrice(SqList L);

// 表初始化函数
SqList InitList_Sq() {
    SqList *L = new SqList;
    L->elem.resize(MAXSIZE);
    if(!L->elem.capacity()) {
        exit(OVERFLOW);
    }
    L->length = 0;
    for(int i = 0; i < MAXSIZE; ++i) {
        L->elem[i].row = i + 1;
    }
    return *L;
}

// 表输入函数
int Create_Sq(SqList &L) {
    cout << "请输入图书数量（不得超过100）：";
    cin >> L.length;
    if(L.length > MAXSIZE) {
        cout << "数量不能超过" << MAXSIZE << endl;
        return ERROR;
    } else {
        for(int i = 0; i < L.length; i++) {
            cout << "请输入第" << i + 1 << "本书的信息，包括：书号 书名 价格（用空格隔开）：";
            cin >> L.elem[i].no >> L.elem[i].name >> L.elem[i].price;
        }
    }
    return OK;
}

// 表打印函数
int Display(SqList L) {
    if(!L.length) {
        cout << "当前表为空表，请先输入元素。" << endl << endl;
        return ERROR;
    }

    cout << "当前图书系统信息（顺序表）读出：" << endl
         << left << setw(3)  << "行标" << "\t"
         << left << setw(20) << "ISBN" << "\t"
         << left << setw(50) << "书名" << "\t"
         << left << setw(5)  << "价格" << endl;

    for(int i = 0; i < L.length; i++) {
        cout << left << setw(3) << L.elem[i].row   << "\t"
             << left << setw(20) << L.elem[i].no   << "\t"
             << left << setw(50) << L.elem[i].name << "\t"
             << left << setw(5) << L.elem[i].price << endl;
    }
    cout << endl;

    return OK;
}

// 重载表打印函数用于打印特定某行元素
int Display(SqList L, int row) {
    if(!L.length) {
        cout << "当前表为空表，请先输入元素。" << endl << endl;
        return ERROR;
    }

    cout << "当前图书系统信息第" << row << "行读出：" << endl
         << left << setw(3)  << "行标" << "\t"
         << left << setw(20) << "ISBN" << "\t"
         << left << setw(50) << "书名" << "\t"
         << left << setw(5)  << "价格" << endl
         << left << setw(3)  << L.elem[row - 1].row   << "\t"
         << left << setw(20) << L.elem[row - 1].no    << "\t"
         << left << setw(50) << L.elem[row - 1].name  << "\t"
         << left << setw(5)  << L.elem[row - 1].price << endl << endl;

    return OK;
}

// 表搜索菜单函数
int searchMenu(SqList L) {
    int choice = -1;

    if(!Display(L)) {
        return ERROR;
    }

    cout << "1. ISBN" << endl
         << "2. 书名" << endl
         << "3. 价格" << endl
         << "0. 退出" << endl
         << "请输入要按什么查找：";
    cin >> choice;

    // 一拖十这个 switch 语句写的，懒得改了就这样吧。
    switch (choice) {
    case 1:
        if(!searchISBN(L)) {
            cout << "查找失败！" << endl << endl;
            return ERROR;
        }
        cout << "查找成功！" << endl << endl;
        return OK;
    case 2:
        if(!searchName(L)) {
            cout << "查找失败！" << endl << endl;
            return ERROR;
        }
        cout << "查找成功！" << endl << endl;
        return OK;
    case 3:
        if(!searchPrice(L)) {
            cout << "查找失败！" << endl << endl;
            return ERROR;
        }
        cout << "查找成功！" << endl << endl;
        return OK;
    case 0:
        return OK;
    default:
        cout << "无效的选择" << endl << endl;
        return ERROR;
    }

    return ERROR;
}

/* 面向复制粘贴编程，虽然写重载可以更亲用户代码可读性也更高，但我懒得写重载。 */

// 按 ISBN 查找函数
int searchISBN(SqList L) {
    int count = 0;
    string ISBN = "";
    cout << "请输入要查找的 ISBN：";
    cin >> ISBN;
    for(int i = 0; i < L.elem.size(); ++i) {
        if(L.elem[i].no == ISBN) {
            Display(L, i + 1);
            ++count;
        }
    }
    if(!count) {
        return ERROR;
    }
    cout << "共找到" << count << "本符合搜索条件的书" << endl;
    return OK;
}

// 按书名查找函数
int searchName(SqList L) {
    int count = 0;
    string name = "";
    cout << "请输入要查找的书名：";
    cin >> name;
    for(int i = 0; i < L.elem.size(); ++i) {
        if(L.elem[i].name == name) {
            Display(L, i + 1);
            ++count;
        }
    }
    if(!count) {
        return ERROR;
    }
    cout << "共找到" << count << "本符合搜索条件的书" << endl;
    return OK;
}

// 按价格查找函数
int searchPrice(SqList L) {
    int count = 0;
    double price = 0;
    cout << "请输入要查找的价格：";
    cin >> price;
    for(int i = 0; i < L.elem.size(); ++i) {
        if(L.elem[i].price == price) {
            Display(L, i + 1);
            ++count;
        }
    }
    if(!count) {
        return ERROR;
    }
    cout << "共找到" << count << "本符合搜索条件的书" << endl;
    return OK;
}


//表插入函数
int Insert(SqList &L) {
    int choice = -1;
    int row = 0;
    if(!Display(L)) {
        return ERROR;
    }
    
    if(L.length >= 100) {
        cout << "表长度已达最大值（100），请先删除元素后进行插入。" << endl;
        return ERROR;
    }

    cout << "请输入想插入的行标（默认尾插）：";
    cin >> row;

    if(row < 1 || row > L.length) {
        cout << "行标越界" << endl;
        return ERROR;
    }

    if(row == 1) {
        cout << "你输入的行标为第一行，请选择插入位置：" << endl
             << "1. 头插" << endl
             << "2. 尾插（默认）" << endl;
        cin >> choice;
        if(choice == 1) {
            for(int i = L.length; i > 0; --i) {
                L.elem[i] = L.elem[i - 1];
                ++L.elem[i].row;
            }
            cout << "请输入第" << row << "本书的信息，包括：书号 书名 价格（用空格隔开）：";
            cin >> L.elem[row - 1].no >> L.elem[row - 1].name >> L.elem[row - 1].price;
            ++L.length;
            return OK;
        }
    }

    for(int i = L.length; i > row + 1; --i) {
        L.elem[i] = L.elem[i - 1];
        ++L.elem[i].row;
    }
    cout << "请输入第" << row + 1 << "本书的信息，包括：书号 书名 价格（用空格隔开）：";
    cin >> L.elem[row].no >> L.elem[row].name >> L.elem[row].price;
    ++L.length;
    return OK;
}

// 表删除函数
int Delete(SqList &L) {
    int row = 0;

    if(!Display(L)) {
        return ERROR;
    }

    cout << "请输入想删除的行标：";
    cin >> row;

    if(row > L.length || row < 1) {
        cout << "行标越界" << endl;
        return ERROR;
    }

    if(row == L.length) {                      // 对于末行
        L.elem[row - 1].name = "";
        L.elem[row - 1].no = "";
        L.elem[row - 1].price = 0;
        --L.length;
        return OK;
    } else {                                    // 对于非末行
        for(int i = row - 1; i < L.length; ++i) {
            L.elem[i].name = L.elem[i + 1].name;
            L.elem[i].no = L.elem[i + 1].no;
            L.elem[i].price = L.elem[i + 1].price;
        }
        --L.length;
        return OK;
    }

    return ERROR;
}

// 表取值函数
int getValue(SqList L) {
    int row = 0;

    if(!Display(L)) {
        return ERROR;
    }

    cout << "请输入想取值的行标：";
    cin >> row;

    if(row < 1 || row > L.length) {
        cout << "行标越界" << endl;
        return ERROR;
    }

    Display(L, row);
    return OK;
}

void menu() {
    cout << "1. 输入\n";
    cout << "2. 取值\n";
    cout << "3. 查找\n";
    cout << "4. 插入\n";
    cout << "5. 删除\n";
    cout << "6. 打印\n";
    cout << "0. 退出\n";
}

int main(int argc, char *argv[]) {
    SqList L = InitList_Sq();
    int choose = -1;
    while (true) {
        menu();
        cout << "请选择:";
        cin >> choose;
        switch (choose) {
        case 1:
            if(!Create_Sq(L)) {
                cout << "顺序表输入元素失败" << endl << endl;
                break;
            }
            cout << "顺序表输入元素成功" << endl << endl;
            break;
        case 2:
            if(!getValue(L)) {
                cout << "顺序表取值失败" << endl << endl;
                break;
            }
            break;
        case 3:
            if(!searchMenu(L)) {
                cout << "顺序表搜索失败" << endl << endl;
                break;
            }
            break;
        case 4:
            if(!Insert(L)) {
                cout << "顺序表插入元素失败" << endl << endl;
                break;
            }
            cout << "顺序表插入元素成功" << endl << endl;
            break;
        case 5:
            if(!Delete(L)) {
                cout << "删除顺序表元素失败" << endl << endl;
                break;
            }
            cout << "删除顺序表元素成功" << endl << endl;
            break;
        case 6:
            Display(L);
            break;
        case 0:
            exit(0);
        default:
            cout << "无效输入！" << endl;
            break;
        }
    }
    return 0;
}
