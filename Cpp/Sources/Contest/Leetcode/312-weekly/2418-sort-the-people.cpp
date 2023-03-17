#include <bits/stdc++.h>
using namespace std;

    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        for(int i = 1; i < heights.size(); ++i) {
            int key = heights[i];
            string tmp = names[i];
            int j = i - 1;
            while((j >= 0) && (key > heights[j])) {
                heights[j + 1] = heights[j];
                names[j + 1] = names[j];
                j--;
            }
            heights[j + 1] = key;
            names[j + 1] = tmp;
        }
        return names;
    }

int main() {
    vector<string>names{"Alice","Bob","Bob"};
    vector<int> heights{155,185,150};
    names = sortPeople(names, heights);
    return 0;
}