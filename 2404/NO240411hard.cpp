//
// Created by PC on 2024/4/11.
//
//https://leetcode.cn/problems/tree-of-coprimes/description/
//1766. 互质树
#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

const int MX = 51;
vector<int> coprime[MX];
auto init = [] {
    //预处理：coprime[i] 保存 [1, MX)中与 i 互质的所有元素
    for (int i = 1; i < MX; ++i) {
        for (int j = 1; j < MX; ++j) {
            if (__gcd(i, j) == 1) {
                coprime[i].push_back(j);
            }
        }
    }
    return 0;
}();

class Solution {
    vector<vector<int>> g;
    vector<int> ans;
    pair<int, int> val_depth_id[MX];//包含深度和节点编号
    void DFS(int x, int fa, int depth, vector<int> &nums) {
        int val = nums[x];//x的节点值
        //计算与val互质的数中，深度最大的节点编号
        int max_depth = 0;
        for (auto j: coprime[val]) {
            auto [depth, id] = val_depth_id[j];
            if (depth > max_depth) {
                max_depth = depth;
                ans[x] = id;
            }
        }
        auto tmp = val_depth_id[val];//恢复现场
        val_depth_id[val] = {depth, x};//保存val对应的节点深度和节点编号
        for (auto y: g[x]) {
            if (y != fa) {
                DFS(y, x, depth + 1, nums);
            }
        }
        val_depth_id[val] = tmp;//恢复现场
    }

public:
    vector<int> getCoprimes(vector<int> &nums, vector<vector<int>> &edges) {
        int n = nums.size();
        g.resize(n);
        for (auto &e: edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);

        }
        ans.resize(n, -1);
        DFS(0, -1, 1, nums);
        return ans;
    }
};

int main() {
//    init();
}

