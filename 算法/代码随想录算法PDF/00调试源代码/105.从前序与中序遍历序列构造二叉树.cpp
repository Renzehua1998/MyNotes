/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* subBuild(vector<int>& inorder, int inBegin, int inEnd, vector<int>& preorder, int preBegin, int preEnd) {
        if (preBegin == preEnd) return nullptr;  // 空节点
        TreeNode* root = new TreeNode(preorder[preBegin]);
        if (preEnd - preBegin == 1) return root;  // 叶子节点
        int cutIndex = inBegin;  // 切割位置下标
        while (cutIndex < inEnd) {
            if (inorder[cutIndex] == root->val) break;
            cutIndex++;
        }
        // 迭代
        root->left = subBuild(inorder, inBegin, cutIndex, preorder, preBegin + 1, preBegin + cutIndex - inBegin + 1);
        root->right = subBuild(inorder, cutIndex + 1, inEnd, preorder, preBegin + cutIndex - inBegin + 1, preEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.size() == 0 || preorder.size() == 0) return nullptr;
        return subBuild(inorder, 0, inorder.size(), preorder, 0, preorder.size());
    }
};
// @lc code=end

