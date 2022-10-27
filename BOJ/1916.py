# 1916번_최소비용 구하기
import sys, heapq
input = sys.stdin.readline
n = int(input())
m = int(input())
adj = [[] for _ in range(n+1)] # 도시 정보를 인접 리스트로 구성
for i in range(m):
    a, b, c = map(int, input().split())
    adj[a].append((b, c)) # a->b 비용 c

start, end = map(int, input().split())

# 다익스트라
inf = sys.maxsize
cost = [inf] * (n+1)
visited = [False] * (n+1)
def dijkstra(start):
    pq = [(0, start)] # 비용, 도시 번호
    cost[start] = 0
    while len(pq) > 0:
        cur_d, cur_v = heapq.heappop(pq)

        # 우선순위큐에서 꺼낸 도시까지의 최단거리가 최단 거리 리스트에 저장된 값보다 크면
        # 이미 처리가 완료된 값이므로 무시함
        if cost[cur_v] < cur_d: continue
        for next_v, next_d in adj[cur_v]:            
            if cost[next_v] > cost[cur_v]+next_d: # 현재 도시 거쳐서 가면 더 저렴한 경우
                cost[next_v] = cost[cur_v]+next_d
                heapq.heappush(pq, (cost[next_v], next_v))

dijkstra(start)
print(cost[end]) # 도착 도시에 도착하는 최소 비용