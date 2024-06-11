//419. 甲板上的战舰
// Created by PC on 2024/6/11.
//https://leetcode.cn/problems/battleships-in-a-board/
#include "iostream"
#include "vector"
using namespace std;
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'X' &&
                    (j == 0 || board[i][j - 1] != 'X') &&
                    (i == 0 || board[i - 1][j] != 'X')) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
