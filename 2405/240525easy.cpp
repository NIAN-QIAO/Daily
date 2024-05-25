//https://leetcode.cn/problems/find-indices-with-index-and-value-difference-i/description/
// Created by PC on 2024/5/25.
//2903. 找出满足差值条件的下标 I
#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                if (j - i >= indexDifference && abs(nums[j] - nums[i]) >= valueDifference) {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
};
