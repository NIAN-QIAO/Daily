//
// Created by PC on 2024/4/10.
//
//1702. 修改后的最大二进制字符串
//https://leetcode.cn/problems/maximum-binary-string-after-change/description/
#include "iostream"
#include "string"
#include "algorithm"

using namespace std;

/*
 * 提示1：答案不可能包括00
 * 提示2：答案至多包含一个0
 * 提示3：如果binary全是1，那么返回binary即可
 *       如果binary中有0，最终答案会恰好包含一个0
 *只要还有两个 000，那么用操作 2 把右边的 000 往左移，当出现 000000 时就通过操作 1 把左边的 000 变成 111，这会让二进制更大。
 * */
class Solution {
public:
    string maximumBinaryString(string binary) {
        int i = binary.find('0');
        if (i < 0) {
            return binary;
        }
        int cnt1 = count(binary.begin() + i, binary.end(), '1');//统计[i,n-1]中'1'的个数
        return string(binary.size() - 1 - cnt1, '1') + '0' + string(cnt1, '1');
    }
};

int main() {

}