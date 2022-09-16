N, M = map(int, input().split())
isSwitchOn = [False]*(N*N)
isSwitchOn[0] = True
visited = [False]*(N*N)
visited[0] = True

switches = [[] for _ in range(N*N)]
for _ in range(M):
    x, y, a, b = map(int, input().split())
    origin = (x-1) * N + (y-1) 
    target = (a-1) * N + (b-1)
    switches[origin].append(target)

queue = [0]
lights = 1
isInRange = lambda x,y : 0 <= x and x < N and 0 <= y and y < N
rDir = [-1,0,1,0]
cDir = [0,-1,0,1]

while len(queue) > 0:
    curRoom = queue.pop(0)
    curSwitches = switches[curRoom]
    cr, cc = curRoom // N, curRoom % N
    for target in curSwitches:
        if isSwitchOn[target] == False:
            lights += 1
            isSwitchOn[target] = True
            tr, tc = target // N, target % N
            for d in range(4):
                nr, nc = tr + rDir[d], tc + cDir[d]
                if isInRange(nr, nc) and visited[nr*N + nc] == True:
                    visited[target] = True
                    queue.append(target)
                    break

    for d in range(4):
        nr, nc = cr + rDir[d], cc + cDir[d]
        if isInRange(nr, nc) and isSwitchOn[nr*N + nc] == True and visited[nr*N + nc] == False:
            visited[nr*N+nc] = True
            queue.append(nr*N+nc)

print(lights)