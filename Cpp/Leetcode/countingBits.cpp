#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

int main(void) {
    int n = 5;
    vector<int> arr;
    for (int i = 0; i < n + 1; i++) {
        int count = 0;
        for(auto j : bitset<17>(i).to_string()) {
            if(j - 48)
                ++count;
        }
        arr.push_back(count);
    }
    return 0;
}