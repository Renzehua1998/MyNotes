/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    vector<vector<int>> getBord(string& s) {
        vector<vector<int>> hash(26, vector<int>(2, INT_MIN));
        for (int i = 0; i < s.size(); i++) {
            if (hash[s[i] - 'a'][0] == INT_MIN) hash[s[i] - 'a'][0] = i;  // 左边界
            hash[s[i] - 'a'][1] = i;  // 右边界
        }
        vector<vector<int>> hash_filter;  // 去掉没出现的字符
        for (int i = 0; i < 26; i++) {
            if (hash[i][0] != INT_MIN) hash_filter.push_back(hash[i]);
        }
        return hash_filter;
    }
    vector<int> partitionLabels(string s) {
        vector<vector<int>> hash = getBord(s);
        sort(hash.begin(), hash.end(), cmp);  // 按左区间从小到大排
        vector<int> res;
        int left = 0;
        int right = hash[0][1];
        for (int i = 1; i < hash.size(); i++) {
            if (hash[i][0] > right) {
                res.push_back(right - left + 1);
                left = hash[i][0];
            }
            right = max(right, hash[i][1]);
        }
        res.push_back(right - left + 1);  // 最后一个区间
        return res;
    }
};
// @lc code=end

