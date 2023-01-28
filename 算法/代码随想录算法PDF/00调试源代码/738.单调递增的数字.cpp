/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */

// @lc code=start
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int nineIndex = s.size();  // 变为9的最左坐标
        for (int i = s.size() - 1; i > 0; i--) {
            if (s[i - 1] > s[i]) {
                s[i - 1]--;
                nineIndex = i;
            }
        }
        for (int i = nineIndex; i < s.size(); i++) {
            s[i] = '9';
        }
        return stoi(s);
    }
};
// @lc code=end

