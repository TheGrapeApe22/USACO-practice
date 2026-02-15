inputs = input().split()
n = int(inputs[0])
q = int(inputs[1])

cost = [int(i) for i in input().split()]
for i in range(1, n):
    cost[i] = min(cost[i], cost[i-1]*2)
while (len(cost) < 32):
    cost.append(cost[-1]*2)

for _ in range(q):
    ans = 0
    k = int(input())
    for i in range(0, 32):
        if ((k >> i)&1)==1:
            ans += cost[i]
    j = 0
    while (1<<j) < k:
        j += 1
    ans = min(ans, cost[j])
    print(ans)

# print(cost)