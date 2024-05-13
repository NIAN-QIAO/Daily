//
// Created by PC on 2024/5/3.
//1491. 去掉最低工资和最高工资后的工资平均值
//https://leetcode.cn/problems/average-salary-excluding-the-minimum-and-maximum-salary/
#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    double average(vector<int> &salary) {
        int min = INT_MAX, max = INT_MIN, res = 0;
        double aver;
        for (int i = 0; i < salary.size(); ++i) {
            if (salary[i] < min)
                min = salary[i];
            if (salary[i] > max)
                max = salary[i];
            res += salary[i];
        }
        aver = (double) (res - max - min) / (double) (salary.size() - 2);
        return aver;
    }
};