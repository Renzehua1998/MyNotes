/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2) {  // 奇数必不满足，剪枝
            return false;
        }
        stack<char> st;
        for (char c : s) {
            if (c == '(') {
                st.push(')');
            } else if (c == '[') {
                st.push(']');
            } else if (c == '{') {
                st.push('}');
            } else if (st.empty() || st.top() != c) { // 半中间栈空了或右括号匹配不上
                return false;
            } else {
                st.pop();
            }
        }
        return st.empty();
    }
};
// @lc code=end

