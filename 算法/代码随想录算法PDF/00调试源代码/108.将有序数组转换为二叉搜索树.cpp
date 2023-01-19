/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;  // 特殊情况

        TreeNode* root = new TreeNode();  // 初始化
        queue<TreeNode*> nodeQ;
        queue<int> leftQ, rightQ;
        nodeQ.push(root);
        leftQ.push(0);
        rightQ.push(nums.size());

        while (!nodeQ.empty()) {
            TreeNode* node = nodeQ.front(); nodeQ.pop();  // 根节点赋值
            int left = leftQ.front(); leftQ.pop();
            int right = rightQ.front(); rightQ.pop();
            int mid = left + (right - left) / 2;
            node->val = nums[mid];

            if (left < mid) {  // 处理左区间
                node->left = new TreeNode();
                nodeQ.push(node->left);
                leftQ.push(left);
                rightQ.push(mid);
            }

            if (right > mid + 1) {  // 处理右区间
                node->right = new TreeNode();
                nodeQ.push(node->right);
                leftQ.push(mid + 1);
                rightQ.push(right);
            }
        }
        return root;
    }
};
// @lc code=end

