#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    if(n == 0) {
        int tmp = 0;
        cin >> tmp;
        cout << tmp;
        return 0;
    }
    vector<pair<string, string>> nums(n + 1);
    // flag代表是否 不!是! 真首位（忽略前导0）
    bool flag = false;

    for(int i = 0; i <= n; ++i) {
        string tmp = "";
        cin >> tmp;
        if(tmp[0] != '-' && tmp != "0" && tmp != "1" && flag) {
            nums[i].first = "+" + tmp;
            nums[i].second = to_string(n - i);
            continue;
        }
        // 若输入的数为-1且不为最后一位，则只存负号
        if(tmp == "-1" && i != n) {
            nums[i].first = "-";
            nums[i].second = to_string(n - i);
            flag = true;
            continue;
        }
        // 若输入的数为1，则只存负号 不过要加上首位判断flag
        if(tmp == "1") {
            if(flag) {
                nums[i].first = "+";
                nums[i].second = to_string(n - i);
            } else {
                nums[i].first = "";
                nums[i].second = to_string(n - i);
            }
            flag = true;
            continue;
        }
        if(tmp != "0") flag = true;
        nums[i].first = tmp;
        nums[i].second = to_string(n - i);
    }
    if(!flag) return 0;

    for(int i = 0; i < nums.size(); ++i) {
        // 系数为0直接遍历下一位
        if(nums[i].first == "0") continue;

        cout << nums[i].first;

        // 次数为0
        if(nums[i].second == "0") {
            if(nums[i].first == "+" || nums[i].first == "-") cout << "1";
            return 0;
        }
        // 次数为1
        if(nums[i].second == "1") {
            cout << "x";
            continue;
        }
        cout << "x^" << nums[i].second;
    }
    return 0;
}