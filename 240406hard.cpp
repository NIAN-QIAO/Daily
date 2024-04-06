//
// Created by PC on 2024/4/6.
//
//树上倍增算法
//https://leetcode.cn/problems/kth-ancestor-of-a-tree-node/solutions/2305895/mo-ban-jiang-jie-shu-shang-bei-zeng-suan-v3rw/
/*给你一棵树，树上有 n 个节点，按从 0 到 n-1 编号。树以父节点数组的形式给出，其中 parent[i] 是节点 i 的父节点。树的根节点是编号为 0 的节点。
树节点的第 k 个祖先节点是从该节点到根节点路径上的第 k 个节点。*/
#include "iostream"
#include "vector"

using namespace std;

//过预处理，可以知道每个节点的第 1，2，4，8，16...个祖先节点。那么对于每次询问，最多只会向上跳log(n)次。
class TreeAncestor {
    vector<vector<int>> pa;

public:
    TreeAncestor(int n, vector<int> &parent) {
        int m = 32 - __builtin_clz(n);//n的二进制长度
        pa.resize(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
            pa[i][0] = parent[i];
        for (int i = 0; i < m - 1; i++) {
            for (int x = 0; x < n; x++) {
                if (int p = pa[x][i];p != -1)
                    pa[x][i + 1] = pa[p][i];
            }
        }

    }

    int getKthAncestor(int node, int k) {
        int m = 32 - __builtin_clz(k);//k的二进制长度
        for (int i = 0; i < m; i++) {
            if ((k >> i) & 1) {//k的二进制从低到高第i位是1
                node = pa[node][i];
                if (node < 0)
                    break;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */