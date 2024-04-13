//
// Created by PC on 2024/4/13.
//
//2924. 找到冠军 II
//https://leetcode.cn/problems/find-champion-ii/description/
#include "vector"
#include "iostream"
#include "set"

using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>> &edges) {
        vector<bool> all;
        all.resize(n, false);
        if (n == 1)
            return 0;
        if (n > 1 && edges.empty())
            return -1;
        set<int> test;
        //第一列相对优势大的队伍
        for (int i = 0; i < edges.size(); ++i) {
            test.insert(edges[i][0]);
            all[edges[i][0]] = true;
        }
        //第二列相对弱势的队伍要从第一列中剔除
        for (auto unit: test) {
            for (int j = 0; j < edges.size(); ++j) {
                all[edges[j][1]] = true;
                if (unit == edges[j][1]) {
                    test.erase(unit);
                    break;
                }
            }
        }
        //还需要补充没有胜负关系队伍
        for (int i = 0; i < all.size(); ++i) {
            if (all[i] == false) {
                test.insert(i);
            }
        }
        if (test.size() > 1)
            return -1;
        else {
            return *test.begin();
        }
    }
};

int main() {
    Solution a;
    vector<vector<int>> edges = {{0, 1},
                                 {1, 2}};
    cout << a.findChampion(3, edges);
}