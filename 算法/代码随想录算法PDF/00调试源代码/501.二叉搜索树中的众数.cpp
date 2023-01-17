/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    vector<int> findMode(TreeNode* root) {
        TreeNode* pre = nullptr;  // 记录前一个节点
        int maxCount = 0;
        int count;
        vector<int> res;
        stack<TreeNode*> st;
        int minDiff = INT_MAX;
        while (root || !st.empty()) {
            if (root) {
                st.push(root);
                root = root->left;
            } else {
                root = st.top(); st.pop();

                if (!pre) {  // 统计当前遍历元素值的频次
                    count = 1;
                } else if (pre->val == root->val) {
                    count++;
                } else {
                    count = 1;
                }
                pre = root;

                if (count == maxCount) res.push_back(root->val);  // 验证是否为最大频次
                if (count > maxCount) {
                    maxCount = count;
                    res.clear();
                    res.push_back(root->val);
                }

                root = root->right;
            }
        }
        return res;
    }
};
// @lc code=end

