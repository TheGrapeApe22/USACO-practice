# https://leetcode.com/problems/reverse-linked-list/
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return None
        prev = None
        curr = head
        
        while curr.next is not None:
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
            
        curr.next = prev
        return curr
