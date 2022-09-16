### https://www.acmicpc.net/problem/1423 원숭이 키우기

N = int(input()) 
charCounts = list(map(int, input().split()))
charCounts.insert(0,0)
strengths = list(map(int, input().split()))
strengths.insert(0,0)
D = int(input())

# (N+1) * (D+1) * (D+1) matrix
dp = [[ [-1] * (D+1) for _ in range(D+1) ] for _ in range(N+1)]

# dp[curLevel(현재 보고 있는 캐릭터 레벨)][restDays(남은 일 수)][elevated(다음 레벨로 레벨업 할 수 있는 캐릭터 수)] 
#      = max(dp[level+1][restDays - levelUpCnt][upCounts]
#               + (strengths[level + 1]-strengths[level]) * upCounts
#       )  
#
# 0 <= upCounts(레벨업 할 캐릭터 수) <= restDays

def process(curLevel, restDays, elevated):
    if curLevel == N:
        return 0

    if dp[curLevel][restDays][elevated] != -1:
        return dp[curLevel][restDays][elevated]

    maxProfit = 0  
    for upCounts in range(elevated + charCounts[curLevel] + 1):
        if restDays < upCounts:
            break

        profit = (strengths[curLevel+1] - strengths[curLevel]) * upCounts
        maxprofitFromNext = process(curLevel+1, restDays-upCounts, upCounts) + profit

        maxProfit = max(maxProfit, maxprofitFromNext)

    dp[curLevel][restDays][elevated] = maxProfit
    return maxProfit    
    
answer = 0
for level in range(1, N+1):
    answer += strengths[level] * charCounts[level]

answer += process(1, D, 0)
print(answer)