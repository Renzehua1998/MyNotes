#
# @lc app=leetcode.cn id=110 lang=python3
#
# [110] 平衡二叉树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if not root: return True
        st = [root]
        map = {}
        while st:
            node = st.pop()
            if node:
                st.append(node)
                st.append(None)
                if node.right: st.append(node.right)
                if node.left: st.append(node.left)
            else:
                node = st.pop()
                left, right = map.get(node.left, 0), map.get(node.right, 0)
                if abs(left - right) > 1:
                    return False
                map[node] = 1 + max(left, right)
        return True
# @lc code=end

