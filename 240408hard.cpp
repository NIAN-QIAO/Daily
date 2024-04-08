//
// Created by PC on 2024/4/8.
//
/*给你一个整数数组 nums 。每一次操作中，你可以将 nums 中 任意 一个元素替换成 任意 整数。

如果 nums 满足以下条件，那么它是 连续的 ：

nums 中所有元素都是 互不相同 的。
nums 中 最大 元素与 最小 元素的差等于 nums.length - 1 。
比方说，nums = [4, 2, 5, 3] 是 连续的 ，但是 nums = [1, 2, 3, 5, 6] 不是连续的 。

请你返回使 nums 连续 的 最少 操作次数。*/
//2009. 使数组连续的最少操作数
//https://leetcode.cn/problems/minimum-number-of-operations-to-make-array-continuous/description/
//有思路代码不会写
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int minOperations(vector<int> &nums) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());//原地去重
        int ans = 0, left = 0;
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[left] < nums[i] - n + 1) {
                left++;
            }
            ans = max(ans, i - left + 10);
        }
        return n - ans;
    }
};

int main() {
    vector<int> oli = {4, 2, 5, 3};
    Solution a;
    cout << a.minOperations(oli) << endl;
}
