/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2;
        if (!root2) return root1;
        stack<TreeNode*> st;
        st.push(root2);
        st.push(root1);
        while (!st.empty()) {
            TreeNode* node1 = st.top(); st.pop();
            TreeNode* node2 = st.top(); st.pop();
            node1->val += node2->val;

            if (node1->left && node2->left) {
                st.push(node2->left);
                st.push(node1->left);
            }
            if (node1->right && node2->right) {
                st.push(node2->right);
                st.push(node1->right);
            }

            if (!node1->left && node2->left) {
                node1->left = node2->left;
            }
            if (!node1->right && node2->right) {
                node1->right = node2->right;
            }
        }
        return root1;
    }
};
// @lc code=end

