#
# @lc app=leetcode.cn id=501 lang=python3
#
# [501] 二叉搜索树中的众数
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        maxCount = 0
        count = 0
        pre = None
        res = []

        st = []
        while root or st:
            if root:
                st.append(root)
                root = root.left
            else:
                root = st.pop()

                if not pre:
                    count = 1
                elif pre.val == root.val:
                    count += 1
                else:
                    count = 1
                pre = root

                if count == maxCount: res.append(root.val)
                if count > maxCount:
                    maxCount = count
                    res = []
                    res.append(root.val)

                root = root.right
        return res
# @lc code=end

