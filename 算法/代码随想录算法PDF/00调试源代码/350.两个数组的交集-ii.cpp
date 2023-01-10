/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());  // 给两个数组排序
        sort(nums2.begin(), nums2.end());
        int point1 = 0, point2 = 0; // 两个数组的指针
        while (point1 < nums1.size() && point2 < nums2.size()) {
            if (nums1[point1] < nums2[point2]) {
                point1++;
            } else if (nums1[point1] > nums2[point2]) {
                point2++;
            } else {
                res.push_back(nums1[point1]);
                point1++;
                point2++;
            }
        }
        return res;
    }
};
// @lc code=end

