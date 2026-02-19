# https://leetcode.com/problems/reorder-list/description/
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        if not head.next:
            return head
        
        # find halfway point
        slow = head
        fast = head.next
        while fast.next:
            slow = slow.next
            fast = fast.next
            if fast.next:
                fast = fast.next
        
        curr = slow.next
        slow.next = None

        # reverse from halfway point
        prev = None
        while curr:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
        
        a = head
        b = prev
        
        # merge two lists
        while a:
            # insert b in between a and b
            temp = b.next
            b.next = a.next
            a.next = b
            b = temp
            if b is None:
                break
            a = a.next.next
