# 1456번_거의 소수
import math
import sys
input = sys.stdin.readline
a, b = map(int, input().split())
max = 10000001 # 10^7

# 에라토스테네스의 체 방법으로 소수의 배수를 모두 지움
prime = [0] * max
for i in range(2, max): prime[i] = i
for i in range(2, int(math.sqrt(max)+1)):
    if prime[i]:
        for j in range(i+i, max, i): prime[j] = 0

# A이상 B이하 거의 소수의 개수를 셈
ans = 0
for i in range(2, max):
    if prime[i] == 0: continue
    prev = prime[i]
    while prime[i] <= b/prev:
        if prime[i] >= a/prev: ans += 1
        prev *= prime[i]

print(ans)