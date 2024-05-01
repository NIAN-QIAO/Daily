//
// Created by PC on 2024/4/30.
//2798. 满足目标工作时长的员工数目
//https://leetcode.cn/problems/number-of-employees-who-met-the-target/description/
#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int> &hours, int target) {
        int res = 0;
        for (int i = 0; i < hours.size(); ++i) {
            if (hours[i] >= target)
                res++;
        }
        return res;
    }
};