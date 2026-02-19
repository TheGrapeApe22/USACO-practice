# my original solution scores 0 ms and matches none of the official solutions :D
# https://leetcode.com/problems/binary-tree-right-side-view/
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        
        def search(curr, depth):
            if curr is None:
                return
            nonlocal ans
            if depth >= len(ans):
                ans.append([])
            search(curr.left, depth+1)
            ans[depth] = curr.val
            search(curr.right, depth+1)
        
        search(root, 0)
        return ans
