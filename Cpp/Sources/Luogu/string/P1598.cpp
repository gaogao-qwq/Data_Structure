#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
    int cnt[26] = {};
    for (int i = 0; i < 4; ++i) {
        char str[100];
		std::getline(std::cin, str);
        int n = strlen(str);
        for (int i = 0; i < n; ++i) {
            if (str[i] >= 'A' && str[i] <= 'Z') ++cnt[str[i] - 'A'];
        }
    }
    int m = INT32_MIN;
    for (int i = 0; i < 26; ++i) {
        m = max(cnt[i], m);
    }
    for (int i = m; i > 0; --i) {
        for (int j = 0; j < 26; ++j) {
            if (j == 25 && cnt[j] >= i) {
                printf("*\n");
                continue;
            }
            if (j == 25 && cnt[j] != i) {
                printf(" \n");
                continue;
            }
            if (cnt[j] >= i) {
                printf("* ");
                continue;
            }
            printf("  ");
        }
    }
    printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");
    
    return 0;
}
