/* https://leetcode.cn/problems/count-days-spent-together */
#include "LC.h"

int dtoi(string date) {
    int days = 0;
    for(int i = 1; i < stoi(date); ++i) {
        if(i == 2) {
            days += 28;
            continue;
        }
        if(i < 8) {
            if(i % 2) {
                days += 31;
            } else {
                days += 30;
            }
        } else {
            if(i % 2) {
                days += 30;
            } else {
                days += 31;
            }
        }
    }
    return days += stoi(date.substr(3, 2));
}

int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
    int aAlice = dtoi(arriveAlice), lAlice = dtoi(leaveAlice), aBob = dtoi(arriveBob), lBob = dtoi(leaveBob);
    if(max(aAlice, aBob) > min(lAlice, lBob)) return 0;
    return min(lAlice, lBob) - max(aAlice, aBob) + 1;
}

int main() {
    cout << countDaysTogether("08-15","08-18","08-16","08-19") << endl;
    return 0;
}