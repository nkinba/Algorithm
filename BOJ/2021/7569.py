from sys import stdin
from collections import deque
from collections import namedtuple

unprocessed = 0
tomato = namedtuple('tomato', ['H', 'N', 'M'])
getline = stdin.readline
M, N, H = list(map(int, getline().split()))

box = []
tomatoQ = deque([])

hDir = [-1, 1, 0, 0, 0, 0]
nDir = [0, 0, -1, 0, 1, 0]
mDir = [0, 0, 0, -1, 0, 1]

for _ in range(H):
    box.append([list(map(int, getline().split())) for _ in range(N)])

for h in range(H):
    for n in range(N):
        for m in range(M):
            if box[h][n][m] == 1:
                tomatoQ.append(tomato(H=h, N=n, M=m))
            elif box[h][n][m] == 0:
                unprocessed += 1


def isIn(h, n, m):
    return 0 <= h and h < H and 0 <= n and n < N and 0 <= m and m < M


def bfs():
    dayAnswer = 0
    processed = 0

    while True:
        tomatoCnt = len(tomatoQ)
        for _ in range(tomatoCnt):
            aTomato = tomatoQ.popleft()
            for i in range(6):
                nh = aTomato.H + hDir[i]
                nn = aTomato.N + nDir[i]
                nm = aTomato.M + mDir[i]
                if isIn(nh, nn, nm) and box[nh][nn][nm] == 0:
                    box[nh][nn][nm] = 1
                    tomatoQ.append(tomato(H=nh, N=nn, M=nm))
                    processed += 1

        if len(tomatoQ) == 0:
            break
        dayAnswer += 1

    if unprocessed != processed:
        dayAnswer = -1

    return dayAnswer


if unprocessed == 0:
    print(0)
else:
    print(bfs())
