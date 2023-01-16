/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        stack<TreeNode*> st;
        unordered_map<TreeNode*, int> map;
        st.push(root);
        int left, right;  // 左右子节点高度
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node) {  // 不为空，说明是第一次遍历
                st.push(nullptr);
                if (node->right) st.push(node->right);
                if (node->left) st.push(node->left);
            } else {
                st.pop();
                node = st.top();
                st.pop();
                if (map.find(node->left) == map.end()) {  // map中没找到，默认为0
                    left = 0;
                } else {
                    left = map[node->left];
                }
                if (map.find(node->right) == map.end()) {
                    right = 0;
                } else {
                    right = map[node->right];
                }

                if (abs(left - right) > 1) return false;
                map[node] = 1 + max(left, right);
            }
        }
        return true;
    }
};
// @lc code=end

