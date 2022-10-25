# 1747번_소수&팰린드롬
# 어떤 수 N (1 ≤ N ≤ 1,000,000)이 주어졌을 때, N보다 크거나 같고, 
# 소수이면서 팰린드롬인 수 중에서, 가장 작은 수를 구하는 프로그램을 작성하시오.
import sys, math
input = sys.stdin.readline
n = int(input())
max = 10000001

# 소수 구하기
prime = [0] * max
for i in range(2, max): prime[i] = i
for i in range(2, int(math.sqrt(max))+1):
    if prime[i]:
        for j in range(i+i, max, i):
            prime[j] = 0

# 소수이면서 팰린드롬인 수를 찾으면 출력하고 탈출
for i in range(n, max):
    if not prime[i]: continue
    if str(prime[i]) == str(prime[i])[::-1]:
        print(prime[i])
        break