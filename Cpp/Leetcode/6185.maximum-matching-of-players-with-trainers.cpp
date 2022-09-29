/* https://leetcode.cn/problems/maximum-matching-of-players-with-trainers */
#include "LC.h"

int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
    int cnt = 0;
    sort(players.begin(), players.end());
    sort(trainers.begin(), trainers.end());
    for(int i = 0, j = i; i < players.size() && j < trainers.size();) {
        if(players[i] <= trainers[j]) {
            ++i, ++j;
            ++cnt;
        } else {
            ++j;
        }
    }
    return cnt;
}

int main() {
    vector<int> players{4,7,9}, trainers{8,2,5,8};
    cout << matchPlayersAndTrainers(players, trainers);
    return 0;
}