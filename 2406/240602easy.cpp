//575. 分糖果
// Created by PC on 2024/6/2.
//https://leetcode.cn/problems/distribute-candies/
#include "algorithm"
#include "iostream"
#include "map"
#include "vector"
using namespace std;
class Solution {
public:
    int distributeCandies(vector<int> &candyType) {
        int type = candyType.size() / 2;
        map<int, int> candy;
        for (int i = 0; i < candyType.size(); ++i) {
            candy[candyType[i]]++;
        }
        if (candy.size() <= type)
            return candy.size();
        else
            return type;
    }
};