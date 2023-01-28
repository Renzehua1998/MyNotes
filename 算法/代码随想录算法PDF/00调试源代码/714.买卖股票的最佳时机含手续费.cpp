/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int res = 0;
        int minPrice = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < minPrice) minPrice = prices[i];
            if (prices[i] > minPrice + fee) {
                res += prices[i] - minPrice - fee;
                minPrice = prices[i] - fee;  // 重要！用于在有更高价格时后悔
            }
        }
        return res;
    }
};
// @lc code=end

