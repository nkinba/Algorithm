from sys import stdin
from collections import deque
getline = stdin.readline

N, M = list(map(int, getline().split()))
matrix = [list(map(int, getline().split())) for _ in range(N)]
nDir = [-1, 0, 1, 0]
mDir = [0, -1, 0, 1]
icebergs = set()
iceQueue = deque([])
year = 0


def isIn(n, m):
    return 0 <= n and n < N and 0 <= m and m < M


for n in range(N):
    for m in range(M):
        if matrix[n][m] > 0:
            icebergs.add((n, m))

while len(icebergs) > 0:
    iceCount = len(icebergs)
    visited = [[False] * M for _ in range(N)]
    checkedIce = 1
    firstIce = next(icebergs.__iter__())
    iceQueue.append(firstIce)
    visited[firstIce[0]][firstIce[1]] = True
    meltTarget = []

    while len(iceQueue) > 0:
        anIce = iceQueue.popleft()
        n, m = anIce
        for d in range(4):
            nn = n + nDir[d]
            nm = m + mDir[d]
            if isIn(nn, nm):
                if matrix[nn][nm] == 0:
                    meltTarget.append((n, m))
                elif visited[nn][nm] == False:
                    visited[nn][nm] = True
                    iceQueue.append((nn, nm))
                    checkedIce += 1

    if checkedIce != iceCount:
        break

    for melt in meltTarget:
        if matrix[melt[0]][melt[1]] > 0:
            matrix[melt[0]][melt[1]] -= 1
            if matrix[melt[0]][melt[1]] == 0:
                icebergs.remove(melt)

    year += 1

if len(icebergs) == 0:
    print(0)
else:
    print(year)
