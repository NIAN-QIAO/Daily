//
// Created by PC on 2024/5/4.
//1235. 规划兼职工作
//https://leetcode.cn/problems/maximum-profit-in-job-scheduling/
#include "vector"
#include "iostream"
#include "array"
#include "ranges"
#include "algorithm"

using namespace std;

class Solution {
public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
        int n = startTime.size();
        vector<array<int, 3>> jobs(n);
        for (int i = 0; i < n; i++) {
            jobs[i] = {endTime[i], startTime[i], profit[i]};
        }
        ranges::sort(jobs, [](auto &a, auto &b) { return a[0] < b[0]; }); // 按照结束时间排序

        vector<int> f(n + 1);
        for (int i = 0; i < n; i++) {
            int j = upper_bound(jobs.begin(), jobs.begin() + i, array<int, 3>{jobs[i][1], INT_MAX}) - jobs.begin();
            // 状态转移中，为什么是 j 不是 j+1：上面算的是 > 开始时间，-1 后得到 <= 开始时间，但由于还要 +1，抵消了
            f[i + 1] = max(f[i], f[j] + jobs[i][2]);
        }
        return f[n];
    }
};

