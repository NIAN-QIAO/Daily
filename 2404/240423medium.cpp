//
// Created by PC on 2024/4/23.
//
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes) {
        int res = 0;
        for (int i = 0; i < grumpy.size(); ++i) {
            if (!grumpy[i])
                res += customers[i];
        }
//        cout << "res:" << res << endl;
        int max = res;
        for (int i = 0; i < grumpy.size() - minutes + 1; ++i) {
            int temp = res;
            for (int j = i; j < i + minutes; ++j) {
                if (grumpy[j])
                    temp += customers[j];
            }
            if (max < temp)
                max = temp;
        }
        return max;
    }
};

int main() {
    vector<int> customers = {1};
    vector<int> grumpy = {0};
    int minutes = 1;
    Solution a;
    cout << a.maxSatisfied(customers, grumpy, minutes);
}
