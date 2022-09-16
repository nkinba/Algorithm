numOnDice = [0] * 7
dicePosition = [-1, 2, 4, 1, 3, 5, 6]
#     1
# 2   3   4
#     5
#     6
mapArr = []
steps = []
directions = ['-', 'E', 'W', 'N', 'S']
xDir = [0, 0, -1, 1]
yDir = [1, -1,  0, 0]

N, M, cx, cy, K = map(int, input().split())


def isInMap(nx: int, ny: int):
    return (0 <= nx) & (nx < N) & (0 <= ny) & (ny < M)


def move(dirKind: int):
    direction = directions[dirKind]

    if(direction == 'E'):
        tmp = dicePosition[6]
        dicePosition[6] = dicePosition[4]
        dicePosition[4] = dicePosition[3]
        dicePosition[3] = dicePosition[2]
        dicePosition[2] = tmp

    elif(direction == 'W'):
        tmp = dicePosition[6]
        dicePosition[6] = dicePosition[2]
        dicePosition[2] = dicePosition[3]
        dicePosition[3] = dicePosition[4]
        dicePosition[4] = tmp

    elif(direction == 'N'):
        tmp = dicePosition[6]
        dicePosition[6] = dicePosition[1]
        dicePosition[1] = dicePosition[3]
        dicePosition[3] = dicePosition[5]
        dicePosition[5] = tmp

    elif(direction == 'S'):
        tmp = dicePosition[6]
        dicePosition[6] = dicePosition[5]
        dicePosition[5] = dicePosition[3]
        dicePosition[3] = dicePosition[1]
        dicePosition[1] = tmp

    if(mapArr[cx][cy] == 0):
        mapArr[cx][cy] = numOnDice[dicePosition[6]]
    else:
        numOnDice[dicePosition[6]] = mapArr[cx][cy]
        mapArr[cx][cy] = 0

    print(numOnDice[dicePosition[3]])


for n in range(N):
    mapArr.append(list(map(int, input().split())))

steps = list(map(int, input().split()))

for step in steps:
    nx = cx + xDir[step-1]
    ny = cy + yDir[step-1]

    if(isInMap(nx, ny) == False):
        continue

    cx = nx
    cy = ny
    move(step)
