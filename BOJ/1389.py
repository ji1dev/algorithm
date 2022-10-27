# 1389번_케빈 베이컨의 6단계 법칙
import sys
input = sys.stdin.readline
n, m = map(int, input().split())
inf = sys.maxsize
dist = [[inf for _ in range(n+1)] for _ in range(n+1)]
for i in range(m):
    a, b = map(int, input().split())
    dist[a][b] = 1
    dist[b][a] = 1

# 플로이드-워셜 알고리즘으로 다른 친구와 이어지는 단계를 구함
def floyd():
    for k in range(n+1):
        for s in range(n+1):
            for e in range(n+1):
                if dist[s][e] > dist[s][k]+dist[k][e]:
                    dist[s][e] = dist[s][k]+dist[k][e]

# 케빈 베이컨 수가 최소인 사람의 번호를 구함
floyd()
ans = 0
min_sum = inf
for i in range(1, n+1):
    sum = 0
    for j in range(1, n+1): sum += dist[i][j]
    if min_sum > sum:
        min_sum = sum
        ans = i

print(ans)