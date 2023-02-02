/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp(2, 0);
        dp[0] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            int dp0 = dp[0], dp1 = dp[1];
            dp[0] = max(dp0, -prices[i]);
            dp[1] = max(dp1, prices[i] + dp0);
        }
        return dp[1];
    }
};
// @lc code=end

