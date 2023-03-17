#include <bits/stdc++.h>
using namespace std;

    int minimizeXor(int num1, int num2) {
        int cnt1 = 0, cnt2 = 0;
        string str1, str2, str3(32, '0');
        bitset<32> bits2 = num2, bits1 = num1;
        str1 = bits1.to_string(), str2 = bits2.to_string();
        for(auto i : str1) {
            if(i == '1') ++cnt1;
        }
        for(auto i : str2) {
            if(i == '1') ++cnt2;
        }
        if(cnt1 == cnt2) return num1;
        if(cnt1 < cnt2) {
            for(int i = 0; i < str3.size(); ++i) {
                if(str1[i] == '1') {
                    str3[i] = '1';
                    --cnt2;
                }
            }
            for(int i = str3.size() - 1; i >= 0 && cnt2 > 0; --i) {
                if(str3[i] != '1') {
                    str3[i] = '1';
                    --cnt2;
                }
            }
            int ans = stoi(str3, nullptr, 2);
            return ans;
        }
        for(int i = 0; i < str3.size() && cnt2 > 0; ++i) {
            if(str1[i] == '1') {
                str3[i] = '1';
                --cnt2;
            }
        }
        return stoi(str3, nullptr, 2);
    }

int main() {
    cout << minimizeXor(1, 12);
    return 0;
}