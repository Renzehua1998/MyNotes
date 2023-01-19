#
# @lc app=leetcode.cn id=450 lang=python3
#
# [450] 删除二叉搜索树中的节点
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if not root: return root
        cur = root
        pre = None
        while cur:
            if cur.val == key: break
            pre = cur
            if cur.val > key:
                cur = cur.left
            else:
                cur = cur.right
        if cur:
            if not cur.right:
                if pre:
                    if pre.val > key:
                        pre.left = cur.left
                    else:
                        pre.right = cur.left
                    return root
                else:
                    return cur.left
            tmp = cur.right
            while tmp.left:
                tmp = tmp.left
            tmp.left = cur.left
            if pre:
                if pre.val > key:
                    pre.left = cur.right
                else:
                    pre.right = cur.right
            else:
                return cur.right
        return root
# @lc code=end

