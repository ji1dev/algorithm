# 11403번_경로 찾기
import sys
input = sys.stdin.readline
n = int(input())
dist = [[0 for _ in range(n)] for _ in range(n)]
for i in range(n):
    dist[i] = list(map(int, input().split()))

# 플로이드-워셜 변형
def floyd():
    for k in range(n):
        for s in range(n):
            for e in range(n):
                # s->k, k->e 존재하면 s->e 가능
                if dist[s][k] and dist[k][e]:
                    dist[s][e] = 1

floyd()
for i in range(n):
    for j in range(n):
        print(dist[i][j], end=' ')
    print()