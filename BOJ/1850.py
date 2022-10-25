# 1850번_최대공약수
import sys, math
input = sys.stdin.readline
a, b = map(int, input().split())

# A와 B의 길이를 나타내는 두 숫자의 GCD는 A와 B의 GCD의 길이와 같음
result = math.gcd(a, b)
for _ in range(result):
    print(1, end='')