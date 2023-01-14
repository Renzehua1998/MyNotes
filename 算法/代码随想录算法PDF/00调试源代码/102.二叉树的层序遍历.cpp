/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    void order(TreeNode* node, vector<vector<int>>& res, int layer) {
        if (node == nullptr) return;
        if (res.size() == layer) res.push_back(vector<int>());  // 开始了新的一层
        res[layer].push_back(node->val);
        order(node->left, res, layer + 1);
        order(node->right, res, layer + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int layer = 0;  // 层数，用于确认遍历到节点值放的位置
        vector<vector<int>> res;
        order(root, res, layer);
        return res;
    }
};
// @lc code=end

