/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
private:
    const string letterMap[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
public:
    vector<string> res;
    string s;
    void backtracking(string& digits, int index) {
        if (index == digits.size()) {
            res.push_back(s);
            return ;
        }
        string letters = letterMap[digits[index] - '0'];  // 取到此时的字符集
        for (char c : letters) {
            s.push_back(c);
            backtracking(digits, index + 1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return res;
        backtracking(digits, 0);
        return res;
    }
};
// @lc code=end

