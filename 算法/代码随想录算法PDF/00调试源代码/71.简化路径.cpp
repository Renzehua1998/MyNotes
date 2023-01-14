/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        deque<string> st;
        for (int i = 0; i < path.size();) {
            if (path[i] == '/') {  // 遇到分隔符，继续向后遍历
                i++;
            } else {
                string folder;  // 文件夹名
                while (i < path.size() && path[i] != '/') {
                    folder += path[i++];
                }
                if (folder == ".." && !st.empty()) {  // 返回上一级
                    st.pop_back();
                } else if (folder != ".." && folder != ".") {  // 正常文件目录
                    st.push_back(folder);
                }
            }
        }
        string res = "/";
        for (string& s : st) {
            res += s + "/";
        }
        if (res.size() > 1) {
            res.pop_back();
        }
        return res;
    }
};
// @lc code=end

