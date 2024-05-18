//2644. 找出可整除性得分最大的整数
// Created by PC on 2024/5/18.
//https://leetcode.cn/problems/find-the-maximum-divisibility-score/description/
#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
class Solution {
public:
    int maxDivScore(vector<int> &nums, vector<int> &divisors) {
        int max = 0, res = 0, count = 0;
        for (int i = 0; i < divisors.size(); ++i) {
            count = 0;
            for (int j = 0; j < nums.size(); ++j) {
                if (nums[j] % divisors[i] == 0) {
                    count++;
                }
            }
            if (count > max || count == max && divisors[i] < divisors[res]) {
                max = count;
                res = i;
            }
        }
        return divisors[res];
    }
};
int main() {
    vector<int> nums = {73, 13, 20, 6};
    vector<int> divisors = {56, 75, 83, 26, 24, 53, 56, 61};
    Solution a;
    cout << a.maxDivScore(nums, divisors);
}