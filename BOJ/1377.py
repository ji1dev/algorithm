# 1377번_버블 소트
import sys
input = sys.stdin.readline
n = int(input())
a = []
for idx in range(n):
    a.append((idx, int(input()))) # 인덱스, 값 쌍

# 두 번째 원소인 값을 기준으로 정렬
sorted = sorted(a, key=lambda x: x[1])

# 왼쪽으로 가장 멀리 이동한 원소의 이동 거리를 구함
# 해당 거리는 swap이 수행된 pass의 횟수와 같음
# 따라서 (거리+1)이 swap이 발생하지 않은 pass의 번호
dist = 0
for idx in range(n):
    if dist > idx-sorted[idx][0]:
        dist = idx-sorted[idx][0]

print(abs(dist)+1)