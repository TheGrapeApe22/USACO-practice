# https://codeforces.com/problemset/problem/2267/F1
# terrible problem. pretty much just brute force after observations.

import random

def operation(arr):
    n = len(arr)
    pool = []
    for i in range(n):
        for j in range(i+1, n):
            pool.append(arr[i] ^ arr[j])
    return sorted(pool)[:n]

# arr = []
# for _ in range(20):
#     arr.append(random.randint(1, (1<<10)))

# for _ in range(10):
#     print(arr)
#     arr = operation(arr)

t = int(input())
for _ in range(t):
    n, q = [int(x) for x in input().split()]
    arr: list[int] = [int(x) for x in input().split()]
    arr = sorted(arr)
    cache = []
    for __ in range(33):
        cache.append(arr[-1] - arr[0])
        if sum(arr) == 0:
            break
        arr = operation(arr)

    for __ in range(q):
        print(cache[min(len(cache)-1, int(input()))])