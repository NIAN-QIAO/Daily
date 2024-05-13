//
// Created by PC on 2024/4/5.
//
//给定二叉树的根节点 root，找出存在于 不同 节点 A 和 B 之间的最大值 V，其中 V = |A.val - B.val|，且 A 是 B 的祖先。
//
//（如果 A 的任何子节点之一为 B，或者 A 的任何子节点是 B 的祖先，那么我们认为 A 是 B 的祖先）
//


#include "iostream"
#include "algorithm"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int res = 0;

    void DFS(TreeNode *node, int mn, int mx) {
        if (node == nullptr) {
            res = max(res, mx - mn);
            return;
        }
        mn = min(mn, node->val);
        mx = max(mx, node->val);
        DFS(node->left, mn, mx);
        DFS(node->right, mn, mx);
    }

public:
    int maxAncestorDiff(TreeNode *root) {
        DFS(root, root->val, root->val);
        return res;
    }
};