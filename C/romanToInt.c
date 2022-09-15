#include <stdio.h>
#include <string.h>

int romanToInt(char * s) {
    int res = 0, len = strlen(s);
    // 字母转为数字作为数组下标，此处运用了哈希表思维。
    int map[26];
    map['I' - 'A'] = 1;
    map['V' - 'A'] = 5;
    map['X' - 'A'] = 10;
    map['L' - 'A'] = 50;
    map['C' - 'A'] = 100;
    map['D' - 'A'] = 500;
    map['M' - 'A'] = 1000;
    for(int i = 0; i < len; ++i) {
        int temp = map[s[i] - 'A'];
        // 这里 i < len - 1 是为了防止数组最末一位与无用数据进行错误判断。
        if(i < len - 1 && temp < map[s[i + 1] - 'A']) {
            res -= temp;
        } else {
            res += temp;
        }
    }
    return res;
}

int main(int argc, char **argv) {
    char str[16] = {"LVIII"};
    printf("%d", romanToInt(str));
    return 0;
}