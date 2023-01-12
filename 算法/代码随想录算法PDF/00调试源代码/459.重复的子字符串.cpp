/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution {
public:
    void getNext(int* next, string s) {
        int j = -1;
        next[0] = j;
        for (int i = 1; i < s.size(); i++) { // 遍历s填充next
            while (j >= 0 && s[j + 1] != s[i]) {
                j = next[j];  // 回溯相同子串继续匹配
            }
            if (s[j + 1] == s[i]) {
                j++;
            }
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern(string s) {
        if (s.size() == 0) {  // 特殊情况
            return false;
        }
        int next[s.size()];
        getNext(next, s);
        if (next[s.size() - 1] != -1 && s.size() % (s.size() - (next[s.size() - 1] + 1)) == 0) {
            return true;
        } else {
            return false;
        }
    }
};
// @lc code=end

