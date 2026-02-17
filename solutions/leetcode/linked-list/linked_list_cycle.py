# https://leetcode.com/problems/linked-list-cycle/
# cheesed because i couldn't figure out the two pointer solution
class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        dummy = ListNode()
        while head:
            if head == dummy:
                return True
            next = head.next
            head.next = dummy
            head = next
        return False
