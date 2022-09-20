#include "LC.h"

vector<int> getRow(int rowIndex) {
    if(rowIndex == 0) return {1};
    if(rowIndex == 1) return {1,1};
    vector<int> temp{1,1};
    vector<int> ans;
    for(int i = 1; i < rowIndex; ++i) {
        ans.resize(i + 2);
        for(int j = 0; j < i + 2; ++j) {
            if(j == 0 || j == i + 1) {
                ans[j] = 1;
                continue;
            }
            ans[j] = temp[j - 1] + temp[j];
        }
        temp = ans;
    }
    return ans;
}

int main() {
    for(auto i : getRow(3)) {
        cout << i << " ";
    }
    return 0;
}