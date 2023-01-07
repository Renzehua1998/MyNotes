#
# @lc app=leetcode.cn id=76 lang=python3
#
# [76] 最小覆盖子串
#

# @lc code=start
import collections
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        need = collections.defaultdict(int)  # 需求字典
        for c in t:
            need[c] += 1
        left = 0  # 左指针
        needCnt = len(t)  # 总需求
        zone = (0, float('inf'))  # 截取最小覆盖子串的区间
        for right in range(len(s)):  # 遍历右指针
            c = s[right]
            if need[c] > 0:  # 更新需求字典
                needCnt -= 1
            need[c] -= 1
            if needCnt == 0:  # 满足条件以后
                while need[s[left]] < 0:  # 移动左指针到第一个不满足的字符之前
                    need[s[left]] += 1
                    left += 1
                if right - left < zone[1] - zone[0]: # 更新最优子串位置
                    zone = (left, right)
                need[s[left]] += 1
                needCnt += 1
                left += 1
        return '' if zone[1] == float('inf') else s[zone[0]: zone[1] + 1]
# @lc code=end

