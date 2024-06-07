//1103. 分糖果 II
// Created by PC on 2024/6/3.
//https://leetcode.cn/problems/distribute-candies-to-people/
#include "iostream"
#include "vector"
using namespace std;
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people, 0);
        int number = 1;
        while (candies >= 0) {
            for (int i = 0; i < res.size(); ++i) {
                if (candies >= number) {
                    res[i] += number;
                    candies -= number;
                    number++;
                } else if (candies < number) {
                    res[i] += candies;
                    candies = -1;
                    break;
                }
            }
        }
        return res;
    }
};