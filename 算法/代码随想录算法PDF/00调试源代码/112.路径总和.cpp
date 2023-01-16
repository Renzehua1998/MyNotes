/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        stack<pair<TreeNode*, int>> st;
        st.push(pair<TreeNode*, int> (root, root->val));
        while (!st.empty()) {
            pair<TreeNode*, int> node = st.top(); st.pop();
            if (!node.first->left && !node.first->right && node.second == targetSum) {
                return true;
            }
            if (node.first->left) {
                st.push(pair<TreeNode*, int> (node.first->left, node.second + node.first->left->val));
            }
            if (node.first->right) {
                st.push(pair<TreeNode*, int> (node.first->right, node.second + node.first->right->val));
            }
        }
        return false;
    }
};
// @lc code=end

