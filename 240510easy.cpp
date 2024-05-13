//2960. 统计已测试设备
// Created by PC on 2024/5/10.
//https://leetcode.cn/problems/count-tested-devices-after-test-operations/
#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

class Solution {
public:
    int countTestedDevices(vector<int> &batteryPercentages) {
        int res = 0;
        for (int i = 0; i < batteryPercentages.size(); ++i) {
            if (batteryPercentages[i] > 0) {
                res++;
                for (int j = i + 1; j < batteryPercentages.size(); ++j) {
                    if (j == batteryPercentages.size())
                        break;
                    batteryPercentages[j] = max(0, batteryPercentages[j] - 1);
                }
            }
        }
        return res;
    }
};
