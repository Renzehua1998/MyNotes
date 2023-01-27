/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int ten = 0, five = 0;
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) five++;
            if (bills[i] == 10) {
                if (five) {
                    five--;
                    ten++;
                } else {
                    return false;
                }
            }
            if (bills[i] == 20) {
                if (ten && five) {
                    ten--;
                    five--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

