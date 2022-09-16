N, M = map(int, input().split())
scoreList =  list(map(int, input().split()))
scoreList.insert(0, 0)
bonusList =  list(map(int, input().split()))
bonusList.insert(0, 0)

#어떤 문제에서 선택지는 두 가지
# - 정답 맞출 시 코인 1개
# - 맞추지 못하면 코인 모두 반납, 해당 문제 점수 감점
# M개 코인 모을 시 해당하는 문제 보너스 점수 획득, 코인 모두 반납

answer = 0
scoreOnZeroCoin = [0] * (N+1)
scoreSum = [0] * (N+1)

for n in range(1, N+1):
    scoreSum[n] = scoreSum[n-1] + scoreList[n]

for n in range(1, N+1):
    if n < M:
        scoreOnZeroCoin[n] = answer - scoreList[n]
    else:
        scoreOnZeroCoin[n] = max(answer - scoreList[n], 
                        scoreOnZeroCoin[n - M] + (scoreSum[n] - scoreSum[n - M]) + bonusList[n])
    answer = max(answer + scoreList[n], scoreOnZeroCoin[n]) 

print(answer)