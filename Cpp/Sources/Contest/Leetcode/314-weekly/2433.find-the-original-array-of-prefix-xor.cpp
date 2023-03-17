#include <bits/stdc++.h>
using namespace std;

    vector<int> findArray(vector<int>& pref) {
        vector<int> ans{pref[0]};
        for(int i = 1; i < pref.size(); ++i) {
            ans.push_back((pref[i] ^ pref[i - 1]));
        }
        return ans;
    }

int main() {
    vector<int> pref{5,2,0,3,1};
    for(auto i : findArray(pref)) {
        cout << i << " ";
    }
    return 0;
}
