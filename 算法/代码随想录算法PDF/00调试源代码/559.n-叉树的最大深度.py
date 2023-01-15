#
# @lc app=leetcode.cn id=559 lang=python3
#
# [559] N 叉树的最大深度
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
    def maxDepth(self, root: 'Node') -> int:
        que = deque([])
        depth = 0
        if root:
            que.append(root)
        while que:
            depth += 1
            size = len(que)
            while size:
                node = que.popleft()
                for ch in node.children:
                    if ch:
                        que.append(ch)
                size -= 1
        return depth
# @lc code=end

