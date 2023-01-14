#
# @lc app=leetcode.cn id=71 lang=python3
#
# [71] 简化路径
#

# @lc code=start
class Solution:
    def simplifyPath(self, path: str) -> str:
        st = []
        i = 0  # 遍历下标
        while i < len(path):
            if path[i] == '/':
                i += 1
            else:
                folder = ""
                while i < len(path) and path[i] != '/':
                    folder += path[i]
                    i += 1
                if folder == ".." and st:
                    st.pop()
                elif folder != ".." and folder != ".":
                    st.append(folder)
        res = "/"
        for f in st:
            res += f + "/"
        if len(res) > 1:
            res = res[:-1]
        return res

# @lc code=end

