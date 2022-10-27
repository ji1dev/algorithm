# 11657번_타임머신
import sys
input = sys.stdin.readline
n, m = map(int, input().split())

edge = []
for _ in range(m):
    a, b, c = map(int, input().split())
    edge.append((a, b, c)) # 시작, 종료, 가중치

inf = sys.maxsize
dist = [inf] * (n+1)
def bellman_ford(start):
    dist[start] = 0
    # 최단 거리 업데이트 n-1회 후 음수 사이클 여부 확인위해 한번 더 돌아감
    for i in range(n+1):
        for s, e, w in edge: # 시작, 종료, 가중치
            if dist[s] == inf: continue # 도달 불가능한 정점
            if dist[e] > dist[s]+w: # 현재 간선 거치면 더 빠른 경우
                dist[e] = dist[s]+w

                # 업데이트 발생했는데 n회차인 경우 음수 사이클이 있다는 것
                # 음수 사이클 없으면 n-1회에 최단 거리가 모두 구해짐
                if i == n: return False
    
    return True # n회차에 업데이트 없으면 음수 사이클 존재하지 않음
            

if bellman_ford(1):
    for i in range(2, n+1):
        if dist[i] == inf: print(-1)
        else: print(dist[i])
else:
    print(-1) # 음수 사이클 존재하는 경우