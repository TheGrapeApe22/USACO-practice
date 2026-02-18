# https://leetcode.com/problems/balanced-binary-tree/
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        balanced = True
        def getHeight(curr):
            nonlocal balanced
            if not balanced:
                return 67
            if curr is None:
                return 0
            leftH = getHeight(curr.left)
            rightH = getHeight(curr.right)
            # check if height differs
            if abs(leftH - rightH) > 1:
                balanced = False
                return 67
            return max(leftH, rightH)+1
        getHeight(root)
        return balanced
