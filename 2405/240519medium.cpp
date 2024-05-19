//1535. 找出数组游戏的赢家
// Created by PC on 2024/5/19.
//https://leetcode.cn/problems/find-the-winner-of-an-array-game/description/
#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
class Solution {
public:
    int getWinner(vector<int> &arr, int k) {
        int i = 0, t = 0;// t记录连胜次数
        while (t < k && i < arr.size() - 1) {
            if (arr[i] > arr[i + 1]) {
                arr[i + 1] = arr[i];
                ++t;
            } else
                t = 1;
            ++i;
        }
        return arr[i];
    }
};


int main() {
    vector<int> arr = {2, 1, 3, 5, 4, 6, 7};
    Solution a;
    cout << a.getWinner(arr, 10);
}