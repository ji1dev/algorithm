# 10986번_나머지 합
import sys
input = sys.stdin.readline
n, m = map(int, input().split())
nums = list(map(int, input().split()))
dp = [0] # 합 배열 인덱스 1부터 합 데이터 저장
ans = 0

# 합 배열 구하기
for i in nums:
    dp.append(dp[-1]+i)

# 처음~마지막 사이의 각 구간을 m으로 나눈 나머지를 구함
cnt = [0]*m # 나머지 값별 개수를 저장
for i in range(1, n+1):
    tmp = dp[i]%m
    cnt[tmp] += 1
    if tmp == 0:
        ans += 1 # 나누어 떨어지는 구간 합 개수 증가

# m으로 나눈 나머지(cnt[i])가 동일한 합 배열의 두 원소의 인덱스로 구간을 잡음
# 이 구간의 합을 m으로 나누면 나누어 떨어진다는 점을 이용
# 즉, cnt[i] 중 2개를 고르는 조합임
for i in range(m):
    if cnt[i] >= 2:
        ans += cnt[i]*(cnt[i]-1)//2

print(ans)