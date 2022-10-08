#include "LC.h"

    // dfs
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
        int color = image[sr][sc], R = image.size(), C = image[0].size();
        if(color == newColor) return image;
        function<void(int, int)> dfs = [&](int r, int c) -> void {
            if(image[r][c] == color) {
                image[r][c] = newColor;
                if(r >= 1) {
                    dfs(r - 1, c);
                }
                if(r + 1 < R) {
                    dfs(r + 1, c);
                }
                if(c >= 1) {
                    dfs(r, c - 1);
                }
                if(c + 1 < C) {
                    dfs(r, c + 1);
                }
            }
        };
        dfs(sr, sc);
        return image;
    }

int main() {
    vector<vector<int>> image{{1,1,1},{1,1,0},{1,0,1}};
    image = floodFill(image, 1, 1, 2);
    return 0;
}