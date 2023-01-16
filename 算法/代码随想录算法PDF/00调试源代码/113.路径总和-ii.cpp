/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> res;  // 公共变量
    vector<int> path;
    void dfs(TreeNode* root, int targetSum) {
        if (!root) return ;
        path.push_back(root->val);
        if (!root->left && !root->right && targetSum == root->val) {
            res.push_back(path);
        }
        if (root->left) {
            dfs(root->left, targetSum - root->val);
            path.pop_back();  // 回溯
        }
        if (root->right) {
            dfs(root->right, targetSum - root->val);
            path.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return res;
    }
};
// @lc code=end

