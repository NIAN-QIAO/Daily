//3038. 相同分数的最大操作数目 I
// Created by PC on 2024/6/7.
//https://leetcode.cn/problems/maximum-number-of-operations-with-the-same-score-i/
#include "iostream"
#include "vector"
using namespace std;
class Solution {
public:
    int maxOperations(vector<int> &nums) {
        if (nums.size() < 2)
            return 0;
        int i = 0, res = 0, end = nums.size() - 1;
        int score = nums[i] + nums[i + 1];
        while (end - i + 1 > 1) {
            if ((nums[i] + nums[i + 1]) == score) {
                i = i + 2;
                res++;
            } else
                break;
        }
        return res;
    }
};