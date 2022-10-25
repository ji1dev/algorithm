# 1934번_최소공배수
import sys
input = sys.stdin.readline
t = int(input())

# 최소공배수를 구하는 함수
def gcd(a, b):
    if a < b: # b를 더 작은 숫자로 배치
        tmp = a
        a = b
        b = tmp
    
    if b == 0: # 나머지가 0이 될 때의 작은 숫자가 GCD
        return a
    else:
        return gcd(b, a%b)

for _ in range(t):
    a, b = map(int, input().split())
    print(int(a*b/gcd(a, b))) # LCM은 A*G/GCD로 구할 수 있음