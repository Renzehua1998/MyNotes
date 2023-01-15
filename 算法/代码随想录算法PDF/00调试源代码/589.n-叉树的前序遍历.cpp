/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
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
    vector<int> preorder(Node* root) {
        vector<int> res;
        stack<Node*> st;
        if (root == nullptr) return res;
        st.push(root);
        while (!st.empty()) {
            Node* node = st.top();
            st.pop();
            res.push_back(node->val);
            for (int i = node->children.size(); i > 0; i--) {
                if (node->children[i - 1]) st.push(node->children[i - 1]);
            }
        }
        return res;
    }
};
// @lc code=end

