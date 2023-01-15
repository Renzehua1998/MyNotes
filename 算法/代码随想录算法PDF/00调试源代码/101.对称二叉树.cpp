/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        stack<TreeNode*> st;
        st.push(root->left);
        st.push(root->right);
        while (!st.empty()) {
            TreeNode* left = st.top();
            st.pop();
            TreeNode* right = st.top();
            st.pop();
            if (!left && !right) continue;  // 继续迭代
            if (!left || !right || left->val != right->val) {  // 不对称的情况
                return false;
            }
            st.push(left->left);  // 两两压栈
            st.push(right->right);
            st.push(left->right);
            st.push(right->left);
        }
        return true; // 正常遍历完没返回false，说明对称
    }
};
// @lc code=end

