#include <bits/stdc++.h>
using namespace std;

    int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB) {
        int n = temperatureA.size();
        vector<int> c1(n - 1), c2(n - 1);
        int cnt = 0, ans = 0;
        for(int i = 1; i < n; ++i) {
            if(temperatureA[i] > temperatureA[i - 1]) {
                c1[i - 1] = 1;
            } else if(temperatureA[i] < temperatureA[i - 1]) {
                c1[i - 1] = -1;
            } else {
                c1[i - 1] = 0;
            }
            if(temperatureB[i] > temperatureB[i - 1]) {
                c2[i - 1] = 1;
            } else if(temperatureB[i] < temperatureB[i - 1]) {
                c2[i - 1] = -1;
            } else {
                c2[i - 1] = 0;
            }
        }
        for(int i = 0; i < c1.size(); ++i) {
            if(c1[i] == c2[i]) {
                ++cnt;
            } else {
                cnt = 0;
            }
            ans = max(cnt, ans);
        }
        return ans;
    }

    int main() {
        vector<int> t1{21,18,18,18,31}, t2{34,32,16,16,17};
        cout << temperatureTrend(t1, t2);
        return 0;
    }