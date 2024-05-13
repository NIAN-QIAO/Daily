//
// Created by PC on 2024/5/5.
//1652. 拆炸弹
//https://leetcode.cn/problems/defuse-the-bomb/description/
#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int> &code, int k) {
        int temp = 0, temp1 = 0;
        vector<int> res(code.size(), 0);
        if (k == 0) {}
        else if (k > 0) {
            for (int i = 0; i < code.size(); ++i) {
                temp = 0;
                for (int j = 1; j <= k; ++j) {
                    temp += code[(i + j) % code.size()];
                }
                res[i] = temp;
            }
        } else {
//            k = k % code.size();
            for (int i = 0; i < (-k); ++i) {
                int temp2 = 0;
                for (int j = -1; j >= k; j--) {
                    if (i + j >= 0)
                        temp2 += code[i + j];
                    else
                        temp2 += code[code.size() + i + j];
                }
                res[i] = temp2;
            }
            for (int i = -k; i < code.size(); ++i) {
                temp1 = 0;
                for (int j = -1; j >= k; j--) {
                    temp1 += code[(i + j) % code.size()];
                }
                res[i] = temp1;
            }
        }
        for (int i = 0; i < code.size(); ++i) {
            code[i] = res[i];
        }
        return res;
    }
};

int main() {
    Solution a;
    vector<int> code = {10, 5, 7, 7, 3, 2, 10, 3, 6, 9, 1, 6};
    int k = -4;
    a.decrypt(code, k);
    for (int i = 0; i < code.size(); ++i) {
        cout << code[i] << " ";
    }
//    cout << (-4) % 12;
}