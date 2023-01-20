/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
public:
    vector<string> res;
    vector<string> path;
    bool isIPNum(string& s, int left, int right) {
        if (left > right) return false;  // 输入参数不合适
        if (s[left] == '0' && left < right) return false;  // 以0打头
        int num = 0;
        for (int i = left; i <= right; i++) {
            if (s[i] < '0' || s[i] > '9') return false; // 非数字不合规
            num = num * 10 + (s[i] - '0');
            if (num > 255) return false;  // 大于255
        }
        return true;
    }
    void backtracking(string& s, int startIndex) {
        if (path.size() == 4 && startIndex >= s.size()) {
            string ans = "";
            for (string part : path) {
                ans += part;
                ans += ".";
            }
            ans.erase(ans.end() - 1); // 删除最后一个点
            res.push_back(ans);
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (isIPNum(s, startIndex, i)) {
                path.push_back(s.substr(startIndex, i - startIndex + 1));
                backtracking(s, i + 1);
                path.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        res.clear();
        if (s.size() < 4 || s.size() > 12) return res;
        backtracking(s, 0);
        return res;
    }
};
// @lc code=end

