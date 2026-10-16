# https://codeforces.com/problemset/problem/2268/B

def is_meaty(x: int):
    return x.bit_count() % 2 == 0

t = int(input())
for _ in range(t):
    n = int(input())
    q = int(input())
    for i in range(n):
        arr[i] = int(input())
