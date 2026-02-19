# https://leetcode.com/problems/lru-cache/
class Node:
    def __init__(self, val:int = 0, key:Optional[Node] = None, prev:Optional[Node] = None, next:Optional[Node] = None):
        self.key = key
        self.val = val
        self.prev = prev
        self.next = next

class LRUCache:
    def __init__(self, capacity: int):
        self.cap = capacity
        self.nodes = {}
        self.size = 0
        self.head = Node()
        self.tail = self.head

    def move_to_end(self, key):
        curr = self.nodes[key]
        if curr.next:
            curr.prev.next = curr.next
            curr.next.prev = curr.prev
            curr.next = None
            curr.prev = self.tail
            self.tail.next = curr
            self.tail = curr
        
    def get(self, key: int) -> int:
        if key not in self.nodes:
            return -1
        # move it to the end of the list
        self.move_to_end(key)
        return self.tail.val

    def put(self, key: int, value: int) -> None:
        if key not in self.nodes:
            if self.size == self.cap:
                # evict LRU
                del self.nodes[self.head.next.key]
                self.head.next = self.head.next.next
                if self.head.next:
                    self.head.next.prev = self.head
                else:
                    self.tail = self.head
                self.size -= 1
            # add node at end
            self.nodes[key] = Node(key=key, val=value, prev=self.tail)
            self.tail.next = self.nodes[key]
            self.tail = self.tail.next
            self.size += 1
            
        else:
            # move node to end
            self.move_to_end(key)
            self.tail.val = value
