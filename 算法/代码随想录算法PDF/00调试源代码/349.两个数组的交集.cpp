/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> resSet;
        vector<int> numVec(1001, 0);
        for (int num : nums1) {
            numVec[num] = 1;
        }
        for (int num : nums2) {
            if (numVec[num] == 1) {
                resSet.insert(num);
            }
        }
        return vector<int> (resSet.begin(), resSet.end());
    }
};
// @lc code=end

