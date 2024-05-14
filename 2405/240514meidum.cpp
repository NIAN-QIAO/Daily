//2244. 完成所有任务需要的最少轮数
// Created by PC on 2024/5/14.
//https://leetcode.cn/problems/minimum-rounds-to-complete-all-tasks/description/
#include "algorithm"
#include "iostream"
#include "stack"
#include "unordered_map"
#include "vector"
using namespace std;
class Solution {
public:
    int minimumRounds(vector<int> &tasks) {
        unordered_map<int, int> freq;
        int mx = 0;
        for (auto t: tasks) {
            freq[t]++;
            mx = max(mx, freq[t]);
        }
        // dp
        mx = max(mx, 4);
        vector<int> dp(mx + 1, 0);
        dp[1] = INT_MAX / 2;
        dp[2] = dp[3] = 1;
        for (int i = 4; i <= mx; ++i) {
            dp[i] = 1 + min(dp[i - 2], dp[i - 3]);
        }
        int ans = 0;
        for (auto &kv: freq) {
            int num = kv.second;
            if (num == 1) return -1;
            ans += dp[num];
        }
        return ans;
    }
};


int main() {
    vector<int> tasks = {2, 2, 3, 3, 2, 4, 4, 4, 4, 4};
    Solution a;
    cout << a.minimumRounds(tasks);
}