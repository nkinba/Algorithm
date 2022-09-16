N = int(input())
nums = list(map(int, input().split()))
opCnts = list(map(int, input().split()))
maxAns = -1000000000
minAns = 1000000000


def cal(numPos: int, curVal: int):
    if(numPos == len(nums)):
        global minAns
        minAns = min(minAns, curVal)
        global maxAns
        maxAns = max(maxAns, curVal)
        return

    for i in range(4):
        if((i == 0) & (opCnts[0] > 0)):
            opCnts[0] -= 1
            cal(numPos + 1, curVal + nums[numPos])
            opCnts[0] += 1

        if((i == 1) & (opCnts[1] > 0)):
            opCnts[1] -= 1
            cal(numPos + 1, curVal - nums[numPos])
            opCnts[1] += 1

        if((i == 2) & (opCnts[2] > 0)):
            opCnts[2] -= 1
            cal(numPos + 1, curVal * nums[numPos])
            opCnts[2] += 1

        if((i == 3) & (opCnts[3] > 0)):
            opCnts[3] -= 1
            if(curVal < 0):
                cal(numPos + 1, -(-curVal // nums[numPos]))
            else:
                cal(numPos + 1, curVal // nums[numPos])
            opCnts[3] += 1

    return


cal(1, nums[0])
print(maxAns)
print(minAns)
