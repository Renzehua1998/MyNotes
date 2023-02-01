/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    vector<int> robTree(TreeNode* root) {
        if (!root) return vector<int>{0, 0};
        vector<int> left = robTree(root->left);
        vector<int> right = robTree(root->right);
        int res1 = root->val + left[0] + right[0];
        int res2 = max(left[0], left[1]) + max(right[0], right[1]);
        return vector<int>{res2, res1};
    }
    int rob(TreeNode* root) {
        vector<int> res = robTree(root);
        return max(res[0], res[1]);
    }
};
// @lc code=end

