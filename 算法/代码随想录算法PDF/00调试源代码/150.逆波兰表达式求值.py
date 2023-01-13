#
# @lc app=leetcode.cn id=150 lang=python3
#
# [150] 逆波兰表达式求值
#

# @lc code=start
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        st = []
        for s in tokens:
            if s in {"+", "-", "*", "/"}:
                num1 = st.pop()
                num2 = st.pop()
                st.append(int(eval(f'{num2} {s} {num1}')))
            else:
                st.append(int(s))
        return st.pop()
# @lc code=end

