#include "LC.h"

    bool checkAlmostEquivalent(string word1, string word2) {
        // 只有26个小写字母 数组模拟哈希表即可
        vector<int> map(26, 0);
        for(int i = 0; i < word1.size(); ++i) {
            map[word1[i] - 'a']++;
            map[word2[i] - 'a']--;
        }
        for(auto i : map) {
            if(abs(i) > 3) return false;
        }
        return true;
    }

int main() {
    cout << boolalpha << checkAlmostEquivalent("aaan", "baaa");
    return 0;
}