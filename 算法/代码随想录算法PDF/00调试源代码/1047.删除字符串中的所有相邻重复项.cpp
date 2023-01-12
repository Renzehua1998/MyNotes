/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        int slow = 0, fast = 0;
        while (fast < s.size()) {
            s[slow] = s[fast];
            if (slow > 0 && s[slow] == s[slow - 1]) {
                slow--;
            } else {
                slow++;
            }
            fast++;
        }
        return s.substr(0, slow);
    }
};
// @lc code=end

