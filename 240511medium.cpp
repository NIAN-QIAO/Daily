//2391. 收集垃圾的最少总时间
// Created by PC on 2024/5/11.
//https://leetcode.cn/problems/minimum-amount-of-time-to-collect-garbage/description/
#include "string"
#include "vector"
#include "algorithm"
#include <numeric>

using namespace std;

class Solution {
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel) {
        int ans = reduce(travel.begin(), travel.end()) * 3;
        for (auto &g: garbage) {
            ans += g.length();
        }
        for (char c: {'M', 'P', 'G'}) {
            for (int i = garbage.size() - 1; i && garbage[i].find(c) == string::npos; i--) {
                ans -= travel[i - 1]; // 没有垃圾 c，多跑了
            }
        }
        return ans;
    }
};
