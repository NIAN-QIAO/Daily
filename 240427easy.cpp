//
// Created by PC on 2024/4/27.
//
#include "vector"
#include "iostream"
#include "string"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<int> ans(n);
        for (int j = 0; j < n; j++) {
            for (auto& row : grid) {
                ans[j] = max(ans[j], (int) to_string(row[j]).length());
            }
        }
        return ans;
    }
};
