#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int _min = INT_MAX, ans = -1;
        for (int i = 0; i < points.size(); ++i) {
            if ((points[i][0] == x || points[i][1] == y) && abs(points[i][0] - x) + abs(points[i][1] - y) < _min)
                ans = i, _min = abs(points[i][0] - x) + abs(points[i][1] - y);
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> points{{1,2},{3,1},{2,4},{2,3},{4,4}};
    Solution s;
    cout << s.nearestValidPoint(3, 4, points);
    return 0;
}