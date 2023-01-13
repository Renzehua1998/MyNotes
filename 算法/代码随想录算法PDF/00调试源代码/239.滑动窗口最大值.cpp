/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class MyQueue {  // 单调队列
    public:
        deque<int> que;  // 底层用双向队列实现

        void push(int x) {  // 直到末尾元素大于x或全部pop，才将元素放入队尾
            while (!que.empty() && que.back() < x) {
                que.pop_back();
            }
            que.push_back(x);
        }

        void pop(int x) {  // 只有队头元素等于x，才把它pop出来，否则不动
            if (!que.empty() && que.front() == x) {
                que.pop_front();
            }
        }

        int maxVal() {  // 获取最大元素（当前队头元素）
            return que.front();
        }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> res;
        for (int i = 0; i < k; i++) {
            que.push(nums[i]);
        }
        res.push_back(que.maxVal());
        for (int i = k; i < nums.size(); i++) {
            que.pop(nums[i - k]);
            que.push(nums[i]);
            res.push_back(que.maxVal());
        }
        return res;
    }
};
// @lc code=end

