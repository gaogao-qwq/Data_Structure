/* https://leetcode.cn/problems/check-if-it-is-a-straight-line/ */
#include "LC.h"

bool checkStraightLine(vector<vector<int>>& coordinates) {
    if(coordinates.size() == 2) return true;
    for(auto i = coordinates.begin() + 2; i != coordinates.end(); ++i) {
        if( (coordinates[1][1] - coordinates[0][1]) * ((*i)[0] - coordinates[0][0]) != ((*i)[1] - coordinates[0][1]) * (coordinates[1][0] - coordinates[0][0]) ) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<vector<int>> coordinates{{0,0},{0,1},{0,-1}};
    cout << checkStraightLine(coordinates);
    return 0;
}
