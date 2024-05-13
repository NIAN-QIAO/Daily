//
// Created by PC on 2024/4/4.
//
//祖先节点 2192
//给你一个正整数 n ，它表示一个 有向无环图 中节点的数目，节点编号为 0 到 n - 1 （包括两者）。
//
//给你一个二维整数数组 edges ，其中 edges[i] = [fromi, toi] 表示图中一条从 fromi 到 toi 的单向边。
//
//请你返回一个数组 answer，其中 answer[i]是第 i 个节点的所有 祖先 ，这些祖先节点 升序 排序。
//
//如果 u 通过一系列边，能够到达 v ，那么我们称节点 u 是节点 v 的 祖先 节点。
#include "vector"
#include "iostream"

/*先找对应的前继节点，递归累加*/
using namespace std;


class Solution {
public:
    void DFS(int i, int u, vector<bool> &vis) {
        for (auto &v: Graph[u]) {
            if (!vis[v]) {
                vis[v] = true;
                res[v].push_back(i);
                DFS(i, v, vis);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
        //逆向DFS或者正向DFS
        Graph = vector<vector<int>>(n);
        res = vector<vector<int>>(n);
        for (auto &edge: edges) {//建立邻接表
            Graph[edge[0]].push_back(edge[1]);
        }
        for (int i = 0; i < n; i++) {
            vector<bool> vis(n);
            DFS(i, i, vis);
        }
        return res;
    }

private:
    vector<vector<int>> Graph;

    vector<vector<int>> res;
};

int main() {
    int n = 8;
    vector<vector<int>> edgeList = {{0, 3},
                                    {0, 4},
                                    {1, 3},
                                    {2, 4},
                                    {2, 7},
                                    {3, 5},
                                    {3, 6},
                                    {3, 7},
                                    {4, 6}};
//    for (const auto& row : edgeList) {
//        for (const auto& elem : row) {
//            std::cout << elem << " ";
//        }
//        std::cout << std::endl; // 每行后换行
//    }
    Solution a;
    a.getAncestors(8, edgeList);
}
