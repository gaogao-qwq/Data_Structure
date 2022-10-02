#include <bits/stdc++.h>
using namespace std;

class LUPrefix {
public:
    LUPrefix(int n) {
        videos.resize(n);
    }
    
    void upload(int video) {
        ++videos[video - 1];
    }
    
    int longest() {
        for(int i = length; i < videos.size(); ++i) {
            if(videos[i] == 0) {
                break;
            }
            ++length;
        }
        return length;
    }
private:
    int length = 0;
    vector<int> videos;
};

int main() {
    auto server = new LUPrefix(4);
    server->upload(3);                    // 上传视频 3 。
    server->longest();                    // 由于视频 1 还没有被上传，最长上传前缀是 0 。
    server->upload(1);                    // 上传视频 1 。
    server->longest();                    // 前缀 [1] 是最长上传前缀，所以我们返回 1 。
    server->upload(2);                    // 上传视频 2 。
    server->longest();                    // 前缀 [1,2,3] 是最长上传前缀，所以我们返回 3 。
    return 0;
}