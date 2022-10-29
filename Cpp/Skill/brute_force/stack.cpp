#include <bits/stdc++.h>
using namespace std;

stack<int> input, output;
int N = 4;

void dfs(int index, vector<int> &data) {
    if (index == N) {
        // 从全局中获取这两个栈
        stack<int> outtmp(output);
        stack<int> intmp(input);

        // 将input栈清空到output栈中
        while (intmp.size()) {
            int num = intmp.top();
            intmp.pop();
            outtmp.push(num);
        }

        // 为实现输出结果，需要先将output栈中元素输入到一个栈中，然后从该栈中输出，这样可以实现从栈底到栈顶的遍历
        // 为减少空间代价，这里选择的这个栈为input
        while (outtmp.size()) {
            intmp.push(outtmp.top());
            outtmp.pop();
        }

        while (intmp.size()) {
            cout << intmp.top() << " ";
            intmp.pop();
        }
        cout << endl;
        return ;
    }
    // 栈不为空，先选择出栈
    if (input.size()) {
        int num = input.top();
        input.pop();
        output.push(num);      
        dfs(index, data);
        output.pop();
        input.push(num);
    }
    
    //然后选择入栈
    input.push(data[index]);
    dfs(index + 1, data);
    input.pop();
}

int main() {
    vector<int> data{1, 2, 3, 4};
    dfs(0, data);
    return 0;
}