//
// Created by PC on 2024/4/3.
//
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//克隆树
#include<vector>
#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target) {
        if (original == nullptr || original == target) {
            return cloned;
        }
        auto left_res = getTargetCopy(original->left, cloned->left, target);
        if (left_res) {
            return left_res;
        }
        return getTargetCopy(original->right, cloned->right, target);
    }
};