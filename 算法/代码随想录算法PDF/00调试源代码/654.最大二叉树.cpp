/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode* traversal(vector<int>& nums, int begin, int end) {
        if (begin >= end) return nullptr;
        int maxNum = nums[begin];
        int maxIndex = begin;
        for (int i = begin; i < end; i++) { // 找最大元素和下标
            if (nums[i] > maxNum) {
                maxNum = nums[i];
                maxIndex = i;
            }
        }
        TreeNode* root = new TreeNode(maxNum);
        root->left = traversal(nums, begin, maxIndex);
        root->right = traversal(nums, maxIndex + 1, end);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traversal(nums, 0 , nums.size());
    }
};
// @lc code=end

