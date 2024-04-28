//
// Created by PC on 2024/4/28.
//
#include "string"
#include "algorithm"

using namespace std;

class Solution
{
public:
    string baseNeg2(int n)
    {
        if (n == 0)
            return "0";

        string ans;
        while (n != 0)
        {
            // 获取当前最低位f
            if (n % -2 == 0) // 当前n为偶数，当前n的最低位为0，后续直接抹去这个最低位，除以-2即可
                ans += "0";
            else // 当前n为奇数，当前n的最低位f为1 （tips：虽然 n % -2 可能为1或-1，但不影响，都是最低位f=1）
            {
                n -= 1; // 将最低位的值抹去后，使得n变为偶数，在进行除负二操作时是整除
                ans += "1";
            }

            // 将n的负二进制表达式向右移一位
            n /= -2;
        }
        reverse(ans.begin(), ans.end()); // 除法和取余运算得到的是从低位到高位的结果，故最后要翻转
        return ans;
    }
};
