/* https://leetcode.cn/problems/capitalize-the-title/ */
#include <iostream>
using namespace std;

string capitalizeTitle(string title) {
    int j = 1, first = 0;
    for(int i = 0; i < title.size(); ++i) {
        if(title[i] == ' ') {
            j = 0;
            first = i + 1;
        }
        if(j <= 2 && title[first] >= 'A' && title[first] <= 'Z') {
            title[first] += ('a' - 'A');
        }
        if(j > 2 && title[first] >= 'a' && title[first] <= 'z') {
            title[first] -= ('a' - 'A');
        }
        if(j > 1 && title[i] >= 'A' && title[i] <= 'Z') {
            title[i] += ('a' - 'A');
        }
        ++j;
    }
    return title;
}

int main(void) {
    string s = "First leTTeR of EACH Word";
    string res = capitalizeTitle(s);
    cout << res << endl;
    return 0;
}
