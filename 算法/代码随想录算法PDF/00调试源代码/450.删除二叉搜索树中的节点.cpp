/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;  // 特殊情况
        TreeNode* cur = root;
        TreeNode* pre = nullptr;  // 记录父节点
        while (cur) {
            if (cur->val == key) break;
            pre = cur;
            if (cur->val > key) cur = cur->left;
            else cur = cur->right;
        }
        if (cur) {  // 找到了，执行删除操作
            if (!cur->right) {
                if (pre) {
                    if (pre->val > key) pre->left = cur->left;
                    else pre->right = cur->left;
                    return root;  // 此时不执行后面了，直接返回
                } else {
                    return cur->left;
                }
            }
            TreeNode* tmp = cur->right;
            while (tmp->left) {
                tmp = tmp->left;
            }
            tmp->left = cur->left;
            if (pre) {
                if (pre->val > key) pre->left = cur->right;
                else pre->right = cur->right;
            } else {
                return cur->right;
            }
        }
        return root;
    }
};
// @lc code=end

