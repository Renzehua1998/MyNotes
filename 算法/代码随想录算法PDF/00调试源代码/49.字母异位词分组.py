#
# @lc app=leetcode.cn id=49 lang=python3
#
# [49] 字母异位词分组
#

# @lc code=start
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        repeat = {}  # 结果字典
        for str in strs:
            temp = ''.join(sorted(str))
            if temp not in repeat:
                repeat[temp] = [str]
            else:
                repeat[temp].append(str)
        return list(repeat.values())
# @lc code=end

