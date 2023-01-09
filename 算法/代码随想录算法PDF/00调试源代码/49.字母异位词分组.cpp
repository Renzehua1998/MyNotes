/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res; // 结果
        unordered_map <string, int> repeat; // key：排序后的字符串；value：异位词数组在结果数组的下标
        int index = 0;
        for (auto str: strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());  // t作为s排序字符串，异位词将完全相同
            if (repeat.count(tmp)) {
                res[repeat[tmp]].push_back(str);
            } else {
                repeat[tmp] = index++;  // 新字符串排序存入字典，其结果下标自增放入
                vector<string> singleStr(1, str);
                res.push_back(singleStr);
            }
        }
        return res;
    }
};
// @lc code=end

