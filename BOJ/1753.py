# 175번_최단 경로
import sys, heapq
input = sys.stdin.readline
v, e = map(int, input().split())
k = int(input()) # 시작 정점
adj = [[] for _ in range(v+1)] # 단방향 그래프 인접 리스트로 표현
for i in range(e):
    a, b, c = map(int, input().split()) # a->b 비용 c
    adj[a].append((b, c))

# 다익스트라 알고리즘으로 시작 정점에서 다른 모든 정점으로의 최단 거리를 구함
inf = 987654321
dist = [inf] * (v+1)
visited = [False] * (v+1)
def dijkstra(k):
    pq = [] # 우선순위큐로 사용할 리스트
    heapq.heappush(pq, (0, k)) # 거리, 정점번호 쌍
    dist[k] = 0 # 출발 정점의 최단 거리는 0
    while len(pq) > 0:
        cur = heapq.heappop(pq)
        cur_d = cur[0]
        cur_v = cur[1]
        for next in adj[cur_v]:
            next_v = next[0]
            next_d = next[1]
            if dist[next_v] > dist[cur_v]+next_d: # 현재 정점 거치면 더 빠른 경우
                dist[next_v] = dist[cur_v]+next_d
                visited[next_v] = True
                heapq.heappush(pq, (dist[next_v], next_v))
                
dijkstra(k) # k에서 시작
for i in range(1, v+1):
    if dist[i] == inf: print("INF")
    else: print(dist[i])