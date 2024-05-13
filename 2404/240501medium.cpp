//
// Created by PC on 2024/5/1.
//2462. 雇佣 K 位工人的总代价
//https://leetcode.cn/problems/total-cost-to-hire-k-workers/description/
#include "vector"
#include "iostream"
#include "queue"

using namespace std;


class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<>> pq0, pq1;
        int i = 0;
        int j = costs.size() - 1;
        long long ans = 0;

        while (k--) {
            /* 从左右分别选candidates个候选 */
            while (pq0.size() < candidates && i <= j) {
                pq0.push(costs[i++]);
            }
            while (pq1.size() < candidates && i <= j) {
                pq1.push(costs[j--]);
            }
            /* 找到最小值, 相同时选下标更小的 */
            int a = (pq0.size() > 0) ? pq0.top() : INT_MAX;
            int b = (pq1.size() > 0) ? pq1.top() : INT_MAX;
            if (a <= b) { /* 累加当前的最小代价 */
                ans += a;
                pq0.pop();
            } else {
                ans += b;
                pq1.pop();
            }
        }
        return ans;
    }
};
