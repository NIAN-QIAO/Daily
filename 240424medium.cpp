//
// Created by PC on 2024/4/24.
//
//2385. 感染二叉树需要的总时间
//https://leetcode.cn/problems/amount-of-time-for-binary-tree-to-be-infected/description/
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
#include "vector"
#include "iostream"
#include "queue"
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


public:
    int amountOfTime(TreeNode *root, int start) {
        if (root == nullptr)
            return 0;
        vector<vector<int>> graph(100001);
        queue<TreeNode *> q;
        q.push(root);
        int res(0);
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            if (cur->left) {
                graph[cur->val].push_back(cur->left->val);
                graph[cur->left->val].push_back(cur->val);
                q.push(cur->left);
            }
            if (cur->right) {
                graph[cur->val].push_back(cur->right->val);
                graph[cur->right->val].push_back(cur->val);
                q.push(cur->right);
            }
        }
        vector<int> visit(100001, -1);
        queue<int> que;
        que.push(start);
        visit[start] = 0;
        while (!que.empty()) {
            auto cur = que.front();
            que.pop();
            for (auto i: graph[cur]) {
                if (visit[i] == -1) {
                    visit[i] = visit[cur] + 1;
                    res = max(res, visit[i]);
                    que.push(i);
                }
            }
        }
        return res;
    }
};