# https://leetcode.com/problems/diameter-of-binary-tree/
class Solution:
    def search(self, curr: Optional[TreeNode]):
        # find depth (from bottom) of current node and maxDiameter of (this node and all its children)
        if curr is None:
            return (0, 0)
        depth_left, diameter_left = self.search(curr.left)
        depth_right, diameter_right = self.search(curr.right)
        
        depth = max(depth_left, depth_right) + 1
        maxDiameter = max(diameter_left, diameter_right, depth_left + depth_right)
        return (depth, maxDiameter)

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        return self.search(root)[1]
