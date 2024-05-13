//
// Created by PC on 2024/4/25.
//
//2739. 总行驶距离
//https://leetcode.cn/problems/total-distance-traveled/
class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int distance = 0;
        while (mainTank >= 5) {
            distance += 50;
            mainTank -= 5;
            if (additionalTank >= 1) {
                additionalTank--;
                mainTank++;
            }
        }
        distance = distance + mainTank * 10;
        return distance;
    }
};
//每用掉5L，从副邮箱提取1L