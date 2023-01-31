/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (string word : wordDict) {
                if (i >= word.size()) {
                    dp[i] = dp[i] || (dp[i - word.size()] && word == s.substr(i - word.size(), word.size()));
                }
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end

