#
# @lc app=leetcode.cn id=100 lang=python3
#
# [100] 相同的树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        st = []
        st.append(p)
        st.append(q)
        while st:
            p = st.pop()
            q = st.pop()
            if not p and not q: continue
            if not p or not q or p.val != q.val:
                return False
            st.append(p.left)
            st.append(q.left)
            st.append(p.right)
            st.append(q.right)
        return True
# @lc code=end

