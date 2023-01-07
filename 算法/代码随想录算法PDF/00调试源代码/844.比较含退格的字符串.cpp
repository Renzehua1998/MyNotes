/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1, j = t.length() - 1;  // 字符串遍历变量
        int backS = 0, backT = 0;
        while (i >= 0 || j >= 0) {
            if (i >= 0) {  // 防止某个指针减到-1以后数组越界
                if (s[i] == '#') {  // 为#号时清空自增
                    backS++;
                    i--;
                    continue;
                } else if (backS > 0) {  // 不为#号但后面有清空时清空不考虑
                    backS--;
                    i--;
                    continue;
                }
            }
            if (j >= 0) {
                if (t[j] == '#') {
                    backT++;
                    j--;
                    continue;
                } else if (backT > 0) {
                    backT--;
                    j--;
                    continue;
                }
            }
            if (i >= 0 && j >= 0) {
                if (s[i] != t[j]) {
                    return false;
                }
            } else if (i >= 0 || j >= 0) {  // 有一个字符串先跑完了，此时为false
                return false;
            }
            i--; j--;
        }
        return true;
    }
};
// @lc code=end

