#include "LC.h"

class LockingTree {
public:
    LockingTree(vector<int> &parent) {
        parents = std::move(parent);
        children = std::move(vector<vector<int>>(parents.size(), vector<int>()));
        for (int i = 0; i < parents.size(); ++i) {
            if (parents[i] == -1) continue;
            children[parents[i]].push_back(i);
        }
        lockBy = std::move(vector<int>(parents.size(), 0));
    }

    bool lock(int num, int user) {
        if (lockBy[num] != 0) {
            return false;
        }
        lockBy[num] = user;
        return true;
    }

    bool unlock(int num, int user) {
        if (lockBy[num] != user) {
            return false;
        }
        lockBy[num] = 0;
        return true;
    }

    bool upgrade(int num, int user) {
        if (lockBy[num]) {
            return false;
        }
        for (int i = parents[num]; i >= 0; i = parents[i]) {
            if (lockBy[i]) return false;
        }
        vector<int> lockList;
        for (int i: children[num]) {
            dfs(i, lockList);
        }
        if (lockList.empty()) {
            return false;
        }
        lockBy[num] = user;
        for (int i: lockList) {
            lockBy[i] = 0;
        }
        return true;
    }

private:
    void dfs(int num, vector<int> &lockList) {
        if (lockBy[num]) lockList.push_back(num);
        if (children[num].empty()) return;
        for (int i: children[num]) {
            dfs(i, lockList);
        }
    }

private:
    vector<int> parents;
    vector<vector<int>> children;
    vector<int> lockBy;
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */

int main() {
    vector<int> parent = {-1, 0, 0, 1, 1, 2, 2};
    auto obj = new LockingTree(parent);
    cout << boolalpha << obj->lock(4, 5) << endl;
    cout << boolalpha << obj->upgrade(0, 1) << endl;
}