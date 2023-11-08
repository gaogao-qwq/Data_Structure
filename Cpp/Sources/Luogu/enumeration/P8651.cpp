#include <bits/stdc++.h>
using namespace std;

const int arrange[3][3] = {{0, 1, 2},
                           {2, 1, 0},
                           {2, 0, 1}};
const int days_leap[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string s;
vector<string> ans, date;
unordered_set<string> uset;

int main(int argc, char *argv[]) {
    cin >> s;
    date = {s.substr(0, 2),
           s.substr(3, 2),
           s.substr(6, 2)};
    for (auto a : arrange) {
        string year = date[a[0]], month = date[a[1]], day = date[a[2]];
        int yearn = stoi(year), monthn = stoi(month), dayn = stoi(day);
        if (monthn <= 12 && monthn && dayn <= (yearn % 4 ? days[monthn] : days_leap[monthn]) && dayn) {
            stringstream ss;
            yearn >= 60
                ? ss << "19" << year << '-' + month << '-' + day
                : ss << "20" << year << '-' + month << '-' + day;
            if(!uset.contains(ss.str())) {
                ans.emplace_back(ss.str());
                uset.emplace(ss.str());
            }
        }
    }
    std::sort(ans.begin(), ans.end());
    for (const auto &i : ans) {
        cout << i << endl;
    }
}