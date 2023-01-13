#
# @lc app=leetcode.cn id=347 lang=python3
#
# [347] 前 K 个高频元素
#

# @lc code=start
import collections
import random
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        def mySort(count, start, end, res, k):
            randIndex = random.randint(start, end - 1)  # 随机挑一个下标作为中间值开始找
            count[start], count[randIndex] = count[randIndex], count[start] # 先把这个随机找到的中间元素放到开头
            
            midVal = count[start][1] # 选中的中间值
            index = start + 1
            for i in range(start + 1, end):
                if count[i][1] > midVal: # 把所有大于中间值的放到左边
                    count[index], count[i] = count[i], count[index]
                    index += 1
            count[start], count[index - 1] = count[index - 1], count[start] # 中间元素归位

            if k < index - start: # 随机找到的top大元素比k个多，继续从前面top大里面找k个
                mySort(count, start, index, res, k)
            elif k > index - start: # 随机找到的比k个少
                for i in range(start, index): # 先把top大元素的key存入结果
                    res.append(count[i][0])
                mySort(count, index, end, res, k - (index - start)) # 继续往后找
            else: # 随机找到的等于k个
                for i in range(start, index): # 把topk元素的key存入结果
                    res.append(count[i][0])
                return
        
        num_map = collections.defaultdict(int)  # 次数字典
        for num in nums:
            num_map[num] += 1
        
        count = list(num_map.items())  # 转换为列表
        res = [] # 结果
        mySort(count, 0, len(count), res, k)  # 迭代函数求前k个
        return res
# @lc code=end

