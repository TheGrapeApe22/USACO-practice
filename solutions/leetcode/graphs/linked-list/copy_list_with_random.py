# https://leetcode.com/problems/copy-list-with-random-pointer/
# the O(1) space solution for this is genius btw
class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        copies = {None: None}
        a = Node(x=0, next=head)
        b = Node(x=0)
        while a.next:
            b.next = Node(x=a.next.val)
            copies[a.next] = b.next
            a = a.next
            b = b.next
        a = head
        b = copies[head]
        # print(copies)
        while a:
            b.random = copies[a.random]
            a = a.next
            b = b.next
        return copies[head]
