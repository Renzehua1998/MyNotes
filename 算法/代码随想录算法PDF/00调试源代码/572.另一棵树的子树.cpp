/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
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
private:
    // int lNull = INT_MAX;  // 用于填充为空的左右子节点
    // int rNull = INT_MAX - 1;
    void dfsOrder(TreeNode* root, vector<int>& order) {
        if (!root) return;
        order.push_back(root->val);
        if (root->left) {
            dfsOrder(root->left, order);
        } else {
            order.push_back(INT_MAX);
        }
        if (root->right) {
            dfsOrder(root->right, order);
        } else {
            order.push_back(INT_MAX);
        }
    }
    bool kmp(vector<int>& s, vector<int>& t) {
        int lens = s.size(), lent = t.size();
        vector<int> next(lent, -1);
        for (int i = 1, j = -1; i < lent; i++) {
            while (j != -1 && t[i] != t[j + 1]) {
                j = next[j];
            }
            if (t[i] == t[j + 1]) {
                j++;
            }
            next[i] = j;
        }
        for (int i = 0, j = -1; i < lens; i++) {
            while (j != -1 && s[i] != t[j + 1]) {
                j = next[j];
            }
            if (s[i] == t[j + 1]) {
                j++;
            }
            if (j == lent - 1) {
                return true;
            }
        }
        return false;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<int> rootOrd, subOrd;
        dfsOrder(root, rootOrd);
        dfsOrder(subRoot, subOrd);
        return kmp(rootOrd, subOrd);
    }
};
// @lc code=end

