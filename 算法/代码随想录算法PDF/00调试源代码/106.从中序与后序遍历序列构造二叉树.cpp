/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* subBuild(vector<int>& inorder, int inBegin, int inEnd, vector<int>& postorder, int poBegin, int poEnd) {
        if (poBegin == poEnd) return nullptr;  // 空节点
        TreeNode* root = new TreeNode(postorder[poEnd - 1]);
        if (poEnd - poBegin == 1) return root;  // 叶子节点
        int cutIndex = inBegin;  // 切割位置下标
        while (cutIndex < inEnd) {
            if (inorder[cutIndex] == root->val) break;
            cutIndex++;
        }
        // 迭代
        root->left = subBuild(inorder, inBegin, cutIndex, postorder, poBegin, poBegin + cutIndex - inBegin);
        root->right = subBuild(inorder, cutIndex + 1, inEnd, postorder, poBegin + cutIndex - inBegin, poEnd - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return nullptr;
        return subBuild(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};
// @lc code=end

