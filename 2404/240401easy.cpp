//
// Created by PC on 2024/4/1.
//
#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
using namespace std;
//双端队列
class Solution {
public:
    string finalString(string s) {
        string res;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'i')
                reverse(res.begin(), res.end());
            else
                res += s[i];
        }
        return res;
    }
    string finalString1(string s) {
        deque<char> q;
        bool head = false;
        for (char ch: s) {
            if (ch != 'i') {
                if (head) {
                    q.push_front(ch);
                } else {
                    q.push_back(ch);
                }
            } else {
                head = !head;
            }
        }
        string res = head ? string{q.rbegin(), q.rend()} : string{q.begin(), q.end()};
        return res;
    }
};
int main() {
    string s = "poiinter";
    Solution a;
    cout << a.finalString(s) << endl;
    cout << a.finalString1(s) << endl;
}
