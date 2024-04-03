//
// Created by PC on 2024/4/2.
/*
894. 所有可能的真二叉树
中等
给你一个整数 n ，请你找出所有可能含 n 个节点的 真二叉树 ，并以列表形式返回。答案中每棵树的每个节点都必须符合 Node.val == 0 。
答案的每个元素都是一棵真二叉树的根节点。你可以按 任意顺序 返回最终的真二叉树列表。
真二叉树 是一类二叉树，树中每个节点恰好有 0 或 2 个子节点。
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>
#include <vector>

using namespace std;
#define tree

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<TreeNode *> f[11];

auto init = [] {
    f[1] = {new TreeNode()};
    for (int i = 2; i < 11; i++) { // 计算 f[i]
        for (int j = 1; j < i; j++) { // 枚举左子树叶子数
            for (auto left: f[j]) { // 枚举左子树
                for (auto right: f[i - j]) { // 枚举右子树
                    f[i].push_back(new TreeNode(0, left, right));
                }
            }
        }
    }
    return 0;
}();

class Solution {
public:
    vector<TreeNode *> allPossibleFBT(int n) {
        return f[n % 2 ? (n + 1) / 2 : 0];
    }
};

//

int main() {
    cout << "hello world!" << endl;
}