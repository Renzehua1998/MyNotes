/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                if (s == "+") st.push(num2 + num1);
                if (s == "-") st.push(num2 - num1);
                if (s == "*") st.push(num2 * num1);
                if (s == "/") st.push(num2 / num1);
            } else {
                st.push(stoll(s));
            }
        }
        return st.top();
    }
};
// @lc code=end

