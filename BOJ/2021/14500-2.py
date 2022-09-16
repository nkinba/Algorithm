from sys import stdin

getline = stdin.readline

maxVal = 0
N, M = map(int, getline().split())
matrix = [list(map(int, getline().split())) for row in range(N)]

visited = [[False] * M for row in range(N)]
rDir = [-1, 0, 1, 0]
cDir = [0, -1, 0, 1]


def movePossible(r: int, c: int):
    return (0 <= r and r < N and 0 <= c and c < M) and (visited[r][c] == False)


def dfs(r: int, c: int, curVal: int, steps: int):
    global maxVal
    if(curVal + maxValInMatrix * (4 - steps) <= maxVal):
        return

    if(steps == 4):
        maxVal = max(maxVal, curVal)
        return

    for i in range(4):
        nr = r + rDir[i]
        nc = c + cDir[i]
        if(movePossible(nr, nc)):
            if(steps == 2):
                visited[nr][nc] = True
                dfs(r, c, curVal + matrix[nr][nc], steps + 1)
                visited[nr][nc] = False

            visited[nr][nc] = True
            dfs(nr, nc, curVal + matrix[nr][nc], steps + 1)
            visited[nr][nc] = False


maxValInMatrix = max(map(max, matrix))

for row in range(N):
    for col in range(M):
        visited[row][col] = True
        dfs(row, col, matrix[row][col], 1)
        visited[row][col] = False

print(maxVal)
