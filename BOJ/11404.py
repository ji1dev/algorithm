# 11404번_플로이드
import sys
input = sys.stdin.readline
n = int(input())
m = int(input())

# 최단 거리 리스트를 최초 비용로 초기화
inf = sys.maxsize
cost = [[inf for _ in range(n+1)] for _ in range(n+1)] # n*n 크기
for i in range(n+1):
    cost[i][i] = 0 # 자기 자신으로 가는 최소 비용은 0

for i in range(m):
    a, b, c = map(int, input().split())
    # 출발 도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있으므로, 최소 비용으로 갱신
    if cost[a][b] > c:
        cost[a][b] = c

# 플로이드-워셜 알고리즘으로 모든 도시 간 최소 비용을 구함
def floyd():
    for k in range(1, n+1): # 경유 도시
        for s in range(1, n+1): # 출발 도시
            for e in range(1, n+1): # 도착 도시
                if cost[s][e] > cost[s][k]+cost[k][e]: # k거치면 더 저렴한 경우
                    cost[s][e] = cost[s][k]+cost[k][e]

floyd()
for i in range(1, n+1):
    for j in range(1, n+1):
        print(0 if cost[i][j]==inf else cost[i][j], end=' ')
    print()