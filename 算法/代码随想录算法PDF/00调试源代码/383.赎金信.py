#
# @lc app=leetcode.cn id=383 lang=python3
#
# [383] 赎金信
#

# @lc code=start
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        charMap = [0] * 26  # 字符哈希数组
        for ch in magazine:
            charMap[ord(ch) - ord('a')] += 1
        for ch in ransomNote:
            charMap[ord(ch) - ord('a')] -= 1
            if charMap[ord(ch) - ord('a')] < 0:
                return False
        return True
# @lc code=end

