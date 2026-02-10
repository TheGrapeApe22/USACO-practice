# https://leetcode.com/problems/balance-a-binary-search-tree
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def balanceBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        elements = []
        def search(node):
            elements.append(node.val)
            if node.left is not None:
                search(node.left)
            if node.right is not None:
                search(node.right)
        search(root)
        elements.sort()
        def build(l, r):
            if (l > r):
                return None
            mid = (l+r)//2
            curr = TreeNode (val=elements[mid])
            curr.left = build(l, mid-1)
            curr.right = build(mid+1, r)
            return curr
        return build(0, len(elements)-1)

