/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    int getHappy(int n) {  // 获取下一个happy数
        int res = 0;
        while (n) {
            res += (n % 10) * (n % 10);
            n /= 10;
        }
        return res;
    }

    bool isHappy(int n) {
        unordered_set<int> Cycle({4, 16, 37, 58, 89, 145, 42, 20});
        do {
            n = getHappy(n);
        } while (n != 1 && Cycle.find(n) == Cycle.end());
        return n == 1;
    }
};
// @lc code=end

