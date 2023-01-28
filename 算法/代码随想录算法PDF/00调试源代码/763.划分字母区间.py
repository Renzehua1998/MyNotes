#
# @lc app=leetcode.cn id=763 lang=python3
#
# [763] 划分字母区间
#

# @lc code=start
class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        # 记录每个字母出现的区间
        def getBord(s):
            hash = [[-float('inf')] * 2 for _ in range(26)]
            for i in range(len(s)):
                if hash[ord(s[i]) - ord('a')][0] == -float('inf'):
                    hash[ord(s[i]) - ord('a')][0] = i
                hash[ord(s[i]) - ord('a')][1] = i
            # 去除字符串中未出现的字母所占用区间
            hash_filter = []
            for item in hash:
                if item[0] != -float('inf'): hash_filter.append(item)
            return hash_filter

        # 得到无重叠区间题意中的输入样例格式：区间列表
        hash = getBord(s)
        # 按照左边界从小到大排序
        hash.sort(key= lambda x: x[0])
        res = []
        left = 0
        # 记录最大右边界
        right = hash[0][1]
        for i in range(len(hash)):
            # 一旦下一区间左边界大于当前右边界，即可认为出现分割点
            if hash[i][0] > right:
                res.append(right - left + 1)
                left = hash[i][0]
            # 实时更新最大右边界
            right = max(right, hash[i][1])
        # 最右侧区间（字符串长度为1时的特殊情况也包含于其中）
        res.append(right - left + 1)
        return res
# @lc code=end

