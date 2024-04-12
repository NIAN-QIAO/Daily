//
// Created by PC on 2024/4/12.
//
//2923. 找到冠军 I
//https://leetcode.cn/problems/find-champion-i/description/
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int findChampion(vector<vector<int>> &grid) {
        vector<int> res(grid.size());
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = i + 1; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1)
                    res[i]++;
                else
                    res[j]++;
            }
        }
        int ans = res[0], index = 0;
        for (int i = 1; i < res.size(); ++i) {
            if (ans < res[i]) {
                ans = res[i];
                index = i;
            }
        }
        return index;
    }
};

int main() {
//    vector<vector<int>> grid = {{0, 0, 1},
//                                {1, 0, 1},
//                                {0, 0, 0}};
    vector<vector<int>> grid = {{0, 1},
                                {0, 0}};
    Solution test;
    cout << test.findChampion(grid);
}




//写在解题后：横看成岭侧成峰