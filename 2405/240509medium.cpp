//2105. 给植物浇水 II
// Created by PC on 2024/5/9.
//https://leetcode.cn/problems/watering-plants-ii/description/
#include "deque"
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int minimumRefill(vector<int> &plants, int capacityA, int capacityB) {
//        deque<int> roads;
//        for (int i = 0; i < plants.size(); ++i) {
//            roads.push_back(plants[i]);
//        }
        int i = 0, j = plants.size() - 1, times = 0, tempa = capacityA, tempb = capacityB;
        while (i < j) {
            if (tempa >= plants[i]) {
                tempa = tempa - plants[i];
                i++;
            } else {
                tempa = capacityA - plants[i];
                times++;
                i++;
            }
            if (tempb >= plants[j]) {
                tempb = tempb - plants[j];
                j--;
            } else {
                tempb = capacityB - plants[j];
                times++;
                j--;
            }
        }
        if (i == j) {
            if (tempa >= tempb) {
                if (tempa < plants[i]) {
                    times++;
                }
            }else{
                if (tempb < plants[i]) {
                    times++;
                }
            }
        }
        return times;
    }
};

int main() {

}
