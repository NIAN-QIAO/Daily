//
// Created by PC on 2024/5/2.
//857. 雇佣 K 名工人的最低成本
//https://leetcode.cn/problems/minimum-cost-to-hire-k-workers/description/
#include "vector"
#include "iostream"
#include "numeric"
#include "algorithm"
#include "queue"

using namespace std;

class Solution {
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k) {
        int n = quality.size(), id[n], sum_q = 0;
        iota(id, id + n, 0);
        sort(id, id + n, [&](int i, int j) {
            return wage[i] * quality[j] < wage[j] * quality[i];
        });
        priority_queue<int> pq;
        for (int i = 0; i < k; ++i) {
            pq.push(quality[id[i]]);
            sum_q += quality[id[i]];
        }
        double ans = sum_q * ((double) wage[id[k - 1]]) / quality[id[k - 1]];
        for (int i = k; i < n; ++i) {
            if (int q = quality[id[i]];q < pq.top()) {
                sum_q -= pq.top() - q;
                pq.pop();
                pq.push(q);
                ans = min(ans, sum_q * ((double) wage[id[i]] / q));
            }
        }
        return ans;
    }
};