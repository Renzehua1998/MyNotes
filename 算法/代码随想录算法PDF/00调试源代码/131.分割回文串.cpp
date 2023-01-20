/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    bool isPalindrome(string& s, int start, int end) {
        while (start <= end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    void backtracking(string& s, int startIndex) {
        if (startIndex >= s.size()) {
            res.push_back(path);
            return ;
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (isPalindrome(s, startIndex, i)) {
                path.push_back(s.substr(startIndex, i - startIndex + 1));
                backtracking(s, i + 1);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return res;
    }
};
// @lc code=end

