/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N 叉树的后序遍历
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
    vector<int> postorder(Node* root) {  // 统一法
        vector<int> res;
        stack<Node*> st;
        if (root) st.push(root);
        while (!st.empty()) {
            Node* node = st.top();
            if (node) {
                st.pop();
                st.push(node);
                st.push(nullptr);
                for (int i = node->children.size(); i > 0; i--){
                    if (node->children[i - 1]) {
                        st.push(node->children[i - 1]);
                    }
                }
            } else {
                st.pop();
                node = st.top();
                st.pop();
                res.push_back(node->val);
            }
        }
        return res;
    }
};
// @lc code=end

