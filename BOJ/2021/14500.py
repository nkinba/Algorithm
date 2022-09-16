ans = 0
N, M = list(map(int, input().split()))
mapArr = []
for i in range(N):
    mapArr.append(list(map(int, input().split())))


for r in range(N):
    for c in range(M):
        if(r+3 < N):
            ans = max(ans, mapArr[r][c] + mapArr[r+1]
                      [c] + mapArr[r+2][c] + mapArr[r+3][c])
        if(c+3 < M):
            ans = max(ans, sum(mapArr[r][c:c+4]))
        if((c+1 < M) & (r+1 < N)):
            ans = max(ans, sum(mapArr[r][c:c+2]) + sum(mapArr[r+1][c:c+2]))
        if((c+2 < M) & (r+1 < N)):
            whole = sum(mapArr[r][c:c+3]) + sum(mapArr[r+1][c:c+3])
            ans = max(ans, whole - mapArr[r][c] - mapArr[r+1][c+2])
            ans = max(ans, whole - mapArr[r+1][c] - mapArr[r][c+2])
            ans = max(ans, whole - mapArr[r][c] - mapArr[r][c+2])
            ans = max(ans, whole - mapArr[r+1][c] - mapArr[r+1][c+2])
            ans = max(ans, whole - mapArr[r][c] - mapArr[r][c+1])
            ans = max(ans, whole - mapArr[r+1][c] - mapArr[r+1][c+1])
            ans = max(ans, whole - mapArr[r][c+1] - mapArr[r][c+2])
            ans = max(ans, whole - mapArr[r+1][c+1] - mapArr[r+1][c+2])
        if((c+1 < M) & (r+2 < N)):
            whole = sum(mapArr[r][c:c+2]) + sum(mapArr[r+1]
                                                [c:c+2]) + sum(mapArr[r+2][c:c+2])
            ans = max(ans, whole - mapArr[r][c] - mapArr[r+1][c])
            ans = max(ans, whole - mapArr[r][c+1] - mapArr[r+1][c+1])
            ans = max(ans, whole - mapArr[r+1][c] - mapArr[r+2][c])
            ans = max(ans, whole - mapArr[r+1][c+1] - mapArr[r+2][c+1])
            ans = max(ans, whole - mapArr[r][c] - mapArr[r+2][c+1])
            ans = max(ans, whole - mapArr[r][c+1] - mapArr[r+2][c])
            ans = max(ans, whole - mapArr[r][c] - mapArr[r+2][c])
            ans = max(ans, whole - mapArr[r][c+1] - mapArr[r+2][c+1])

print(ans)
