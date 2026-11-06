"""
goofy problem (see robot_championship.py)
"""

n = int(input('n = '))
# n=9
board = [[1] * n for _ in range(n)]
for i in range(n):
    for j in range(n):
        board[i][j] = i+j+2

def printb(b):
    for i in range(n-1, -1, -1):
        print(b[i])


# board[2][1] = 5

def valid(a, b):
    return a >= 0 and b >= 0 and a < n and b < n

def advance():
    global board
    nboard = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            for a, b in [(i+1, j+1), (i-1, j), (j-1, i)]:
                if valid(a, b) and valid(i, j) and board[a][b]:
                    nboard[i][j] = i+j+2

    board = nboard

def clear(x):
    for i in range(x):
        a, b = x-i-2, i
        if valid(a, b):
            board[a][b] = 0

while (True):
    try:
        clear(int(input('clear: ')))
    except KeyboardInterrupt:
        break
    except:
        pass
    print('\nafter clearing: ')
    printb(board)
    advance()
    print('\nafter advancing: ')
    printb(board)
