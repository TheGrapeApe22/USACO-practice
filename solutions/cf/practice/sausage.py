# https://codeforces.com/problemset/problem/2268/B

def is_meaty(x: int):
    return int(x.bit_count() % 2 == 0)

t = int(input())
for _ in range(t):
    n, q = [int(x) for x in input().split()]

    arr = input().split()
    for i in range(n):
        arr[i] = is_meaty(int(arr[i]))

    meaties = sum(arr)

    print(meaties, end=' ')
    for i in range(q):
        a, b = [int(x) for x in input().split()]
        meaties += is_meaty(b) - arr[a-1]
        arr[a-1] = is_meaty(b)
        print(meaties, end=' ')
    print()
