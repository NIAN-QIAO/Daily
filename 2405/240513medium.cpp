//https://leetcode.cn/problems/rotting-oranges/description/
// Created by PC on 2024/5/13.
//994. 腐烂的橘子
#include "iostream"
#include "vector"
using namespace std;
class Solution {
    int DIRECTIONS[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    int orangesRotting(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        int fresh = 0;
        vector<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    fresh++;
                } else if (grid[i][j] == 2) {
                    q.emplace_back(i, j);
                }
            }
        }
        int ans = -1;
        while (!q.empty()) {
            ans++;
            vector<pair<int, int>> nxt;
            for (auto &[x, y]: q) {
                for (auto d: DIRECTIONS) {
                    int i = x + d[0], j = y + d[1];
                    if (0 <= i && i < m && 0 <= j && j < n && grid[i][j] == 1) {
                        fresh--;
                        grid[i][j] = 2;
                        nxt.emplace_back(i, j);
                    }
                }
            }
            q = move(nxt);
        }
        return fresh ? -1 : max(ans, 0);
    }
};
int main() {
    cout << "  dsad" << endl;
}