#include <bits/stdc++.h>
using namespace std;

    int hardestWorker(int n, vector<vector<int>> &logs) {
        int startTime = 0, maxTime = 0, ans = 501;
        vector<int> index;
        for(int i = 0; i < logs.size(); ++i) {
            if(logs[i][1] - startTime > maxTime) {
                maxTime = logs[i][1] - startTime;
            }
            startTime = logs[i][1];
        }
        startTime = 0;
        for(int i = 0; i < logs.size(); ++i) {
            if(logs[i][1] - startTime == maxTime) {
                index.push_back(i);
            }
            startTime = logs[i][1];
        }
        for(auto i : index) {
            ans = min(logs[i][0], ans);
        }
        return ans;
    }

int main() {
    return 0;
}