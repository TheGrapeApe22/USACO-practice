"""
https://usaco.org/index.php?page=viewproblem2&cpid=1542
YOOOO i thought this problem was gonna be impossible but i actually broke it down really well :D
i am not gonna try to leave notes for this one lmao. check purple notebook if scavenging.
"""


# arr = []
# for t in range(30):
#     if t > 0:
#         arr = arr[1:t//2+1] + [arr[0]] + arr[t//2+1:]
#     arr.append(t)
#     print(t, arr)

# t = 7
# i = 4
# for _ in range(10):
#     print(t, i)
#     temp = t+i+1
#     i, t = temp//2, temp

def whereis(x, search_t):
    if search_t < 2*x-1:
        return x

    t = max(0, 2*x-1)
    i = x
    while t < search_t:
        temp = t+i+1
        i, t = temp//2, temp
    # print(f'at time {t}, cow {x} is at {i}')
    if t == search_t:
        return i
    return t-search_t-1

def whatisat0(t):
    if (t + 1) % 3 == 0:
        return (t + 1) // 3
    return whatisat0((2*t+2)//3 - 1)

def whatisat(i, t):
    if i >= t//2 + 1:
        return i
    return whatisat0(i+t)

# for r in range(30):
#     print(r, '[', end='')
#     for i in range(r+1):
#         print(whatisat(i, r), end=', ')
#     print(']')
# for r in range(30):
#     print(whatisat0(r))
# print('chesee')
# print(whatisat(2, 9))

n = int(input())
for _ in range(n):
    a, b, c = [int(x) for x in input().split()]
    if a == 1:
        print(whereis(b, c))
    else:
        print(whatisat(b, c))