/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode* root) {
        TreeNode* pre = nullptr;  // 记录前一个节点
        stack<TreeNode*> st;
        while (root || !st.empty()) {
            if (root) {
                st.push(root);
                root = root->left;
            } else {
                root = st.top(); st.pop();
                if (pre && pre->val >= root->val) {
                    return false;
                }
                pre = root;
                root = root->right;
            }
        }
        return true;
    }
};
// @lc code=end

