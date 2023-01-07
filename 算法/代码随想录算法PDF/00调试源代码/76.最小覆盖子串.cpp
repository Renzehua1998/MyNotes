/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map <char, int> need;  // 每个字符的需求字典
        int left = 0, right = 0; // 左右指针
        int start = 0, size = INT32_MAX; // 子串位置和长度，动态更新
        int needCnt = t.length(); // 总共还需要的字符数量
        for (char c: t) {  // 初始化need
            need[c]++;
        }
        while (right < s.length()) { // 窗口右指针滑动
            char c = s[right];
            if (need[c] > 0) needCnt--;  // 更新总需要数量
            need[c]--; // 更新need
            if (needCnt == 0) {  // 此时需要改变左指针滑动窗口
                while (left < right && need[s[left]] < 0) {  // 左窗口移动直到下一个不满足覆盖
                    need[s[left++]]++;
                }
                if (right - left + 1 < size) {  // 更新子串位置
                    size = right - left + 1;
                    start = left;
                }
                need[s[left++]]++;  // 左指针移动开启下一轮窗口
                needCnt ++;  // 刚好缺一个
            }
            right++;
        }
        return size == INT32_MAX ? "" : s.substr(start, size);
    }
};
// @lc code=end

