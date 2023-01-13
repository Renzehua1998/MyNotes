/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    void mySort(vector<pair<int, int>>& count, int start, int end, vector<int>& res, int k) {
        int randIndex = rand() % (end - start) + start;  // 随机挑一个下标作为中间值开始找
        swap(count[start], count[randIndex]);  // 先把这个随机找到的中间元素放到开头
        
        int midVal = count[start].second;  // 选中的中间值
        int index = start + 1;
        for (int i = start + 1; i < end; i++) {
            if (count[i].second > midVal) {  // 把所有大于中间值的放到左边
                swap(count[index++], count[i]);
            }
        }
        swap(count[start], count[index - 1]);  // 中间元素归位

        if (k < index - start) {  // 随机找到的top大元素比k个多，继续从前面top大里面找k个
            mySort(count, start, index, res, k);
        } else {
            for (int i = start; i < index; i++) {  // 随机找到的比k个少或相等
                res.push_back(count[i].first);  // 先把top大元素的key存入结果
            }
            if (k > index - start) {  // 如果恰好等于，不用做。若比k个少，需要继续往后找
                mySort(count, index, end, res, k - (index - start));
            }
        }

    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;  // 使用map统计次数
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        vector<pair<int, int>> count;  // 将map转换为pair数组
        for (auto& item : map) {
            count.push_back(item);
        }

        vector<int> res;  // 结果数组
        mySort(count, 0, count.size(), res, k);  // 递归寻找前k个最大值的函数
        return res;
    }
};
// @lc code=end

