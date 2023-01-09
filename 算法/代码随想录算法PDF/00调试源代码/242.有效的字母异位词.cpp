/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        // vector<int> appear(26, 0);  // 三种初始化哈希数组的方式
        // int appear[26] = {0};
        // int* appear = new int[26] ();

        unordered_map <char, int> appear;  // 一种哈希映射的方式
        
        for (int i = 0; i < s.size(); i++) {
            appear[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            appear[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (appear[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

