import math

inp = list(map(int, input()))
numCnt = [0] * 10

for n in inp:
    numCnt[n] += 1
numCnt[6] = math.ceil((numCnt[6] + numCnt[9])/2)

print(sorted(numCnt[0:9])[-1])
