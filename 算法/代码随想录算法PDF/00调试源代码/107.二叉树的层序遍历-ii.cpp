/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> res;
        if (root) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> layer;
            while (size) {
                TreeNode* node = que.front();
                que.pop();
                layer.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
                size--;
            }
            res.push_back(layer);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

