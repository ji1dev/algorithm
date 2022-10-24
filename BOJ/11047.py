# 11047번_동전 0
import sys
input = sys.stdin.readline
n, k = map(int, input().split()) # n종류 동전으로 k원 만들기
a = []
for _ in range(n):
    coin = int(input())
    a.append(coin)

# 액수 큰 동전부터 채워나감
a.sort(reverse=True)
cnt = 0
for i in a:
    if i > k: continue
    cnt += k//i # i원 동전을 최대로 채워넣음
    k %= i # i원 동전으로 채우고 남은 액수 계산

print(cnt)