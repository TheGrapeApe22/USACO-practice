# https://usaco.org/index.php?page=viewproblem2&cpid=1063
# brute force, O(n^5) works for n<(10^8)^(1/5)=40 heheheh

n = int(input())
points = []
xs = []
ys = []

for _ in range(n):
    a, b = [int(x) for x in input().split()]
    points.append([a, b])
    xs.append(a)
    ys.append(b)

# print(points)

contained = [False] * (1<<n)

for x1 in xs:
    for x2 in xs:
        for y1 in ys:
            for y2 in ys:
                bits = 0
                for i in range(n):
                    p = points[i]
                    if min(x1, x2) <= p[0] and p[0] <= max(x1, x2) and \
                    min(y1, y2) <= p[1] and p[1] <= max(y1, y2):
                        bits |= (1<<(n-i-1))
                # print(f"{str(bin(bits))[2:]:0>4}")
                contained[bits] = True

print(sum(contained))