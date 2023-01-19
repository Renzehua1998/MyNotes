#
# @lc app=leetcode.cn id=538 lang=python3
#
# [538] 把二叉搜索树转换为累加树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def convertBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        pre = 0
        st = []
        cur = root
        while cur or st:
            if cur:
                st.append(cur)
                cur = cur.right
            else:
                cur = st.pop()
                cur.val += pre
                pre = cur.val
                cur = cur.left
        return root
# @lc code=end

