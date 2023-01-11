/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> charMap(26, 0);  // 26个字母的出现次数
        if (ransomNote.size() > magazine.size()) {  // 可有可无，有的话快一些
            return false;
        }
        for (int i = 0; i < magazine.size(); i++) {
            charMap[magazine[i] - 'a']++;
        }
        for (int i = 0; i < ransomNote.size(); i++) {
            charMap[ransomNote[i] - 'a']--;
            if (charMap[ransomNote[i] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

