#
# @lc app=leetcode.cn id=20 lang=python3
#
# [20] 有效的括号
#

# @lc code=start
class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) % 2:  # 奇数一定不满足，剪枝
            return False
        st = []
        mapping = {  # 对照表
            '(' : ')',
            '[' : ']',
            '{' : '}',
        }
        for c in s:
            if c in mapping.keys():
                st.append(mapping[c])
            elif not st or st[-1] != c:
                return False
            else:
                st.pop()
        return not st
# @lc code=end

