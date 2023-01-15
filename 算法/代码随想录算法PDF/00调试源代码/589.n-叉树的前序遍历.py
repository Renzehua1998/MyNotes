#
# @lc app=leetcode.cn id=589 lang=python3
#
# [589] N 叉树的前序遍历
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
    def preorder(self, root: 'Node') -> List[int]:
        res = []
        st = []
        if root == None:
            return res
        st.append(root)
        while st:
            node = st.pop()
            res.append(node.val)
            for i in range(len(node.children), 0, -1):
                if node.children[i - 1]:
                    st.append(node.children[i - 1])
        return res
# @lc code=end

