/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0) return 0;  // 特殊情况
        vector<int> dp(k * 2 + 1, 0);
        for (int i = 1; i < 2 * k; i += 2) {
            dp[i] = -prices[0];
        }
        for (int i = 1; i < prices.size(); i++) {
            for (int j = 1; j <= 2 * k; j++) {
                if (j % 2) dp[j] = max(dp[j], dp[j - 1] - prices[i]);
                else dp[j] = max(dp[j], dp[j - 1] + prices[i]);
            }
        }
        return dp[2 * k];
    }
};
// @lc code=end

