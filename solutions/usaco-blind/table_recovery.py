# https://usaco.org/index.php?page=viewproblem2&cpid=1472
# fun, easy problem. just analyze frequencies and recognize that there are 2 possible OGs due to having 2 singletons (top left or bottom right corner of OG.)

from collections import defaultdict
n = int(input())

if n == 1:
    print(input())
    exit()

freq = defaultdict(int)
board = []

for _ in range(n):
    board.append([int(x) for x in input().split()])
    for x in board[-1]:
        freq[x] += 1

reverse_freq = defaultdict(list)
for key, val in freq.items():
    reverse_freq[val].append(key)

def get_other_num_with_same_freq(x):
    if freq[x] == n:
        return x
    a, b = reverse_freq[freq[x]]
    if a == x:
        return b
    return a

singletons = [i for i in range(n) if any([freq[board[i][j]] == 1 for j in range(n)])]

def map_to_og(singleton):
    assign = {}
    for i in range(n):
        x = board[singleton][i]
        assign[x] = freq[x]+1
        assign[get_other_num_with_same_freq(x)] = 2*n+1-freq[x]
    return assign

a = map_to_og(singletons[0])
b = map_to_og(singletons[1])

def better_lex():
    for i in range(n):
        for j in range(n):
            x = board[i][j]
            if a[x] == b[x]:
                continue
            if a[x] < b[x]:
                return a
            return b
    assert(False)

cheese = better_lex()

for row in board:
    print(' '.join([str(cheese[x]) for x in row]))
