# 1929번_소수 구하기
import math
import sys
input = sys.stdin.readline
m, n = map(int, input().split()) # m이상 n이하 소수를 모두 구해야 됨
isPrime = [True] * (n+1) # 소수를 표시하는 리스트
for i in range(0, 2):
    isPrime[i] = False

# 에라토스테네스의 체
for i in range(2, int(math.sqrt(n+1))+1):
    if isPrime[i]:
        for j in range(i+i, n+1, i):
            isPrime[j] = False

# 소수로 표시된 숫자만 출력
for i in range(m, n+1):
    if isPrime[i]:
        print(i)