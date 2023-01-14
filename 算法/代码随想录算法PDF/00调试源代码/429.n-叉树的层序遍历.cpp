/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void order(Node* node, vector<vector<int>>& res, int layer) {
        if (node == nullptr) return;
        if (res.size() == layer) res.push_back(vector<int>());  // 开始了新的一层
        res[layer].push_back(node->val);
        for (auto& ch : node->children) {
            order(ch, res, layer + 1);
        }
    }
    vector<vector<int>> levelOrder(Node* root) {
        int layer = 0;  // 层数，用于确认遍历到节点值放的位置
        vector<vector<int>> res;
        order(root, res, layer);
        return res;
    }
};
// @lc code=end

