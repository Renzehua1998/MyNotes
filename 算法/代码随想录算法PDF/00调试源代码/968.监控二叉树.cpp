/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
 */

// @lc code=start
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
class Solution {
public:
    int res;
    int traversal(TreeNode* root) {
        if (!root) return 2;  // 终止条件
        int left = traversal(root->left);  // 后序递归
        int right = traversal(root->right);
        // 单层逻辑
        if (left == 2 && right == 2) return 0;
        if (left == 0 || right == 0) {
            res++;
            return 1;
        }
        if (left == 1 || right == 1) return 2;  // 这行必须在下面，优先保证监控
        return -1;  // 占位用，不会到这里
    }
    int minCameraCover(TreeNode* root) {
        res = 0;
        if (traversal(root) == 0) {
            res++;
        }
        return res;
    }
};
// @lc code=end

