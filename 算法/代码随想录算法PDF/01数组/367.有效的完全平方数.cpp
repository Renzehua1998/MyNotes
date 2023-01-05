/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        int item = 1;
        while (num > 0) {
            num -= item;
            item += 2;
        }
        return num == 0;
    }
};
// @lc code=end

