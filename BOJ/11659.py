# 11659번_구간 합 구하기 4
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
nums = list(map(int, input().split()))
s = [0] # 합 배열, 데이터 1부터 저장
tmp = 0

# 합 배열 생성
for i in nums:
    tmp += i
    s.append(tmp)

# i부터 j까지의 구간 합 구함
for x in range(m):
    i, j = map(int, input().split())
    print(s[j]-s[i-1])