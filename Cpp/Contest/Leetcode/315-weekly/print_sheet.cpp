#include <bits/stdc++.h>
using namespace std;

ofstream OutFile("Test.txt");

int main() {
    unordered_set<int> uset;
    for (int i = 0; i <= 1e5; ++i) {
        int sum = i;
        string s = to_string(i);
        reverse(s.begin(), s.end());
        sum += stoi(s);
        if (uset.find(sum) == uset.end()) {
            uset.emplace(sum);
        }
    }
    for (auto i : uset) {
        OutFile << i << ", ";
    }
    return 0;
}