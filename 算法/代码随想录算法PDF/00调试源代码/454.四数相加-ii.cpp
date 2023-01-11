/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> umap;  // 存放前两个数组所有可能的和
        for (int a : nums1) {
            for (int b : nums2) {
                umap[a + b]++;
            }
        }
        int count = 0;  // 只计数即可
        for (int c : nums3) {
            for (int d : nums4) {
                if (umap.find(0 - c - d) != umap.end()) {
                    count += umap[0 - c - d];
                }
            }
        }
        return count;
    }
};
// @lc code=end

