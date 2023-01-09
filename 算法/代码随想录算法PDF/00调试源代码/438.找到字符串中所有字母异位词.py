#
# @lc app=leetcode.cn id=438 lang=python3
#
# [438] 找到字符串中所有字母异位词
#

# @lc code=start
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        m , n = len(s), len(p)
        res = []
        if m < n: return res
        smap = [0] * 26
        pmap = [0] * 26
        for i in range(n):
            smap[ord(s[i]) - ord('a')] += 1
            pmap[ord(p[i]) - ord('a')] += 1
        if smap == pmap: res.append(0)
        for i in range(n, m):
            smap[ord(s[i]) - ord('a')] += 1
            smap[ord(s[i - n]) - ord('a')] -= 1
            if smap == pmap: res.append(i - n + 1)
        return res
# @lc code=end

