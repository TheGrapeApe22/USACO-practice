# https://cses.fi/problemset/result/19096666/
# silly mistake: returned 0 instead of arr[val] in edge case

n = int(input())
arr = [int(x) for x in input().split()]
n = len(arr)

cache = [[-1e11] * n] * n

def solve(left, right, sum):
    # print(left, right, sum, cache[left][right])
    if left == right:
        print(left, right, sum, cache[left][right])
        return arr[left]
    if cache[left][right] != -1e11:
        print(left, right, sum, cache[left][right])
        return cache[left][right]
    cache[left][right] = max(
        sum - solve(left+1, right, sum-arr[left]),
        sum - solve(left, right-1, sum-arr[right])
    )
    print(left, right, sum, cache[left][right])
    return cache[left][right]

print(solve(0, n-1, sum(arr)))
