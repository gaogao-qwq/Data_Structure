#include <bits/stdc++.h>
using namespace std;

// WA
    void findO(vector<int> &loc, vector<string> plate);
    vector<int> up(int step, int num, vector<int> loc, vector<string> plate);
    vector<int> down(int step, int num, vector<int> loc, vector<string> plate);
    vector<int> left(int step, int num, vector<int> loc, vector<string> plate);
    vector<int> right(int step, int num, vector<int> loc, vector<string> plate);


    void findO(vector<int> &loc, vector<string> plate) {
        int n = plate.size(), m = plate[0].size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(plate[i][j] == 'O') {
                    loc[0] = i, loc[1] = j;
                    return;
                }
            }
        }
    }

    vector<int> up(int step, int num, vector<int> loc, vector<string> plate) {
        if(step > num) return {};
        if(loc[0] - 1 < 0 && plate[loc[0]][loc[1]] == '.') {
            if(loc[1] != 0 && loc[1] != plate[0].size() - 1) {
                return loc;
            }
            return {};
        }
        --loc[0];
        step += 1;
        if(plate[loc[0]][loc[1]] == '.') {
            if(up(step, num, loc, plate) != *(new vector<int>)) {
                return up(step, num, loc, plate);
            }
            return {};
        }
        if(plate[loc[0]][loc[1]] == 'E') {
            if(left(step, num, loc, plate) != *(new vector<int>)) {
                return left(step, num, loc, plate);
            }
            return {};
        }
        if(plate[loc[0]][loc[1]] == 'W') {
            if(right(step, num, loc, plate) != *(new vector<int>)) {
                return right(step, num, loc, plate);
            }
            return {};
        }
        return {};
    }

    vector<int> down(int step, int num, vector<int> loc, vector<string> plate) {
        if(step > num) return {};
        if(loc[0] + 1 >= plate.size() && plate[loc[0]][loc[1]] == '.') {
            if(loc[1] != 0 && loc[1] != plate[0].size() - 1) {
                return loc;
            }
            return {};
        }
        ++loc[0];
        step += 1;
        if(plate[loc[0]][loc[1]] == '.') {
            if(down(step, num, loc, plate) != *(new vector<int>)) {
                return down(step, num, loc, plate);
            }
            return {};
        }
        if(plate[loc[0]][loc[1]] == 'E') {
            if(right(step, num, loc, plate) != *(new vector<int>)) {
                return right(step, num, loc, plate);
            }
            return {};
        }
        if(plate[loc[0]][loc[1]] == 'W') {
            if(left(step, num, loc, plate) != *(new vector<int>)) {
                return left(step, num, loc, plate);
            }
            return {};
        }
        return {};
    }

    vector<int> left(int step, int num, vector<int> loc, vector<string> plate) {
        if(step > num) return {};
        if(loc[1] - 1 < 0 && plate[loc[0]][loc[1]] == '.') {
            if(loc[0] != 0 && loc[0] != plate.size() - 1) {
                return loc;
            }
            return {};
        }
        --loc[1];
        step += 1;
        if(plate[loc[0]][loc[1]] == '.') {
            if(left(step, num, loc, plate) != *(new vector<int>)) {
                return left(step, num, loc, plate);
            }
            return {};
        }
        if(plate[loc[0]][loc[1]] == 'E') {
            if(down(step, num, loc, plate) != *(new vector<int>)) {
                return down(step, num, loc, plate);
            }
            return {};
        }
        if(plate[loc[0]][loc[1]] == 'W') {
            if(right(step, num, loc, plate) != *(new vector<int>)) {
                return right(step, num, loc, plate);
            }
            return {};
        }
        return {};
    }

    vector<int> right(int step, int num, vector<int> loc, vector<string> plate) {
        if(step > num) return {};
        if(loc[1] + 1 >= plate[0].size() && plate[loc[0]][loc[1]] == '.') {
            if(loc[0] != 0 && loc[0] != plate.size() - 1) {
                return loc;
            }
            return {};
        }
        ++loc[1];
        step += 1;
        if(plate[loc[0]][loc[1]] == '.') {
            if(left(step, num, loc, plate) != *new vector<int>) {
                return left(step, num, loc, plate);
            }
            return {};
        }
        if(plate[loc[0]][loc[1]] == 'E') {
            if(down(step, num, loc, plate) != *new vector<int>) {
                return down(step, num, loc, plate);
            }
            return {};
        }
        if(plate[loc[0]][loc[1]] == 'W') {
            if(right(step, num, loc, plate) != *new vector<int>) {
                return right(step, num, loc, plate);
            }
            return {};
        }
        return {};
    }

    vector<vector<int>> ballGame(int num, vector<string>& plate) {
        int n = plate.size(), m = plate[0].size(), step = 0;
        if(n <= 2 && m <= 2) return {};
        vector<vector<int>> ans{}, res{};
        vector<int> loc(2);
        findO(loc, plate);
        ans.push_back(up(step, num, loc, plate));
        ans.push_back(down(step, num, loc, plate));
        ans.push_back(left(step, num, loc, plate));
        ans.push_back(right(step, num, loc, plate));
        for(int i = 0; i < ans.size(); ++i) {
            if(ans[i] == *(new vector<int>)) {
                ans.erase(ans.begin() + i);
                --i;
            }
        }
        return ans;
    }

    int main() {
        vector<string> plate{"..E.",".EOW","..W."};
        vector<vector<int>> ans = ballGame(4, plate);
        return 0;
    }