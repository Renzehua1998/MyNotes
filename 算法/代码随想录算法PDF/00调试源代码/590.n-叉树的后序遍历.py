#
# @lc app=leetcode.cn id=590 lang=python3
#
# [590] N 叉树的后序遍历
#

# @lc code=start
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        res = []
        st = []
        if root:
            st.append(root)
        while st:
            node = st.pop()
            if node:
                st.append(node)
                st.append(None)
                for i in range(len(node.children), 0, -1):
                    if node.children[i - 1]:
                        st.append(node.children[i - 1])
            else:
                node = st.pop()
                res.append(node.val)
        return res
# @lc code=end

