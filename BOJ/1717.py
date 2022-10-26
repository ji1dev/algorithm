# 1717번_집합의 표현
import sys
input = sys.stdin.readline
n, m = map(int, input().split())

# parent 배열 채우기
parent = [0] * (n+1)
for i in range(1, n+1): parent[i] = i


# Union 연산
def union(a, b):
    # 각 노드가 속한 집합의 대표 노드를 찾음
    # 두 노드가 서로 다른 집합 소속이면 두 집합을 합침
    a = find(a)
    b = find(b)
    if a != b:
        parent[b] = a # b의 대표 노드가 a로 설정됨

# Find 연산
def find(a):
    # 자기 자신이 대표 노드인 경우 리턴
    # 아니면 대표 노드 찾을때까지 부모를 타고 올라감
    if a == parent[a]: return a
    else:
        parent[a] = find(parent[a])
        return parent[a]

# m개 연산 수행
for i in range(m):
    op, a, b = map(int, input().split())
    if op == 0: union(a, b)
    else:
        if find(a) == find(b): print('YES')
        else: print('NO')
