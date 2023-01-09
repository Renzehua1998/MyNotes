/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.length(), n = p.length();
        vector <int> res;
        if (n > m) {  // 特殊情况
            return res;
        }

        vector <int> smap(26, 0), pmap(26, 0);  // 字典
        for (int i = 0; i < n; i++) {
            smap[s[i] - 'a']++;
            pmap[p[i] - 'a']++;
        }
        if (smap == pmap) {
            res.push_back(0);
        }
        for (int i = n; i < m; i++) {
            smap[s[i] - 'a']++;
            smap[s[i-n] - 'a']--;
            if (smap == pmap) {
                res.push_back(i - n + 1);
            }
        }
        return res;
    }
};
// @lc code=end

