//2028. 找出缺失的观测数据
// Created by PC on 2024/5/27.
//https://leetcode.cn/problems/find-missing-observations/description/
#include "iostream"
#include "vector"
using namespace std;
class Solution {
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n) {
        int sum = mean * (rolls.size() + n);
        int sum_n = 0, sum_m = 0;
        for (int i = 0; i < rolls.size(); ++i) {
            sum_m = sum_m + rolls[i];
        }
        sum_n = sum - sum_m;
        if (sum_n < n || sum_n > 6 * n)
            return {};
        vector<int> res;
        int i = 0;
        while (i * n <= sum_n) {
            i++;
        }
        i--;
        int left = sum_n - i * n;
        res.resize(n, i);
        for (int j = 0; j < left; ++j) {
            res[j]++;
        }
        return res;
    }
};
int main() {
    Solution a;
    vector<int> rolls = {3, 2, 4, 3};
    int mean = 4, n = 2;
    a.missingRolls(rolls, mean, n);
}