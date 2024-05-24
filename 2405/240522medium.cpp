//2225. 找出输掉零场或一场比赛的玩家
// Created by PC on 2024/5/22.
//https://leetcode.cn/problems/find-players-with-zero-or-one-losses/
#include "iostream"
#include "map"
#include "set"
#include "unordered_map"
#include "vector"
using namespace std;
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches) {
        unordered_map<int, int> loss_count;
        for (auto &m: matches) {
            if (!loss_count.contains(m[0])) {
                loss_count[m[0]] = 0;
            }
            loss_count[m[1]]++;
        }

        vector<vector<int>> ans(2);
        for (auto &[player, cnt]: loss_count) {
            if (cnt < 2) {
                ans[cnt].push_back(player);
            }
        }
        ranges::sort(ans[0]);
        ranges::sort(ans[1]);
        return ans;
    }
};
