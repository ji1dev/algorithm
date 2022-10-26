# 1312번_소수
import sys
input = sys.stdin.readline
a, b, n = map(int, input().split())

# 실제로 나눗셈을 하는 과정을 그대로 구현함
for i in range(n+1):
    ans = a//b
    a %= b
    a *= 10

print(ans)