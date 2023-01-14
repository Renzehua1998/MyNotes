#
# @lc app=leetcode.cn id=429 lang=python3
#
# [429] N 叉树的层序遍历
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
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        def order(node, res, layer):
            if node == None:
                return
            if len(res) == layer:
                res.append([])
            res[layer].append(node.val)
            for ch in node.children:
                order(ch, res, layer + 1)

        res = []
        layer = 0
        order(root, res, layer)
        return res
        
# @lc code=end

