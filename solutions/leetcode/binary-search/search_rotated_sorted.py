class Solution:
    def search(self, arr: List[int], target: int) -> int:
        l = 0
        r = len(arr) - 1
        while l < r:
            mid = (l+r)//2
            if arr[mid] == target:
                return mid
            
            # target is on the left
            if target >= arr[0]:
                # mid is on the left
                if arr[mid] >= arr[0]:
                    if arr[mid] > target:
                        r = mid - 1
                    else:
                        l = mid + 1
                # mid is on the right
                else:
                    r = mid - 1
            # target is on the right
            else:
                # mid is on the left
                if arr[mid] >= arr[0]:
                    l = mid + 1
                # mid is on the right
                else:
                    if arr[mid] > target:
                        r = mid - 1
                    else:
                        l = mid + 1
        if arr[l] == target:
            return l
        return -1