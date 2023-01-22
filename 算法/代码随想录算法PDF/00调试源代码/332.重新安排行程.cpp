/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
class Solution {
public:
    unordered_map<string, deque<string>> targets;
    vector<string> res;
    int ticketNum;
    bool backtracking(const string& start) {
        if (res.size() == ticketNum + 1) return true;
        for (int i = 0; i < targets[start].size(); i++) {
            string tmp = targets[start].front();
            targets[start].pop_front();
            res.push_back(tmp);
            if (backtracking(tmp)) return true;
            res.pop_back();
            targets[start].push_back(tmp);
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        targets.clear();
        res.clear();
        for (const vector<string>& ticket : tickets) {  // 初始化目标映射
            targets[ticket[0]].push_back(ticket[1]);
        }
        res.push_back("JFK");
        ticketNum = tickets.size();
        for (pair<const string, deque<string>>& target : targets) {
            sort(target.second.begin(), target.second.end());
        }
        backtracking("JFK");
        return res;
    }
};
// @lc code=end

