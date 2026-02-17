# https://leetcode.com/problems/remove-nth-node-from-end-of-list/
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        curr = head
        size = 0
        while curr:
            size += 1
            curr = curr.next
        
        dummy = ListNode(next=head)
        curr = dummy
        for _ in range(size - n):
            curr = curr.next
        curr.next = curr.next.next
        return dummy.next
